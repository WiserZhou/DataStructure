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

// 选择排序
void SelectSort(SqList &L)
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
    InfoType *info;
    int length;
} HeapType;

/**
 * int s: 待调整的子树的根节点下标。
 * int m: 堆的长度，即数组的最后一个元素下标。
 */
void HeapAdjust(HeapType &H, int s, int m) // 将R[s..m]调整成堆
{
    int j;
    RcdType rc = H.r[s];            // 暂存r[s]到rc
    for (j = 2 * s; j <= m; j *= 2) // j的初值为r[s]的左孩子,循环一次后j翻倍即指向其左孩子
    {

        if (j < m && H.r[j].key < H.r[j + 1].key) // 横比r[s]的两个孩子，如果右孩子大于左孩子,j指向右孩子。最终j指向r[s]的最大孩子
            ++j;
        if (rc.key >= H.r[j].key) // 纵比,如果rc最大，结束循环
            break;
        H.r[s] = H.r[j]; // r[j]最大，放入r[s]
        s = j;           // s变为j, 然后进入下一次循环j*=2,进入下一层 ,继续寻找rc应放的位置
    }
    H.r[s] = rc; // 此时的s是低层的最大的元素的位置，也是上次移出赋值的位置
} // HeapAdjust

void HeapSort(HeapType &H)
{
    int i;
    RcdType temp;
    for (i = H.length / 2; i > 0; --i) // 建堆 ,这里的H.length/2刚好就是最后一个结点的父结点
        HeapAdjust(H, i, H.length);    // 将从i开始到后面的调整好
    for (i = H.length; i > 1; --i)
    {
        temp = H.r[i];
        H.r[i] = H.r[1];
        H.r[1] = temp;           // 交换
        HeapAdjust(H, 1, i - 1); // 调整R[1..i-1]
    }
} // HeapSort
