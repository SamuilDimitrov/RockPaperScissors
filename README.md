# RockPaperScissors
48-hours C++ Assigment from Lake3D


# To compile from build directory
rm -rf * & cmake -G "Visual Studio 17 2022" .. -T host=x64 -A x64 & cmake --build . --config Release
# To test
ctest -C Release --output-on-failure