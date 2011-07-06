
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

