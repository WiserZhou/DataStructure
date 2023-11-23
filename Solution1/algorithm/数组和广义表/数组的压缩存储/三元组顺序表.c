


// 上述代码定义了两个结构体，triple 表示稀疏矩阵中的非零元素，TSMatrix 表示整个稀疏矩阵。display 函数用于输出稀疏矩阵的存储。

// 在 main 函数中，创建了一个稀疏矩阵 M，并初始化了其属性和非零元素。然后调用 display 函数来输出稀疏矩阵的存储情况。
#include <stdio.h>
#define number 3 // 定义稀疏矩阵的非零元素个数

typedef struct
{
    int i, j; // 非零元素在矩阵中的行号和列号
    int data; // 非零元素的值
} triple;

typedef struct
{
    triple data[number]; // 非零元素数组，用于存储稀疏矩阵的非零元素
    int n, m;            // 矩阵的行数和列数
    int num;             // 矩阵的非零元素个数
} TSMatrix;

// 输出存储的稀疏矩阵
void display(TSMatrix M);

int main()
{
    TSMatrix M;
    M.m = 3;            // 矩阵的列数
    M.n = 3;            // 矩阵的行数
    M.num = 3;          // 矩阵的非零元素个数
    M.data[0].i = 1;    // 第一个非零元素的行号
    M.data[0].j = 1;    // 第一个非零元素的列号
    M.data[0].data = 1; // 第一个非零元素的值
    M.data[1].i = 2;    // 第二个非零元素的行号
    M.data[1].j = 3;    // 第二个非零元素的列号
    M.data[1].data = 5; // 第二个非零元素的值
    M.data[2].i = 3;    // 第三个非零元素的行号
    M.data[2].j = 1;    // 第三个非零元素的列号
    M.data[2].data = 3; // 第三个非零元素的值
    display(M);         // 调用显示函数显示稀疏矩阵
    return 0;
}

void display(TSMatrix M)
{
    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.m; j++)
        {
            int value = 0;
            for (int k = 0; k < M.num; k++)
            {
                if (i == M.data[k].i && j == M.data[k].j)
                {
                    printf("%d ", M.data[k].data); // 显示非零元素的值
                    value = 1;
                    break;
                }
            }
            if (value == 0)
                printf("0 "); // 如果当前位置不是非零元素，则显示0
        }
        printf("\n"); // 换行
    }
}