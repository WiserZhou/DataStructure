#include <stdio.h>

#define MAXSIZE 12500

typedef int ElemType;

typedef struct
{
    int i, j;   // 该非零元的行下标和列下标
    ElemType e; // 该非零元的值
} Triple;       // 三元组类型

typedef struct
{
    Triple data[MAXSIZE + 1]; // data[0]未用
    int mu, nu, tu;           // 矩阵的行数、列数和非零元素的个数
} TSMatrix;                   // 稀疏矩阵类型

int TransposeSMatrix1(TSMatrix M, TSMatrix *T)
{
    int p, q, col;
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    // 其中行数和列数与原稀疏矩阵 M 相反，但是非零元素个数不变
    if (T->tu) // 检查稀疏矩阵 M 是否存在非零元素
    {
        q = 1;                            // 记录新稀疏矩阵 T 中非零元素位置
        for (col = 1; col <= M.nu; ++col) // 遍历原稀疏矩阵 M 的每一列，从第一列到最后一列
            for (p = 1; p <= M.tu; ++p)   // 遍历该列中的每一个非零元素
                if (M.data[p].j == col)   // 如果该非零元素的列下标等于当前遍历到的列 col，
                {
                    T->data[q].i = M.data[p].j;
                    T->data[q].j = M.data[p].i;
                    T->data[q].e = M.data[p].e;
                    ++q;
                    // 将该元素的行下标、列下标和值复制到新稀疏矩阵 T 中，并将 T 中的非零元素个数 tu 加 1
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

    // 设置原始稀疏矩阵 M 的信息
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
    // 调用转置函数
    TransposeSMatrix1(M, &T);
    // 输出转置后的稀疏矩阵 T 的信息
    printf("Transposed Matrix T:\n");
    printf("mu = %d, nu = %d, tu = %d\n", T.mu, T.nu, T.tu);
    for (int i = 1; i <= T.tu; ++i)
    {
        printf("T.data[%d].i = %d, T.data[%d].j = %d, T.data[%d].e = %d\n", i, T.data[i].i, i, T.data[i].j, i, T.data[i].e);
    }

    TransposeSMatrix2(M, &N);
    // 输出转置后的稀疏矩阵 T 的信息
    printf("Transposed Matrix N:\n");
    printf("mu = %d, nu = %d, tu = %d\n", N.mu, N.nu, N.tu);
    for (int i = 1; i <= N.tu; ++i)
    {
        printf("N.data[%d].i = %d, N.data[%d].j = %d, N.data[%d].e = %d\n", i, N.data[i].i, i, N.data[i].j, i, N.data[i].e);
    }
    return 0;
}
