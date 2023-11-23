

#include <stdio.h>
#define MAXSIZE 10

typedef struct
{
    int i, j; // �кź��к�
    int data; // Ԫ�ص�ֵ
} triple;

typedef struct
{
    triple data[MAXSIZE]; // �洢����Ԫ�ص�����
    int m, n, num;        // ����������������ͷ���Ԫ�ظ���
} TSMatrix;

// ת�þ���
TSMatrix transposeMatrix(TSMatrix M, TSMatrix T)
{
    T.m = M.n;     // ת�ú�ľ�����������ԭ���������
    T.n = M.m;     // ת�ú�ľ�����������ԭ���������
    T.num = M.num; // ����Ԫ�ظ������ֲ���

    if (T.num)
    {              // �������Ԫ�ظ�����Ϊ��
        int q = 0; // T����ķ���Ԫ�ص�����
        for (int col = 1; col <= M.m; col++)
        { // ����ԭ�������
            for (int p = 0; p < M.num; p++)
            { // ����ԭ����ķ���Ԫ��
                if (M.data[p].j == col)
                {                                    // �ҵ���Ӧ�еķ���Ԫ��
                    T.data[q].i = M.data[p].j;       // ת�ú���кŵ���ԭ������к�
                    T.data[q].j = M.data[p].i;       // ת�ú���кŵ���ԭ������к�
                    T.data[q].data = M.data[p].data; // ����Ԫ�ص�ֵ���ֲ���
                    q++;                             // T����ķ���Ԫ��������1
                }
            }
        }
    }

    return T;
}

int main()
{
    // ��ʼ��ԭ����M
    TSMatrix M;
    M.m = 2;
    M.n = 3;
    M.num = 4;
    M.data[0].i = 1;
    M.data[0].j = 2;
    M.data[0].data = 1;
    M.data[1].i = 2;
    M.data[1].j = 2;
    M.data[1].data = 3;
    M.data[2].i = 3;
    M.data[2].j = 1;
    M.data[2].data = 6;
    M.data[3].i = 3;
    M.data[3].j = 2;
    M.data[3].data = 5;

    // ��ʼ��ת�þ���T
    TSMatrix T;
    T.m = M.n;
    T.n = M.m;
    T.num = M.num;

    // ����ת�þ�����
    T = transposeMatrix(M, T);

    // ���ת�þ���T�ķ���Ԫ��
    for (int i = 0; i < T.num; i++)
    {
        printf("(%d,%d,%d)\n", T.data[i].i, T.data[i].j, T.data[i].data);
    }

    return 0;
}