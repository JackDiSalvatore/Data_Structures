/*
 * chessBoard.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: jack
 */
#include <iostream>

using namespace std;

class ChessBoard {
public:
	ChessBoard();		// 8x8 chessboard
	ChessBoard(int);	// nxn chessboard

	void findSolutions();
private:
	const bool available;
	const int squares, norm;	// norm is used to avoid negatives when indexing the rightDiagonal array, ex: representing the range (-3,3) in 4x4 with (0,6)
	bool *column, *leftDiagonal, *rightDiagonal;
	int *positionInRow, howMany;

	void putQueen(int);
	void printBoard(ostream&);
	void initializeBoard();
};

ChessBoard::ChessBoard() :
		available(true), squares(8), norm(squares-1)
{
	initializeBoard();
}

ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1) {
	initializeBoard();
}

void ChessBoard::printBoard(ostream& out) {
	const unsigned char Queen = 'Q';
	const unsigned char openSquare = 'x';
	int rPrev = 0;

	for(int r = 0; r < squares; r++) {
		for(int c = 0; c < squares; c++) {
			if(r > rPrev){
				cout << '\n';
				rPrev++;
			}
			//out << '(' << r << ',' << c << ')';
			if(positionInRow[r] == c)
				out << Queen;
				//out << "Queen in " << r << ',' << c << ' ';
			else
				out << openSquare;
		}
	}

	howMany++;
	cout << "\n\n";
}

void ChessBoard::initializeBoard() {
	register int i;
	column = new bool[squares];
	positionInRow = new int[squares];
	leftDiagonal = new bool[squares*2 - 1];
	rightDiagonal = new bool[squares*2 - 1];

	for(i = 0; i < squares; i++)
		positionInRow[i] = -1;
	for(i = 0; i < squares; i++)
		column[i] = available;
	for(i = 0; i < squares*2 - 1; i++)
		leftDiagonal[i] = rightDiagonal[i] = available;
	howMany = 0;
}

void ChessBoard::putQueen(int row) {
	for(int col = 0; col < squares; col++)
		if(column[col] == available &&
		   leftDiagonal[row+col] == available &&
		   rightDiagonal[row-col+norm] == available) {
			positionInRow[row] = col;
			column[col] = !available;
			leftDiagonal[row+col] = !available;
			rightDiagonal[row-col+norm] = !available;
			if(row < squares-1)
				putQueen(row+1);
			else printBoard(cout);
			column[col] = available;
			leftDiagonal[row+col] = available;
			rightDiagonal[row-col+norm] = available;
		}
}

void ChessBoard::findSolutions() {
	putQueen(0);
	cout << howMany << " solutions found.\n";
}

int main() {
	cout << "Recursive chess board" << endl;
	ChessBoard MyChessBoard(4);

	MyChessBoard.findSolutions();
	return 0;
}
