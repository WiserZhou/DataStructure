#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y))  // ����ط��Ļ������ڲ��ᱣ֤���ȼ��ģ���Ҫʱ��ע��һ�µ�
// Ҫ�ǲ������ŵĻ� �ͻ���������  max(max(a, b), c)ʵ���ϻᱻչ��Ϊ ((a > b) ? a : b) > c ? ((a > b) ? a : b) : c���Ⲣ������Ҫ�Ľ��

// ������к�����

// �㷨1  ʱ�临�Ӷ�T(N)=O(N^3),��������ѭ�����Ƚϵ������뵽������ʱ�临�ӶȱȽϵĸ�
int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for (i = 0; i < N; i++) // i��¼������˵�λ��
    {
        for (j = i; j < N; j++) // j��¼�����Ҷ˵�λ��
        {
            ThisSum = 0; // ��ʼ��ThisSum
            for (k = i; k <= j; k++)
            {
                ThisSum += A[k]; // �����A[i]��A[j]�ĺ�
            }
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// �㷨2  ʱ�临�Ӷ� T(N)=O(N^2),����һ��ѭ����
int MaxSubseqSum2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (j = i; j < N; j++)
        {
            ThisSum += A[j]; //  ������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�һ���
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// �㷨3 ʱ�临�Ӷ� T(N)=O(NlogN)
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
// �㷨4 ʱ�临�Ӷ�T(N)=O(N)
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
// { /* ����3�������е����ֵ */
//     return max(max(A, B), C);
// }

// int DivideAndConquer(int List[], int left, int right)
// {                                            /* ���η���List[left]��List[right]��������к� */
//     int MaxLeftSum, MaxRightSum;             /* �������������Ľ� */
//     int MaxLeftBorderSum, MaxRightBorderSum; /* ��ſ�ֽ��ߵĽ��*/

//     int LeftBorderSum, RightBorderSum;
//     int center, i;

//     if (left == right)
//     { /* �ݹ����ֹ����������ֻ��1������ */
//         if (List[left] > 0)
//             return List[left];
//         else
//             return 0;
//     }

//     /* ������"��"�Ĺ��� */
//     center = (left + right) / 2; /* �ҵ��зֵ� */
//     /* �ݹ�����������е����� */
//     MaxLeftSum = DivideAndConquer(List, left, center);  // �����δ���������Եݹ��ˣ�ֻҪ���׵ݹ��ԭ��ͺ��ˡ�
//     MaxRightSum = DivideAndConquer(List, center + 1, right);

//     /* �������ֽ��ߵ�������к� */
//     MaxLeftBorderSum = 0;
//     LeftBorderSum = 0;
//     for (i = center; i >= left; i--)
//     { /* ����������ɨ�� */
//         LeftBorderSum += List[i];
//         if (LeftBorderSum > MaxLeftBorderSum)
//             MaxLeftBorderSum = LeftBorderSum;// ���ֵ�͸�ֵ����ߣ��Ӷ��ҵ��÷ֿ�����µ��������ֵ��
//     } /* ���ɨ����� */

//     MaxRightBorderSum = 0;
//     RightBorderSum = 0;
//     for (i = center + 1; i <= right; i++)
//     { /* ����������ɨ�� */
//         RightBorderSum += List[i];
//         if (RightBorderSum > MaxRightBorderSum)
//             MaxRightBorderSum = RightBorderSum;
//     } /* �ұ�ɨ����� */

//     /* ���淵��"��"�Ľ�� */
//     return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
// }

// int MaxSubseqSum3(int List[], int N)
// { /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
//     return DivideAndConquer(List, 0, N - 1);
// }