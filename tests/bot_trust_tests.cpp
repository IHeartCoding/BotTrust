
#include "bot_trust.h"

#include <string>
#include <sstream>
#include <gtest/gtest.h>

TEST(BotTrust, ReadNumTests) {
    std::string line("3\n");
    std::stringstream stream(line);
    EXPECT_EQ(3, read_num_tests(stream));
}

