#include <cstddef>

// example for Rule of Five
template<typename T>
struct Vector {
 private:
  T* data_;
  size_t size_;
 public:

  // constructor
  Vector(size_t s) : size_(s) {
    data_ = new T[s];
  }

  // 1. destructor
  ~Vector() noexcept {
    delete[] data_;
  }

  // 2. copy constructor
  Vector(const Vector& other) : size_(other.size_) {
    data_ = new T[size_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  // 3. copy assignment
  Vector& operator=(const Vector& other) {
    if (this != &other) {
      delete[] data_;
      size_ = other.size_;
      data_ = new T[size_];
      for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
      }
    }
    return *this;
  }

  // 4. move constructor
  Vector(Vector&& other) noexcept : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
    other.size_ = 0;
  }
  // 5. move assignment
  Vector& operator=(Vector&& other) noexcept {
    if (this != &other) {
      delete[] data_;
      data_ = other.data_;
      size_ = other.size_;
      other.data_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  T& operator[](size_t index) {
    return data_[index];
  }

  T operator[](size_t index) const {
    return data_[index];
  }

  size_t size() const {
    return size_;
  }
  
};