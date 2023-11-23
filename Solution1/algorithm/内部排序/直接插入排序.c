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

// ֱ�Ӳ�������

void InsertionSort(SqList *L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i].key < L->r[i - 1].key) // �����ʱ������˳���ǶԵģ���ô���ǲ���Ҫִ�д�������
        {
            L->r[0] = L->r[i]; //    ��ֵ��Ԫ��Ϊ������
            for (j = i - 1; L->r[0].key < L->r[j].key; --j)
                L->r[j + 1] = L->r[j]; // ��¼����
            L->r[j + 1] = L->r[0];     // ���뵽��ȷ��λ��
        }
    }
}

// �۰���������൱�ڼ�֦�ˣ�ʱ�临�Ӷ���С��ֱ�Ӳ��������(һ�������)
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

// ��������
int Partition(SqList *L, int low, int high)
{
    KeyType pivotkey;
    pivotkey = L->r[low].key; // ����һ������
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