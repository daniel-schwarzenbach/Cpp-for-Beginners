#include <exception>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

// approximate sqrt using Newton's method
double sqrt(double x) {
  if (x < 0) {
    throw std::invalid_argument("Negative argument not allowed in sqrt");
  }
  double guess = x / 2.0;
  double next_guess;
  constexpr double ε = 1e-10;
  int count = 0;
  do {
    ++count;
    double next_guess = (guess + x / guess) / 2.0;
    guess = next_guess;
  } while (std::abs(next_guess - guess) > ε && count < 1000);
  return guess;
} 

int fib(int n) {
  if (n < 0) {
    throw std::invalid_argument("Negative argument not allowed in fib");
  }
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  try {
    cout << fib(2) << ", " 
         << sqrt(0.25) << ", " 
         << fib(-2) << ", " 
         << sqrt(-4.0);
  } catch (std::exception& e) {
    cout << "Exception caught: " << e.what() << endl;
  }
  return 0;
}