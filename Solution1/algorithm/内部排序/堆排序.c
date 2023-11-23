#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    int key;
    // ������Ա����
} RedType;

typedef struct
{
    RedType *r; // ��������
    int length; // ���鳤��
} HeapType;

// �������ɸѡ�㷨
void HeapAdjust(HeapType *H, int s, int m)
{
    int j;
    RedType rc = H->r[s]; // �ݴ�r[s]��rc
    for (j = 2 * s; j <= m; j *= 2)
    {
        // j�ĳ�ֵΪr[s]������,ѭ��һ�κ�j������ָ��������
        if (j < m && H->r[j].key < H->r[j + 1].key) // ���r[s]����������
            ++j;                                    // ����Һ��Ӵ�������,jָ���Һ��ӡ�����jָ��r[s]�������
        if (rc.key >= H->r[j].key)
            break;         // �ݱ�,���rc��󣬽���ѭ��
        H->r[s] = H->r[j]; // r[j]��󣬷���r[s]
        s = j;             // s��Ϊj, Ȼ�������һ��ѭ��j*=2,������һ�� ,����Ѱ��rcӦ�ŵ�λ��
    }
    H->r[s] = rc; // ��rc����Ӧ�ŵ�λ��r[s]��
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
    // ��ʼ��������
    HeapType H;
    int length = 10;
    H.r = (RedType *)malloc((length + 1) * sizeof(RedType)); // �±��1��ʼ
    H.length = length;

    for (int i = 1; i <= length; i++)
    {
        H.r[i].key = length - i + 1; // ����������ķ�ʽ�洢����
    }

    // ִ�ж�����
    HeapSort(&H);

    // ���������
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", H.r[i].key);
    }
    printf("\n");

    free(H.r);

    return 0;
}
