#include <string>
using namespace std;

class wordChecker
{
public:
	explicit wordChecker() : alpha_hash{} {}

	void makehash(const string& str1, int& total_count)
	{
		memset(alpha_hash, 0, sizeof(alpha_hash));
		for (auto ch : str1)
		{
			if (alpha_hash[ch - 'A'] == 0) {
				alpha_hash[ch - 'A'] = 1;
				total_count++;
			}
		}
	}

	void countSameWord(const string& str2, int& total_count, int& same_count)
	{
		for (auto ch : str2)
		{
			if (alpha_hash[ch - 'A'] == 1) {
				same_count++;
				alpha_hash[ch - 'A']++;
			}
			else if (alpha_hash[ch - 'A'] == 0) total_count++;
		}
	}

	int wordCompare(const string& str1, const string& str2)
	{
		int total_count = 0;
		int same_count = 0;
		makehash(str1, total_count);
		countSameWord(str2, total_count, same_count);
		return ((same_count / (float)total_count) * 40);
	}
  
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
		
		return roundf((1 - ((float)gab / short_len)) * 60);
	}
 
private:
	int alpha_hash[50];
};