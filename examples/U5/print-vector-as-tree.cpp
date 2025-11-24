#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::stringstream;
using std::vector;

/**
 * Prints a vector representing a binary heap as a tree structure.
 * @example {1, 3, 2, 7, 6, 4, 5}
 * Output:
 *           1
 *        /    \
 *      3       2
 *    /  \    /  \
 *   7   6   4   5
 */
void print_as_tree(const vector<int> &vec) {
  size_t n = vec.size();
  if (n == 0)
    return;
  int levelsSize = floor(log2(n) + 1);
  stack<string> levels;
  string spaces = "  ";
  // line spacing is half of th
  string spaces_half = " ";
  string forgoten_spaces = "";
  // first go to the lowes layer
  for (int level = levelsSize - 1; level > 0; --level) {
    int i = pow(2, level) - 1;
    int nextLevel_i = pow(2, level + 1) - 1;
    stringstream ss1;
    stringstream ss2;
    ss1 << spaces << forgoten_spaces;
    ss2 << spaces << forgoten_spaces;
    while (i < n && i < nextLevel_i) {
      ss1 << vec[i] << spaces << spaces;
      if (i % 2 == 0) {
        ss2 << spaces_half << "\\" << spaces_half << spaces << spaces;
      } else {
        ss2 << spaces_half << "/" << spaces_half;
      }
      ++i;
    }
    spaces_half = spaces_half + spaces_half;
    spaces = spaces + spaces;
    forgoten_spaces += " ";
    levels.push(ss1.str());
    levels.push(ss2.str());
  }
  cout << spaces << forgoten_spaces << vec[0] << endl;
  while (!levels.empty()) {
    cout << levels.top() << endl;
    levels.pop();
  }
}

int main() {
  vector<int> heap = {1, 3, 2, 7, 60, 40, 5, 8, 9, 1, 1, 3, 2,2 ,2,2,2,2};
  cout << "Heap as tree:" << endl;
  print_as_tree(heap);
  return 0;
}