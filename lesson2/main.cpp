#include <math>

using namespace math;

// f: ℝ → ℝ
// extern: means the function is defined outside of this file
extern flt f(flt x);

int main() {
  Plot plot;
  // set the plot ranges
  plot.x_min = -2.5;
  plot.x_max = 2.5;
  plot.y_min = -2.5;
  plot.y_max = 2.5;
  // add the derivative of f as function to plot
  Function<flt(flt)> Df = derivative(f);
  plot.add_function(Df, "δ", t_colors::RED);
  // add the integral of f as function to plot
  Function<flt(flt)> If = integral(f);
  plot.add_function(If, "∫", t_colors::GREEN);
  // add f as function to plot
  plot.add_function(f, "▮", t_colors::BLUE);
  // render the plot
  plot.render();
  return 0;
}