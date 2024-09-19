#include <iostream>

#include "GameController.hpp"

GameController::GameController(){
    this->player = Player(Player::PlayerType::Human);
    this->computer =  Player(Player::PlayerType::Computer);
}

void GameController::playGame() {
    std::string playAgain;
    do {
        std::system("cls");
        playRound();
        std::cout << "Do you want to play again? (yes/no): ";
        std::cin >> playAgain;

    } while (playAgain == "yes");

    // Print the final results
    std::system("cls");
    std::cout << "Thanks for playing! The end result is:\n";
    std::cout << "Human wins: " << player.getNumberOfWins() << "\n";
    std::cout << "Computer wins: " << computer.getNumberOfWins() << "\n";
}

void GameController::playRound() {
    Move playerMove = player.getMove();
    Move computerMove = computer.getMove();

    std::cout << "Computer chose: " << moveToString(computerMove) << "\n";
    std::cout << "You chose: " << moveToString(playerMove) << "\n";

    RoundOutcome result = determineWinner(playerMove, computerMove);

    switch (result)
    {
    case RoundOutcome::PlayerWins:
        player.addWin();
        break;
    case RoundOutcome::ComputerWins:
        computer.addWin();
        break;
    default:
        break;
    }

    std::cout << OutcomeToString(result) << "\n";
}


std::string GameController::moveToString(Move move) const {
    switch (move) {
    case Move::Rock: return "Rock";
    case Move::Paper: return "Paper";
    case Move::Scissors: return "Scissors";
    default: return "";
    }
}

std::string GameController::OutcomeToString(RoundOutcome move) const {
    switch (move) {
    case RoundOutcome::Tie: return "Tie";
    case RoundOutcome::PlayerWins: return "You win!";
    case RoundOutcome::ComputerWins: return "Computer wins!";
    default: return "";
    }
}

// Method to determine the winner based on moves
GameController::RoundOutcome GameController::determineWinner(Move playerMove, Move computerMove) const {
    if (playerMove == computerMove) {
        return RoundOutcome::Tie;
    }

    // // Use a lookup map to determine the winning pairs
    // const std::unordered_map<Move, Move> winMap = {
    //     {Move::Rock, Move::Scissors},
    //     {Move::Scissors, Move::Paper},
    //     {Move::Paper, Move::Rock}
    // };

    // if (winMap.at(playerMove) == computerMove) {
    if (true) {
        return RoundOutcome::PlayerWins;
    } else {
        return RoundOutcome::ComputerWins;
    }
}