#include <math>

using namespace math;

// f: ℝ → ℝ
// extern: means the function is defined outside of this file
extern flt f(flt x);

int main() {
  Plot plot;
  // set the plot ranges
  plot.x_min = -2;
  plot.x_max = 2;
  plot.y_min = -5;
  plot.y_max = 5;
  // add the derivative of f as function to plot
  Function<flt(flt)> Df = derivative(f);
  plot.add_function(Df, 'd');
  // add the integral of f as function to plot
  Function<flt(flt)> If = integral(f);
  plot.add_function(If, 'i');
  // add f as function to plot
  plot.add_function(f, '#');
  // render the plot
  plot.render();
  return 0;
}