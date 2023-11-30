#include <stdio.h>

#define MAXSIZE 12500

typedef int ElemType;

typedef struct
{
    int i, j;   // �÷���Ԫ�����±�����±�
    ElemType e; // �÷���Ԫ��ֵ
} Triple;       // ��Ԫ������

typedef struct
{
    Triple data[MAXSIZE + 1]; // data[0]δ��
    int mu, nu, tu;           // ����������������ͷ���Ԫ�صĸ���
} TSMatrix;                   // ϡ���������

int TransposeSMatrix1(TSMatrix M, TSMatrix *T)
{
    int p, q, col;
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    // ����������������ԭϡ����� M �෴�����Ƿ���Ԫ�ظ�������
    if (T->tu) // ���ϡ����� M �Ƿ���ڷ���Ԫ��
    {
        q = 1;                            // ��¼��ϡ����� T �з���Ԫ��λ��
        for (col = 1; col <= M.nu; ++col) // ����ԭϡ����� M ��ÿһ�У��ӵ�һ�е����һ��
            for (p = 1; p <= M.tu; ++p)   // ���������е�ÿһ������Ԫ��
                if (M.data[p].j == col)   // ����÷���Ԫ�ص����±���ڵ�ǰ���������� col��
                {
                    T->data[q].i = M.data[p].j;
                    T->data[q].j = M.data[p].i;
                    T->data[q].e = M.data[p].e;
                    ++q;
                    // ����Ԫ�ص����±ꡢ���±��ֵ���Ƶ���ϡ����� T �У����� T �еķ���Ԫ�ظ��� tu �� 1
                }
    }
    return 0;
}

int TransposeSMatrix2(TSMatrix M, TSMatrix *T)
{
    int p, q, col;
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    if (T->tu) 
    {
        q = 1;                            
        for (col = 1; col <= M.mu; ++col) 
            for (p = 1; p <= M.tu; ++p)   
                if (M.data[p].i == col) 
                {
                    T->data[q].i = M.data[p].j;
                    T->data[q].j = M.data[p].i;
                    T->data[q].e = M.data[p].e;
                    ++q;
                }
    }
    return 0;
}
int main()
{
    TSMatrix M, T, N;

    // ����ԭʼϡ����� M ����Ϣ
    M.mu = 3;
    M.nu = 4;
    M.tu = 5;

    M.data[1].i = 1;
    M.data[1].j = 2;
    M.data[1].e = 10;

    M.data[2].i = 2;
    M.data[2].j = 1;
    M.data[2].e = 20;

    M.data[3].i = 2;
    M.data[3].j = 3;
    M.data[3].e = 30;

    M.data[4].i = 3;
    M.data[4].j = 1;
    M.data[4].e = 40;

    M.data[5].i = 3;
    M.data[5].j = 4;
    M.data[5].e = 50;

    printf("Primitive Matrix M:\n");
    printf("mu = %d, nu = %d, tu = %d\n", M.mu, M.nu, M.tu);
    for (int i = 1; i <= M.tu; ++i)
    {
        printf("M.data[%d].i = %d, M.data[%d].j = %d, M.data[%d].e = %d\n", i, M.data[i].i, i, M.data[i].j, i, M.data[i].e);
    }
    // ����ת�ú���
    TransposeSMatrix1(M, &T);
    // ���ת�ú��ϡ����� T ����Ϣ
    printf("Transposed Matrix T:\n");
    printf("mu = %d, nu = %d, tu = %d\n", T.mu, T.nu, T.tu);
    for (int i = 1; i <= T.tu; ++i)
    {
        printf("T.data[%d].i = %d, T.data[%d].j = %d, T.data[%d].e = %d\n", i, T.data[i].i, i, T.data[i].j, i, T.data[i].e);
    }

    TransposeSMatrix2(M, &N);
    // ���ת�ú��ϡ����� T ����Ϣ
    printf("Transposed Matrix N:\n");
    printf("mu = %d, nu = %d, tu = %d\n", N.mu, N.nu, N.tu);
    for (int i = 1; i <= N.tu; ++i)
    {
        printf("N.data[%d].i = %d, N.data[%d].j = %d, N.data[%d].e = %d\n", i, N.data[i].i, i, N.data[i].j, i, N.data[i].e);
    }
    return 0;
}
