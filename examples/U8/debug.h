#pragma once

#include <iostream>

#include "./terminal-colors.h"

using std::cout;
using std::endl;

#ifdef Debug
#define info(x) cout << terminal::green << "𝑖 " << x << terminal::reset << endl;
#define input(x) cout << terminal::blue << "> " << x << terminal::reset << endl;
#define warning(x) cout << terminal::yellow << "! " << x << terminal::reset << endl;
#define error(x) cout << terminal::red << "↯ " << x << terminal::reset << endl;
#else
#define info(x)
#define input(x)
#define warning(x)
#define error(x)
#endif