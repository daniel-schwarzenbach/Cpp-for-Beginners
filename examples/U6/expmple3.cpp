#include <iostream>
#include <ostream>
#include <vector>

using u64 = unsigned long long;
using std::cout;
using std::endl;
using std::vector;

// Overload operator<< to print vectors
template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &vec) {
  os << "{";
  for (size_t i = 0; i < vec.size(); ++i) {
    os << vec[i];
    if (i != vec.size() - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

// Backtracking function to generate power set
void backtrack(u64 idx, const vector<int> &orginal_set,
               vector<int> &current, vector<vector<int>> &result) {
  // if the index reaches the size of the original set, add the current subset to result
  if (idx == orginal_set.size()) {
    result.push_back(current);
    return;
  }
  backtrack(idx + 1, orginal_set, current, result);
  current.push_back(orginal_set[idx]);
  backtrack(idx + 1, orginal_set, current, result);
  current.pop_back(); 
}

vector<vector<int>> P(const vector<int> &orginal_set) {
  vector<vector<int>> result {};
  vector<int> current = {};
  backtrack(0, orginal_set, current, result);
  return result;
}

int main() {
  vector<int> A = {1, 2, 3, 4};
  cout << P(A) << endl;
  return 0;
}
