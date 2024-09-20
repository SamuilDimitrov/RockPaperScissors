# RockPaperScissors
48-hour C++ Assignment from Lake3D

## Overview
This project is a simple implementation of the Rock-Paper-Scissors game in C++. It allows players to compete against the computer in a classic game format.

## Prerequisites
- CMake (version 3.30 or later)
- C++20 with target compiler: MSVC

## Build Instructions

### On Unix-Based Systems
   ```bash
   chmod +x build.sh
   ./build.sh
   ```

### On Windows
   ```batch
   .\build.bat
   ```

## Testing the Project
To run the tests, navigate to the build directory and use CTest:
```bash
cd build
ctest -C Release --output-on-failure --verbose
```

## Executing the Program
### To run the program, from the build directory:
### On Unix-Based Systems
```bash
./build/src/Release/RockPaperScissors.out
```

### On Windows
```batch
.\build\src\Release\RockPaperScissors.exe
```