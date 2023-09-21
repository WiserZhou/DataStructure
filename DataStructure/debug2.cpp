#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#define MAX_ARRAY 1000000
vector<string> vec;
string str1;

int a = 0, b = 0;
double c = 0;
int N = 1;
int Next[MAX_ARRAY] = {};
void getNext()
{
    Next[0] = 0;
    int i = 0, j = 0;
    // cout<<str1.length();
    while (i < str1.length())
    {
        if (j == 0 || str1[i] == str1[j])
        {
            i++;
            j++;
            if (str1[i] != str1[j])
                Next[i] = j;
            else
                Next[i] = Next[j];
        }
        else
            j = Next[j];
        // cout << "hello" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vec.push_back(str);
    }
    cin >> str1;
    getNext();
    for (const auto &s : vec)
    {
        // cout << s << endl;
        for (unsigned i = 0; i < s.length(); i++)
        {
            int k = i;
            unsigned j = 0;
            for (; j < str1.length(); j++)
            {
                if (s[k] == str1[j])
                {
                    k++;
                }
                else
                    break;
            }
            if ((double)j / str1.length() - c > 1e-6)
            {
                // cout << "j:" << j << endl;
                a = N;
                b = i + 1;
                c = (double)j / str1.length();
                // cout << a << " " << b << " ";
                // cout << fixed << setprecision(2) << c * 100 << "%" << endl;
            }
        }
        N++;
    }
    std::cout << a << " " << b << " ";
    std::cout << fixed << setprecision(2) << c * 100 << "%" << endl;
    return 0;
}