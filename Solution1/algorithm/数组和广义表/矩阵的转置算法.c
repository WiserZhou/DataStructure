

#include <stdio.h>
#define MAXSIZE 10

typedef struct
{
    int i, j; // 行号和列号
    int data; // 元素的值
} triple;

typedef struct
{
    triple data[MAXSIZE]; // 存储非零元素的数组
    int m, n, num;        // 矩阵的行数、列数和非零元素个数
} TSMatrix;

// 转置矩阵
TSMatrix transposeMatrix(TSMatrix M, TSMatrix T)
{
    T.m = M.n;     // 转置后的矩阵行数等于原矩阵的列数
    T.n = M.m;     // 转置后的矩阵列数等于原矩阵的行数
    T.num = M.num; // 非零元素个数保持不变

    if (T.num)
    {              // 如果非零元素个数不为零
        int q = 0; // T矩阵的非零元素的索引
        for (int col = 1; col <= M.n; col++)
        { // 遍历原矩阵的列
            for (int p = 0; p < M.num; p++)
            { // 遍历原矩阵的非零元素
                if (M.data[p].j == col)
                {                                    // 找到对应列的非零元素
                    T.data[q].i = M.data[p].j;       // 转置后的行号等于原矩阵的列号
                    T.data[q].j = M.data[p].i;       // 转置后的列号等于原矩阵的行号
                    T.data[q].data = M.data[p].data; // 非零元素的值保持不变
                    q++;                             // T矩阵的非零元素索引加1
                }
            }
        }
    }

    return T;
}

int main()
{
    // 初始化原矩阵M
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

    // 初始化转置矩阵T
    TSMatrix T;
    T.m = M.n;
    T.n = M.m;
    T.num = M.num;

    // 调用转置矩阵函数
    T = transposeMatrix(M, T);

    // 输出转置矩阵T的非零元素
    for (int i = 0; i < T.num; i++)
    {
        printf("(%d,%d,%d)\n", T.data[i].i, T.data[i].j, T.data[i].data);
    }

    return 0;
}