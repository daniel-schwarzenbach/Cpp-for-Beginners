# A1

define this struct and functions
```cpp
struct vec3D { int x, y, z; };
int dot_product(vec3D const& a, vec3D const& b);
vec3D cross_product(vec3D const& a, vec3D const& b);
vec3D add(vec3D const& a, vec3D const& b);
```

Given two 3D vectors
a = [x,y,z]
b = [u,v,w]

scalar product:
a ⋅ b := x*u + y*v + z*w
cross product:
a × b := [y*w - z*v, z*u - x*w, x*v - y*u]
vector addition:
a + b := [x + u, y + v, z + w]

# A2

undo implementieren

```cpp
#include <string>
#include <stack>

using std::string;
using std::stack;

stack<string> pastMoves;
stack<char> deadPieces;

// add an element to the undo stack
pastMoves.push(currentMove);
// get last element from the undo stack
string lastMove = pastMoves.top();
pastMoves.pop();
```

# A3

Look at: https://www.youtube.com/watch?v=0wPlzMU-k00

Heap
- use an `std::vector` or `std::deque` to store the Elements.
- you could use `std::swap`
- Children of element at index ´i´ are ´2(i+1)-1´ and ´2(i+1)´
- Parent of element at index ´i´ is ´(i+1)/2 - 1´
- insert:
  - add ellement at the end(`.push_back(element)`)
  - bubble up the element to restore heap property
    - compare with parent and swap if smaller
    - repeat until root or no swap needed
- extract min:
  - swap first and last element
  - pop last element (the minimum) (`.pop_back()`)
  - bubble down the new first element to restore heap property
    - compare with children and swap with the smaller one
    - if no children are smaller, stop
    - otherwise swap the elements and repeat
