// 改进版

#include <stdio.h>
#include <string.h>
typedef struct
{
    int key;
    // 这里可以添加其他需要排序的数据成员
} Elem;

void BubbleSort(Elem R[], int n)
{
    int i = n; // i表示某趟排序得到的最大或最小元素应该放入的位置，初值为n
    while (i > 1)
    {
        int lastExchangeIndex = 1; // 记录本趟发生过交换的最后一个位置
        for (int j = 1; j < i; j++)
        {
            if (R[j].key > R[j + 1].key)
            {
                // 交换 R[j] 和 R[j+1]
                Elem temp = R[j];
                R[j] = R[j + 1];
                R[j + 1] = temp;
                lastExchangeIndex = j; // 更新发生交换的位置
            }
        }
        i = lastExchangeIndex; // i取本趟发生过交换的最后一个记录的位置
    }                          // while
} // BubbleSort

int main()
{
    Elem arr[] = {{5}, {3}, {8}, {2}, {1}}; // 示例数据，key为需要排序的关键字
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i].key);
    }
    printf("\n");

    BubbleSort(arr, n);
    printf("%d\n", n);
    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i].key);
    }
    printf("\n");

    return 0;
}
