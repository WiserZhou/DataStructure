#include <iostream>
using namespace std;
void Merge(int *a, int p, int q, int r);
void MergeSort(int *a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r); // ����Ƕ�׽�����ֽ���ʣ��������������Ľ�������������֮��ݹ���С������������������ɡ�
        Merge(a, p, q, r);      // �������ָ��λ�ý�������
    }
}
void Merge(int *a, int p, int q, int r)
{
    int n1 = q - p + 1; // �����һ���ֵĳ���
    int n2 = r - q;     // ����ڶ����ֵĳ���
    int L[n1 + 1] = {};
    int R[n2 + 1] = {};
    for (int i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[q + i + 1];
    L[n1] = R[n2] = __INT_MAX__; // �õ������µ����飬���ҽ����һ���ڱ�����Ϊ������ֹ�ı�ǡ�
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) // �������ķ�Χ�ڽ��з���
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