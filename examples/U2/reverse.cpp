#include <iostream>
#include <string>

using std::string;

/**
 * @brief Reverses the input string.
 * @param str The string to be reversed.
 * @return The reversed string.
 */
string reverse(string str) {
  string reversed;
  for (long i = str.size() - 1; i >= 0; --i) {
    reversed += str.at(i);
  }
  return reversed;
}

int main() {
  string line;
  // read lines from standard input until EOF
  while (std::getline(std::cin, line)) {
    std::cout << reverse(line) << "\n";
  }
  return 0;
}