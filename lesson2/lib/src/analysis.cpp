#include "../include/analysis.hpp"
#include "cmath"
#include <random>



namespace math {

flt get_random(flt min, flt max) {
  static std::mt19937 generator(std::random_device{}());
  std::uniform_real_distribution<flt> distribution(min, max);
  return distribution(generator);
}

flt derivative(Function<flt(flt)> const& f, flt x) {
  constexpr double h = 1e-8;
  constexpr double c = 1/ (12 * h);
  return     c*f(x - 2*h)  +  c*8*f(x + h)
          -  c*f(x + 2*h)  -  c*8*f(x - h);
}

Function<flt(flt)> derivative(Function<flt(flt)> const& f) {
  return [f](flt x) {
    return derivative(f, x);
  };
}

namespace QuadRules{

template<typename Function1x1>
double weddle_rule( Function1x1 const& f, 
                    double const& a, 
                    double const& b){
    constexpr double c = 1/840;
    const double h = b-a;
    return    c*41.*f(a)
            + c*216.*f(a+h/6.)
            + c*27.*f(a+h/3.)
            + c*272.*f(a+h/2.)
            + c*27.*f(a+h*3./2.)
            + c*216. * f(a+h*5./6.)
            + c*41. * f(b);
}

template<typename Function1x1>
double simpson_rule(const Function1x1& f, 
                              const double& a, 
                              const double& b){
     return    (    f(a) 
                    + 4 * f(a + (b-a)/2.0)  
                    + f(b)
               )    * (b-a) / 6.0;
}
               
template<typename Function1x1>
double trapez_rule( const Function1x1& f, 
                    const double& a, 
                    const double& b){
     return (f(a) + f(b)) * (b-a) / 2.0;
}

}

double integral(Function<flt(flt)> const& f,
                double a,
                double b){
  //static constexpr double dx_max = 2;
  static constexpr double h_min = 1e-8;
  static constexpr double absTol = 1e-10;
  static constexpr double relTol = 0.05;
  static constexpr double monteTol = 1e-2;
  double sign = 1;
  if(a > b){
    sign = -1;
    std::swap(a,b);
  }
  const double h = b-a;
  if(h < h_min){
    return QuadRules::weddle_rule(f,a,b);
  }
  // Quadrature
  const double fa = f(a);
  const double fb = f(b);
  const double fm = f(a+h/2.);
  double simpson_rule = (fa + 4*fm + fb) * (h/6.);
  double trapez_rule = (fa*.5 + fb*.5)*h;
  if(   h < h_min ||
        abs(simpson_rule - trapez_rule) < relTol*abs(simpson_rule)
        || abs(simpson_rule - trapez_rule) < absTol){
      const double f1_6 = f(a+h/6.);
      const double f1_3 = f(a+h/3.);
      const double f2_3 = f(a+h*(2./3.));
      const double f5_6 = f(a+h*(5./6.));
      constexpr double c = 1./840.;
      double weddle_rule =  c*41. *fa
                          + c*216.*f1_6
                          + c*27. *f1_3
                          + c*272.*fm
                          + c*27. *f2_3
                          + c*216.*f5_6
                          + c*41. *fb;
      weddle_rule *= h;
      if(         h < h_min ||
                  abs(simpson_rule - weddle_rule) < absTol
                  || abs(simpson_rule - weddle_rule) 
                      < relTol*abs(weddle_rule))
      {
        double h_min_monte = 1e-4;
        if(h < h_min_monte){
            return sign*weddle_rule;
        }
        const double fprim1 =f(a+h*(4111./5039.));
        const double fprim2 =f(a+h*(1811./3923.));
        const double fprim3 =f(a+h*(2467./9769.));
        const double frand1 =f(get_random(a,b));
        const double frand2 =f(get_random(a,b));
        const double frand3 =f(get_random(a,b));
        const double frand4 =f(get_random(a,b));
        const double frand5 =f(get_random(a,b));
        double monte_rule =  .125*frand1
                            +.125*frand2
                            +.125*frand3
                            +.125*frand4
                            +.125*frand5
                            +.125*fprim1
                            +.125*fprim2
                            +.125*fprim3;
        monte_rule *= h;
        if(abs(simpson_rule - monte_rule) < monteTol){
            return sign*weddle_rule;
        }
      }
  }
  // divide a-b
  uint divisions = get_random(2, 7);
  double h_ = h/divisions;
  double sum = 0;
  for(uint i = 0; i < divisions; ++i){
      sum += integral(f,a+h_*i,a+h_*(i+1));
  }
  return sign*sum;   
}

Function<flt(flt)> integral(Function<flt(flt)> const& f) {
  return [f](flt x) {
    return integral(f, 0.0, x);
  };
}

} // namespace math