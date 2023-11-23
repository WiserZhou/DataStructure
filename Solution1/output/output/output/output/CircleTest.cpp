#include <iostream>
#include <string>
using namespace std;

bool canSuccess(const string &s) {
	if (s.length() < 2 || s.length() >= 15) return false;
	if (s.length() == 2) return s[0] == s[1];
	bool flag = false;
	auto begin= s.begin(), end = s.end();
	while (end - begin > 2)
	{
		if (*begin == *(begin + 1) && *begin == *(begin + 2))
		{
			string tmp1(s.begin(), begin);
			string tmp2(begin + 3, end);
			flag |= canSuccess(tmp1 + tmp2);
		}
		else if (*begin + 1 == *(begin + 1)) {
			int midSameCount = 0;
			char mid = *(begin + 1);
			auto iter = begin + 1;
			while (*iter == mid)
			{
				midSameCount++;
				if (++iter == end)
				{
					midSameCount = -1;
					break;
				}
			}
			if (midSameCount > 0 && mid + 1 == *iter) {
				string tmp1(s.begin(), begin);
				string tmp2;
				tmp2.insert(0, midSameCount - 1, mid);
				string tmp3(iter + 1, end);
				flag |= canSuccess(tmp1 + tmp2 + tmp3);
			}

		}
		++begin;
	}
	return flag;
}
int main()
{
	string input;
	getline(cin, input);
	bool flag = canSuccess(input);
	cout << (flag ? "yes" : "tenpaishimasen") << endl;
}
