#include <gtest/gtest.h>
#include "NumberSystemConverter.h"

TEST(NumberConverterTest, BasicConversion) {
    EXPECT_EQ(NumberSystemConverter::convertBase("10", 2, 10), "2");
    EXPECT_EQ(NumberSystemConverter::convertBase("FF", 16, 10), "255");
    EXPECT_EQ(NumberSystemConverter::convertBase("255", 10, 16), "FF");
}

TEST(NumberConverterTest, AdditionTest) {
    std::string result = NumberSystemConverter::addNumbers("FF", 16, "1", 16, 16);
    EXPECT_EQ(result, "100");
}

TEST(NumberConverterTest, ValidationTest) {
    EXPECT_TRUE(NumberSystemConverter::isValidNumber("101", 2));
    EXPECT_FALSE(NumberSystemConverter::isValidNumber("102", 2));
}