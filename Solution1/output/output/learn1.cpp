#include <iostream>
using namespace std;
#include <algorithm>
#define N 100001
int main()
{
    int n;
    cin >> n;
    int a[N] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = a[0],result = 0;
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    if (max == a[n - 1])
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            num += a[i];
        }
        result = n * num;
    }
    else
    {
        for (; flag == true; n--)
        {
            while (a[n - 1] != 0)
            {
                int num = 0;
                for (int i = n - 1; i >= 0; i--)
                {
                    if (a[i] != 0)
                    {
                        num++;
                        a[i]--;
                    }
                }
                result += n * num;
            }
            if (n == 1)
                flag = false;
        }
    }
    cout << result;
    return 0;
}
