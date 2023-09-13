#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ERROR -2
#define OVERFLOW -1
class Stack
{
private:
    ElemType *base;
    ElemType *top;
    int stackSize;

public:
    Stack()
    {
        base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
        if (!base)
            exit(OVERFLOW);
        top = base;
        stackSize = STACK_INIT_SIZE;
    }
    void push(ElemType e)
    {
        if (top - base >= stackSize)
        {
            ElemType *p = (ElemType *)realloc(base, sizeof(ElemType) * (stackSize + STACK_INCREMENT));
            if (!p)
                exit(OVERFLOW);
            top = base + stackSize;
            stackSize += STACK_INCREMENT;
        }
        *top++ = e;
    }
    int pop()
    {
        if (base == top)
            return ERROR;
        return *--top;
    }
    bool empty()
    {
        if (top == base)
            return true;
        else
            return false;
    }
};
char transfer(int x)
{
    if (x < 10)
        return x + '0';
    else if (x == 10)
        return 'A';
    else if (x == 11)
        return 'B';
    else if (x == 12)
        return 'C';
    else if (x == 13)
        return 'D';
    else if (x == 14)
        return 'E';
    else
        return 'F';
}
int main()
{
    Stack S;
    int a, b;
    scanf("%d%d", &a, &b);
    while (a)
    {
        int e = a % b;
        a /= b;
        S.push(e);
    }
    while (!S.empty())
        printf("%c", transfer(S.pop()));
    return 0;
}