#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int ratio, index, flag = 0;

    while (scanf("%d %d", &ratio, &index) != EOF)
    {
        if (index)
        {
            if (flag)
                printf(" ");
            flag = 1;
            printf("%d %d", ratio * index, index - 1);
        }
    }
    if (!flag)
        printf("0 0");

    return 0;
}
