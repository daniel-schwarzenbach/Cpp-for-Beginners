#include <memory>
#include <initializer_list>
#include <iostream>
// iostream
using std::cout;
using std::endl;
// memory
using std::make_unique;
using std::unique_ptr;
using std::move;

using element_t = int;

struct Subarray {
  constexpr static size_t min_size = 4;
  unique_ptr<element_t[]> data;
  size_t size = 0;
  size_t start_index = 0;
  size_t end_index = 0;
  unique_ptr<Subarray> next = nullptr;
  // constructor
  Subarray(size_t n) {
    size_t initial_size = n < min_size ? min_size : n;
    // create data array of size initial_size
    data = make_unique<element_t[]>(initial_size);
    size = initial_size;
    start_index = 0;
    end_index = n;
    next = nullptr;
  }
  // get used up size
  constexpr size_t used_size() { return end_index - start_index; }
  // acces operator
  constexpr element_t& operator[](size_t index) {
    return data[start_index + index];
  }
  // is full
  bool is_full() { return start_index == 0 && end_index == size; }
  // move array
  void move_array(int shift) {
    // shift forward on positive shift
    if (shift > 0) {
      for (long i = end_index-1; i >= start_index; ++i) {
        data[i + shift] = data[i];
      }
    // otherwise shift backward
    } else if (shift < 0) {
      for (long i = start_index; i < end_index; ++i) {
        data[i + shift] = data[i];
      }
    }
    // update indices
    start_index += shift;
    end_index += shift;
  }
  // push front
  void push_front(const element_t& value) {
    if (start_index == 0) move_array(1);
    data[start_index-1] = value;
    --start_index;
  }
  // push back
  void push_back(const element_t& value) {
    if (end_index == size) move_array(-1);
    ++end_index;
    data[end_index-1] = value;
  }
};

struct Deque {
  private:
    unique_ptr<Subarray> head;
    Subarray* tail;
  public:

    Deque(size_t n) {
      head = make_unique<Subarray>(Subarray(n));
      tail = head.get();
    }

    Deque(): Deque(0) {};

    Deque(std::initializer_list<element_t> init_list) 
        : Deque(init_list.size()) {
      size_t index = 0;
      for (const auto& value : init_list) {
        (*this)[index++] = value;
      }
    }

    element_t& operator[](size_t index) {
      // Traverse the linked Subarrays
      Subarray* current = head.get();
      while (current) {
        size_t size = current->used_size();
        // if the index is within this subarray
        if (index < size) {
          return (*current)[index];
        // otherwise go to the next subarray
        } else {
          index -= size;
          current = current->next.get();
        }
      }
      throw std::out_of_range("Index out of range");
    }

    size_t size() {
      // sum up the sizes of all subarrays
      size_t sum = 0;
      Subarray* current = head.get();
      while(current) {
        sum += current->used_size();
        current = current->next.get();
      }
      return sum;
    }

    void push_back(element_t value) {
      if (tail->is_full()) {
        tail->next = make_unique<Subarray>(2*tail->size);
        tail = tail->next.get();
        tail->end_index = 0;
      }
      tail->push_back(value);
    }

    void push_front(element_t value) {
      if (head->is_full()) {
        auto new_head = make_unique<Subarray>(2*head->size);
        // new head is empty
        new_head->start_index = new_head->size;
        new_head->next = move(head);
        head = move(new_head);
      }
      head->push_front(value);
    }

    element_t pop_front() {
      if (head->used_size() == 1) {
        element_t value = (*head)[0];
        head = move(head->next);
        return value;
      } else {
        element_t value = (*head)[0];
        ++head->start_index;
        return value;
      }
    }

    element_t pop_back() {
      if (tail->used_size() == 1) {
        element_t value = (*tail)[0];
        // find the new tail
        Subarray* current = head.get();
        while (current->next.get() != tail) {
          current = current->next.get();
        }
        current->next = nullptr;
        tail = current;
        return value;
      } else {
        element_t value = (*tail)[tail->used_size() - 1];
        --tail->end_index;
        return value;
      }
    }

    element_t remove_at(size_t index) {
      element_t value;
      // Traverse the linked Subarrays
      Subarray* previous = nullptr;
      Subarray* current = head.get();
      while (current) {
        size_t size = current->used_size();
        // if the index is within this subarray
        if (index < size) {
          value = (*current)[index];
          // if this was the last element in the subarray, remove the subarray
          if (size == 1) {
            if (previous) {
              previous->next = move(current->next);
              if (current == tail) tail = previous;
            } else {
              head = move(current->next);
              if (current == tail) tail = head.get();
            }
          // otherwise shift elements to fill the gap
          } else {
            for (size_t i = index; i < size - 1; ++i) {
              (*current)[i] = (*current)[i + 1];
            }
            --current->end_index;
          }
          return value;
        // otherwise go to the next subarray
        } else {
          index -= size;
          current = current->next.get();
        }
      }
      throw std::out_of_range("Index out of range");
    }

    friend std::ostream& operator<<(std::ostream& os, Deque& dq) {
      Subarray* current = dq.head.get();
      while (current) {
        os << "[";
        for (long i = 0; i < current->size; ++i) {
          if (i >= current->start_index && i < current->end_index) {
            os << current->data[i];
          } else {
            os << "░"; // char[] = {-30 -106 -111 0}
          }
          if (i+1 < current->size) os << ", ";
        }
        current = current->next.get();
        os << "] -> ";
      }
      return os;
    }
};

int main() {
  Deque dq = {1,2,3,4};
  // output the dq
  std::cout << "Starting: " << dq << endl << endl;
  // add to new numbers on the back and replace dq[4] than with 16
  dq.push_back(8);
  dq.push_back(2);
  dq[4] = 16;
  // output the dq and its size
  cout << dq << endl;
  cout << "size: " << dq.size() << endl << endl;
  // add numbers 0 ... 11 to the back
  for (int i = 0; i < 12; ++i) dq.push_back(i);
  // add numbers 0 ... 4 to the front
  for (int i = 0; i < 5; ++i) dq.push_front(i);
  dq[2] = 30;
  // output the dq
  cout << "After pushing: " <<  dq << endl << endl;
  // remove element at index 5 and 9
  dq.remove_at(5);
  dq.remove_at(9);
  cout << "After removal" << dq << endl << endl;
  // pop 10 elements from the front
  for (int i = 0; i < 10; ++i) dq.pop_front();
  cout <<  "After poping front: " << dq << endl << endl;
  // pop 5 elements from the back
  for (int i = 0; i < 5; ++i) dq.pop_back();
  cout <<  "After poping back: "<< dq << endl << endl;
  return 0;
}