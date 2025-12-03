#include <array>
#include <iostream>

using std::cout;
using std::endl;
using u64 = unsigned long long;
using std::array;

// maximum factorial precomputed
constexpr size_t MAX_FAC = 200;

// create factorials at compile time
constexpr array<u64, 200> make_factorials() {
  array<u64, 200> facs{};
  facs[0] = 1;
  for (u64 i = 1; i < 200; ++i) {
    facs[i] = i * facs[i - 1];
  }
  return facs;
}

// precompute factorials
constexpr array<u64, MAX_FAC> factorials = make_factorials();

u64 ultra_fast_fac(u64 n) {
  if (n >= (u64)MAX_FAC)
    return 0;
  return factorials[n];
}

int main() {
  cout << ultra_fast_fac(6) << ", " << ultra_fast_fac(200) << endl;
  return 0;
}
