dir=$(dirname "$0")

# compile all cpp files in this directory
for file in ${dir}/*.cpp; do
		program=${file%.cpp}
		g++ -g3 -DDebug -std=c++17 -Wall -Wextra -pedantic -O0 -o $program $file
done