#include <iostream>
using namespace std;

class SimilarityChecker {
public:
	
	SimilarityChecker() : totalScore{ 0 }, appearAlpha{ {0} }, totalCnt{ 0 }, sameCnt{ 0 } {};
	
	int compareLength(string str1, string str2) {
		if (str1.length() > str2.length()) {
			longStrLength = str1.length();
			shortStrLength = str2.length();
		}
		else {
			longStrLength = str2.length();
			shortStrLength = str1.length();
		}

		if (shortStrLength == longStrLength)
			return LENGTH_SCORE_MAX;
		if (longStrLength >= shortStrLength * 2)
			return LENGTH_SCORE_MIN;
		
		int score = (float)(2 * shortStrLength - longStrLength) / (float)shortStrLength * LENGTH_SCORE_MAX;
		totalScore += score;
		return score;
	}

	int compareAlpha(string str1, string str2) {
		for (auto ch : str1) {
			checkInvalidCharacter(ch);
			calTotalCount(ch);
		}
		for (auto ch : str2) {
			checkInvalidCharacter(ch);
			calSameCount(ch);
			calTotalCount(ch);
		}
		int score = sameCnt * ALPHA_SCORE_MAX / totalCnt;
		totalScore += score;
		return score;
	}
	
private:
	void checkInvalidCharacter(char ch)
	{
		if (!(ch >= 'A' && ch <= 'Z'))
			throw invalid_argument("String should consist of capital letters.");
	}
	
	void calSameCount(char ch)
	{
		if (appearAlpha[ch - 'A'] == 1)
			sameCnt++;
	}
	
	void calTotalCount(char ch)
	{
		if (appearAlpha[ch - 'A'] == 0) {
			appearAlpha[ch - 'A'] = 1;
			totalCnt++;
		}
	}

	const int LENGTH_SCORE_MAX = 60;
	const int LENGTH_SCORE_MIN = 0;
	const int ALPHA_SCORE_MAX = 40;
	const int ALPHA_SCORE_MIN = 0;
	const static int NUM_OF_ALPHABET = 26;

	int totalScore;
	int shortStrLength;
	int longStrLength;
	int appearAlpha[NUM_OF_ALPHABET] ;
	int totalCnt;
	int sameCnt;
};