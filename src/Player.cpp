#include <iostream>
#include <random>

#include "Player.hpp"

Player::Player(){}
Player::Player(PlayerType human_player)
{
    this->prlayer_wins = 0;
    this->is_player_human = human_player;
}

bool Player::isHuman() const{
    return is_player_human == PlayerType::Human;
}

// Handle user input
Move Player::getHumanMove() const {
    int choice;
    // Loop until valid input is received
    while (true) { 
        std::cout << "Enter your move (0 = Rock, 1 = Paper, 2 = Scissors): ";

        // Check if input is integer
        if (std::cin >> choice) {  
            // Check if input is valid
            if (choice >= 0 && choice <= 2) {
                return static_cast<Move>(choice);
            } else {
                std::cout << "Invalid choice. Please enter (0 = Rock, 1 = Paper, 2 = Scissors):" << std::endl;
            }
        } else {
            // If the input is not an integer, clear the error and discard the invalid input
            std::cout << "Invalid input. Please enter a number (0 = Rock, 1 = Paper, 2 = Scissors):" << std::endl;
            std::cin.clear();  // Clear the error flag
            //ignore the user input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //
        }
    }
}

Move Player::getMove(){
        if(isHuman()){
            return getHumanMove();
        } else {
            return getComputerMove();
        }
    }

Move Player::getComputerMove() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 2);
    return static_cast<Move>(dist(gen));
}

bool Player::addWin(){
    if (prlayer_wins == std::numeric_limits<int>::max()) {
        return false;  // Cannot increment, already at maximum value
    }
    prlayer_wins++;
    return true;  // Successfully incremented
}

// Get the number of wins
int Player::getNumberOfWins() const {
    return this->prlayer_wins;
}