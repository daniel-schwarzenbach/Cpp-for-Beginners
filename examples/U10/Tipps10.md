## Ex 1: Generic Linked List with Iterators

```cpp
template <typename T>
class List {
 public:
  struct Node {
    T value;
    unique_ptr<Node> next;
    Node* prev;
  };
  struct Iterator {
    Node* nodePtr;

    T& operator*() const { ... }
    T* operator->() const { ... }
    Iterator& operator=(const Iterator& other) { ... }
    Iterator& operator++() { ... } // ++it
    Iterator operator++(int) { ... } // it++
    Iterator& operator--() { ... } // --it
    Iterator operator--(int) { ... } // it--
    friend bool operator==(const Iterator& lhs, const Iterator& rhs) { ... }
    friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { ... }
  };

 private:
  unique_ptr<Node> _head;
  Node* _tail;
  size_t _size;

 public:
  // Rule of 3
  List() : ... {}
  List(List const& other) : ... { ... }
  List& operator=(const List& other) { ... }
  // initializer list constructor
  List(initializer_list<T> init) : ... { ... }
  // geter functions
  constexpr size_t size() const { ... }
  constexpr Iterator begin() const { ... }
  constexpr Iterator end() const { ... }
  // modification functions
  void append(T const& val) { ... }
  void remove(T val) { ... }
};
```


## Ex 2: Check Mate Detection

to detect a check mate situation, we need to verify if the king is in check and if there are any possible moves left for the player to escape the check. The following functions help us achieve this:

```cpp
bool is_check_mate(const Board& chessBoard, bool checkWhiteKing, bool checkBlackKing) {
  Cords wKCords = find_king(chessBoard, Piece::WHITE_KING);
  Cords bKCords = find_king(chessBoard, Piece::BLACK_KING);
// check if any piece of team can hit the aposing king
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      if (checkWhiteKing && is_black(chessBoard(i, j))) {
        // can it hit the white king
        if (is_legal_move(Cords{i, j}, wKCords, true, chessBoard)) {
          // if white can't counter it's check mate
          if (!can_white_counter(chessBoard)) {
            return true;
          }
        }
      } else if (checkBlackKing && is_white(chessBoard(i, j))) {
        // can it hit the black king
        if (is_legal_move(Cords{i, j}, bKCords, true, chessBoard)) {
          // if black cant counter it's check mate
          if (!can_black_counter(chessBoard)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}
```

while the function `can_black_counter` checks if the black player can make any legal move to escape check:

```cpp
bool can_black_counter(ChessBoard& chessBoard) {
  // check now every black posible move and look if its preventing check
  for (int ox = 1; ox <= 8; ++ox) {
    for (int oy = 1; oy <= 8; ++oy) {
      if (is_black(chessBoard(ox, oy))) {
        for (int tx = 1; tx <= 8; ++tx) {
          for (int ty = 1; ty <= 8; ++ty) {
            if (!is_black(chessBoard(tx, ty)) &&
                is_legal_move(Cords{ox, oy}, Cords{tx, ty}, is_white(chessBoard(tx, ty)), chessBoard)) {
              char t = chessBoard(tx, ty);y
              // make this move
              chessBoard(tx, ty) = chessBoard(ox, oy);
              chessBoard(ox, oy) = ' ';
              bool hasToReturn = !is_check(false, true, chessBoard);
              // undo this move
              chessBoard(ox, oy) = chessBoard(tx, ty);
              chessBoard(tx, ty) = t;
              if (hasToReturn) return true;
            }
          }
        }
      }
    }
  }
  // its checkmate
  return false;
}
```