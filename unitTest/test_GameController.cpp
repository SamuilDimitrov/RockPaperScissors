#include <gtest/gtest.h>
#include <string>

#include "GameController.hpp"

#define RANDOM_TEST_RUN_LENGHT 100

class GameControllerTest : public ::testing::Test
{
protected:
    GameController game;

    void SetUp() override
    {
        game = GameController();
    }
};

TEST_F(GameControllerTest, shortGameTest)
{
    std::istringstream empty_input("0\n no\n");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(empty_input.rdbuf());

    std::stringstream captured_output;
    std::streambuf *cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());

    game.playGame();

    std::cin.rdbuf(cin_buffer);
    std::cout.rdbuf(cout_buffer);

    std::string expected_output_round =  "Enter your move";
    std::string expected_output_ask =  "Do you want to play again? (yes/no): ";
    std::string expected_output_end =  "Thanks for playing! The end result is:\n";

    EXPECT_TRUE(captured_output.str().find(expected_output_round) != std::string::npos);
    EXPECT_TRUE(captured_output.str().find(expected_output_ask) != std::string::npos);
    EXPECT_TRUE(captured_output.str().find(expected_output_end) != std::string::npos);
}

TEST_F(GameControllerTest, endScreenDispaly)
{
    std::istringstream empty_input("0\n no\n");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(empty_input.rdbuf());

    std::stringstream captured_output;
    std::streambuf *cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());

    game.playGame();

    std::cin.rdbuf(cin_buffer);
    std::cout.rdbuf(cout_buffer);

    std::string end_screen_tie =  "Thanks for playing! The end result is:\nPlayer wins: 0\nComputer wins: 0\n";
    std::string end_screen_player =  "Thanks for playing! The end result is:\nPlayer wins: 1\nComputer wins: 0\n";
    std::string end_screen_computer =  "Thanks for playing! The end result is:\nPlayer wins: 0\nComputer wins: 1\n";

    EXPECT_TRUE(
        captured_output.str().find(end_screen_tie) != std::string::npos ||
        captured_output.str().find(end_screen_player) != std::string::npos ||
        captured_output.str().find(end_screen_computer) != std::string::npos
    );
}

TEST_F(GameControllerTest, roundDispaly)
{
    std::istringstream empty_input("0\n no\n");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(empty_input.rdbuf());

    std::stringstream captured_output;
    std::streambuf *cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());

    game.playGame();

    std::cin.rdbuf(cin_buffer);
    std::cout.rdbuf(cout_buffer);

    std::string round_screen_tie =  "Computer chose: Rock\nYou chose: Rock\nThe result of the round is: Tie\n";
    std::string round_screen_player =  "Computer chose: Scissors\nYou chose: Rock\nThe result of the round is: You win!\n";
    std::string round_screen_computer =  "Computer chose: Paper\nYou chose: Rock\nThe result of the round is: Computer wins!\n";

    EXPECT_TRUE(
        captured_output.str().find(round_screen_tie) != std::string::npos ||
        captured_output.str().find(round_screen_player) != std::string::npos ||
        captured_output.str().find(round_screen_computer) != std::string::npos
    );
}