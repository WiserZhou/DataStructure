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

// 冒泡排序
void BubbleSort(RcdType R[], int n)
{              // R有效元素位置从1开始，共n个
    int i = n; // i表示某趟排序得到的最大或最小元素应该放入的位置，初值为n
    while (i > 1)
    {
        int lastExchangeIndex = 1;
        for (int j = 1; j < i; j++) // i位置已经比较过了，所以j不需要等于i
            if (R[j + 1].key < R[j].key)
            {
                swap(R[j], R[j + 1]);
                lastExchangeIndex = j; // 记下发生交换的记录的位置，这个位置是交换的两个元素的前一个位置
            }                          // if
        i = lastExchangeIndex;         // i取本趟发生过交换的,循环中的 i 表示上一趟发生交换的最后一个位置，确保下一趟只需考虑未排序部分。
    }                                  // while 最后一个记录的位置
} // BubbleSort 表明i之后的记录是有序

// 快速排序
int Partition(SqList &L, int low, int high)
{
    // 一次快排/一次划分
    KeyType pivotKey = L.r[low].key;
    L.r[0] = L.r[low]; // 在0位置放置轴的值

    while (low < high)
    {
        while (low < high && L.r[high].key >= pivotKey) // 每个小循环里都要判断是否high>low
            --high;
        L.r[low] = L.r[high];
        while (low < high && L.r[low].key <= pivotKey) // 每个小循环里都要判断是否high>low
            ++low;
        L.r[high] = L.r[low];
    }

    L.r[low] = L.r[0]; // 枢轴记录入位
    return low;        // 返回枢轴位置
} // Partition

// 快速排序
void QSort(SqList &L, int low, int high)
{ 
    if (low < high)
    {
        int pivot_location = Partition(L, low, high); // 将L.r[low..high]一分为二
        QSort(L, low, pivot_location - 1);            // 对低子表递归快排，中间位置已经排过了，不必再排了
        QSort(L, pivot_location + 1, high);           // 对高子表递归快排
    }
} // QSort
