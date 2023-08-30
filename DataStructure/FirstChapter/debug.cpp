#include <iostream>
using namespace std;
int maxTri(int a, int b, int c)
{
    a = a > b ? a : b;
    a = a > c ? a : c;
    return a;
}
int maxSum(int data[], int first, int end)
{
    if (first == end)
        return data[first];
    int mid = (first + end) / 2;
    int sumLeft = maxSum(data, first, mid);
    int sumRight = maxSum(data, mid + 1, end);

    int sum1 = 0, left = 0;
    for (int i = mid; i >= first; i--)
    {
        left += data[i];
        if (left > sum1)
            sum1 = left;
    }
    int sum2 = 0, right = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        right += data[i];
        if (right > sum2)
            sum2 = right;
    }
    int sum = sum1 + sum2;

    return maxTri(sum, sumLeft, sumRight);
}

int main()
{
    int data[] = {-3, 23, 3, -23, -1, 23, -2, 3};
    printf("max value: %d", maxSum(data, 0, sizeof(data) / sizeof(int) - 1));
    return 0;
}
