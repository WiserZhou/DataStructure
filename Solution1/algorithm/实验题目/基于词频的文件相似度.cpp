#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

int N;
set<string> v[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        do
        {
            cin >> str;
            if (str == "#")
                continue;
            for (int j = 0; str[j]; ++j)
            {
                if (isupper(str[j]))
                    str[j] = str[j] - 'A' + 'a';
                if (!(isupper(str[j]) || islower(str[j])))
                {
                    str[j] = ' ';
                }
            }
            stringstream ss;
            ss << str;
            while (ss >> str)
            {
                if (str.length() > 10)
                {
                    str = str.erase(10);
                    v[i + 1].insert(str);
                }
                else if (str.length() > 2)
                {
                    v[i + 1].insert(str);
                }
            }

        } while (str != "#");
    }
    int K;
    cin >> K;
    set<string> sc;
    for (int i = 0; i < K; ++i)
    {
        int a, b, same = 0;
        cin >> a >> b;
        for (const auto &item : v[a])
        {
            if (v[b].count(item))
            {
                same++;
            }
        }
        cout << fixed << setprecision(1) << same * 100.0 / (v[a].size() + v[b].size() - same) << "%\n";
        sc.clear();
    }
    return 0;
}