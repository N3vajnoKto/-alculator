#include "pch.h"
#include "../Calculator-team-8/Source.h"

TEST(firstCases, test1) {
    EXPECT_LT(unarySum(3), 5);
}

TEST(firstCases, test2) {
    EXPECT_EQ(unarySum(3), 5);
}

TEST(firstCases, test3) {
    EXPECT_LE(unarySum(3), 4);
}

TEST(firstCases, test4) {
    EXPECT_LT(unarySum(3), 4);
}
