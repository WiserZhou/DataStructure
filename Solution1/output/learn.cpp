#include <bits/stdc++.h>
using namespace std;

char c;
map<char, int> vis;
int maxx = 0, minx = 0x3fffffff;
bool judge(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); ++i)
        if (!(n % i))
            return 0;
    return 1;
}
int main()
{
    while ((c = getchar()) != '\n')
        vis[c]++;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        if (vis[ch])
        {
            maxx = max(maxx, vis[ch]);
            minx = min(minx, vis[ch]);
        }
    if (!judge(maxx - minx))
        printf("No Answer\n0");
    else
        printf("Lucky Word\n%d", maxx - minx);

    return 0;
}