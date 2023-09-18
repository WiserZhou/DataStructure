#include "..\header\unity.h"

#define MAX_SIZE 12500
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
int main()
{
    TS_Matrix M;
}
