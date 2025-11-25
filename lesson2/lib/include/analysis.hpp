#pragma once
#include "./types.hpp"

namespace math {

flt derivative(Function<flt(flt)> const& func, flt point);
Function<flt(flt)> derivative(Function<flt(flt)> const& func);
flt integral(Function<flt(flt)> const& func, flt a, flt b);
Function<flt(flt)> integral(Function<flt(flt)> const& func);


} // namespace math