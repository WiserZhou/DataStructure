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

// 直接插入排序算法
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
        }
    }
} // InsertSort

// 折半插入排序算法
void BiInsertionSort(SqList &L)
{
    int i, j;
    for (i = 2; i <= L.length; ++i)
    {
        if (LT(L.r[i].key, L.r[i - 1].key))
            L.r[0] = L.r[i]; // 将 L.r[i] 暂存到 L.r[0]

        int low = 1;
        int high = i - 1;
        while (low <= high) // 两者相等的位置就是要插入的位置
        {
            int m = (low + high) / 2; // 折半
            if (LT(L.r[0].key, L.r[m].key))
                high = m - 1; // 插入点在低半区
            else
                low = m + 1; // 插入点在高半区
        }

        for (j = i - 1; j >= high + 1; --j) // high+1 到i-1就是当前位置比L.r[i].key大的元素s
            L.r[j + 1] = L.r[j];            // 记录后移

        L.r[high + 1] = L.r[0]; // 插入
    }                           // for
                                // BInsertSort
}
// 当找到插入点时，low 和 high 的最终状态为 low > high，并
// 且 high 指向的是插入点的前一个位置。此时，high + 1 就是插入点的位置。
#include "../header/unity.h"

void ShellInsert(SqList &L, int dk)
{ // 增量为dk时的希尔
    int i, j;
    for (i = dk + 1; i <= L.length; ++i) // 从第一个元素的后一个1+dk开始
        if (LT(L.r[i].key, L.r[i - dk].key))
        {
            L.r[0] = L.r[i];                                               // 暂存在R[0]
            for (j = i - dk; j > 0 && LT(L.r[0].key, L.r[j].key); j -= dk) // j从在当前子序列中的最后一个元素的前一个元素的位置就是i-dk开始
                L.r[j + dk] = L.r[j];                                      // 记录后移，查找插入位置
            L.r[j + dk] = L.r[0];                                          // 插入
        }
}

int delta[5] = {10, 7, 5, 3, 1}; // delta的选取很重要，最后一个值必须为1
void ShellSort(SqList &L, int delta[], int t)
{
    // 增量为delta[]的希尔排序
    int k;
    for (k = 0; k < t; ++k)
        ShellInsert(L, delta[k]); // 一趟增量为delta[k]的插入排序
}
