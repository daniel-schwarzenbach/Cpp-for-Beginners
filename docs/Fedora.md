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
sudo dnf install make
sudo dnf install cmake
```

Install VSCode from the official website: [VSCode](https://code.visualstudio.com/)

Install Julia from the official website: [Julia](https://code.visualstudio.com/)

## 3. Verify the Installation

```bash
gcc --version
g++ --version
gdb --version
git --version
code --version
```

[Go Back to Guide](../Readme.md#installation-guide)