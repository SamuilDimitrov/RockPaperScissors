cmake_minimum_required(VERSION 3.30)  # or the version you need

set(Sources
    test_Player.cpp
    test_GameController.cpp
)

add_executable(test_runner ${Sources})

target_link_libraries(test_runner PUBLIC gtest_main RockPaperScissorsLib)

target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(NAME test_runner COMMAND test_runner)