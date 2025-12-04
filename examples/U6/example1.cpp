// hpp file content: mainly declarations
#include <iostream>
#include <cmath>

struct complex {
  double real;
  double imag;
  // constructor
  complex(double r = 0.0, double i = 0.0);

  ///     operator overloads
  // addition
  complex operator+(complex const& other) const;
  // multiplication
  complex operator*(complex const& other) const;
  // add and assign
  complex& operator+=(complex const& other);
  // multiply and assign
  complex& operator*=(complex const& other);
  // equality
  bool operator==(complex const& other) const;
  // output stream
  friend std::ostream &operator<<(std::ostream &os, complex const& c);
  // absolute value
  double abs() const { return std::sqrt(real * real + imag * imag); }
};

// cpp file content: definitions
complex::complex(double r, double i) : real(r), imag(i) {}

complex complex::operator+(complex const& other) const {
  return complex(real + other.real, imag + other.imag);
}

complex complex::operator*(complex const& other) const {
  return complex(real * other.real - imag * other.imag,
                 real * other.imag + imag * other.real);
}

complex& complex::operator+=(complex const& other) {
  real += other.real;
  imag += other.imag;
  return *this;
}

complex& complex::operator*=(complex const& other) {
  complex tmp = *this * other;
  *this = tmp;
  return *this;
}

bool complex::operator==(complex const& other) const {
  constexpr double ε = 1e-10;
  return (real - other.real) < ε && (imag - other.imag) < ε;
}

std::ostream &operator<<(std::ostream &os, complex const& c) {
  os << c.real << " + " << c.imag << "î";
  return os;
}

// main.cxx file content
using std::cout;
using std::endl;

int main() {
  complex a(1.0, 2.0);
  complex b(3.0, 4.0);
  cout << a + b << endl;
  cout << a * b << endl;
  return 0;
}
