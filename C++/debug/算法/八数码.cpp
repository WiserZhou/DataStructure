#include <bits/stdc++.h>
using namespace std;

string s1, s2, q[1000001];

int k, st[1000001], pd[1000001];
int gh[4] = {-3, -1, 1, 3};

map<string, int> p;

int main()
{
	cin >> s1;
	s1 = " " + s1;
	p[s1] = 1;
	s2 = " 123804765";
	/*
	0 1 2
	3 4 5
	6 7 8
	*/
	int t = 2, h = 1;
	q[1] = s1;
	st[1] = 0;
	pd[1] = 0;
	while (h < t)
	{
		for (int i = 1; i <= 9; i++)
			if (q[h][i] == '0')
			{
				k = i;
				break;
			}
		for (int i = 0; i < 4; i++)
		{
			int kk = k + gh[i];

			if (kk <= 0 || kk > 9 || gh[i] == -1 && k % 3 == 1 || gh[i] == 1 && k % 3 == 0 || pd[h] == -gh[i])
				continue;

			q[t] = q[h];

			char c;
			c = q[t][k];
			q[t][k] = q[t][kk];
			q[t][kk] = c;

			if (p[q[t]] == 1)
				continue;

			p[q[t]] = 1;
			st[t] = st[h] + 1;
			pd[t] = gh[i];
			if (q[t] == s2)
			{
				cout << st[t] << endl;
				return 0;
			}
			t++;
		}
		h++;
	}
	cout << 0 << endl;
	return 0;
}
/*
	603712458
	23
*/
