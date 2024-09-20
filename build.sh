#!/bin/bash

BUILD_DIR="./build"

if [ ! -d "$BUILD_DIR" ]; then
    echo "Build folder not found. Creating it..."
    mkdir -p "$BUILD_DIR"
fi

cd "$BUILD_DIR" || { echo "Failed to navigate to the build folder"; }

rm -rf *

echo "Generating project files with CMake..."
cmake -G "Visual Studio 17 2022" .. -T host=x64 -A x64

if [ $? -eq 0 ]; then
    echo "Project files generated successfully."
else
    echo "Failed to generate project files."
    exit 1
fi

# Build the project in Release mode
echo "Building the project in Release mode..."
cmake --build . --config Release

if [ $? -eq 0 ]; then
    echo "Build completed successfully."
else
    echo "Build failed."
    exit 1
fi
