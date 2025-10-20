# Fedora Based Linux

```bash
# c++ Compiler and Tools
sudo dnf groupinstall "Development Tools"
sudo dnf install gcc-c++ make

# Debugger
sudo dnf install gdb

# Visual Studio Code
sudo dnf install code

# Git
sudo dnf install git

# CMake
sudo dnf install cmake
```

## 3. Verify the Installation

```bash
gcc --version
g++ --version
gdb --version
git --version
code --version
```

[Go Back to Guide](../Readme.md#installation-guide)