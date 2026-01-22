#pragma once

#include <iostream>

struct Complex {
  double real;
  double imag;

  // constructors
  constexpr Complex() : real(0.0), imag(0.0) {}
  constexpr Complex(double r, double i = 0.0) : real(r), imag(i) {}

  // Arithmetic operators
  Complex operator+(const Complex &other) const;
  Complex operator-(const Complex &other) const;
  Complex operator*(const Complex &other) const;
  Complex operator/(const Complex &other) const;

  // Unary operators
  Complex operator-() const;

  // Compound assignment operators
  Complex &operator+=(const Complex &other);
  Complex &operator-=(const Complex &other);
  Complex &operator*=(const Complex &other);
  Complex &operator/=(const Complex &other);

  // Comparison operators
  bool operator==(const Complex &other) const;
  bool operator!=(const Complex &other) const;

  // Utility methods
  double magnitude() const;
  double abs() const;
  Complex conjugate() const;
};

// Stream operators
std::ostream &operator<<(std::ostream &os, const Complex &c);
std::istream &operator>>(std::istream &is, Complex &c);