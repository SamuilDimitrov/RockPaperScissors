#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <unordered_map>

#include "Player.hpp"

class GameController
{
public:
    GameController();

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
    static const std::unordered_map<Move, Move> winMap;

    void clearScreen() const;
    bool askPlayAgain();
    void playRound();
    void displayEndScreen();
    void displayRoundResults(Move computerMove, Move playerMove, RoundOutcome result);
    std::string moveToString(Move move) const;
    std::string OutcomeToString(RoundOutcome move) const;
    RoundOutcome determineWinner(Move playerMove, Move computerMove) const;
};

#endif // GAMECONTROLLER_HPP
