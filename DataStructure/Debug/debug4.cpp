#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

void transfer(string &str)
{
    str = str.substr(0, 10);

    for (int j = 0; j < str.size(); j++)
    {
        str[j] = tolower(str[j]);
    }
}

bool Is(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(); // 清除换行符

    vector<vector<string>> vec(N);

    for (int i = 0; i < N; i++)
    {
        string str = "";
        getline(cin, str);
        // str = str.substr(0, str.size() - 1); // 去除末尾的换行符

        while (str != "#")
        {
            int pos = 0;

            for (int s = 0; s < str.size(); s++)
            {
                if ((!Is(str[s]) || s == str.size() - 1) && Is(str[s - 1]))
                {
                    if (s == str.size() - 1 && Is(str[s]))
                    {
                        s++;
                    }

                    string str1 = str.substr(pos, s - pos);
                    transfer(str1);
                    if (str1.size() >= 3 && str1.size() <= 10)
                        vec[i].push_back(str1);
                    pos = s + 1;
                }
                else if (!Is(str[s]))
                {
                    pos = s + 1;
                }
            }
            getline(cin, str);

            // str = str.substr(0, str.size() - 1); // 去除末尾的换行符
        }
    }

    int n = 0;
    cin >> n;
    cin.ignore(); // 清除换行符

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        set<string> set1;
        set<string> set2;
        set<string> set3;

        for (int j = 0; j < vec[a].size(); j++)
        {
            set1.insert(vec[a][j]);
        }

        for (int j = 0; j < vec[b].size(); j++)
        {
            set2.insert(vec[b][j]);
        }

        for (auto k = set1.begin(); k != set1.end(); k++)
        {
            auto j = set2.find(*k);
            if (j != set2.end())
            {
                num++;
            }
            set3.insert(*k);
        }

        for (auto k = set2.begin(); k != set2.end(); k++)
        {
            set3.insert(*k);
        }

        cout << fixed << setprecision(1) << num / (double)set3.size() * 100 << "%" << endl;
    }

    return 0;
}
