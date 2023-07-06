#include <string>
using namespace std;

class wordChecker
{
public:
	int lengthCompare(const string &str1, const string &str2)
	{
		int gab = 0;
		int short_len = 0;
		if (str1.length() > str2.length()) {
			gab = str1.length() - str2.length();
			short_len = str2.length();
			}
		else {
			gab = str2.length() - str1.length();
			short_len = str1.length();
		}
		int score = roundf((1 - ((float)gab / short_len)) * 60);
		return score;
	}
};