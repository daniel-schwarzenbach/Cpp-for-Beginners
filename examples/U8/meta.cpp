#include <iostream>

using std::cout;
using std::endl;

template<int N>
struct Fib {
	static constexpr int value = Fib<N-1>::value + Fib<N-2>::value;
};

template<>
struct Fib<0> {
	static constexpr int value = 0;
};

template<>
struct Fib<1> {
	static constexpr int value = 1;
};

int main() {
	cout << Fib<4>::value << endl;
	return 0;
}