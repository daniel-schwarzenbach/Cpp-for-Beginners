# MacOS/Unix

## 1. Install Homebrew (Package Manager for MacOS)

![Homebrew Logo](pics/HomeBrew.png)

Open Terminal and run the following command to install Homebrew:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

altenatively, you can visit [Homebrew's official website](https://brew.sh/) for more information.


## 2. Install the Required Packages

```bash
# C++ Compiler and Tools
brew install gcc

# Git
brew install git

# CMake
brew install make
brew install cmake

# Debugger
xcode-select --install
# enable the use of the debugger
sudo DevToolsSecurity --enable
```

Install VSCode from the official website: [VSCode](https://code.visualstudio.com/)

Install Julia from the official website: [Julia](https://julialang.org/install/)

## Debugging with LLDB-MI on macOS



## 3. Verify the Installation

```bash
gcc --version
g++ --version
gdb --version
git --version
code --version
```

[Go Back to Guide](../Readme.md#installation-guide)
