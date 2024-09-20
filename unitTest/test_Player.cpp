#include <gtest/gtest.h>
#include <string>

#include "Player.hpp"

#define RANDOM_TEST_RUN_LENGHT 100

class PlayerTest : public ::testing::Test
{
protected:
    Player human_player;
    Player computer_player;

    void SetUp() override
    {
        human_player = Player(Player::PlayerType::Human);
        computer_player = Player(Player::PlayerType::Computer);
    }

    std::map<Move, int> countsMoves(int n)
    {
        std::map<Move, int> moveCounts = {
            {Move::Rock, 0},
            {Move::Paper, 0},
            {Move::Scissors, 0}};

        for (int i = 0; i < n; ++i)
        {
            Move move = computer_player.getMove();
            moveCounts[move]++;
        }
        return moveCounts;
    }
};

TEST_F(PlayerTest, HumanPlayerInitialization)
{
    EXPECT_EQ(human_player.isHuman(), true);
}

TEST_F(PlayerTest, ComputerPlayerInitialization)
{
    EXPECT_EQ(computer_player.isHuman(), false);
}

TEST_F(PlayerTest, AddWin)
{
    EXPECT_EQ(human_player.getNumberOfWins(), 0);
    human_player.addWin();
    EXPECT_EQ(human_player.getNumberOfWins(), 1);
}

TEST_F(PlayerTest, ReachMaxNumberOfWins)
{
    EXPECT_EQ(human_player.getNumberOfWins(), 0);
    for (int i = 0; i < MAX_WINS; ++i)
    {
        ASSERT_TRUE(human_player.addWin());
    }
    EXPECT_EQ(human_player.getNumberOfWins(), MAX_WINS);

    EXPECT_FALSE(human_player.addWin());
    EXPECT_EQ(human_player.getNumberOfWins(), MAX_WINS);
}

TEST_F(PlayerTest, ComputerMoveTest)
{
    std::set<Move> moves;

    for (int i = 0; i < RANDOM_TEST_RUN_LENGHT; i++) {
        moves.insert(computer_player.getMove());
        if(moves.size() == 3) break;
    }

    EXPECT_EQ(moves.size(), 3);
    EXPECT_TRUE(moves.find(Move::Rock) != moves.end());
    EXPECT_TRUE(moves.find(Move::Paper) != moves.end());
    EXPECT_TRUE(moves.find(Move::Scissors) != moves.end());
}

TEST_F(PlayerTest, IsComputerMoveRandom)
{
    std::map<Move, int> run1 = countsMoves(RANDOM_TEST_RUN_LENGHT);
    std::map<Move, int> run2 = countsMoves(RANDOM_TEST_RUN_LENGHT);
    std::map<Move, int> run3 = countsMoves(RANDOM_TEST_RUN_LENGHT);

    EXPECT_TRUE(run1 != run2);
    EXPECT_TRUE(run2 != run3);
    EXPECT_TRUE(run1 != run3);
}

TEST_F(PlayerTest, HumanMovePromptIsPrinted)
{
    std::stringstream captured_output;
    std::streambuf *cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());

    std::istringstream test_input("0");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(test_input.rdbuf());

    human_player.getMove();

    std::cout.rdbuf(cout_buffer);
    std::cin.rdbuf(cin_buffer);

    std::string expected_output = "Enter your move (0 = Rock, 1 = Paper, 2 = Scissors): ";
    EXPECT_EQ(captured_output.str(), expected_output);
}

TEST_F(PlayerTest, RockInput) {
    std::istringstream test_input("0");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(test_input.rdbuf());

    Move move = human_player.getMove();

    std::cin.rdbuf(cin_buffer);

    EXPECT_EQ(move, Move::Rock);
}

TEST_F(PlayerTest, PaperInput) {
    std::istringstream test_input("1");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(test_input.rdbuf());

    Move move = human_player.getMove();

    std::cin.rdbuf(cin_buffer);

    EXPECT_EQ(move, Move::Paper);
}

TEST_F(PlayerTest, ScissorsInput) {
    std::istringstream test_input("2");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(test_input.rdbuf());

    Move move = human_player.getMove();

    std::cin.rdbuf(cin_buffer);

    EXPECT_EQ(move, Move::Scissors);
}

TEST_F(PlayerTest, EmptyInput) {
    std::istringstream empty_input("\n 1\n");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(empty_input.rdbuf());

    std::stringstream captured_output;
    std::streambuf *cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());

    Move move = human_player.getMove();

    std::cin.rdbuf(cin_buffer);
    std::cout.rdbuf(cout_buffer);

    std::string expected_output = "No input detected. Please enter a number (0 = Rock, 1 = Paper, 2 = Scissors): ";

    std::cout << captured_output.str();
    EXPECT_TRUE(captured_output.str().find(expected_output) != std::string::npos);
}

TEST_F(PlayerTest, InvalidChoiceInput) {
    std::istringstream empty_input("3\n 1\n");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(empty_input.rdbuf());

    std::stringstream captured_output;
    std::streambuf *cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());

    Move move = human_player.getMove();

    std::cin.rdbuf(cin_buffer);
    std::cout.rdbuf(cout_buffer);

    std::string expected_output =  "Invalid choice. Please enter (0 = Rock, 1 = Paper, 2 = Scissors): ";

    std::cout << captured_output.str();
    EXPECT_TRUE(captured_output.str().find(expected_output) != std::string::npos);
}

TEST_F(PlayerTest, InvalidArgumentInput) {
    std::istringstream empty_input("this is not a number\n 1\n");
    std::streambuf* cin_buffer = std::cin.rdbuf();
    std::cin.rdbuf(empty_input.rdbuf());

    std::stringstream captured_output;
    std::streambuf *cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());

    Move move = human_player.getMove();

    std::cin.rdbuf(cin_buffer);
    std::cout.rdbuf(cout_buffer);

    std::string expected_output =  "Invalid input. Please enter a number (0 = Rock, 1 = Paper, 2 = Scissors): ";

    std::cout << captured_output.str();
    EXPECT_TRUE(captured_output.str().find(expected_output) != std::string::npos);
}