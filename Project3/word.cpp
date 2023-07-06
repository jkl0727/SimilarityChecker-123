#include <string>
using namespace std;

class wordChecker
{
public:
	explicit wordChecker() : alpha_hash{} {}
	
	int wordCompare(const string& str1, const string& str2)
	{
		memset(alpha_hash, 0, sizeof(alpha_hash));

		int total_count = 0;
		for (auto ch : str1)
		{
			if (alpha_hash[ch - 'A'] == 0) {
				alpha_hash[ch - 'A'] = 1;
				total_count++;
			}
		}

		int same_count = 0;
		for (auto ch : str2)
		{
			if (alpha_hash[ch - 'A'] == 1) {
				same_count++;
				alpha_hash[ch - 'A']++;
			}
			else if (alpha_hash[ch - 'A'] == 0) total_count++;
		}
		return ((same_count / (float)total_count) * 40);
	}
private:
	int alpha_hash[50];
};