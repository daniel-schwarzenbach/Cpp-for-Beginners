#include <iostream>
#include <regex>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::regex;

int main() { 
	regex regular_expression("a(bc)+d");
	string testStr = "xxabcdy";
	string result = std::regex_replace(testStr, regular_expression, "[$&]");
	// result = "xx[abcd]y"
	cout << result << endl;
	return 0;
}