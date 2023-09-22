#include <iostream>
#include <string>
using namespace std;
#define MAX_ARRAY 100
int main()
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    int Next[MAX_ARRAY] = {0};
    unsigned i = 0, j = 0;
    while (j < str2.length() && i < str2.length())
    {
        if (str2[i] == str2[j])
        {
            i++;
            j++;
        }
        else
            j = Next[j];
    }
    

    unsigned i = 0, j = 0;

    while (i < str1.length() && j < str2.length())
    {
        if (str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = Next[j];
        }
    }
}