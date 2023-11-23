
// 这段代码实现了多维数组的顺序存储模拟。主要包括以下几个函数和结构体。

// 结构体Array：定义了一个多维数组的结构，包括数组元素基址base，数组维数dim，数组维界基址bounds，以及数组映象函数常量基址constants。
// 函数InitArray：根据维数和维界，构造多维数组，并返回状态值。
// 函数DestroyArray：销毁多维数组，释放相应的内存空间。
// 函数Locate：根据给定的下标值，计算出元素在多维数组中的相对地址。
// 函数Value：根据给定的下标值，获取多维数组中相应元素的值。
// 函数Assign：根据给定的下标值，将值赋给多维数组的相应元素。
// 在main函数中，示例了一个3维数组A的构造和使用过程。
// 通过调用InitArray函数初始化数组A，
// 然后使用Assign函数将值赋给数组元素，并使用Value函数获取数组元素的值。最后，使用循环遍历并打印出整个数组。

#include <stdarg.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h> // atoi()
#include <io.h>     // eof()
#include <math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW 3
#define UNDERFLOW 4

typedef int Status;  // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
typedef int ElemType;
#define MAX_ARRAY_DIM 8 // 假设数组维数的最大值为8

typedef struct
{
    ElemType *base; // 数组元素基址，由InitArray分配
    int dim;        // 数组维数
    int *bounds;    // 数组维界基址，由InitArray分配
    int *constants; // 数组映象函数常量基址，由InitArray分配
} Array;

Status InitArray(Array *A, int dim, ...)
{
    // 若维数dim和各维长度合法，则构造相应的数组A，并返回OK
    int elemtotal = 1, i; // elemtotal是元素总值
    va_list ap;
    if (dim < 1 || dim > MAX_ARRAY_DIM)
        return ERROR;
    (*A).dim = dim;
    (*A).bounds = (int *)malloc(dim * sizeof(int));
    if (!(*A).bounds)
        exit(OVERFLOW);
    va_start(ap, dim); // ap=(va_list)&dim+sizeof(dim)    获取可变参数列表的第一个参数的地址
    for (i = 0; i < dim; ++i)
    {
        (*A).bounds[i] = va_arg(ap, int);
        if ((*A).bounds[i] < 0)
            return UNDERFLOW;
        elemtotal *= (*A).bounds[i];
    }
    va_end(ap); //   ap=(va_list)0  清空va_list可变参数列表
    (*A).base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if (!(*A).base)
        exit(OVERFLOW);
    (*A).constants = (int *)malloc(dim * sizeof(int));
    if (!(*A).constants)
        exit(OVERFLOW);
    (*A).constants[dim - 1] = 1;
    for (i = dim - 2; i >= 0; --i)
        (*A).constants[i] = (*A).bounds[i + 1] * (*A).constants[i + 1];
    return OK;
}

Status DestroyArray(Array *A)
{
    // 销毁数组A
    if ((*A).base)
    {
        free((*A).base);
        (*A).base = NULL;
    }
    else
        return ERROR;
    if ((*A).bounds)
    {
        free((*A).bounds);
        (*A).bounds = NULL;
    }
    else
        return ERROR;
    if ((*A).constants)
    {
        free((*A).constants);
        (*A).constants = NULL;
    }
    else
        return ERROR;
    return OK;
}

Status Locate(Array A, va_list ap, int *off) // Value()、Assign()调用此函数 */
{
    // 若ap指示的各下标值合法，则求出该元素在A中的相对地址off
    int i, ind;
    *off = 0;
    for (i = 0; i < A.dim; i++)
    {
        ind = va_arg(ap, int); //  ((int *)(list+=sizeof(int)))[-1]获取可变参数的当前参数，返回指定类型并将指针指向下一参数
        if (ind < 0 || ind >= A.bounds[i])
            return OVERFLOW;
        *off += A.constants[i] * ind;
    }
    return OK;
}

Status Value(ElemType *e, Array A, ...) // 在VC++中，...之前的形参不能是引用类型
{
    // 依次为各维的下标值，若各下标合法，则e被赋值为A的相应的元素值
    va_list ap;
    Status result;
    int off;
    va_start(ap, A);
    if ((result = Locate(A, ap, &off)) == OVERFLOW) // 调用Locate()
        return result;
    *e = *(A.base + off);
    return OK;
}

Status Assign(Array *A, ElemType e, ...)
{
    // 依次为各维的下标值，若各下标合法，则将e的值赋给A的指定的元素
    va_list ap;
    Status result;
    int off;
    va_start(ap, e);
    if ((result = Locate(*A, ap, &off)) == OVERFLOW) // 调用Locate()
        return result;
    *((*A).base + off) = e;
    return OK;
}

int main()
{
    Array A;
    int i, j, k, *p, dim = 3, bound1 = 3, bound2 = 4, bound3 = 2; // a[3][4][2]数组
    ElemType e, *p1;
    InitArray(&A, dim, bound1, bound2, bound3); // 构造3＊4＊2的3维数组A
    p = A.bounds;
    printf("A.bounds=");
    for (i = 0; i < dim; i++) // 顺序输出A.bounds
        printf("%d ", *(p + i));
    p = A.constants;
    printf("\nA.constants=");
    for (i = 0; i < dim; i++) // 顺序输出A.constants
        printf("%d ", *(p + i));
    printf("\n%d页%d行%d列矩阵元素如下:\n", bound1, bound2, bound3);
    for (i = 0; i < bound1; i++)
    {
        for (j = 0; j < bound2; j++)
        {
            for (k = 0; k < bound3; k++)
            {
                Assign(&A, i * 100 + j * 10 + k, i, j, k); // 将i*100+j*10+k赋值给A[i][j][k]
                Value(&e, A, i, j, k);                     // 将A[i][j][k]的值赋给e
                printf("A[%d][%d][%d]=%2d ", i, j, k, e);  // 输出A[i][j][k]
            }
            printf("\n");
        }
        printf("\n");
    }
    p1 = A.base;
    printf("A.base=\n");
    for (i = 0; i < bound1 * bound2 * bound3; i++) // 顺序输出A.base
    {
        printf("%4d", *(p1 + i));
        if (i % (bound2 * bound3) == bound2 * bound3 - 1)
            printf("\n");
    }
    DestroyArray(&A);
    return 0;
}