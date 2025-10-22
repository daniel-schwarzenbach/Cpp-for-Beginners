// import the standard library for general purpose functions: std::atoi
#include <cstdlib>
// import input/output stream from the standart library: std::cout, std::cerr
// std::endl
#include <iostream>
// import math library for mathematical functions: std::sqrt
#include <cmath>
// import exception handling from the standard library: std::exception
#include <exception>

/**
 * @brief This function checks if a given number is prime or not.
 * @param  {int} number : the numer we want to check if it is prime
 * @return {bool}       : true if the number is prime, false otherwise
 */
bool is_prime(int number) {
  // Check if the number is less than 2, which are not prime numbers
  if (number < 2) {
    return false;
  }
  // Check for factors from 2 to the square root of the number
  double sqrtNumber = std::sqrt(number);
  for (int i = 2; i <= sqrtNumber; i++) {
    if (number % i == 0) {
      return false; // Found a factor, so it's not prime
    }
  }
  return true; // No factors found, so it is prime
}

/**
 * @brief The main function is the entry point of the program. For programm call
 * like `./isPrime 5 abc` we get the inputs:
 * ```cpp
 * argsSize = 3;
 * args = {
 *  "./isPrime",
 *  "5",
 *  "abc"
 * };
 * ```
 *
 * @param  {int} argsSize : The number of arguments that are passed into the
 *  program
 *
 * @param  {char* []} arguments : The arguments that are passed into the
 * program. a char* is a pointer to a character array, which is a classic
 * c-strting
 *
 * @return {int}                : A return value of 0 indicates that the program
 * has executed successfully. If the program returns a non-zero value, it
 * indicates that an error has occurred during execution.
 */
int main(int argsSize, char *args[]) {
  // first we check if the user has provided an argument
  if (argsSize < 2) {
    std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
    return 1; // Return 1 to indicate an error code
  }
  // now we convert the first argument to an integer
  int number = std::atoi(args[1]);
  // Now we can check if the number is prime
  if (is_prime(number) /* call the function is_prime on number */) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
  return 0; // Return 0 to indicate successful execution
}