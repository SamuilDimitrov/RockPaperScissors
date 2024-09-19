#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "Player.hpp"

class GameController
{
public:
    GameController();

    // Method to start the game
    void playGame();

private:
    enum class RoundOutcome
    {
        Tie,
        PlayerWins,
        ComputerWins
    };
    Player player;
    Player computer;

    // Handle one round of the game
    void playRound();
    // Helper function to convert enums to string
    std::string moveToString(Move move) const;
    std::string OutcomeToString(RoundOutcome move) const;
    // Method to determine the winner based on moves
    RoundOutcome determineWinner(Move playerMove, Move computerMove) const;
};

#endif // GAMECONTROLLER_HPP
