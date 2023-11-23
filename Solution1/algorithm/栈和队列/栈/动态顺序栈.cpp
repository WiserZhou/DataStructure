#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100 // 栈容量
#define STACKINCREMENT 10   // 栈增量

typedef int SElemType; // 假设栈中元素为整数类型

typedef struct
{
    SElemType *base; // 基地址
    SElemType *top;  // 栈顶指针
    int stacksize;   // 栈容量
} SqStack;

// 初始化栈
int InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
    {
        return 0;
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return 1;
}

// 压栈操作
int Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        // 新分配的内存地址赋给 S.base
        if (!S.base)
        {
            return 0;
        }
        // 此时再将top指针指向新的栈顶，然后再将栈扩大，这样就不会发生溢出了
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    // 将 e 的值赋给 S.top 指向的内存地址，并将 S.top 指针向后移动一个位置，指向下一个栈顶元素的地址
    return 1;
}

// 弹栈操作
int Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)  // 说明此时栈空
    {
        return 0;
    }
    else
    {
        e = *(--S.top);
    }
    return 1;
}

int main()
{
    SqStack S;
    SElemType e;

    // 初始化栈
    if (!InitStack(S))
    {
        printf("初始化栈失败！\n");
        return -1;
    }

    // 压入元素
    for (int i = 1; i <= 10; i++)
    {
        if (!Push(S, i))
        {
            printf("压入元素 %d 失败！\n", i);
            return -1;
        }
    }

    // 弹出元素
    while (Pop(S, e))
    {
        printf("%d ", e);
    }
    printf("\n");

    return 0;
}
