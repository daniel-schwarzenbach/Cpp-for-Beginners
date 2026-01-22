# Testing

the most popular testing framework is gtest (Google Test)

## Linux (Ubuntu)

To install gtest on Ubuntu, you can use the following command:

```bash
sudo apt-get install libgtest-dev
```

than you just add the library flags to your compile command:

```bash
-lgtest -lgtest_main -lpthread
```

## Windows

The easiest way to install gtest on Windows is using vcpkg:

```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat
vcpkg install gtest
```

Then integrate it with your build system:

```bash
vcpkg integrate install
```

When compiling, link against the gtest libraries:

```bash
-lgtest -lgtest_main
```

Alternatively, you can download gtest from the official repository and build it manually with CMake.

## MacOS

To install gtest on MacOS, use Homebrew:

```bash
brew install googletest
```

Then add the library flags to your compile command:

```bash
-lgtest -lgtest_main -lpthread
```