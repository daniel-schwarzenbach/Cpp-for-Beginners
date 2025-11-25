#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <format>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::format;

/**
Prints a vector representing a binary heap as a tree structure.
```md
example {1, 3, 2, 7, 6, 4}
Output:
           1
        /    \
      3       2
    /  \    /  \
   7   6   4

```
 */
template<typename T>
void print_as_tree(const vector<T> &vec) {
  int n = vec.size();
  if (n == 0)
    return;
  // now we can set the spaces accordingly
  const string base_padding(5, ' ');
  constexpr const char* form = "{:^5}";
  string startPadding = "";
  string inBetweenPadding = "";
  int levelsSize = floor(log2(n) + 1);
  std::stack<string> levels;
  // first go to the lowes layer
  for (int level = levelsSize - 1; level > 0; --level) {
    int i = pow(2, level) - 1;
    int nextLevel_i = pow(2, level + 1) - 1;
    stringstream ss1;
    stringstream ss2;
    ss1 << startPadding;
    ss2 << startPadding;
    while (i < n && i < nextLevel_i) {
      ss1 << format(form, vec[i]);
      if (i % 2 == 0) {
        ss2 << format(form, "\\ ") << inBetweenPadding;
        ss1 << inBetweenPadding;
      } else {
        ss2 << format(form, "  /") << inBetweenPadding;
        ss1 << inBetweenPadding;
      }
      ++i;
    }
    inBetweenPadding += inBetweenPadding + base_padding;
    startPadding = string(pow(2, levelsSize - 1 - level) * 5 - 2, ' ');
    levels.push(ss1.str());
    levels.push(ss2.str());
  }
  cout << startPadding << format(form, vec[0]) << endl;
  while (!levels.empty()) {
    cout << levels.top() << endl;
    levels.pop();
  }
  cout << endl;
}