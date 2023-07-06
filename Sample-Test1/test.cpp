#include "pch.h"
#include "../Project3/word.cpp"

class wordFixture : public testing::Test
{
	
};

TEST(wordFixture, lengthCompare) {
	wordChecker checker;

	EXPECT_EQ(checker.lengthCompare("ASD", "DSA"), 60);
	EXPECT_EQ(checker.lengthCompare("A", "BB"), 0);
	EXPECT_EQ(checker.lengthCompare("AAABB", "BAA"), 20);
	EXPECT_EQ(checker.lengthCompare("AA", "AAE"), 30);
}