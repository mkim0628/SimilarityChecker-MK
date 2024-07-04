#include "pch.h"
#include "../SimlarityChecker/SimilarityChecker.cpp"

using namespace std;

TEST(SimilarityCheckerTest, sameLength) {
	SimilarityChecker sc;
	int actual = sc.compareLength("ABC", "ABC");
	EXPECT_EQ(actual, 60);
}
TEST(SimilarityCheckerTest, doubleLength) {
	SimilarityChecker sc;
	int actual = sc.compareLength("ABC", "ABCXYZ");
	EXPECT_EQ(actual, 0);
}

TEST(SimilarityCheckerTest, partiallySame) {
	SimilarityChecker sc;
	int actual = sc.compareLength("ABC", "AB");
	EXPECT_EQ(actual, 30);

	actual = sc.compareLength("ABCDE", "XYZ");
	EXPECT_EQ(actual, 20);
}