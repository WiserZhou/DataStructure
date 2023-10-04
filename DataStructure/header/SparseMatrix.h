#include "..\header\unity.h"

#define MAX_SIZE 12500

typedef int ElemType;
typedef struct
{
    int i, j; // 矩阵元素的位置坐标
    ElemType e;
} Triple;

typedef struct
{
    Triple data[MAX_SIZE + 1];
    int mu, nu, tu; // 矩阵的行数、列数和非零元素的个数
} TS_Matrix;

Status TransposeSMatrix(TS_Matrix M, TS_Matrix &T)
{
    int p, q, col;
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu)
    {
        q = 1;
        for (col = 1; col <= M.nu; col++)
        {
            for (p = 1; p <= M.tu; p++) // 每次都对列进行重新搜素
            {
                if (M.data[p].j == col)
                {
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    q++;
                }
            }
        }
    }
    return OK;
}
/**
 * 稀疏矩阵的快速转置算法
 */
Status FastTransposeSMatrix(TS_Matrix M, TS_Matrix &T)
{
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int num[MAX_SIZE] = {0};
    int c_pot[MAX_SIZE] = {0};
    if (T.tu)
    {
        for (int col = 1; col <= M.nu; col++)
            num[col] = 0; // 初始化数量值为0
        for (int t = 1; t <= M.tu; t++)
            ++num[M.data[t].j]; // 在每一个M的数据出现的列上+1，表示每一列的数据值
        c_pot[1] = 1;           // 初始化第一列的索引为1
        for (int col = 2; col <= M.nu; col++)
            c_pot[col] = c_pot[col - 1] + num[col - 1]; // 依次计算之后每列的索引值
        for (int p = 1; p <= M.tu; p++)
        {
            int col = M.data[p].j; // 得到每一个M矩阵里元素的列值
            int q = c_pot[col];    // 得到所得列的第一个元素的出现位置
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++c_pot[col]; // 向后挪，从而第二次出现的时候也能计算到
        }
    }
    return OK;
}
#define MAX_RC 100
typedef struct
{
    Triple data[MAX_SIZE + 1];
    int r_pos[MAX_RC + 1];
    int mu, nu, tu;
} RLS_Matrix;

Status MultSMatrix(RLS_Matrix M, RLS_Matrix N, RLS_Matrix &Q)
{
    if (M.nu != N.mu)
        return ERROR;

    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;

    if (M.tu * N.tu != 0)
    {
        for (int arrow = 1; arrow <= M.mu; ++arrow)
        {
            int c_temp[MAX_RC] = {0};
            Q.r_pos[arrow] = Q.tu + 1;
            int tp;
            if (arrow < M.mu)
                tp = M.r_pos[arrow + 1];
            else
                tp = M.tu + 1;
            for (int p = M.r_pos[arrow]; p < tp; ++p)
            {
                int brow = M.data[p].j;
                int t;
                if (brow < N.mu)
                    t = N.r_pos[brow + 1];
                else
                    t = N.tu + 1;
                for (int q = N.r_pos[brow]; q < t; q++)
                {
                    int c_col = N.data[q].j;
                    c_temp[c_col] += M.data[p].e * N.data[q].e;
                }
            }
            for (int c_col = 1; c_col <= Q.nu; ++c_col)
            {
                if (c_temp[c_col])
                {
                    if (++Q.tu > MAX_SIZE)
                        return ERROR;
                    Q.data[Q.tu].i = arrow;
                    Q.data[Q.tu].j = c_col;
                    Q.data[Q.tu].e = c_temp[c_col];
                }
            }
        }
    }
    return OK;
}