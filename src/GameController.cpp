#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

#include "GameController.hpp"

const std::unordered_map<Move, Move> GameController::winMap = {
    {Move::Rock, Move::Scissors},
    {Move::Scissors, Move::Paper},
    {Move::Paper, Move::Rock}
};

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
    std::string input;
    std::cout << "Do you want to play again? (yes/no): ";

    while (true)
    {
        std::getline(std::cin, input);
        
        if (!input.empty())break;

        input.clear();
        clearScreen();
        std::cout << "No input detected. Do you want to play again? (yes/no):";
    }

    std::transform(input.begin(), input.end(), 
        input.begin(), [](unsigned char c){ return std::tolower(c); });
    return (input == "yes");
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
    std::cout << "Computer chose: " << moveToString(computerMove) << "\n";
    std::cout << "You chose: " << moveToString(playerMove) << "\n";
    std::cout << OutcomeToString(result) << "\n";
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