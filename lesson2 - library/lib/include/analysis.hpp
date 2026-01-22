#pragma once
#include "./types.hpp"

namespace math {

// compute the derivative of a function at a point numerically
flt derivative(Function<flt(flt)> const& func, flt point);

/*
returns the derivative function of a given function numerically
```default
d/dx f(x)
```
*/
Function<flt(flt)> derivative(Function<flt(flt)> const& func);

/*
returns the integral of a function from a to b numerically
```default
ₐ∫ᵇ f(x) dx
```
*/
flt integral(Function<flt(flt)> const& func, flt a, flt b);

/*
returns the integral function of a given function numerically
```default
₀∫ʸ f(x) dx
```
*/
Function<flt(flt)> integral(Function<flt(flt)> const& func);


} // namespace math