/*
 * main.cpp
 *
 *  Exiting a Maze.
 *      The maze: 1's are walls, 0's are passages, m is the mouse
 *      (player), and e is the elevator out of the maze
 *
 *			x,y - top left is origin(1,1)
 *
 * 		pos(1,1)       (1,4)
 *      		1 1 0 0
 *      		0 0 0 e
 *      		0 0 m 1
 *      pos(3,1)	   (3,4)
 *
 *      Pad maze with walls, so mouse doesnt fall off, we get:
 *
 *            1 1 1 1 1 1
 *      	  1	1 1 0 0 1
 *      	  1	0 0 0 e 1
 *      	  1	0 0 m 1 1
 *      	  1 1 1 1 1 1
 *
 *
 *	stack: open positions mouse can move to, will move UP, DOWN, LEFT, RIGHT
 *
 *			|     |		|     |		|     |		|     |		|     |		|(2 4)|		|     |
 *			|     |		|(3 1)|		|(2 1)|		|(2 2)|		|(2 3)|		|(1 3)|		|(1 3)|
 *			|(3 2)|		|(2 2)|		|(2 2)|		|(2 2)|		|(2 2)|		|(2 2)|		|(2 2)|
 *			|(2 3)|		|(2 3)|		|(2 3)|		|(2 3)|		|(2 3)|		|(2 3)|		|(2 3)|
 *			-------		-------		-------		-------		-------		-------		-------
 *
 *	current	 (3 3)		(3 2)		(3 1)		(2 1)		(2 2)		(2 3)		(2 4)
 *	 pos
*      		1 1 0 0		1 1 0 0		1 1 0 0		1 1 0 0		1 1 0 0		1 1 0 0		1 1 0 0
*      		0 0 0 e		0 0 0 e		0 0 0 e		. 0 0 e		. . 0 e		. . . e		. . . e
*      		0 0 m 1		0 . m 1		. . m 1		. . m 1		. . m 1		. . m 1		. . m 1
 *
 */


#include <iostream>
#include <string.h>
#include <stack>

using namespace std;


template<class T>
class Stack : public stack<T> {
public:
	// Override the pop message to return the top element as well
	// as popping it
	T pop() {
		T tmp = stack<T>::top();
		stack<T>::pop();
		return tmp;
	}
};


class Cell {
public:
	Cell(int i = 0, int j = 0) {
		x = i; y = j;
	}
	bool operator== (const Cell& c) const {
		return (x == c.x) && (y == c.y);
	}
private:
	int x, y;
	friend class Maze;
};


class Maze {
public:
	Maze();
	void exitMaze();
private:
	Cell currentCell, exitCell, entryCell;		// Create our three cell objects each with (x,y)
	const char exitMarker, entryMarker, visited, passage, wall;	// Constant char parts of the maze
	Stack<Cell> mazeStack;
	char **store;		// array of strings

	void pushUnvisited(int, int);	// x, y
	friend ostream& operator<< (ostream&, const Maze&);

	int rows, cols;
};


Maze::Maze() : 
exitMarker('e'), entryMarker('m'), 
visited('.'), passage('0'), wall('1') 
{
    Stack<char*> mazeRows;
	char str[80], *s;
	int col, row = 0;
	cout << "Enter a rectangular maze using the following "
	     << "characters:\nm - entry\ne - exit\n1 - wall\n0 - passage\n"
	     << "Enter one line at a time; end with Ctrl-z:\n";
	while (cin >> str) {
		row++;
		cols = strlen(str);		// 9
        s = new char[cols+3];   // two more cells for borderline columns
        
        mazeRows.push(s);
        strcpy(s+1, str);
        s[0] = s[cols+1] = wall;    // fill the borderline cells with 1's
        s[cols+2] = '\0';			// NULL terminate ?
        
        // NOTE: 'strchr' Returns a pointer to the first occurrence of character in the C string str.
        
        if(strchr(s, exitMarker) != 0) {
            exitCell.x = row;
            exitCell.y = strchr(s, exitMarker) - s;
        }
        if (strchr(s, entryMarker) != 0) {
            entryCell.x = row;
            entryCell.y = strchr(s, entryMarker) - s;
        }
	}
    
    rows = row;
    store = new char*[rows+2];      // create a 1D array of pointers
    store[0] = new char[cols+3];    // a borderline row
    
    for ( ; !mazeRows.empty(); row--) {
        store[row] = mazeRows.pop();
    }
    
    store[rows+1] = new char[cols+3];   // another borderline row;
    store[0][cols+2] = store[rows+1][cols+2] = '\0';
    
    for (col = 0; col <= cols+1; col++) {
        store[0][col] = wall;       // fill the borderline rows with 1's
        store[rows+1][col] = wall;
    }
}


void Maze::pushUnvisited(int row, int col) {
    if (store[row][col] == passage || store[row][col] == exitMarker) {
        mazeStack.push(Cell(row,col));
    }
}

void Maze::exitMaze() {
    int row, col;
    currentCell = entryCell;
    
    while (!(currentCell == exitCell)) {
        row = currentCell.x;
        col = currentCell.y;
        
        cout << *this;      // print a snapshot
        
        if (!(currentCell == entryCell))
            store[row][col] = visited;
        
        // UP, DOWN, LEFT, RIGHT
        pushUnvisited(row-1, col);
        pushUnvisited(row+1, col);
        pushUnvisited(row, col-1);
        pushUnvisited(row, col+1);
        
        if (mazeStack.empty()) {
            cout << *this;
            cout << "Failure\n";
            return;
        }
        else currentCell = mazeStack.pop();
    }
    cout << *this;
    cout << "Success\n";
}

// Prints the Maze
ostream& operator<< (ostream& out, const Maze& maze) {
    for (int row = 0; row <= maze.rows+1; row++)
        out << maze.store[row] << endl;
    out << endl;
    
    return out;
}


int main(int argv, char *argc[]) {
	cout << "Figure 4.23: Exiting a maze" << endl;

    Maze().exitMaze();
    
	return 0;
}



