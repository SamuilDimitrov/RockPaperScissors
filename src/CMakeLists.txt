cmake_minimum_required(VERSION 3.30)  # or the version you need

set(Headers
    Move.hpp
    Player.hpp
    GameController.hpp
)

set(Sources
    RockPaperScissors.cpp
    Player.cpp
    GameController.cpp
)

option(ENABLE_TESTING "Enable unit tests" ON)
if(ENABLE_TESTING)
add_library(RockPaperScissorsLib STATIC ${Sources}) 
endif()

add_executable(RockPaperScissors ${Sources})