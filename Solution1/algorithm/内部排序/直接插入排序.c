#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
#define KeyType int
#define InfoType char

typedef struct
{
    KeyType key;
    InfoType otherinfo;
} RedType;

typedef struct
{
    RedType r[MAXSIZE + 1];
    int length;
} SqList;

// 直接插入排序

void InsertionSort(SqList *L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i].key < L->r[i - 1].key) // 如果此时的数字顺序是对的，那么就是不需要执行此轮排序
        {
            L->r[0] = L->r[i]; //    赋值该元素为监视哨
            for (j = i - 1; L->r[0].key < L->r[j].key; --j)
                L->r[j + 1] = L->r[j]; // 记录后移
            L->r[j + 1] = L->r[0];     // 插入到正确的位置
        }
    }
}

// 折半插入排序，相当于剪枝了，时间复杂度是小于直接插入排序的(一般情况下)
void BiInsertionSort(SqList *L)
{
    int i, j, m;
    for (i = 2; i <= L->length; ++i)
    {
        if (L->r[i].key < L->r[i - 1].key)
            L->r[0] = L->r[i];
        int low = 1, high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (L->r[0].key < L->r[m].key)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; --j)
            L->r[j + 1] = L->r[j];
        L->r[high + 1] = L->r[0];
    }
}

// 快速排序
int Partition(SqList *L, int low, int high)
{
    KeyType pivotkey;
    pivotkey = L->r[low].key; // 设置一个枢轴
    L->r[0] = L->r[low];
    while (low < high)
    {
        while (low < high && L->r[high].key >= pivotkey)
            --high;
        L->r[low] = L->r[high];
        while (Low < high && L->r[low].key <= pivotkey)
            ++low;
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0];
    return low;
}

void Qsort(SqList *L, int low, int high)
{
    int pivotloc;
    if (low < high)
    {
        pivotloc = Partition(L, low, high);
        Qsort(L, low, pivotloc - 1);
        Qsort(L, pivotloc + 1, high);
    }
}