#pragma once
#include "./types.hpp"

namespace math {
  struct Plot {
    public:
    // plot dimensions
    u32 width = 160;
    u32 height = 50;
    // plot ranges
    flt x_min = -5.0;
    flt x_max = 5.0;
    flt y_min = -10.0;
    flt y_max = 10.0;

    private:
    Vector<tuple<Function<flt(flt)>, char>> functions = {};

    public:
    void add_function(Function<flt(flt)> func, char displayChar = '*');
    void render();
  };
}