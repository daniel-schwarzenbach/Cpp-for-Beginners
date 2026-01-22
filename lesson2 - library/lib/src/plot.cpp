#include "../include/plot.hpp"
#include <string>
#include <iostream>
#include <cmath>
using std::string;
using std::cout;
using std::endl;

namespace math {


void Plot::add_function(Function<flt(flt)> func, char displayChar, string colorCode) {
  functions.push_back({func, string(1,displayChar), colorCode});
}

void Plot::add_function(Function<flt(flt)> func, 
                        string displayUnicode, 
                        string colorCode) {
  functions.push_back({func, displayUnicode, colorCode});
}

flt diff_to_int(flt x) {
  flt round = std::round(x);
  return std::abs(x - round);
}

void Plot::render() {
  // get the string matrix
  Vector<Vector<string>> canvas(height, Vector<string>(width, string(" ")));
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
      // check if we have to mark naturals
      if (mark_naturals && x > 0 && x < width-1) {
        flt x_prev = x_min + (x-1) * dx;
        flt x_curr = x_min + x * dx;
        flt x_next = x_min + (x+1) * dx;
        if (diff_to_int(x_prev) > diff_to_int(x_curr) &&
            diff_to_int(x_next) > diff_to_int(x_curr) &&
            diff_to_int(x_curr) < (dx / 2.0)) {
          canvas[y0][x] = '+';
        }
      }
    }
  }
  if (x_min < 0.0 && x_max > 0.0) {
    u32 x0 = static_cast<u32>((-x_min / X) * static_cast<flt>(width));
    for (u32 y = 0; y < height; ++y) {
      canvas[y][x0] = '|';
      if (mark_naturals && y > 0 && y < height-1) {
        flt y_prev = y_max - (y-1) * dy;
        flt y_curr = y_max - y * dy;
        flt y_next = y_max - (y+1) * dy;
        if (diff_to_int(y_prev) > diff_to_int(y_curr) &&
            diff_to_int(y_next) > diff_to_int(y_curr) &&
            diff_to_int(y_curr) < (dy / 2.0)) {
          canvas[y][x0] = '+';
        }
      }
    }
  }
  // define x
  flt x = x_min;
  // iterate over width
  for (u32 i = 0; i < width; ++i) {
    // iterate over functions
    for (auto& [func, displaySymbol, displayColor] : functions) {
      // get y
      flt y = func(x);
      // check if y is in range
      if (y >= y_min && y <= y_max) {
        // get the corresponding y index
        u32 j = std::round((-y-y_min) / dy);
        // set the characters
        if (j < height) {
          // fill the canvas at position (i,j)
          canvas[j][i] = displayColor + displaySymbol + t_colors::RESET;
        }
      }
    }
    // increment x
    x += dx;
  }
  // print the canvas
  for (u32 j = 0; j < height; ++j) {
    for (u32 i = 0; i < width; ++i) {
      cout << canvas[j][i];
    }
    cout << endl;
  }
}

} // namespace math