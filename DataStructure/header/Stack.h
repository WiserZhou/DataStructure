#define OVERFLOW -2
#define ERROR 0

#define OK 1
#define TRUE 1
#define FALSE 0
#define NONE 0
// typedef int ElemType;
typedef int Status;
typedef int Position;
typedef int LEN;
typedef int SElemType;
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#include <iostream>
using namespace std;

class Stack
{
private:
    SElemType *base;
    SElemType *top;
    int stackSize;
    void addSpace();

public:
    Stack();
    SElemType getTop();
    void push(SElemType e);
    SElemType pop();
    void destroy();
    void clear();
    bool isEmpty();
    LEN length();
    void traverse(Status (*visit)(SElemType &e));
    void display();
};
void Stack::display()
{
    SElemType *p = top;
    while (p != base)
        cout << *--p<<" ";
}
void Stack::traverse(Status (*visit)(SElemType &e))
{
    SElemType *p = top;
    while (p != base)
        visit(*--p);
    // visit(*p);
}
LEN Stack::length()
{
    return top - base;
}
bool Stack::isEmpty()
{
    if (top == base)
        return true;
    else
        return false;
}
void Stack::clear()
{
    top = base; // 就算有元素存在也可以不必考虑，把他们都当成最开始初始化的0值即可
}
void Stack::destroy()
{
    free(base);
    base = nullptr;
    top = nullptr;
    stackSize = 0;
}

SElemType Stack::pop()
{
    if (base == top)
        return NONE;
    return *--top; // top指向的永远都是栈顶元素的下一个位置，所以要先减
}
void Stack::addSpace()
{
    base = (SElemType *)realloc(base, sizeof(SElemType) * (stackSize + STACK_INCREMENT));
    if (!base)
        exit(OVERFLOW);

    top = base + stackSize; // 虽然申请了更大的空间，但是元素个数没变
    stackSize += STACK_INCREMENT;
}
Stack::Stack()
{
    base = (SElemType *)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
    if (!base)
        exit(OVERFLOW);
    top = base;
    stackSize = STACK_INIT_SIZE;
    cout << "stack init success" << endl;
}
SElemType Stack::getTop()
{
    if (base == top)
        return NONE;
    else
        return *(top - 1);
}
void Stack::push(SElemType e)
{
    if (top - base >= stackSize)
        addSpace();
    *top++ = e;
}
