#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "functions.h"

 TEST(expression, format) {
	EXPECT_ANY_THROW(solution<double>("()")); 
    EXPECT_ANY_THROW(solution<double>("(1"));
    EXPECT_ANY_THROW(solution<double>("("));
    EXPECT_ANY_THROW(solution<double>(""));
    EXPECT_ANY_THROW(solution<double>(")"));
    EXPECT_ANY_THROW(solution<double>("(1 + 3"));
    EXPECT_ANY_THROW(solution<double>("(1 + )3 + 4"));
    EXPECT_ANY_THROW(solution<double>("(1 + ((3 + 4)"));
    EXPECT_ANY_THROW(solution<double>("2 ** 2 ***3"));
	EXPECT_NEAR(solution<double>("(1)"), 1.0, 0.00001);
	EXPECT_NEAR(solution<double>("1 + 2 3"), 7.0, 0.00001);
	EXPECT_NEAR(solution<double>("(1 + 2)(3 + 4) (4+1)"), 105.0, 0.00001);
	EXPECT_NEAR(solution<double>("(1 + 2)7 (4+1)"), 105.0, 0.00001);
	EXPECT_NEAR(solution<double>("(1 + 2)(3 + 4)5"), 105.0, 0.00001);
	EXPECT_NEAR(solution<double>("7 (1   + 2)  / 7   * 5"), 15.0, 0.00001);
	EXPECT_NEAR(solution<double>("4"), 4.0, 0.00001);
	EXPECT_NEAR(solution<double>("2 + 2 * 2"), 6.0, 0.00001);
	EXPECT_NEAR(solution<double>("2 ** 2 ** 3"), 256.0, 0.00001);
}