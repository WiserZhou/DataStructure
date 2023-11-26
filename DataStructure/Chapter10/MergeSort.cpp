typedef char InfoType;
#include "../header/unity.h"
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

/**
 * 归并排序
 * i：表示当前子序列的起始位置（左边界）。
 * m：表示当前子序列的中间位置，即第一个有序子序列的结束位置。
 * n：表示当前子序列的结束位置（右边界），也是第二个有序子序列的结束位置。
 * SR中存有两个有序子序列
 */
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
    index_merged = 0;
    while (left <= right)
        SR[left++] = TR[index_merged++];
} // Merge

/**
 * 递归的2-路归并排序算法
 * 参数 SR 是原始数组
 * TR 是临时数组用于存储中间结果
 * s 和 t 表示当前需要排序的子数组的起始和结束索引。
 */
void M_sort(RcdType SR[], RcdType *TR, int s, int t)
{
    // 将SR[s..t] 归并排序为 TR[s..t]
    if (s == t)
        TR[s] = SR[s]; // 如果长度为1，直接赋值，递归结束
    else
    {

        int m = (s + t) / 2;      // 将SR[s..t]平分为SR[s..m]和SR[m+1..t]
        M_sort(SR, TR, s, m);     // 递归地将SR[s..m]归并为有序的TR[s..m]
        M_sort(SR, TR, m + 1, t); // 递归地SR[m+1..t]归并为有序的TR[m+1..t]
        Merge(SR, TR, s, m, t);   // 将TR[s..m]和TR[m+1..t]归并到TR[s..t]
    }
}

void MergeSort(SqList &L)
{                                            // 再封装,对表 L 进行2-路归并排序
    RcdType *TR = new RcdType[L.length + 1]; // 创建临时数组TR用于存储中间结果
    M_sort(L.r, TR, 1, L.length); // 调用递归的归并排序算法
    delete[] TR;                  // 释放临时数组的内存
} // MergeSort

void M_sort(RcdType A[], RcdType B[], int n, int l)
{
    int i = 1, t;
    while (i + 2 * l - 1 <= n)
    {
        Merge(A, B, i, i + l - 1, i + 2 * l - 1);
        i = i + 2 * l;
    }
    if (i + l - 1 < n)
        Merge(A, B, i, i + l - 1, n);
    else
        for (t = i; t <= n; t++)
            B[t] = A[t];
}

void MergeSort(RcdType A[], int n)
{
    // 再封装,对表 L进行非递归的2-路归并排序
    int l = 1;
    RcdType B[MAXSIZE];
    while (l < n)
    {
        M_sort(A, B, n, l);
        l = 2 * l;
        if (l >= n)
            break;
        M_sort(B, A, n, l);
        l = 2 * l;
    }
}
// #include "../header/Queue.h"
void radixsort(int figure, QUEUE &A)
{ // 关键字链表用队列存储
    QUEUE Q[10];
    records data;
    int pass, r, i; // pass用于位数循环,r取位数
    for (pass = 1; pass <= firure; pass++)
    {
        for (i = 0; i <= 9; i++)
            MAKENULL(Q[i])
        while (!EMPTY(A))
        {
            data = FRONT(A);                           // 获取A中的需要处理的数据给data
            DEQUEUE(A);                                // data从A中出队
            r = ((data.key / pow(10, pass - 1)) % 10); // 计算第pass位的值给r
            ENQUEUE(data, Q[r]);                       // 把data插入队列Q[r]
        }
        for (i = 1; i <= 9; i++)
            CONCATENATE(Q[0], Q[i]); // 收集
        A = Q[0];                    // 收集的结果赋给A
    }
}