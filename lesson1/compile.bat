@echo off
g++ -g3 -std=c++17 -Wall -Wextra -pedantic -O0 -o .\lesson1\isPrime.exe .\lesson1\isPrime.cpp
REM To also generate readable assembly, uncomment:
g++ -S -fverbose-asm -std=c++17 -Wall -Wextra -pedantic -O0 -o .\lesson1\isPrime.s .\lesson1\isPrime.cpp