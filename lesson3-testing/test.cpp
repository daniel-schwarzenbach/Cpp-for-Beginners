#include "complex.hpp"
#include <cmath>
#include <gtest/gtest.h>

// Test constructors
TEST(ComplexTest, DefaultConstructor) {
  Complex c;
  EXPECT_EQ(c.real, 0.0);
  EXPECT_EQ(c.imag, 0.0);
}

TEST(ComplexTest, ParameterizedConstructor) {
  Complex c1(3.0, 4.0);
  EXPECT_EQ(c1.real, 3.0);
  EXPECT_EQ(c1.imag, 4.0);

  Complex c2(5.0);
  EXPECT_EQ(c2.real, 5.0);
  EXPECT_EQ(c2.imag, 0.0);
}

// Test addition
TEST(ComplexTest, Addition) {
  Complex c1(3.0, 4.0);
  Complex c2(1.0, 2.0);
  Complex result = c1 + c2;
  EXPECT_EQ(result.real, 4.0);
  EXPECT_EQ(result.imag, 6.0);
}

TEST(ComplexTest, AdditionWithNegative) {
  Complex c1(3.0, 4.0);
  Complex c2(-1.0, -2.0);
  Complex result = c1 + c2;
  EXPECT_EQ(result.real, 2.0);
  EXPECT_EQ(result.imag, 2.0);
}

// Test subtraction
TEST(ComplexTest, Subtraction) {
  Complex c1(5.0, 7.0);
  Complex c2(2.0, 3.0);
  Complex result = c1 - c2;
  EXPECT_EQ(result.real, 3.0);
  EXPECT_EQ(result.imag, 4.0);
}

// Test multiplication
TEST(ComplexTest, Multiplication) {
  Complex c1(3.0, 2.0); // 3 + 2i
  Complex c2(1.0, 4.0); // 1 + 4i
  Complex result =
      c1 * c2; // (3 + 2i)(1 + 4i) = 3 + 12i + 2i + 8i² = 3 + 14i - 8 = -5 + 14i
  EXPECT_EQ(result.real, -5.0);
  EXPECT_EQ(result.imag, 14.0);
}

TEST(ComplexTest, MultiplicationByReal) {
  Complex c1(3.0, 4.0);
  Complex c2(2.0, 0.0);
  Complex result = c1 * c2;
  EXPECT_EQ(result.real, 6.0);
  EXPECT_EQ(result.imag, 8.0);
}

// Test division
TEST(ComplexTest, Division) {
  Complex c1(10.0, 5.0);
  Complex c2(2.0, 1.0);
  Complex result = c1 / c2; // (10 + 5i) / (2 + i) = (10 + 5i)(2 - i) / (4 + 1)
                            // = (20 - 10i + 10i - 5i²) / 5 = (20 + 5) / 5 = 5
  EXPECT_DOUBLE_EQ(result.real, 5.0);
  EXPECT_DOUBLE_EQ(result.imag, 0.0);
}

TEST(ComplexTest, DivisionComplex) {
  Complex c1(1.0, 1.0);
  Complex c2(1.0, -1.0);
  Complex result = c1 / c2; // (1 + i) / (1 - i) = (1 + i)(1 + i) / (1 + 1) = (1
                            // + 2i + i²) / 2 = (1 + 2i - 1) / 2 = i
  EXPECT_DOUBLE_EQ(result.real, 0.0);
  EXPECT_DOUBLE_EQ(result.imag, 1.0);
}

TEST(ComplexTest, DivisionByZeroThrows) {
  Complex c1(5.0, 3.0);
  Complex c2(0.0, 0.0);
  EXPECT_THROW(c1 / c2, std::runtime_error);
}

// Test unary negation
TEST(ComplexTest, UnaryNegation) {
  Complex c(3.0, -4.0);
  Complex result = -c;
  EXPECT_EQ(result.real, -3.0);
  EXPECT_EQ(result.imag, 4.0);
}

// Test compound assignment operators
TEST(ComplexTest, CompoundAddition) {
  Complex c1(3.0, 4.0);
  Complex c2(1.0, 2.0);
  c1 += c2;
  EXPECT_EQ(c1.real, 4.0);
  EXPECT_EQ(c1.imag, 6.0);
}

TEST(ComplexTest, CompoundSubtraction) {
  Complex c1(5.0, 7.0);
  Complex c2(2.0, 3.0);
  c1 -= c2;
  EXPECT_EQ(c1.real, 3.0);
  EXPECT_EQ(c1.imag, 4.0);
}

TEST(ComplexTest, CompoundMultiplication) {
  Complex c1(2.0, 1.0);
  Complex c2(3.0, 2.0);
  c1 *= c2; // (2 + i)(3 + 2i) = 6 + 4i + 3i + 2i² = 6 + 7i - 2 = 4 + 7i
  EXPECT_EQ(c1.real, 4.0);
  EXPECT_EQ(c1.imag, 7.0);
}

TEST(ComplexTest, CompoundDivision) {
  Complex c1(10.0, 5.0);
  Complex c2(2.0, 1.0);
  c1 /= c2;
  EXPECT_DOUBLE_EQ(c1.real, 5.0);
  EXPECT_DOUBLE_EQ(c1.imag, 0.0);
}

// Test comparison operators
TEST(ComplexTest, Equality) {
  Complex c1(3.0, 4.0);
  Complex c2(3.0, 4.0);
  Complex c3(3.0, 5.0);
  EXPECT_TRUE(c1 == c2);
  EXPECT_FALSE(c1 == c3);
}

TEST(ComplexTest, Inequality) {
  Complex c1(3.0, 4.0);
  Complex c2(3.0, 4.0);
  Complex c3(3.0, 5.0);
  EXPECT_FALSE(c1 != c2);
  EXPECT_TRUE(c1 != c3);
}

// Test magnitude/abs
TEST(ComplexTest, Magnitude) {
  Complex c1(3.0, 4.0);
  EXPECT_DOUBLE_EQ(c1.magnitude(), 5.0);

  Complex c2(0.0, 0.0);
  EXPECT_DOUBLE_EQ(c2.magnitude(), 0.0);

  Complex c3(-3.0, -4.0);
  EXPECT_DOUBLE_EQ(c3.magnitude(), 5.0);
}

TEST(ComplexTest, Abs) {
  Complex c(5.0, 12.0);
  EXPECT_DOUBLE_EQ(c.abs(), 13.0);
}

// Test conjugate
TEST(ComplexTest, Conjugate) {
  Complex c1(3.0, 4.0);
  Complex conj = c1.conjugate();
  EXPECT_EQ(conj.real, 3.0);
  EXPECT_EQ(conj.imag, -4.0);

  Complex c2(2.0, -5.0);
  Complex conj2 = c2.conjugate();
  EXPECT_EQ(conj2.real, 2.0);
  EXPECT_EQ(conj2.imag, 5.0);
}

// Test edge cases
TEST(ComplexTest, ZeroComplex) {
  Complex zero;
  Complex c(5.0, 3.0);
  Complex result1 = c + zero;
  EXPECT_EQ(result1.real, 5.0);
  EXPECT_EQ(result1.imag, 3.0);

  Complex result2 = c * zero;
  EXPECT_EQ(result2.real, 0.0);
  EXPECT_EQ(result2.imag, 0.0);
}

TEST(ComplexTest, PureImaginary) {
  Complex c1(0.0, 3.0);
  Complex c2(0.0, 4.0);
  Complex result = c1 * c2; // 3i * 4i = 12i² = -12
  EXPECT_EQ(result.real, -12.0);
  EXPECT_EQ(result.imag, 0.0);
}

TEST(ComplexTest, ConjugateProperty) {
  Complex c(3.0, 4.0);
  Complex conj = c.conjugate();
  Complex product = c * conj;           // z * z* = |z|²
  EXPECT_DOUBLE_EQ(product.real, 25.0); // 3² + 4² = 25
  EXPECT_DOUBLE_EQ(product.imag, 0.0);
}
