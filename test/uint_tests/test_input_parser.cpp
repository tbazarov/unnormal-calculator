#include <gtest/gtest.h>
#include "InputParser.h"

TEST(InputParserTest, ValidInput) {
    std::vector<std::string> lines = {
        "16: \"FF\"",
        "10: \"15\"",
        "2"
    };
    InputData data = InputParser::parseInput(lines);
    EXPECT_EQ(data.baseA, 16);
    EXPECT_EQ(data.numberA, "FF");
    EXPECT_EQ(data.baseB, 10);
    EXPECT_EQ(data.numberB, "15");
    EXPECT_EQ(data.baseC, 2);
}

TEST(InputParserTest, EmptyLines) {
    std::vector<std::string> lines = {
        "",
        "16: \"A\"",
        "",
        "10: \"10\"",
        "",
        "8"
    };
    InputData data = InputParser::parseInput(lines);
    EXPECT_EQ(data.baseA, 16);
    EXPECT_EQ(data.numberA, "A");
}