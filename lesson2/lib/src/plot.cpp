#include "../include/plot.hpp"
#include <string>
#include <iostream>
#include <cmath>
using std::string;
using std::cout;
using std::endl;

namespace math {


void Plot::add_function(Function<flt(flt)> func, char displayChar) {
  functions.push_back({func, displayChar});
}

void Plot::render() {
  // get the string matrix
  Vector<string> canvas(height, string(width, ' '));
  // define ranges
  const flt X = x_max - x_min;
  const flt Y = y_max - y_min;
  // define steps
  flt dx = X / static_cast<flt>(width);
  flt dy = Y / static_cast<flt>(height);
  // get the lines arround y=0 | and x=0 -
  if (y_min < 0.0 && y_max > 0.0) {
    u32 y0 = static_cast<u32>((y_max / Y) * static_cast<flt>(height));
    for (u32 x = 0; x < width; ++x) {
      canvas[y0][x] = '-';
    }
  }
  if (x_min < 0.0 && x_max > 0.0) {
    u32 x0 = static_cast<u32>((-x_min / X) * static_cast<flt>(width));
    for (u32 y = 0; y < height; ++y) {
      canvas[y][x0] = '|';
    }
  }
  // define x
  flt x = x_min;
  // iterate over width
  for (u32 i = 0; i < width; ++i) {
    // iterate over functions
    for (auto& [func, displayChar] : functions) {
      // get y
      flt y = func(x);
      // check if y is in range
      if (y >= y_min && y <= y_max) {
        // get the corresponding y index
        u32 j = std::round((-y-y_min) / dy);
        // set the character
        if (j < height)
          canvas[j][i] = displayChar;
      }
    }
    // increment x
    x += dx;
  }
  // print the canvas
  for (u32 j = 0; j < height; ++j) {
    cout << canvas[j] << endl;
  }
}

} // namespace math