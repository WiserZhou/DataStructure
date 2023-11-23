#include <stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
#define Max_l 1000
#define Num 100

int main()
{
    int num;
    cin >> num;
    int i, max_l = 0;
    string s[Num];
    for (i = 0; i < num; i++)
    {
        cin >> s[i];
        if (s[i].length() > max_l)
            max_l = s[i].length();
    }
    string ans;
    cin >> ans;
    int a[Num][Max_l] = {0};
    for (i = 0; i < num; i++)
    {
        for (int j = 0; j < s[i].length(); j++)
        {
            int cnt = 0;
            int b;
            for (b = j; cnt < ans.length() && b < s[i].length(); b++)
            {
                if (s[i][b] == ans[cnt])
                {
                    cnt++;
                    a[i][j] = cnt;
                }
                else
                {
                    break;
                }
            }
        }
    }
    int max1 = 0, max2 = 0, max_ans = 0;
    for (i = 0; i < num; i++)
    {
        for (int j = 0; j < max_l; j++)
        {
            if (a[i][j] > max_ans)
            {
                max_ans = a[i][j];
                max1 = i;
                max2 = j + 1;
            }
        }
    }
    if (max_ans != 0)
    {
        double gd = ((double)max_ans / ans.length()) * 100.0;
        printf("%d %d %.2lf%%", max1 + 1, max2, gd);
    }
    else
    {
        printf("0 0 0.00%%");
    }
}
