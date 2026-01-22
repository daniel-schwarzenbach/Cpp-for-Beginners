# Lesson 2 - Compiling and Linking

In this lesson, we will learn how to compile and link C++ programs that use multiple source files and libraries. We will cover the following topics:
- Compiling multiple source files
- Creating and using static libraries

## Compiling Multiple Source Files

When your program consists of multiple source files, you need to compile each file separately and then link them together to create the final executable. You can do this using the `g++` compiler. For example, if you have two source files `main.cpp` and `utils.cpp`, you can compile and link them as follows:
```bash
g++ -o my_program main.cpp utils.cpp
```
This command compiles both `main.cpp` and `utils.cpp`, and links them to create an executable named `my_program`.

Or, you can compile each file separately into object files and then link them:
```bash
g++ -c main.cpp -o main.o
g++ -c utils.cpp -o utils.o
g++ -o my_program main.o utils.o
```

## Creating and Using Static Libraries
A static library is a collection of object files that can be linked into your program. To create a static library, you can use the `ar` command. For example, if you have two object files `utils.o` and `math.o`, you can create a static library named `libmylib.a` as follows:
```bash
ar rcs libmylib.a utils.o math.o
```
To use the static library in your program, you need to link it during the compilation process.
For example, if you have a source file `main.cpp` that uses functions from `libmylib.a`, you can compile and link it as follows:
```bash
g++ -o my_program main.cpp -L. -lmylib
```
Here, `-L.` tells the compiler to look for libraries in the current directory, and `-lmylib` tells it to link against `libmylib.a`.

If you have Include files in your library, you may also need to specify the include path using the `-I` option:
```bash
g++ -o my_program main.cpp -I./include -L. -lmylib
```

## Makefiles

To simplify the compilation and linking process, you can use a Makefile. A Makefile is a script that defines how to build your program. Here is an example Makefile for a program that uses multiple source files and a static library:
