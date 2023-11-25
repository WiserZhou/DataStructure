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
typedef struct ElemType
{
    KeyType key;
    InfoType *info;
} ElemType;

void Swap(ElemType &a, ElemType &b)
{
    ElemType temp = a;
    a = b;
    b = temp;
}
// 冒泡排序
void BubbleSort(ElemType R[], int n)
{              // R有效元素位置从1开始，共n个
    int i = n; // i表示某趟排序得到的最大或最小元素应该放入的位置，初值为n
    while (i > 1)
    {
        int lastExchangeIndex = 1;
        for (int j = 1; j < i; j++) // i位置已经比较过了，所以j不需要等于i
            if (R[j + 1].key < R[j].key)
            {
                Swap(R[j], R[j + 1]);
                lastExchangeIndex = j; // 记下发生交换的记录的位置
            }                          // if

        i = lastExchangeIndex; // i取本趟发生过交换的,循环中的 i 表示上一趟发生交换的最后一个位置，确保下一趟只需考虑未排序部分。
    }                          // while// 最后一个记录的位置
} // BubbleSort///表明i之后的记录是有序



int Partition(SqList &L, int low, int high)
{ // 一次快排/一次划分
    KeyType pivotKey;
    pivotKey = L.r[low].key;
    L.r[0] = L.r[low]; // 在0位置放置轴的值
    while (low < high)
    {
        while (low < high && L.r[high].key >= pivotKey)
            --high;
        L.r[low] = L.r[high];
        while (low < high && L.r[low].key <= pivotKey)
            ++low;
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0]; // 枢轴记录入位
    return low;        // 返回枢轴位置
} // Partition

void QSort(SqList &L, int low, int high)
{ // 快排递归算法
    int pivot_location;
    if (low < high)
    {
        pivot_location = Partition(L, low, high); // 将L.r[low..high]一分为二
        QSort(L, low, pivot_location - 1);        // 对低子表递归快排
        QSort(L, pivot_location + 1, high);       // 对高子表递归快排
    }
} // QSort

void SelectSort(SqList L)
{
    int i, j, min; // min存储L.r[i...n]中最小值的下标
    for (i = 1; i < L.length; i++)
    {
        min = i; // min初值为i
        for (j = i + 1; j <= L.length; j++)
            if (L.r[j].key < L.r[min].key)
                min = j;
        if (min != i) // 如果min较比初值发生变化，则交换
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[min];
            L.r[min] = L.r[0];
        }
    }
}

typedef struct
{
    RcdType r[MAXSIZE + 1];
    InfoType info;
    int length;
} HeapType;

void HeapAdjust(HeapType &H, int s, int m)
{ // 将R[s..m]调整成堆
    int j;
    RcdType rc = H.r[s]; // 暂存r[s]到rc
    for (j = 2 * s; j <= m; j *= 2)
    {
        // j的初值为r[s]的左孩子,循环一次后j翻倍即指向其左孩子
        if (j < m && H.r[j].key < H.r[j + 1].key) // 横比r[s]的两个孩子
            ++j;                                  // 如果右孩子大于左孩子,j指向右孩子。最终j指向r[s]的最大孩子
        if (rc.key >= H.r[j].key)
            break;       // 纵比,如果rc最大，结束循环
        H.r[s] = H.r[j]; // r[j]最大，放入r[s]
        s = j;           // s变为j, 然后进入下一次循环j*=2,进入下一层 ,继续寻找rc应放的位置
    }
    H.r[s] = rc; // 将rc放入应放的位置r[s]中
} // HeapAdjust

void HeapSort(HeapType &H)
{
    int i;
    RcdType temp;
    for (i = H.length / 2; i > 0; --i) // 建堆
        HeapAdjust(H, i, H.length);
    for (i = H.length; i > 1; --i)
    {
        temp = H.r[i];
        H.r[i] = H.r[1];
        H.r[1] = temp;           // 交换
        HeapAdjust(H, 1, i - 1); // 调整R[1..i-1]
    }
} // HeapSort

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