
#include <cstdio>
int readint()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            f = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
#define FOR_MAX 1600000000//Լ1.6��10^10��Ϊ1 second��ѭ�������