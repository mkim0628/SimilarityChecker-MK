#include <iostream>
using namespace std;

class SimilarityChecker {
public:
	const int LENGTH_SCORE_MAX = 60;
	const int LENGTH_SCORE_MIN = 0;
	
	int compareLength(string str1, string str2) {
		calShortLength(str1, str2);
		if (shortStrLength == longStrLength)
			return LENGTH_SCORE_MAX;
		if (longStrLength >= shortStrLength * 2)
			return LENGTH_SCORE_MIN;
		return (float)(2 * shortStrLength - longStrLength) / (float)shortStrLength * LENGTH_SCORE_MAX;
	}
private:
	void calShortLength(string str1, string str2) {
		if (str1.length() > str2.length()) {
			longStrLength = str1.length();
			shortStrLength = str2.length();
		}
		else {
			longStrLength = str2.length();
			shortStrLength = str1.length();
		}
	}
	int shortStrLength;
	int longStrLength;

};