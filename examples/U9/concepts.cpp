#include <concepts>
#include <iostream>
#include <ostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

using std::string;

template<typename T>
concept IteratorName = requires(T a) {
  // Check that T has a nested type named 'ValueType'
  typename T::value_type;

  // Check that T has the dereference operator
  { *a } -> std::same_as<typename T::value_type&>;

  // Check that T has the increment operator
  { ++a } -> std::same_as<T&>;

  // Check that T has the equality operator
  { a != a } -> std::convertible_to<bool>;
};


template<typename T>
concept ContainerName = requires(T a) {
    // Check that T::Iterator satisfies the Iterator concept
    requires IteratorName<typename T::iterator>;

    // Check that T has begin() and end() methods
    {a.begin()} -> std::same_as<typename T::iterator>;
    {a.end()} -> std::same_as<typename T::iterator>;
};


template<ContainerName Container>
string to_string(const Container& c) {
  std::stringstream ss;
  ss << "{";
  for (auto it = c.begin(); it != c.end(); ++it) {
    ss << *it;
    if (std::next(it) != c.end()) {
      ss << ", ";
    }
  }
  ss << "}";
  return ss.str();
}

template<ContainerName Container>
requires (!std::same_as<Container, string>)
std::ostream& operator<<(std::ostream& os, const Container& c) {
  os << to_string(c);
  return os;
}

template<typename T1, typename T2>
struct Pair{
  T1 key;
  T2 value;
  using key_type = T1;
  using value_type = T2;
};

using std::get;

template<size_t I, typename T1, typename T2>
constexpr auto& get(const Pair<T1, T2>& p) {
  if constexpr (I == 0) return p.key;
  else return p.value;
}

template<typename Pair>
concept PairName = requires (Pair p){
    { get<0>(p) } -> std::convertible_to<typename Pair::key_type>;
    { get<1>(p) } -> std::convertible_to<typename Pair::value_type>;
};

template<PairName Pair>
std::ostream& operator<<(std::ostream& os, Pair const& p) {
  auto [key, value] = p;
  os  << key << " => " << value;
  return os;
}

using std::cout;
using std::endl;

auto main() -> int {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::deque<int> deq = {6, 7, 8, 9, 10};
  std::cout << to_string(vec) << endl;
  std::cout << deq << endl;
  Pair<int, char> p = {1, '2'};
  cout << p << endl;
  return 0;
}