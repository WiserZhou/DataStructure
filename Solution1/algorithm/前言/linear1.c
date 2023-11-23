#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y))  // 这个地方的话，由于不会保证优先级的，需要时刻注意一下的
// 要是不加括号的话 就会是这样的  max(max(a, b), c)实际上会被展开为 ((a > b) ? a : b) > c ? ((a > b) ? a : b) : c，这并不是想要的结果

// 最大子列和问题

// 算法1  时间复杂度T(N)=O(N^3),上了三重循环。比较的容易想到，但是时间复杂度比较的高
int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for (i = 0; i < N; i++) // i记录子列左端的位置
    {
        for (j = i; j < N; j++) // j记录子列右端的位置
        {
            ThisSum = 0; // 初始化ThisSum
            for (k = i; k <= j; k++)
            {
                ThisSum += A[k]; // 计算从A[i]到A[j]的和
            }
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// 算法2  时间复杂度 T(N)=O(N^2),少了一次循环。
int MaxSubseqSum2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (j = i; j < N; j++)
        {
            ThisSum += A[j]; //  对于相同的i，不同的j，只要在j-1次循环的基础上累加一项即可
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// 算法3 时间复杂度 T(N)=O(NlogN)
int Max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxSum(int A[], int begin, int end)
{
    if (begin == end)
    {
       return max(0, A[begin]);
    }
    int mid = (begin + end) / 2;
    int max1 = maxSum(A, begin, mid);
    int max2 = maxSum(A, mid + 1, end);

    int sum1 = INT_MIN, left = 0;
    for (int i = mid; i >= begin; i--)
    {
        left += A[i];
        if (left > sum1)
            sum1 = left;
    }

    int sum2 = INT_MIN, right = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        right += A[i];
        if (right > sum2)
            sum2 = right;
    }
    int sum = sum1 + sum2;
    return Max3(sum, max1, max2);
}

int MaxSubseqSum3(int A[], int N)
{
    return maxSum(A, 0, N - 1);
}
// 算法4 时间复杂度T(N)=O(N)
int MaxSubseqSum4(int A[], int N)
{
    int ThisSum = 0, MaxSum = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main()
{
    int A[] = {-1, 3, -2, 4, -6, 1, 6, -1};
    int N = sizeof(A) / sizeof(A[0]);
    printf("%d\n", MaxSubseqSum1(A, N));
    printf("%d\n", MaxSubseqSum2(A, N));
    printf("%d\n", MaxSubseqSum3(A, N));
    printf("%d\n", MaxSubseqSum4(A, N));
    return 0;
}





// int Max3(int A, int B, int C)
// { /* 返回3个整数中的最大值 */
//     return max(max(A, B), C);
// }

// int DivideAndConquer(int List[], int left, int right)
// {                                            /* 分治法求List[left]到List[right]的最大子列和 */
//     int MaxLeftSum, MaxRightSum;             /* 存放左右子问题的解 */
//     int MaxLeftBorderSum, MaxRightBorderSum; /* 存放跨分界线的结果*/

//     int LeftBorderSum, RightBorderSum;
//     int center, i;

//     if (left == right)
//     { /* 递归的终止条件，子列只有1个数字 */
//         if (List[left] > 0)
//             return List[left];
//         else
//             return 0;
//     }

//     /* 下面是"分"的过程 */
//     center = (left + right) / 2; /* 找到中分点 */
//     /* 递归求得两边子列的最大和 */
//     MaxLeftSum = DivideAndConquer(List, left, center);  // 这两段代码就是无脑递归了，只要明白递归的原理就好了。
//     MaxRightSum = DivideAndConquer(List, center + 1, right);

//     /* 下面求跨分界线的最大子列和 */
//     MaxLeftBorderSum = 0;
//     LeftBorderSum = 0;
//     for (i = center; i >= left; i--)
//     { /* 从中线向左扫描 */
//         LeftBorderSum += List[i];
//         if (LeftBorderSum > MaxLeftBorderSum)
//             MaxLeftBorderSum = LeftBorderSum;// 大的值就赋值给左边，从而找到该分块情况下的左侧的最大值。
//     } /* 左边扫描结束 */

//     MaxRightBorderSum = 0;
//     RightBorderSum = 0;
//     for (i = center + 1; i <= right; i++)
//     { /* 从中线向右扫描 */
//         RightBorderSum += List[i];
//         if (RightBorderSum > MaxRightBorderSum)
//             MaxRightBorderSum = RightBorderSum;
//     } /* 右边扫描结束 */

//     /* 下面返回"治"的结果 */
//     return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
// }

// int MaxSubseqSum3(int List[], int N)
// { /* 保持与前2种算法相同的函数接口 */
//     return DivideAndConquer(List, 0, N - 1);
// }