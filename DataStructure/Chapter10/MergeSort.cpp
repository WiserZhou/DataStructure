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

// 归并排序
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n)
{
    int j, k;
    for (j = m + 1, k = i; i <= m && j <= n; ++k)
    {
        if (LQ(SR[i].key, SR[j].key))
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m)
        while (k <= n && i <= m)
            TR[k++] = SR[i++];
    if (j <= n)
        while (k <= n && j <= n)
            TR[k++] = SR[j++];
} // Merge

RcdType TR2[MAXSIZE];

void M_sort(RcdType SR[], RcdType *TR1, int s, int t)
{
    // 将SR[s..t] 归并排序为 TR1[s..t]
    if (s == t)
        TR1[s] = SR[s]; // 如果长度为1，直接赋值，递归结束
    else
    {
        // 71 9.5 归并排序
        int m = (s + t) / 2; // 将SR[s..t]平分为SR[s..m]和SR[m+1..t]
        M_sort(SR, TR2, s, m);
        // 递归地将SR[s..m]归并为有序的TR2[s..m]
        M_sort(SR, TR2, m + 1, t);
        // 递归地SR[m+1..t]归并为有序的TR2[m+1..t]
        Merge(TR2, TR1, s, m, t);
        // 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t]
    }
}
void MergeSort(SqList &L)
{ // 再封装,对表 L进行2-路归并排序
    M_sort(L.r, L.r, 1, L.length);
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