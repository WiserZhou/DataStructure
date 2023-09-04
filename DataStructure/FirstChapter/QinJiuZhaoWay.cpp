#include <iostream>

#define OK 1
using namespace std;

// 秦九韶法 f(x) = a0 + x(a1 +x(a2+x(...))=ao+a1x+a2x^2+a3x^3+...

double f(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}
int main()
{
    double a[4] = {1, 2, 3, 4};
    cout << f(4, a, 3);
    return 0;
}



// 分治法求解最大子列和问题
