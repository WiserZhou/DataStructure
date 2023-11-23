// �Ľ���

#include <stdio.h>
#include <string.h>
typedef struct
{
    int key;
    // ����������������Ҫ��������ݳ�Ա
} Elem;

void BubbleSort(Elem R[], int n)
{
    int i = n; // i��ʾĳ������õ���������СԪ��Ӧ�÷����λ�ã���ֵΪn
    while (i > 1)
    {
        int lastExchangeIndex = 1; // ��¼���˷��������������һ��λ��
        for (int j = 1; j < i; j++)
        {
            if (R[j].key > R[j + 1].key)
            {
                // ���� R[j] �� R[j+1]
                Elem temp = R[j];
                R[j] = R[j + 1];
                R[j + 1] = temp;
                lastExchangeIndex = j; // ���·���������λ��
            }
        }
        i = lastExchangeIndex; // iȡ���˷��������������һ����¼��λ��
    }                          // while
} // BubbleSort

int main()
{
    Elem arr[] = {{5}, {3}, {8}, {2}, {1}}; // ʾ�����ݣ�keyΪ��Ҫ����Ĺؼ���
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
