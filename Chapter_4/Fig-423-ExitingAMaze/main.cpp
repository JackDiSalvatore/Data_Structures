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
#include <string>
#include <stack>

using namespace std;


template<class T>
class Stack : public stack<T> {
public:
	// Override the pop message to return the top element as well
	// as popping it
	T pop() {
		T tmp = top();
		stack<T>::pop();
		return tmp;
	}
};


class Cell {
public:
	Cell(int i = 0; int j = 0) {
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
private:
	Cell currentCell, exitCell, entryCell;		// Create our three cell objects
	const char exitMarker, entryMarker, visited, passage, wall;	// Constant parts of the maze
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
	}    




int main(int argv, char *argc[]) {
	cout << "Figure 4.23: Exiting a maze" << endl;

	return 0;
}


