cmake_minimum_required(VERSION 3.30)  # or the version you need
project(RockPaperScissors C CXX)

# Set C/C++ standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 


add_subdirectory(src)

# Add include directories specifically for the library
# target_include_directories(RockPaperScissors PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Option to enable or disable testing
option(ENABLE_TESTING "Enable unit tests" ON)

if(ENABLE_TESTING)
    # Enable testing feature
    enable_testing()

#     # Download GoogleTest if not available
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2  # Use the tag you need
    )
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(unitTest)
endif()
