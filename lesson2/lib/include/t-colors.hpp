#pragma once

// Define terminal colors for cross-platform usage
namespace math::t_colors{

#if defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(__MACH__)
// ANSI escape codes for Unix-like systems
constexpr const char* RESET   = "\033[0m";
constexpr const char* BLACK   = "\033[30m";
constexpr const char* RED     = "\033[31m";
constexpr const char* GREEN   = "\033[32m";
constexpr const char* YELLOW  = "\033[33m";
constexpr const char* BLUE    = "\033[34m";
constexpr const char* MAGENTA = "\033[35m";
constexpr const char* CYAN    = "\033[36m";
constexpr const char* WHITE   = "\033[37m";
#else
// Windows-specific color codes (placeholders, actual implementation may vary)
constexpr const char* RESET   = "";
constexpr const char* BLACK   = "";
constexpr const char* RED     = "";
constexpr const char* GREEN   = "";
constexpr const char* YELLOW  = "";
constexpr const char* BLUE    = "";
constexpr const char* MAGENTA = "";
constexpr const char* CYAN    = "";
constexpr const char* WHITE   = "";
#endif

}
