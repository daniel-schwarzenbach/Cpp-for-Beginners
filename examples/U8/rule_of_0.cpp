#include <iostream>
#include <ostream>
#include <utility>

using std::cout;
using std::endl;
using std::move;

// Rule of Zero
struct Point {
  int x;
  int y;
};

std::ostream&operator<<(std::ostream &os, const Point &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}


int main() {
  Point p1 = {3, 4};
  Point p2 = {5, 6};
  Point p3(p1);
  p1 = p2;
  Point p4 = move(p2);
  p4 = move(p3);
  cout << "p2: " << p2 << endl;
  cout << "p3: " << p3 << endl;
  return 0;
}

