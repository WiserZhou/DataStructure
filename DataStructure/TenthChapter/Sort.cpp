typedef int InfoType;

#define MAXSIZE 1000 // 待排顺序表最大长度
typedef int KeyType; // 关键字类型为整数类型
typedef struct
{
    KeyType key;        // 关键字项
    InfoType otherInfo; // 其它数据项
} RcdType;              // 记录类型

typedef struct
{
    RcdType r[MAXSIZE + 1]; // r[0]闲置
    int length;             // 顺序表长度
} SqList;                   // 顺序表类型

void InsertionSort(SqList &L)
{
    // 对顺序表 L 作直接插入排序。
    int i, j;
    for (i = 2; i <= L.length; ++i) // 从2号位置开始
    {
        if (L.r[i].key < L.r[i - 1].key) // 如果第2号比第1号小，那么将它放在监视哨上
        {
            L.r[0] = L.r[i];                              // 复制为监视哨
            L.r[i] = L.r[i - 1];                          // 此时已经满足了if条件，直接赋值即可，可减少一次多余的比较
            for (j = i - 2; L.r[0].key < L.r[j].key; --j) // 将所有比监视哨的值大的都后移，给他挪位置
                L.r[j + 1] = L.r[j];                      // 将所有的元素都获取到前面的元素值，从而完成后移
            L.r[j + 1] = L.r[0];                          // 将此元素获取到监视哨的元素值
        }                                                 // if <
    }                                                     // for 2:L.length
} // InsertSort

void BiInsertionSort(SqList &L)
{
    int i, j;
    for (i = 2; i <= L.length; ++i)
    {
        if (L.r[i].key < L.r[i - 1].key)
            L.r[0] = L.r[i]; // 将 L.r[i] 暂存到 L.r[0]

        int low = 1;
        int high = i - 1;
        while (low <= high)
        {
            int m = (low + high) / 2; // 折半
            if (L.r[0].key < L.r[m].key)
                high = m - 1; // 插入点在低半区
            else
                low = m + 1; // 插入点在高半区
        }

        for (j = i - 1; j >= high + 1; --j)
            L.r[j + 1] = L.r[j]; // 记录后移

        L.r[high + 1] = L.r[0]; // 插入
    }                           // for
                                // BInsertSort
}
#include "../header/unity.h"

void ShellInsert(SqList &L, int dk)
{ // 增量为dk时的希尔
    int i, j;
    for (i = dk + 1; i <= L.length; ++i)
        if (LT(L.r[i].key, L.r[i - dk].key))
        {
            L.r[0] = L.r[i]; // 暂存在R[0]
            for (j = i - dk; j > 0 && LT(L.r[0].key, L.r[j].key); j -= dk)
                L.r[j + dk] = L.r[j]; // 记录后移，查找插入位置
            L.r[j + dk] = L.r[0];     // 插入
        }
}

int delta[5] = {10, 7, 5, 3, 1}; // delta的选取很重要，最后一个值必须为1
void ShellSort(SqList &L, int delta[], int t)
{
    // 增量为delta[]的希尔排序
    int k;
    for (k = 0; k < t; ++k)
        ShellInsert(L, delta[k]);
    // 一趟增量为delta[k]的插入排序
}

typedef struct ElemType
{
    int key;
    InfoType info;
} ElemType;
void Swap(ElemType &a, ElemType &b)
{
    ElemType temp = a;
    a = b;
    b = temp;
}
void BubbleSort(ElemType R[], int n)
{              // R有效元素位置从1开始，共n个
    int i = n; // i表示某趟排序得到的最大或最小元素应该放入的位置，初值为n
    while (i > 1)
    {
        int lastExchangeIndex = 1;
        for (int j = 1; j < i; j++)
            if (R[j + 1].key < R[j].key)
            {
                Swap(R[j], R[j + 1]);
                lastExchangeIndex = j; // 记下发生交换的记录的位置
            }                          // if

        i = lastExchangeIndex; // i取本趟发生过交换的
    }                          // while// 最后一个记录的位置
} // BubbleSort///表明i之后的记录是有序

int Partition(SqList &L, int low, int high)
{ // 一次快排/一次划分
    KeyType pivotKey;
    pivotKey = L.r[low].key;
    L.r[0] = L.r[low];
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