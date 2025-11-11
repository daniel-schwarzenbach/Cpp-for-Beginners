#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

constexpr string piece_name(char p) {
  switch (p) {
    case 'k':
      return "black king";
    case 'q':
      return "black queen";
    case 'r':
      return "black rook";
    case 'b':
      return "black bishop";
    case 'n':
      return "black knight";
    case 'p':
      return "black pawn";
    case 'K':
      return "white king";
    case 'Q':
      return "white queen";
    case 'R':
      return "white rook";
    case 'B':
      return "white bishop";
    case 'N':
      return "white knight";
    case 'P':
      return "white pawn";
    default:
      throw std::invalid_argument("invalid piece character");
  }
}

char valid_file(char file) {
  if (file < 'a' || file > 'h') {
    throw std::invalid_argument("file must be between 'a' and 'h'");
  }
  return file;
}

char valid_row(char row) {
  if (row < '1' || row > '8') {
    throw std::invalid_argument("row must be between '1' and '8'");
  }
  return row;
}

string normal_move(string const& move) {
  // we need at least 5 characters for a normal move
  if (move.size() < 5) throw std::invalid_argument("invalid move format");
  std::stringstream ss;
  ss << piece_name(move[0]) << " on file " << valid_file(move[1]) << ", row " << valid_row(move[2]) << " moves to file "
     << valid_file(move.at(3)) << ", row " << valid_row(move.at(4));
  // check if we have a capture move
  if (move.size() > 5) {
    // check for promotion format
    if (move[5] == '=' && move.size() == 7) {
      ss << " and promotes to " << piece_name(move[6]);
    } else {
      throw std::invalid_argument("invalid move format");
    }
  }
  return ss.str();
}

string capture_move(string const& move) {
  // we need at least 6 characters for a capture move
  if (move.size() < 6) throw std::invalid_argument("invalid move format");
  std::stringstream ss;
  ss << piece_name(move[0]) << " on file " << valid_file(move[1]) << ", row " << valid_row(move[2])
     << " captures the piece on file " << valid_file(move.at(4)) << ", row " << valid_row(move.at(5));
  // check if we have a promotion
  if (move.size() > 6) {
    // check for promotion format
    if (move[6] == '=' && move.size() == 8) {
      ss << " and promotes to " << piece_name(move[7]);
    } else {
      throw std::invalid_argument("invalid move format");
    }
  }
  return ss.str();
}

int main(int argsSize, char** args) {
  for (int i = 1; i < argsSize; ++i) {
    try {
      string move = args[i];
      switch (move.at(3)) {
        case 'x':
          cout << capture_move(move) << endl;
          break;
        default:
          cout << normal_move(move) << endl;
      }
    } catch (...) {
      cout << "invalid" << endl;
    }
  }
  return 0;
}