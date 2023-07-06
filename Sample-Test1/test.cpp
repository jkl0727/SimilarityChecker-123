#include "pch.h"
#include "../Project3/word.cpp"

class wordFixture : public testing::Test
{
public:
	wordChecker checker{};
};

TEST_F(wordFixture, CompareAlpha) {
	EXPECT_EQ(checker.wordCompare("ASD", "DSA"), 40);
	EXPECT_EQ(checker.wordCompare("A", "B"), 0);
	EXPECT_EQ(checker.wordCompare("AAABB", "BA"), 40);
	EXPECT_EQ(checker.wordCompare("AA", "AAE"), 20);
}

TEST_F(wordFixture, lengthCompare) {
	EXPECT_EQ(checker.lengthCompare("ASD", "DSA"), 60);
	EXPECT_EQ(checker.lengthCompare("A", "BB"), 0);
	EXPECT_EQ(checker.lengthCompare("AAABB", "BAA"), 20);
	EXPECT_EQ(checker.lengthCompare("AA", "AAE"), 30);
}