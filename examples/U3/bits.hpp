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