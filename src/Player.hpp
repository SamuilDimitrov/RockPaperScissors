#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Move.hpp"

#define MAX_WINS INT32_MAX 
#define MIN_CHOICE 0
#define MAX_CHOICE 2

class Player
{
public:
    enum class PlayerType {
        Human, 
        Computer
    };

    Player();
    Player(PlayerType type);

    bool isHuman() const;
    Move getMove() const;

    bool addWin();
    int getNumberOfWins() const ;

private:
    PlayerType is_player_human;
    int prlayer_wins;

    Move getHumanMove() const;
    Move getComputerMove() const;
};

#endif // PLAYER_HPP