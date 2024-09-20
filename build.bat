@echo off
setlocal

set BUILD_DIR=./build

if not exist "%BUILD_DIR%" (
    echo Build folder not found. Creating it...
    mkdir "%BUILD_DIR%"
)

cd "%BUILD_DIR%" || (
    echo Failed to navigate to the build folder
    exit /b 1
)

echo Removing old build files...
del /q *.*

echo Generating project files with CMake...
cmake -G "Visual Studio 17 2022" .. -T host=x64 -A x64

if %errorlevel% neq 0 (
    echo Failed to generate project files.
    exit /b 1
)

echo Building the project in Release mode...
cmake --build . --config Release

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b 1
)

echo Build completed successfully.
endlocal
