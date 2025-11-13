#include <iostream>

#include "logical_or.cpp"

int main() {
	// init a and b
	int a[] = {0,1,0,1,-1};
	int b[] = {0,0,1,1,-1};
	// give space for c
	int* c = new int[5];
	// c = a | b
	logical_or(c, a, b);
	// print c
	for (int i = 0; c[i] >= 0; ++i) {
		std::cout << c[i] << " ";
	}
	// new line
	std::cout << std::endl;
	// clean up
	delete[] c;
	// return
	return 0;
}