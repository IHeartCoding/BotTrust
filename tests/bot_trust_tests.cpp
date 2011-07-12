
#include "bot_trust.h"

#include <string>
#include <sstream>
#include <gtest/gtest.h>

TEST(BotTrust, ReadNumTests) {
    std::string line("3\n");
    std::stringstream stream(line);
    EXPECT_EQ(3, read_num_tests(stream));
}

TEST(BotTrust, ReadOneStep) {
    std::string line("1 O 2");
    std::stringstream stream(line);
    std::vector<Step> steps;

    read_steps(stream, steps);

    EXPECT_EQ(1, steps.size());
    EXPECT_EQ(ORANGE, steps[0].robot);
    EXPECT_EQ(2, steps[0].button);
}

TEST(BotTrust, ReadTwoSteps) {
    std::string line("2 O 2 B 3");
    std::stringstream stream(line);
    std::vector<Step> steps;

    read_steps(stream, steps);

    EXPECT_EQ(2, steps.size());
    if (steps.size() >= 2)
    {
        EXPECT_EQ(ORANGE, steps[0].robot);
        EXPECT_EQ(2, steps[0].button);
        EXPECT_EQ(BLUE, steps[1].robot);
        EXPECT_EQ(3, steps[1].button);
    }
}

/**
 * Only ORANGE needs to move.
 * Moving from 1 to 2 takes 1 seconds and then takes 1 second to push the button.
 */
TEST(BotTrust, SolveOneOrange) {
    std::vector<Step> steps;
    Step step1 = { ORANGE, 2 };
    steps.push_back(step1);

    EXPECT_EQ(2, solve_test(steps));
}

/**
 * Only ORANGE is moving so no concurrent move can happen.
 * Moving from 1 to 2 takes 1 second and then takes 1 second to push the button.
 * Moving from 2 to 4 takes 2 seconds and then takes 1 second to push the button.
 */
TEST(BotTrust, SolveTwoOrange) {
    std::vector<Step> steps;
    Step step1 = { ORANGE, 2 };
    steps.push_back(step1);
    Step step2 = { ORANGE, 4 };
    steps.push_back(step2);

    EXPECT_EQ(2 + 3, solve_test(steps));
}

/**
 * Only ORANGE is moving so no concurrent move can happen.
 * Moving from 1 to 5 takes 4 second and then takes 1 second to push the button.
 * Moving from 5 to 2 takes 3 seconds and then takes 1 second to push the button.
 */
TEST(BotTrust, SolveTwoOrangeBackwards) {
    std::vector<Step> steps;
    Step step1 = { ORANGE, 5 };
    steps.push_back(step1);
    Step step2 = { ORANGE, 2 };
    steps.push_back(step2);

    EXPECT_EQ(5 + 4, solve_test(steps));
}

