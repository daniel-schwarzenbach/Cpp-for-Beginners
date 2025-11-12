#include <iostream>

using std::cout;
using std::endl;

void copy(char dest[8], const char* src) {
	for (int i = 0; i < 8; ++i) {
		dest[i] = src[i];
		// stop the segmentation fault
		if (src[i] == '\0') throw std::out_of_range("Not enough characters in source");
	}
}

// define the chess board structure
struct ChessBoard {
	char board[8][8];
	// initialize the chess board
	ChessBoard() {
		// Initialize all positions with spaces
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				board[i][j] = ' ';
				
			}
		}
		copy(board[0], "RNBQKBNR");
		copy(board[1], "PPPPPPPP");
		copy(board[6], "pppppppp");
		copy(board[7], "rnbqkbnr");
	}
	
	// define an access operator
	char& operator()(uint x, uint y) {
		if (x >= 8 || y >= 8) {
			throw std::out_of_range("Index out of bounds");
		}
		return board[x][y];
	}
};

// define the output operator for the chess board
std::ostream& operator<<(std::ostream& os, ChessBoard& cb) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			os << cb(i, j);
		}
		os << endl;
	}
	return os;
}


int main() {
	// initialize the chess board
  ChessBoard chessBoard;
	// set some pieces
	chessBoard(2, 7) = 'X';
	chessBoard(3, 3) = 'Y';
	// print the chess board
	cout << chessBoard;
}
