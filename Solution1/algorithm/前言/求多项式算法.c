#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAXN 100

// 秦九韶多项式算法
double fun1(int n, double *a, double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}

// 一般算法
double fun2(int n, double *a, double x)
{
    double p = a[0];
    int i;
    for (i = 1; i <= n; i++)
    {
        p += a[i] * pow(x, i);
    }
    return p;
}
clock_t start, stop;
  double duration;
int main()
{
    int i;
    double a[MAXN];
    start = clock();
    for (i = 0; i < MAXN; i++)
        a[i] = i;
    double p = fun2(MAXN, a, 1);
    stop = clock();
    printf("%.2f\n", p);
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("%ld\n", start);
    printf("%ld\n", stop);
    printf("%.2f", duration);
    return 0;
}