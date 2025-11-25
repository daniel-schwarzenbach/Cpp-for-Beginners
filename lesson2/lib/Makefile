# C++ compiler to use (GNU C++ Compiler)
CXX      := g++

# Archive tool for creating static libraries (.a files)
AR       := ar

# Compiler flags:
# -std=c++17 : Use C++17 standard
# -g3        : Include maximum debugging information (level 3)
# -Wall      : Enable all common warnings
# -Wextra    : Enable extra warnings beyond -Wall
CXXFLAGS := -std=c++17 -g3 -Wall -Wextra

# Directory containing source files (.cpp)
SRCDIR   := src

# Directory where object files (.o) will be placed
OBJDIR   := build

# Name of the static library to create
TARGET   := libmath.a

# Find all .cpp files in the SRCDIR directory
# $(wildcard pattern) expands to all files matching the pattern
# Example: src/functions.cpp, src/analysis.cpp, src/plot.cpp
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Convert source file paths to object file paths
# $(patsubst pattern,replacement,text) does pattern substitution
# Transforms: src/functions.cpp → build/functions.o
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Create dependency file list from object files
# Replaces .o extension with .d
# Dependency files track header dependencies for incremental builds
# Example: build/functions.o → build/functions.d
DEPS    := $(OBJECTS:.o=.d)

# Default target: clean everything, build library, then remove object files
# This ensures a fresh build and clean workspace
all: clean $(TARGET) cleanobjs

# Rule to create the static library archive
# $(TARGET) depends on all object files ($(OBJECTS))
$(TARGET): $(OBJECTS)
	# Create static library archive
	# ar rcs: r=insert/replace, c=create archive, s=create index
	# $@ is the target (libmath.a)
	# $^ are all prerequisites (all .o files)
	$(AR) rcs $@ $^

# Pattern rule: how to build object files from source files
# The | $(OBJDIR) is an "order-only prerequisite"
# It ensures $(OBJDIR) exists before trying to create files in it
# But doesn't trigger rebuild if $(OBJDIR) timestamp changes
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	# Compile source to object file with dependency generation
	# -MMD: Generate dependency file (.d) excluding system headers
	# -MP:  Add phony targets for each dependency to avoid errors if headers are deleted
	# -c:   Compile only, don't link
	# $<:   First prerequisite (the .cpp file)
	# $@:   Target (the .o file)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Rule to create the build directory if it doesn't exist
$(OBJDIR):
	# -p flag: create parent directories as needed, no error if exists
	mkdir -p $@

# Remove both the build directory and the final library
# Completely clean build from scratch
clean:
	# $(RM) is a Make built-in variable (usually 'rm -f')
	# -r: recursive (remove directory and contents)
	$(RM) -r $(OBJDIR) $(TARGET)

# Remove only the build directory, keep the library
# Useful for cleaning intermediate files while preserving output
cleanobjs:
	$(RM) -r $(OBJDIR)

# Include all dependency files
# - prefix means "ignore errors if files don't exist"
# This allows Make to track header file changes and rebuild only what's needed
# If a .h file changes, only .cpp files that include it will recompile
-include $(DEPS)

# Declare phony targets (not real files)
# Make will always execute these even if files with same names exist
.PHONY: all clean cleanobjs