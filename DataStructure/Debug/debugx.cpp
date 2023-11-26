#include <iostream>
using namespace std;
#include "../header/unity.h"
typedef char InfoType;
#define MAXSIZE 1000 // 待排顺序表最大长度
typedef int KeyType; // 关键字类型为整数类型
typedef struct
{
    KeyType key;    // 关键字项
    InfoType *info; // 其它数据项
} RcdType;          // 记录类型 Record Type
typedef struct
{
    RcdType r[MAXSIZE + 1]; // r[0]闲置
    int length;             // 顺序表长度
} SqList;                   // 顺序表类型

void Merge(RcdType SR[], RcdType TR[], int left, int middle, int right)
{
    int index1, index2, index_merged = left;

    // 初始化 index2 为第二个有序子序列的起始位置，index_merged 为新序列的起始位置
    for (index1 = left, index2 = middle + 1; index1 <= middle && index2 <= right;)
    {
        // 比较两个子序列的元素，将较小（或较大）的元素放入新序列
        if (LQ(SR[index1].key, SR[index2].key))
            TR[index_merged++] = SR[index1++];
        else
            TR[index_merged++] = SR[index2++];
    }

    // 处理剩余的元素，如果第一个子序列还有剩余
    if (index1 <= middle)
        while (index_merged <= right && index1 <= middle)
            TR[index_merged++] = SR[index1++];

    // 如果第二个子序列还有剩余
    if (index2 <= right)
        while (index_merged <= right && index2 <= right)
            TR[index_merged++] = SR[index2++];

    // 将已经排序好的再次赋值回去
    index_merged = left;
    while (left <= right)
        SR[left++] = TR[index_merged++];

} // Merge

/**
 * 如果存在i+2l-1小于等于n的情况，说明前面有满足两个序列的条件，那么就while归并
 * 如果没有了，那么继续判断是否有满足一个序列的条件，如果有的话，将这个序列与剩下的序列继续归并
 * 如果连一个序列的条件都不满足，那么一定是有序的，直接赋值即可
 */
void M_sort_non_recursive(RcdType A[], RcdType B[], int n, int l)
{
    int i = 1;
    while (i + 2 * l - 1 <= n)
    {
        Merge(A, B, i, i + l - 1, i + 2 * l - 1);
        i = i + 2 * l;
    }
    if (i + l - 1 < n)
        Merge(A, B, i, i + l - 1, n);
    else
        for (int t = i; t <= n; t++)
            B[t] = A[t];
}

void MergeSort_non_recursive(RcdType A[], int n)
{
    // 再封装,对表 L进行非递归的2-路归并排序
    int l = 1;
    RcdType B[MAXSIZE];
    while (l < n)
    {
        M_sort_non_recursive(A, B, n, l);
        l = 2 * l;
    }
}

int main()
{

    SqList L;
    int a[5] = {1, 3, 2, 5, 4};
    for (int i = 1; i <= 5; i++)
    {
        L.r[i].key = a[i - 1];
    }
    L.length = 5;
    MergeSort_non_recursive(L.r, 5);
    for (int i = 1; i <= 5; i++)
    {
        cout << L.r[i].key << " ";
    }
}