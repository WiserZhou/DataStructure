#include "..\header\unity.h"

typedef struct
{
    ElemType *base;
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
Status push(Stack &S, ElemType e)
{
    if (S.top - S.base >= S.stackSize)
    {
        S.base = (ElemType *)realloc(S.base, sizeof(ElemType) * (STACK_INCREMENT + S.stackSize));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stackSize;
        S.stackSize += STACK_INCREMENT;
    }
    *S.top++ = e;
    return OK;
}
Status pop(Stack &S, ElemType &e)
{
    if (S.top == S.base)
        return NONE;
    else
    {
        e = *(S.top - 1);
        S.top--;
    }
}
