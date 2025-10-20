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

# Debugger
brew install gdb

# Git
brew install git

# Visual Studio Code
brew install --cask visual-studio-code

# CMake
brew install cmake
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