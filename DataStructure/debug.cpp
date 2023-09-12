// 栈是仅限定在表尾进行插入和删除操作的线性表，九种栈的基本操作；分别是构造 销毁 清空 栈长 栈顶 插入 删除 遍历。下面就是代码实现：
// 头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// 宏定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int ElemType;
typedef int Status;

// 栈的顺序结构表示
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

// 1.构建一个空栈
Status InitStack(SqStack &S)
{
    S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base)
        exit(OVERFLOW); // 存储分配失败
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

// 2.销毁栈
Status DestroyStack(SqStack &S)
{
    S.top = NULL;
    S.stacksize = 0;
    free(S.base);
    S.base = nullptr;
    return OK;
}

// 3.清空栈
Status ClearStack(SqStack &S)
{
    S.top = S.base;
    return OK;
}

// 4.判断栈是否为空
Status StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return ERROR;
    else
        return TRUE;
}

// 5.求栈的长度
Status StackLength(SqStack S)
{
    if (S.top == S.base)
        return FALSE;
    else
        return (S.top - S.base); // 也可以直接返回S.top - S.base
}

// 6.//求栈顶元素
Status GetTop(SqStack S, ElemType &e)
{
    if (S.top == S.base)
        return FALSE;
    else
        e = *(S.top - 1);
    return e;
}

// 7.栈顶插入元素
Status Push(SqStack &S, ElemType &e)
{
    if (S.top - S.base >= STACK_INIT_SIZE)
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
        {
            return false;
        }
        S.top = S.base + STACK_INIT_SIZE; // 栈底地址可能改变，重新定位栈顶元素
        S.stacksize = S.stacksize + STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}

// 8.删除栈顶元素
Status Pop(SqStack &S, ElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    else
    {
        S.top--;
        e = *S.top; // 说明：此处容易使人迷惑，实际上此元素并没真正删除，仍在S.top中，但是如果插入元素，就会被更新，就像是删除了一样
        return e;
    }
}

// 9.遍历栈
Status StackTraverse(SqStack S)
{
    if (S.base == NULL)
        return ERROR;
    if (S.top == S.base)
        printf("栈中没有元素……\n");
    ElemType *p;
    p = S.top;
    while (p > S.base)
    {
        p--;
        printf("%d ", *p);
    }

    return OK;
}

// 主函数检验九种操作
int main()
{
    SqStack S;
    printf("构造一个空栈……\n");
    InitStack(S);
    int i, n;
    printf("输入栈的长度:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("输入栈的第%d个元素\n", i);
        ++S.top;
        scanf("%d", S.top - 1);
    }
    printf("……本栈是空栈吗？？……\n");
    if (StackEmpty(S) == 1)
        printf("NO !!!\n");
    else
        printf("YES !!!\n");
    printf("……求出栈的长度……\n");
    int m;
    m = StackLength(S);
    printf("栈的长度是:\n");
    printf("%d\n", m);
    printf("遍历输出栈中的所有元素:\n");
    StackTraverse(S);
    printf("\n");
    printf("……输出栈顶元素……\n");
    int e;
    e = GetTop(S, e);
    printf("栈顶元素是:\n");
    printf("%d\n", e);
    printf("……栈顶插入元素……\n");
    printf("请输入要插入的元素的数值:\n");
    scanf("%d", &e);
    Push(S, e);
    printf("现在栈中的元素是:\n");
    StackTraverse(S);
    printf("\n");
    printf("……栈顶删除元素……\n");
    e = Pop(S, e);
    printf("被删除的元素是:\n");
    scanf("%d", &e);
    printf("现在栈中的元素是:\n");
    StackTraverse(S);
    printf("\n");
    printf("……清空栈……\n");
    ClearStack(S);
    printf("现在栈中的元素是:\n");
    StackTraverse(S);
    printf("……销毁栈……\n");
    if (DestroyStack(S) == 1)
        printf("销毁栈成功\n");
    else
        printf("销毁栈失败\n");
    printf("喜您成功完成所有的功能,毕竟您那么帅!!!\n");
    return 0;
}

// ————————————————
// 版权声明：本文为CSDN博主「6个小石头」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/LiuJiuXiaoShiTou/article/details/53394888