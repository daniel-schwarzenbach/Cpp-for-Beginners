#include "../include/functions.hpp"

namespace math {
  double pow(double x, int64_t y) {
    // check for negative exponent
    bool negative = y < 0;
    // make y positive for calculation, makes it easier
    if (negative) {
      y = -y;
    }
    // i will be used as a bitmask to check each bit of y
    int64_t i = 1;
    // will hold the result
    double result = 1;
    // iterate through all bits of y
    while (i <= y) {
      // if the current bit is set, multiply the result by x
      if (y & i) {
        result *= x;
      }
      // square x for the next bit
      x *= x;
      // shift i to the left to check the next bit
      i <<= 1;
    }
    // if the exponent was negative, return the inverse of the result
    if (negative) {
      return 1.0 / result;
    }
    return result;
  }
}