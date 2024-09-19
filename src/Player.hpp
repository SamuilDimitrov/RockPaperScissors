#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Move.hpp"

#define MIN_CHOICE 0
#define MAX_CHOICE 2

class Player
{
public:
    // Define the enum inside the Player class
    enum class PlayerType {
        Human, 
        Computer
    };

    Player();
    // Constructor that accepts PlayerType
    Player(PlayerType type);

    // Method to get the move from either human or computer
    Move getMove();
    /*  Add one win to the number of wins
        Retunrs a false when the max number of wins is achived. */
    bool addWin();
    // Get the number of wins
    int getNumberOfWins() const ;

private:
    // Use the nested PlayerType
    PlayerType is_player_human;
    // Number of player wins
    int prlayer_wins;

    // Method to check if the player is human
    bool isHuman() const;
    // Handle user input
    Move getHumanMove() const;
    // Random move generation for computer
    Move getComputerMove() const;
};

#endif // PLAYER_HPP