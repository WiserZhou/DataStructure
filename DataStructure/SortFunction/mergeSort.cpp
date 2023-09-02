#include <iostream>
using namespace std;
void Merge(int *a, int p, int q, int r);
void MergeSort(int *a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r); // 利用嵌套将数组分解至剩下最后两个单独的进行排序，排序完之后递归由小及大将整个数组排序完成。
        Merge(a, p, q, r);      // 将数组的指定位置进行排序
    }
}
void Merge(int *a, int p, int q, int r)
{
    int n1 = q - p + 1; // 计算第一部分的长度
    int n2 = r - q;     // 计算第二部分的长度
    int L[n1 + 1] = {};
    int R[n2 + 1] = {};
    for (int i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[q + i + 1];
    L[n1] = R[n2] = __INT_MAX__; // 得到两个新的数组，并且将最后一个哨兵牌作为分配终止的标记。
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) // 在所给的范围内进行发牌
    {
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
}

int main()
{
    int a[10] = {1, 3, 2, 4, 4, 2, 1, 23, 3, 2};
    MergeSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    return 0;
}