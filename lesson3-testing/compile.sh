dir=$(dirname "$0")
program=${dir}/test
file=${program}.cpp

# first we compile complex.cpp to have the implementation available
g++ -c -g3 -std=c++17 -Wall -Wextra -pedantic -O0 -o ${dir}/complex.o ${dir}/complex.cpp
# then we compile the test program linking it with gtest and the complex.o object file
g++ -g3 -std=c++17 -Wall -Wextra -pedantic -O0 -o $program $file ${dir}/complex.o -lgtest -lgtest_main -lpthread