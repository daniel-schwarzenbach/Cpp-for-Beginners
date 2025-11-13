#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::string;

// stringcopy for 8 characters
void copy(char dest[8], const char* src) {
	for (int i = 0; i < 8; ++i) {
		dest[i] = src[i];
		// stop the segmentation fault
		if (src[i] == '\0') throw std::out_of_range("copy: src is to small");
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
		copy(board[7], "rnbqkbnr");
		copy(board[6], "pppppppp");
		copy(board[1], "PPPPPPPP");
		copy(board[0], "RNBQKBNR");
	}

	// access operator using chess coordinates
	char& operator()(const char a, const char b) {
		uint i2 = a - 'a';  // row
    uint i1 = b - '1';  // column
		if (i1 >= 8 || i2 >= 8) {
			string msg = string("Index out of bounds at: (") + string({a}) 
					+ string(", ") + string({b}) + string(")");
			throw std::out_of_range(msg);
		}
		return board[i1][i2];
	}

	// constant access operator using chess coordinates
	char operator()(const char a, const char b) const {
		uint i2 = a - 'a';  // row
    uint i1 = b - '1';  // column
		if (i1 >= 8 || i2 >= 8) {
			string msg = string("Index out of bounds at: (") + string({a}) 
					+ string(", ") + string({b}) + string(")");
			throw std::out_of_range(msg);
		}
		return board[i1][i2];
	}

	// define the output operator for the chess board
	friend std::ostream& operator<<(std::ostream& os, ChessBoard& cb) {
		for (int i = 7; i >= 0; --i) {
			for (int j = 0; j < 8; ++j) {
				os << cb.board[i][j];
			}
			os << endl;
		}
		return os;
	}
};




int main() {
	// initialize the chess board
  ChessBoard chessBoard;
	try {
		// set some pieces
		chessBoard('g', '3') = 'X';
		chessBoard('c', '4') = 'Y';
		chessBoard('a','5') = 'Z';
		char a = 'b', b = '6';
		chessBoard(a, b) = 'W';
		// print the chess board
		cout << chessBoard;
		cout << endl;
		// out of bounds
		chessBoard('a', '9') = 'E'; 
	}
	// catch any exception 
	catch (const std::exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}
