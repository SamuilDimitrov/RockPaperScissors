#include <iostream>
#include <unordered_map>

#include "GameController.hpp"

GameController::GameController()
{
    this->player = Player(Player::PlayerType::Human);
    this->computer = Player(Player::PlayerType::Computer);
}

void GameController::clearScreen() const {
    #if defined(_WIN32)
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

bool GameController::askPlayAgain(){
    std::string playAgain;
    std::cout << "Do you want to play again? (yes/no): ";
    std::cin >> playAgain;
    return playAgain == "yes";
}

void GameController::playGame()
{
    do {
        clearScreen();
        playRound();

    } while (askPlayAgain());

    displayEndScreen();
}

void GameController::displayEndScreen(){
    std::cout << "Thanks for playing! The end result is:\n";
    std::cout << "Human wins: " << player.getNumberOfWins() << "\n";
    std::cout << "Computer wins: " << computer.getNumberOfWins() << "\n";
}

void GameController::displayRoundResults(Move computerMove, Move playerMove, RoundOutcome result){
    std::cout << "Thanks for playing! The end result is:\n";
    std::cout << "Human wins: " << player.getNumberOfWins() << "\n";
    std::cout << "Computer wins: " << computer.getNumberOfWins() << "\n";
}

void GameController::playRound()
{
    Move playerMove = player.getMove();
    Move computerMove = computer.getMove();

    RoundOutcome result = determineWinner(playerMove, computerMove);

    if(result== RoundOutcome::PlayerWins) player.addWin();
    else if(result== RoundOutcome::ComputerWins)  computer.addWin();

    displayRoundResults(computerMove, playerMove, result);
}

std::string GameController::moveToString(Move move) const
{
    switch (move)
    {
    case Move::Rock:
        return "Rock";
    case Move::Paper:
        return "Paper";
    case Move::Scissors:
        return "Scissors";
    default:
        return NULL;
    }
}

std::string GameController::OutcomeToString(RoundOutcome move) const
{
    switch (move)
    {
    case RoundOutcome::Tie:
        return "Tie";
    case RoundOutcome::PlayerWins:
        return "You win!";
    case RoundOutcome::ComputerWins:
        return "Computer wins!";
    default:
        return NULL;
    }
}

GameController::RoundOutcome GameController::determineWinner(Move playerMove, Move computerMove) const
{
    if (playerMove == computerMove)
    {
        return RoundOutcome::Tie;
    }

    const std::unordered_map<Move, Move> winMap = {
        {Move::Rock, Move::Scissors},
        {Move::Scissors, Move::Paper},
        {Move::Paper, Move::Rock}
    };

    if (winMap.at(playerMove) == computerMove)
    {
        return RoundOutcome::PlayerWins;
    }
    else
    {
        return RoundOutcome::ComputerWins;
    }
}