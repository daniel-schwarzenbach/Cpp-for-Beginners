## Exercise 1

To take functions as parameters you can use a template parameter:

```cpp
template <typename Container, typename CompareFn>
void sort_container(Container& container, CompareFn const& compare) {
  ...
}
```


## Exercise 3

Use `debug.h` to print debug information. Complie with `-DDebug` flag.

Things to do:
1. Read chess moves from a file.
2. Checking Pawn promotion.
3. Pawn captures
4. Check for check.
5. Output invalid on invalid moves.

Use `std::ifstream` to read from files. <https://en.cppreference.com/w/cpp/io/basic_ifstream.html>

Use `std::regex` to find out what kind of move or action is described. <https://en.cppreference.com/w/cpp/regex.html>


```cpp
bool is_check() {
  // iterate over all pieces on the board
  for (const auto& piece : pieces) {
    // if the piece is of the opponent and can attack the king's position
    if (piece.color != king.color && piece.can_attack(king.position)) {
      return true; // king is in check
    }
  }
  return false; // king is not in check
}
```

## Alte Kahoots:

<https://daniel.schwarzenbach.dev/blog/computer-sience/constance/>