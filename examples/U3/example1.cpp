#include <iostream>
#include <cmath>

using std::string;
using std::cout;
using std::endl;

// define the dimensions of the plot
constexpr int w = 66;
constexpr int h = 66;

// define the plot area
const double width = 2.0;
const double height = 2.0 * M_PI;

// define the plot symbol
const char symbol = '*';

int main() {
	double dh = height / (h-1);
	double dw = width / (w-1);
	// intialize x
	double x = 0.0;
	for (int i = 0; i < h; ++i) {
		// plot sin
		double y = std::sin(x) + 1;
		int j = std::round(y / dw);
		for (int k = 1; k < j; ++k) {
			cout << ' ';
		}
		cout << symbol << endl;
		x += dh;
	}
}

