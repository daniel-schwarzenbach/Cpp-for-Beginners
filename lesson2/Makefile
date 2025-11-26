# Compiler to use (GNU C++ Compiler)
CXX := g++

# Compiler flags:
# -std=c++17     : Use C++17 standard
# -Wall          : Enable all common warnings
# -Wextra        : Enable extra warnings beyond -Wall
# -g3            : Include maximum debugging information (level 3)
# -Ilib          : Add 'lib' directory to include search path (for headers)
# -Llib          : Add 'lib' directory to library search path (for linking)
CXXFLAGS := -std=c++17 -Wall -Wextra -g3 -Ilib -Llib

# Name of the final executable program
TARGET := myProgram

# List of source files (.cpp) that need to be compiled
SRCS := main.cpp myFunction.cpp

# Convert source file names to object file names
# $(SRCS:.cpp=.o) replaces .cpp extension with .o
# Example: main.cpp → main.o, myFunction.cpp → myFunction.o
OBJS := $(SRCS:.cpp=.o)

# Path to the shared library file (used as a dependency to track changes)
LIBMATH_FILE := lib/libmath.so
# Linker flag for the math library
LIBMATH := -lmath
# Add runtime library path so the executable can find the .so
# Use $ORIGIN to make it relative to the executable's location
LDFLAGS := -Wl,-rpath,'$$ORIGIN/lib'

# Default target when running 'make' with no arguments
# Dependencies execute in order: clean → $(TARGET) → cleanobjs
# This ensures a fresh build every time
all: clean $(TARGET) cleanobjs

# Rule to build the final executable
# $(TARGET) depends on object files ($(OBJS)) and the math library file ($(LIBMATH_FILE))
# If any dependency is newer than $(TARGET), this rule executes
$(TARGET): $(OBJS) $(LIBMATH_FILE)
	# Link all object files and library into the final executable
	# $@ is the target name (main)
	# $(OBJS) expands to all object files
	# $(LIBMATH) is the linker flag (-lmath)
	# $(LDFLAGS) adds runtime library path so .so can be found
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LIBMATH) $(LDFLAGS)

# Pattern rule: how to build any .o file from corresponding .cpp file
# % is a wildcard that matches any filename
# Example: main.o is built from main.cpp
%.o: %.cpp
	# Compile source file to object file without linking
	# -c flag means "compile only, don't link"
	# $< is the first prerequisite (the .cpp file)
	# $@ is the target (the .o file)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target to remove the final executable
# Used to force a complete rebuild
clean:
	# -f flag suppresses errors if file doesn't exist
	rm -f $(TARGET)

# Target to remove only object files
# Keeps the executable but cleans intermediate build files
cleanobjs:
	# Remove all .o files listed in $(OBJS)
	rm -f $(OBJS)

# Declare these targets as "phony" (not real files)
# Make will always run these even if files with these names exist
# Without .PHONY, if a file named "clean" existed, Make would think
# the target is up-to-date and skip it
.PHONY: clean all cleanobjs