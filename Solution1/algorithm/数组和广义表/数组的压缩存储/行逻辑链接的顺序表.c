

#include <stdio.h>
#define MAXSIZE 12500 // 最大元素个数
#define MAXRC 100     // 最大行数或列数
#define ElemType int  // 元素类型定义为int

typedef struct
{
    int i, j;   // 非零元素的行号和列号
    ElemType e; // 非零元素的值
} Triple;

typedef struct
{
    Triple data[MAXSIZE + 1]; // 非零元素数组，用于存储稀疏矩阵的非零元素
    int rpos[MAXRC + 1];      // 每行第一个非零元素在data数组中的位置
    int mu, nu, tu;           // 行数，列数，元素个数
} RLSMatrix;

// 矩阵的输出函数
void display(RLSMatrix M)
{
    for (int i = 1; i <= M.mu; i++)
    {
        for (int j = 1; j <= M.nu; j++)
        {
            int value = 0;
            if (i + 1 <= M.mu)
            {
                for (int k = M.rpos[i]; k < M.rpos[i + 1]; k++)
                {
                    if (i == M.data[k].i && j == M.data[k].j)
                    {
                        printf("%d ", M.data[k].e); // 显示非零元素的值
                        value = 1;
                        break;
                    }
                }
                if (value == 0)
                {
                    printf("0 "); // 如果当前位置不是非零元素，则显示0
                }
            }
            else
            {
                for (int k = M.rpos[i]; k <= M.tu; k++)
                {
                    if (i == M.data[k].i && j == M.data[k].j)
                    {
                        printf("%d ", M.data[k].e); // 显示非零元素的值
                        value = 1;
                        break;
                    }
                }
                if (value == 0)
                {
                    printf("0 "); // 如果当前位置不是非零元素，则显示0
                }
            }
        }
        printf("\n"); // 换行
    }
}

int main(int argc, char *argv[])
{
    RLSMatrix M;
    M.tu = 4;      // 矩阵的非零元素个数
    M.mu = 3;      // 矩阵的行数
    M.nu = 4;      // 矩阵的列数
    M.rpos[1] = 1; // 每行第一个非零元素在data数组中的位置
    M.rpos[2] = 3;
    M.rpos[3] = 4;
    M.data[1].e = 3; // 第一个非零元素的值
    M.data[1].i = 1; // 第一个非零元素的行号
    M.data[1].j = 2; // 第一个非零元素的列号
    M.data[2].e = 5; // 第二个非零元素的值
    M.data[2].i = 1; // 第二个非零元素的行号
    M.data[2].j = 4; // 第二个非零元素的列号
    M.data[3].e = 1; // 第三个非零元素的值
    M.data[3].i = 2; // 第三个非零元素的行号
    M.data[3].j = 3; // 第三个非零元素的列号
    M.data[4].e = 2; // 第四个非零元素的值
    M.data[4].i = 3; // 第四个非零元素的行号
    M.data[4].j = 1; // 第四个非零元素的列号

    // 输出矩阵
    display(M);
    return 0;
}