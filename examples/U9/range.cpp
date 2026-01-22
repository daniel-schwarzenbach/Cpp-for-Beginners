#include <iostream>

using std::cout;
using std::endl;

struct Range {
	int a;
	int b;
	using value_type = int;
	struct iterator {
		public:
		int current;
		constexpr int operator*() const { return current; }
		constexpr iterator& operator++() {
				current += 1;
				return *this;
		}
		constexpr bool operator!=(const iterator& other) const {
				return current != other.current;
		}
	};
	iterator begin() const { return iterator{a}; }
	iterator end() const { return iterator{b};}
};

template <typename Container>
void print(Container const& C) {
  for (auto const& element : C) {
    cout << element << ", ";
  }
  cout << endl;
}

int main() {
	Range r{3, 8};
	print(r);
}