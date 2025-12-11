# Compiling Multiple Files

to Compile multiple C++ files I recommend using a bash script like the following:

```bash
#!/bin/bash

# Compiler and flags
CXX="g++"
CXXFLAGS="-Wall -Wextra -std=c++23 -g"

# Automatically retrieve all .cpp files in the current directory
SRC=(*.c??)
HEADER=(*.h)

# Output executable
TARGET="program.out"

# Function to clean up object files and executable
clean() {
   echo "Cleaning up..."
   rm -f "${OBJ[@]}"
   echo "Clean complete."
}

# format
format(){
  for h in "${HEADER[@]}"; do
    clang-format -i $h
  done
}

# Compile and link
build() {
   # Generate list of object files
   OBJ=()
   for src in "${SRC[@]}"; do
      OBJ+=("${src%.cpp}.o")
   done

   echo "Compiling source files..."
   for src in "${SRC[@]}"; do
      obj="${src%.cpp}.o"
      clang-format -i $src
      echo "Compiling $src -> $obj"
      echo $CXX $CXXFLAGS -c "$src" -o "$obj"
      $CXX $CXXFLAGS -c "$src" -o "$obj"
      if [ $? -ne 0 ]; then
         echo "Error compiling $src"
         exit 1
      fi
   done

    echo "Linking object files..."
    echo $CXX $CXXFLAGS -o "$TARGET" "${OBJ[@]}"
    $CXX $CXXFLAGS -o "$TARGET" "${OBJ[@]}"
    if [ $? -ne 0 ]; then
        echo "Error linking object files"
        exit 1
    fi

    echo "Build complete. Executable: $TARGET"
}

rm "$TARGET"
format
build
clean
```

or you can use a Makefile like the onces you can find in `lesson2`

# Ex 1 + 2

look at the `example2.cpp` and at the lecture slides for reference on how to do inheritance and polymorphism

# Ex3

you might want to make tests of your own befor testing it on the pipline

for a statingpoint see `example1.h`