#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

struct Animal {
  Animal(int age) : age_(age) {};
  protected:
    int age_;
  public:
    int get_age() {
      return age_;
    }
};

struct Dog : Animal {
  Dog(string name, int age) : name_(name), Animal(age) {};
  protected:
    string name_;
  public:
    string get_bark() {
      return "Woof!";
    }
    string get_name() {
      return name_;
    }
    virtual bool is_friendly() {
      return false;
    }
};

struct GoldenRetriever : Dog {
  GoldenRetriever(string name, int age) : Dog(name, age) {}
  string get_bark() {
    return "Woof! Woof!";
  }
  bool is_friendly() override {
    return true;
  }
};

int main() {
  GoldenRetriever gr("Buddy", 4);
  Dog* dog = &gr;
  cout << dog->get_age() << ", " << dog->is_friendly() << ", " << dog->get_bark() << endl;
  return 0;
}
