#pragma once
#include "types.hpp"

namespace math {

/**
 * @brief Computes x raised to the power of y (x^y).
 * @param x The base (double).
 * @param y The exponent (int64_t).
 * @return x^y as a double.
 */
flt pow(flt base, i64);

} // namespace math