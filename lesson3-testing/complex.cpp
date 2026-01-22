#include "complex.hpp"
#include <cmath>

// Arithmetic operators
Complex Complex::operator+(const Complex &other) const {
  return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex &other) const {
  return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex &other) const {
  // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
  return Complex(real * other.real - imag * other.imag,
                 real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex &other) const {
  // (a + bi)/(c + di) = [(a + bi)(c - di)] / (c² + d²)
  double denominator = other.real * other.real + other.imag * other.imag;
  if (denominator == 0.0) {
    throw std::runtime_error("Division by zero");
  }
  return Complex((real * other.real + imag * other.imag) / denominator,
                 (imag * other.real - real * other.imag) / denominator);
}

// Unary operators
Complex Complex::operator-() const { return Complex(-real, -imag); }

// Compound assignment operators
Complex &Complex::operator+=(const Complex &other) {
  real += other.real;
  imag += other.imag;
  return *this;
}

Complex &Complex::operator-=(const Complex &other) {
  real -= other.real;
  imag -= other.imag;
  return *this;
}

Complex &Complex::operator*=(const Complex &other) {
  double new_real = real * other.real - imag * other.imag;
  double new_imag = real * other.imag + imag * other.real;
  real = new_real;
  imag = new_imag;
  return *this;
}

Complex &Complex::operator/=(const Complex &other) {
  *this = *this / other;
  return *this;
}

// Comparison operators
bool Complex::operator==(const Complex &other) const {
  return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex &other) const {
  return !(*this == other);
}

// Utility methods
double Complex::magnitude() const {
  return std::sqrt(real * real + imag * imag);
}

double Complex::abs() const { return magnitude(); }

Complex Complex::conjugate() const { return Complex(real, -imag); }

// Stream operators
std::ostream &operator<<(std::ostream &os, const Complex &c) {
  os << c.real;
  if (c.imag >= 0) {
    os << " + " << c.imag << "𝒾";
  } else {
    os << " - " << -c.imag << "𝒾";
  }
  return os;
}

std::istream &operator>>(std::istream &is, Complex &c) {
  is >> c.real >> c.imag;
  return is;
}
