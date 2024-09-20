#include <gtest/gtest.h>
#include <string>

#include "GameController.hpp"

#define RANDOM_TEST_RUN_LENGHT 100

class GameControllerTest : public ::testing::Test
{
protected:
    GameController game;

    std::istringstream test_input;
    std::stringstream captured_output;
    std::streambuf* cin_buffer;
    std::streambuf* cout_buffer;

    void SetUp() override {
        game = GameController();
        cin_buffer = std::cin.rdbuf();
        cout_buffer = std::cout.rdbuf();
        std::cin.rdbuf(test_input.rdbuf());
        std::cout.rdbuf(captured_output.rdbuf());
    }

    void TearDown() override {
        std::cin.rdbuf(cin_buffer);
        std::cout.rdbuf(cout_buffer);
    }

    int countOccurrencesInString(const std::string& captured_string, const std::string& message) {
        int count = 0;
        int nPos = captured_string.find(message, 0);
        while (nPos != std::string::npos)
        {
            count++;
            nPos = captured_string.find(message, nPos + 1);
        }
        return count;
    }
};

TEST_F(GameControllerTest, shortGameTest)
{
    test_input.str("0\nyes\n0\nno\n");
    game.playGame();

    std::string expected_output_round =  "Enter your move";
    std::string expected_output_ask =  "Do you want to play again? (yes/no): ";
    std::string expected_output_end =  "Thanks for playing! The end result is:\n";

    EXPECT_TRUE(captured_output.str().find(expected_output_round) != std::string::npos);
    EXPECT_TRUE(captured_output.str().find(expected_output_ask) != std::string::npos);
    EXPECT_TRUE(captured_output.str().find(expected_output_end) != std::string::npos);
}

TEST_F(GameControllerTest, endScreenDispaly)
{
    test_input.str("0\nno\n");
    game.playGame();

    std::string end_screen_tie = "Thanks for playing! The end result is:\n"
                                "Player wins: 0\n"
                                "Computer wins: 0\n";
    std::string end_screen_player =  "Thanks for playing! The end result is:\n"
    "Player wins: 1\n"
    "Computer wins: 0\n";
    std::string end_screen_computer =  "Thanks for playing! The end result is:\n"
                                "Player wins: 0\n"
                                "Computer wins: 1\n";

    EXPECT_TRUE(
        captured_output.str().find(end_screen_tie) != std::string::npos ||
        captured_output.str().find(end_screen_player) != std::string::npos ||
        captured_output.str().find(end_screen_computer) != std::string::npos
    );
}

TEST_F(GameControllerTest, roundDispaly)
{
    test_input.str("0\nno\n");
    game.playGame();

    std::string round_screen_tie =  "Computer chose: Rock\n"
                                    "You chose: Rock\n"
                                    "The result of the round is: Tie\n";
    std::string round_screen_player =  "Computer chose: Scissors\n"
                                    "You chose: Rock\n"
                                    "The result of the round is: You win!\n";
    std::string round_screen_computer =  "Computer chose: Paper\n"
                                    "You chose: Rock\n"
                                    "The result of the round is: Computer wins!\n";

    EXPECT_TRUE(
        captured_output.str().find(round_screen_tie) != std::string::npos ||
        captured_output.str().find(round_screen_player) != std::string::npos ||
        captured_output.str().find(round_screen_computer) != std::string::npos
    );
}

TEST_F(GameControllerTest, PlayAgainLowerCase)
{
    test_input.str("0\nyes\n0\nno\n");
    game.playGame();

    int count = countOccurrencesInString(captured_output.str(), 
                                        "Enter your move (0 = Rock, 1 = Paper, 2 = Scissors): ");
    EXPECT_EQ(count, 2);
}

TEST_F(GameControllerTest, PlayAgainUpperCase)
{
    test_input.str("0\nYES\n0\nno\n");
    game.playGame();

    int count = countOccurrencesInString(captured_output.str(), 
                                        "Enter your move (0 = Rock, 1 = Paper, 2 = Scissors): ");
    EXPECT_EQ(count, 2);
}

TEST_F(GameControllerTest, PlayAgainMixedCase)
{
    test_input.str("0\nYeS\n0\nno\n");
    game.playGame();

    int count = countOccurrencesInString(captured_output.str(), 
                                        "Enter your move (0 = Rock, 1 = Paper, 2 = Scissors): ");
    EXPECT_EQ(count, 2);
}

TEST_F(GameControllerTest, GameLogicTest)
{
    test_input.str("0\nno\n");
    game.playGame();

    EXPECT_TRUE(
        (captured_output.str().find("Computer chose: Rock") != std::string::npos && captured_output.str().find("Tie") != std::string::npos) ||
        (captured_output.str().find("Computer chose: Scissors") != std::string::npos && captured_output.str().find("You win!") != std::string::npos) ||
        (captured_output.str().find("Computer chose: Paper") != std::string::npos && captured_output.str().find("Computer wins!") != std::string::npos)
    );
}

TEST_F(GameControllerTest, ScoreBoardTest)
{
    test_input.str("0\nno\n");
    game.playGame();

    std::string end_screen_tie =  "Thanks for playing! The end result is:\n"
                                    "Player wins: 0\n"
                                    "Computer wins: 0\n";
    std::string end_screen_player =  "Thanks for playing! The end result is:\n"
                                    "Player wins: 1\n"
                                    "Computer wins: 0\n";
    std::string end_screen_computer =  "Thanks for playing! The end result is:\n"
                                    "Player wins: 0\n"
                                    "Computer wins: 1\n";

    EXPECT_TRUE(
        (captured_output.str().find("Tie") != std::string::npos && captured_output.str().find(end_screen_tie) != std::string::npos) ||
        (captured_output.str().find("You win!") != std::string::npos && captured_output.str().find(end_screen_player) != std::string::npos) ||
        (captured_output.str().find("Computer wins!") != std::string::npos && captured_output.str().find(end_screen_computer) != std::string::npos)
    );
}
