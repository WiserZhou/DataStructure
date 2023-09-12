#include "..\header\unity.h"

typedef struct
{
    ElemType *base;
    /**
     * top指向的是最后一个栈顶元素的后一个位置，其中没有元素，为空。
     */
    ElemType *top;
    int stackSize;
} Stack;

Status initStack(Stack &S)
{
    S.base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stackSize = STACK_INIT_SIZE;
    return OK;
}
Status getPop(Stack S, ElemType &e)
{
    if (emptyStack(S))
        return NONE;
    e = *(S.top - 1);
    return OK;
}

Status push(Stack &S, ElemType e)
{
    if (S.top - S.base >= S.stackSize)
    {
        S.base = (ElemType *)realloc(S.base, sizeof(ElemType) * (STACK_INCREMENT + S.stackSize));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stackSize;   // 栈底位置改变，重新定义栈顶位置
        S.stackSize += STACK_INCREMENT; // 此时增加的是一个元素的空间大小
    }
    *S.top++ = e; // 将top指针向后移动一个距离，始终保持top指针指向的是最后一个栈顶元素的后一位
    return OK;
}
Status pop(Stack &S, ElemType &e)
{
    if (emptyStack(S))
        return NONE;
    e = *--S.top; // 说明：此处容易使人迷惑，实际上此元素并没真正删除，仍在S.top中，但是如果插入元素，就会被更新，就像是删除了一样
    return OK;
}

Status destroyStack(Stack &S)
{
    while (!emptyStack(S))
        free(S.base);
    S.base = nullptr;
    S.top = nullptr;
    S.stackSize = 0;
    return OK;
}
Status clearStack(Stack &S)
{
    S.top = S.base;
    return OK;
}
LEN lengthStack(Stack S)
{
    return (S.top - S.base);
}
bool emptyStack(Stack S)
{
    if (S.top == S.base)
        return true;
    else
        return false;
}
bool noneStack(Stack S)
{
    if (S.base == nullptr)
        return false;
    else
        return true;
}
Status traverseStack(Stack &S, Status (*visit)(ElemType e))
{
    if (noneStack(S))
        return ERROR;
    if (emptyStack(S))
        return NONE;
    ElemType *p = S.top;
    while (p > S.base)
        visit(*--p);
}
