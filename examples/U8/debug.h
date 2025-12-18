#pragma once

#include <iostream>

#include "./terminal-colors.h"

using std::cout;
using std::endl;

#ifdef Debug
// return important information
#define info(x) cout << terminal::green << "𝑖 " << x << terminal::reset << endl
// echo input commands
#define input(x) cout << terminal::blue << "> " << x << terminal::reset << endl
// warn about potential issues
#define warning(x) cout << terminal::yellow << "! " << x << terminal::reset << endl
// report errors
#define error(x) cout << terminal::red << "↯ " << x << terminal::reset << endl
// check a condition and report if it fails
#define check(x)                   \
  if (!(x)) {                      \
    error("check failed: " << #x); \
  }
#else
// return important information
#define info(x)
// echo input commands
#define input(x)
// warn about potential issues
#define warning(x)
// report errors
#define error(x)
// check a condition and report if it fails
#define check(x)
#endif