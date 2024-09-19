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

Move Player::getHumanMove() const {
    int choice;
    
    while (true) { 
        std::cout << "Enter your move (0 = Rock, 1 = Paper, 2 = Scissors): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number (0 = Rock, 1 = Paper, 2 = Scissors):" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue;
        }

        if (choice < MIN_CHOICE || choice > MAX_CHOICE){
            std::cout << "Invalid choice. Please enter (0 = Rock, 1 = Paper, 2 = Scissors):" << std::endl;
            continue;
        }
        
        return static_cast<Move>(choice);
    }
}

Move Player::getMove(){
    if(isHuman()){
        return getHumanMove();
    }
    return getComputerMove();
}

Move Player::getComputerMove() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 2);
    return static_cast<Move>(dist(gen));
}

bool Player::addWin(){
    if (prlayer_wins == std::numeric_limits<int>::max()) {
        return false;  
    }
    prlayer_wins++;
    return true;
}

int Player::getNumberOfWins() const {
    return this->prlayer_wins;
}