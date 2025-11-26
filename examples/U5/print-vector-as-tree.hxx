#pragma once

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
  // if the vector is empty return
  if (n == 0)
    return;
  // now we can set the spaces accordingly
  const string base_padding(5, ' ');
  // predefine the format
  constexpr const char* form = "{:^5}";
  string startPadding = "";
  string inBetweenPadding = "";
  // calculate number of levels
  int levelsSize = floor(log2(n) + 1);
  // store levels to print later
  std::stack<string> levels;
  // first go to the lowes layer
  // iterate over every layer starting with the lowest
  for (int level = levelsSize - 1; level > 0; --level) {
    // get the current index
    int i = pow(2, level) - 1;
    // get the index of the next levels
    int nextLevel_i = pow(2, level + 1) - 1;
    // init two streams, one for numbers the second for the branches
    stringstream ss1;
    stringstream ss2;
    // add initial padding
    ss1 << startPadding;
    ss2 << startPadding;
    // iterate over every value at this level
    while (i < n && i < nextLevel_i) {
      ss1 << format(form, vec[i]) << inBetweenPadding;
      if (i % 2 == 0) {
        ss2 << format(form, "\\ ") << inBetweenPadding;
      } else {
        ss2 << format(form, "  /") << inBetweenPadding;
      }
      ++i;
    }
    // increase the in between Padding
    inBetweenPadding += inBetweenPadding + base_padding;
    // calculate the next starting level
    startPadding = string(pow(2, levelsSize - 1 - level) * 5 - 2, ' ');
    // add the strings to the stack
    levels.push(ss1.str());
    levels.push(ss2.str());
  }
  // print out the first level
  cout << startPadding << format(form, vec[0]) << endl;
  // print out the other levels
  while (!levels.empty()) {
    cout << levels.top() << endl;
    levels.pop();
  }
  // neline
  cout << endl;
}