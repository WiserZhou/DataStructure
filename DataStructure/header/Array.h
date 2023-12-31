#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#define MAX_ARRAY_DIM 8
typedef int ElemType;
#define ERROR -1
#define OVERFLOW -2
#define UNDERFLOW -3

// typedef int array1[4];
// typedef array1 array2[5];
// typedef int array3[4][5];
// typedef定义的多维数组的名称
class Array
{
private:
    ElemType *base; // 数组元素基址
    int dim;        // 数组维度
    int *bounds;    // 数组维界地址
    int *constants; // 数组映像函数常量基址

public:
    Array(int dim, ...); // 构造函数声明
    ~Array();
    int locate(va_list ap);
    ElemType getValue(...);
    bool setValue(ElemType e, ...);
};
bool Array::setValue(ElemType e, ...)
{
    va_list ap;
    va_start(ap, dim);
    int offset = locate(ap);
    if (offset < 0)
        return false;
    va_end(ap);
    *(base + offset) = e;
    return true;
}

ElemType Array::getValue(...)
{
    va_list ap;
    va_start(ap, dim);
    int offset = locate(ap);
    if (offset < 0)
        return UNDERFLOW;
    // if ((result =) <= 0)
    //     return result
    va_end(ap);
    return *(base + offset);
    // return OK:
}
/**
 * 获取定位位置的元素索引
 */
int Array::locate(va_list ap)
{
    int off = 0;
    for (int i = 0; i < dim; i++)
    {
        int ind = va_arg(ap, int);
        if (ind < 0 || ind >= bounds[i])
            return OVERFLOW;
        off += constants[i] * ind; // 根据提供的每个维度的定位得到顺序表里的储存位置
    }
    return off;
}
Array::~Array()
{
    if (!base)
    {
        std::cout << "base = nullptr" << std::endl;
        return;
    }
    free(base);
    base = nullptr;

    if (!bounds)
    {
        std::cout << "bounds = nullptr" << std::endl;
    }
    free(bounds);
    bounds = nullptr;

    if (!constants)
    {
        std::cout << "bounds = nullptr" << std::endl;
        return;
    }
    free(constants);
    constants = nullptr;
}
Array::Array(int dim, ...) // 构造函数的实现
{
    if (dim < 1 || dim > MAX_ARRAY_DIM) // 数组维度合法性检查
        exit(ERROR);                    // 退出程序，返回错误代码

    this->dim = dim; // 将传入的数组维度赋值给对象的 dim 属性

    if (!(this->bounds = (int *)malloc(sizeof(int) * dim))) // 为维界地址分配内存
        exit(OVERFLOW);                                     // 内存分配失败，退出程序，返回溢出错误代码

    int elemTotal = 1; // 计算数组元素的总个数

    va_list ap;                   // 声明 va_list 类型的变量 ap，用于访问可变参数
    va_start(ap, dim);            // 初始化 va_list 变量 ap，以获取可变参数
    for (int i = 0; i < dim; i++) // 遍历各维度
    {
        bounds[i] = va_arg(ap, int); // 通过 va_arg 获取可变参数的值，赋给当前维度的界限
        if (bounds[i] < 0)           // 维度界限小于 0，说明参数传递错误
            exit(UNDERFLOW);         // 退出程序，返回下溢错误代码
        elemTotal *= bounds[i];      // 计算数组元素的总个数
    }
    va_end(ap); // 结束对可变参数的访问

    if (!(base = (ElemType *)malloc(sizeof(ElemType) * elemTotal))) // 为数组元素基址分配内存
        exit(OVERFLOW);                                             // 内存分配失败，退出程序，返回溢出错误代码
    if (!(constants = (int *)malloc(sizeof(int) * dim)))            // 为映像函数常量地址分配内存
        exit(OVERFLOW);                                             // 内存分配失败，退出程序，返回溢出错误代码
    constants[dim - 1] = 1;                                         // 最后一个维度的映像函数常量为 1
    for (int i = dim - 2; i >= 0; --i)                              // 从倒数第二个维度开始向前计算映像函数常量
        constants[i] = bounds[i + 1] * constants[i + 1];            // 根据下一个维度的界限和常量，计算当前维度的常量
}
