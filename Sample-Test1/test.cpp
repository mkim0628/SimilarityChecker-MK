#include "pch.h"
#include "../SimlarityChecker/SimilarityChecker.cpp"

using namespace std;

// length checker
TEST(SimilarityCheckerTest, zeroLength) {
	SimilarityChecker sc;
	int actual = sc.compareLength("", "ABC");
	EXPECT_EQ(actual, 0);
}

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
// alhpabet checker
TEST(SimilarityCheckerTest, notCapital) {
	try {
		SimilarityChecker sc;
		sc.compareAlpha("abc", "ABC");
		FAIL();
	}
	catch (exception& e){
	}
}

TEST(SimilarityCheckerTest, notCapital2) {
	try {
		SimilarityChecker sc;
		sc.compareAlpha("1", "ABC");
		FAIL();
	}
	catch (exception& e) {
	}
}

TEST(SimilarityCheckerTest, notCapital3) {
	try {
		SimilarityChecker sc;
		sc.compareAlpha("ABC", "1");
		FAIL();
	}
	catch (exception& e) {
	}
}

TEST(SimilarityCheckerTest, alphabet) {
	SimilarityChecker sc;
	int actual = sc.compareAlpha("AABAA", "ABBBAAA");
	EXPECT_EQ(actual, 40);
}

TEST(SimilarityCheckerTest, alphabet2) {
	SimilarityChecker sc;
	int actual = sc.compareAlpha("ABC", "DEF");
	EXPECT_EQ(actual,0);
}

TEST(SimilarityCheckerTest, alphabet3) {
	SimilarityChecker sc;
	int actual = sc.compareAlpha("ABC", "ADE");
	EXPECT_EQ(actual, 8);
}

TEST(SimilarityCheckerTest, alphabet4) {
	SimilarityChecker sc;
	int actual = sc.compareAlpha("ABC", "ABF");
	EXPECT_EQ(actual, 20);
}

TEST(SimilarityCheckerTest, alphabet5) {
	SimilarityChecker sc;
	int actual = sc.compareAlpha("ASD", "DSA");
	EXPECT_EQ(actual, 40);
}

TEST(SimilarityCheckerTest, alphabet6) {
	SimilarityChecker sc;
	int actual = sc.compareAlpha("AAABB", "BA");
	EXPECT_EQ(actual, 40);
}
