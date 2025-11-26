#include <vector>
#include <iostream>
#include <string>
#include <exception>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;

void print_vector(vector<int> const& v);

#ifdef Debug
#include "./print-vector-as-tree.hxx"
void print_vector(vector<int> const& v) {
  cout << endl;
  print_as_tree<int>(v);
}
#else
void print_vector(vector<int> const& v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i < v.size()-1) {
      cout << ",";
    }
  }
}
#endif

struct Heap {
  private:
  vector<int> data = {};

  public:
  // todoo!
  void insert(int toInsert) {
    data.push_back(toInsert);
    // TODO
  }

  // todoo!
  int extract() {
    if (data.empty()) throw std::logic_error("cannot extract form empty heap");
    int result = data[0];
    std::swap(data[0], data[data.size()-1]);
    data.pop_back();
    // TODO
    return result;
  }

  // prints the heap
  void print() {
    print_vector(data);
  }

};


int main() {
  Heap heap;
  string operation;
  int integer;
  while(cout << "heap> " && cin >> operation) {
    try {
      if (operation == "insert" || operation == "i") {
        cin >> integer;
        heap.insert(integer);
        heap.print();
      }
      else if (operation == "extract-min" || operation == "e") {
        heap.extract();
        heap.print();
      }
      else {
        std::cerr << "unown operation: " << operation << endl;
      }
    } catch (std::exception& e){
      std::cerr << "Error: " << e.what() << endl;
    }
  }
}