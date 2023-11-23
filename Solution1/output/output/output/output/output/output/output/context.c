#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define N 100001
int main()
{
    int n, arr[N], sum = 0, tosum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int max = arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    if (max == arr[n - 1])
        printf("%d", n * sum);
    else
    {
       for(int i=n-1;i>=0;i--){
         
       }
        }
    }
    printf("%d", tosum);

    return 0;
}