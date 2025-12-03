#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using u64 = long long;
using std::vector;

u64 fast_fac(u64 n) {
  // static variable is a global variable with local scope
  static vector<u64> facs = {1};
  // check for negative input
  if (n < 0)
    return -1;
  // check if we have already computed this factorial
  if (n < facs.size())
    return facs[n];
  // compute factorial recursively and store it
  u64 fac = n * fast_fac(n - 1);
  facs.push_back(fac);
  return fac;
}

int main() {
  cout << fast_fac(5) << ", " << fast_fac(-5) << endl;
  return 0;
}
