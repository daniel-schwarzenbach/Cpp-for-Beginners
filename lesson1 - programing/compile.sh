dir=$(dirname "$0")
program=${dir}/isPrime
file=${program}.cpp

##  Create an Executable from C++ Source Code
# g++: GNU C++ Compiler
# -g3: Include debugging information
# -std=c++17: Use the C++17 standard
# -Wall: Enable all compiler's warning messages
# -Wextra: Enable extra warning messages
# -pedantic: Issue all the warnings demanded by strict ISO C++
# -O0: Disable optimizations
# -o isPrime: Specify the output file name
g++ -g3 -std=c++17 -Wall -Wextra -pedantic -O0 -o $program $file