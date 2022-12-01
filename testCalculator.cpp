#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "functions.h"

TEST(sum, test) {
	EXPECT_EQ(sum(-1, 2), 1);
	EXPECT_NEAR(sum(-1.5, 2.0), 0.5, 0.00001);
}

TEST(sub, test) {
	EXPECT_EQ(sum(-1, 2), 1);
}