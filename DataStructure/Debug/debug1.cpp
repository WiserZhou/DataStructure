#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
//----- 栈的顺序存储表示 -----
#define STACK_INIT_SIZE 100 // 栈容量
#define STACK_INCREMENT 10  // 栈增量
#include "../header/unity.h"
typedef int SElemType;
typedef struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stackSize;
} SqStack;

Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
    S.top = S.base;
    S.stackSize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stackSize)
    {
        S.base = (SElemType *)realloc(sizeof(SElemType) * (S.stackSize + STACK_INCREMENT));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stackSize;
        S.stackSize += STACK_INCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)
        return NONE;
    else
        e = *(--S.top);
    return OK;
}