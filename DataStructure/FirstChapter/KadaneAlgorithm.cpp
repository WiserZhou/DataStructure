#include <iostream>
using namespace std;

int MAX_N = 8;
//  Kadane's Algorithm
int maxSubArrayAns(int nums[])
{
    int i, thisSum = 0, maxSum = 0;
    for (i = 0; i < MAX_N - 1; i++)
    {
        thisSum += nums[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }

    return maxSum;
}

int main()
{
    int data[] = {-3, 23, 3, -23, -1, 23, -2, 3};
    printf("max value: %d", maxSubArrayAns(data));
    return 0;
}
