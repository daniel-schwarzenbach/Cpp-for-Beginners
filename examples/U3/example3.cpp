#include <iostream>
#include <string>

// logical OR for "bit arrays"
void logical_or(int* dest, const int* lhs, const int* rhs) {
	// get the lenths of the bits
	int lR = 0, lL = 0;
	while (rhs[lR] >= 0) ++lR;
	while (lhs[lL] >= 0) ++lL;
	// reseve space for the naive sum
	int orSize = std::max(lL, lR) + 1;
	for (int i = 0; i < orSize; ++i) {
		// current or
		int co = 0;
		if (lR > i) co = rhs[i];
		if (lL > i) co = co || lhs[i];
		dest[i] = co;
	}
	dest[orSize] = -1; // end of bits
}

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