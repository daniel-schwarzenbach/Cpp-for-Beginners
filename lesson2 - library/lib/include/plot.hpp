#pragma once
#include "./types.hpp"
#include "./t-colors.hpp"

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
    // add markes for at natural numbers
    bool mark_naturals = true;

    private:
    Vector<tuple<Function<flt(flt)>, string, string>> functions = {};

    public:
    void add_function(Function<flt(flt)> func, char displayChar = '*', string colorCode = "");
    void add_function(Function<flt(flt)> func, string displayUnicode, string colorCode = "");

    void render();
  };
}