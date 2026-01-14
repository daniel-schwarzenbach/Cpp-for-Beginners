#include <iostream>
#include <functional>
#include <cmath>

using std::cout;
using std::endl;
using std::function;

function<double(double)> derivative(function<double(double)> f) {
	constexpr double h = 1e-5;
	constexpr double h2 = h+h;
	return [f](double x) {
		return (f(x + h) - f(x - h)) / h2;
	};
}


int main() {
  function<double(double)> dsin = derivative(sin);
	cout << dsin(0) << endl;
	return 0;
}