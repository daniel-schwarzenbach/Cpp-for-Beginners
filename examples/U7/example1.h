struct cords {
  char file;
  char rank;
};

constexpr bool is_legal_move(char piece, cords from, cords to, bool capture) {
  switch (piece) {
    case 'p': {
      if (!capture && from.rank == '7' &&  to.rank == '5') {
        return from.file == to.file;
      }
      return (from.rank - 1 == to.rank) && (capture ? (from.file + 1 == to.file || from.file - 1 == to.file) : from.file == to.file);
    }
    case 'P': {
      if (!capture && from.rank == '2' &&  to.rank == '4') {
        return from.file == to.file;
      }
      return (from.rank + 1 == to.rank) && (capture ? (from.file + 1 == to.file || from.file - 1 == to.file) : from.file == to.file);
    }
  }
  return false;
}