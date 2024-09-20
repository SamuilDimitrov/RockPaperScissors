#include <iostream>
#include <random>
#include <string>
#include <sstream>

#include "Player.hpp"

Player::Player(){}
Player::Player(PlayerType human_player)
{
    this->player_wins = 0;
    this->is_player_human = human_player;
}

bool Player::isHuman() const{
    return is_player_human == PlayerType::Human;
}

Move Player::getHumanMove() const {
    int player_choice;
    std::string input;

    std::cout << "Enter your move (0 = Rock, 1 = Paper, 2 = Scissors): ";
    while (true) { 
        input.clear();
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "No input detected. Please enter a number (0 = Rock, 1 = Paper, 2 = Scissors): ";
            continue;
        }

        std::istringstream input_stream(input);

        if(!(input_stream >> player_choice)) {
            std::cout << "Invalid input. Please enter a number (0 = Rock, 1 = Paper, 2 = Scissors): ";
            continue;
        } 
        
        if (player_choice < MIN_CHOICE || player_choice > MAX_CHOICE) {
            std::cout << "Invalid choice. Please enter (0 = Rock, 1 = Paper, 2 = Scissors): ";
            continue;
        }
        return static_cast<Move>(player_choice);
    }
}



Move Player::getMove() const{
    if(isHuman()){
        return getHumanMove();
    }
    return getComputerMove();
}

Move Player::getComputerMove() const {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 2);
    return static_cast<Move>(distribution(generator));
}

bool Player::addWin(){
    if (player_wins == MAX_WINS) {
        return false;  
    }
    player_wins++;
    return true;
}

int Player::getNumberOfWins() const {
    return this->player_wins;
}