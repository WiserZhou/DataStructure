#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    int key;
    // 其他成员变量
} RedType;

typedef struct
{
    RedType *r; // 数据数组
    int length; // 数组长度
} HeapType;

// 堆排序的筛选算法
void HeapAdjust(HeapType *H, int s, int m)
{
    int j;
    RedType rc = H->r[s]; // 暂存r[s]到rc
    for (j = 2 * s; j <= m; j *= 2)
    {
        // j的初值为r[s]的左孩子,循环一次后j翻倍即指向其左孩子
        if (j < m && H->r[j].key < H->r[j + 1].key) // 横比r[s]的两个孩子
            ++j;                                    // 如果右孩子大于左孩子,j指向右孩子。最终j指向r[s]的最大孩子
        if (rc.key >= H->r[j].key)
            break;         // 纵比,如果rc最大，结束循环
        H->r[s] = H->r[j]; // r[j]最大，放入r[s]
        s = j;             // s变为j, 然后进入下一次循环j*=2,进入下一层 ,继续寻找rc应放的位置
    }
    H->r[s] = rc; // 将rc放入应放的位置r[s]中
}

void HeapSort(HeapType *H)
{
    int i;
    for (i = H->length / 2; i > 0; i--)
    {
        HeapAdjust(H, i, H->length);
    }
    for (i = H->length; i > 1; i--)
    {
        RedType temp = H->r[1];
        H->r[1] = H->r[i];
        H->r[i] = temp;
        HeapAdjust(H, 1, i - 1);
    }
}

int main()
{
    // 初始化堆数据
    HeapType H;
    int length = 10;
    H.r = (RedType *)malloc((length + 1) * sizeof(RedType)); // 下标从1开始
    H.length = length;

    for (int i = 1; i <= length; i++)
    {
        H.r[i].key = length - i + 1; // 假设以逆序的方式存储数据
    }

    // 执行堆排序
    HeapSort(&H);

    // 输出排序结果
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", H.r[i].key);
    }
    printf("\n");

    free(H.r);

    return 0;
}
