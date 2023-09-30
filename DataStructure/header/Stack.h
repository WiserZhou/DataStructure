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
    ~Stack();
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
Stack::~Stack()
{
    destroy();
}
void Stack::display()
{
    SElemType *p = top;
    while (p != base)
        cout << *--p << " ";
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
    return top == base;
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
typedef struct SNode
{
    SElemType e;
    struct SNode *next;
} SNode, *LinkedNode;

/**
 * 具体来说，入栈操作就是在链表的表头插入一个节点，然后更新栈顶指针。
 * 出栈操作就是将栈顶元素弹出，也就是删除链表的表头节点，并返回该节点的值，然后更新栈顶指针。
 */
class LinkedStack
{
private:
    SNode *top;
    SNode *createNode();

public:
    LinkedStack();
    void push(SElemType e);
    SElemType pop();
    bool isEmpty();
    ~LinkedStack();
};
LinkedStack::~LinkedStack()
{
    SNode *p = top->next;
    while (!top)
    {
        free(top);
        top = p;
        p = p->next;
    }
}
bool LinkedStack::isEmpty()
{
    return top == nullptr;
}
LinkedStack::LinkedStack()
{
    top = createNode();
}

SNode *LinkedStack::createNode()
{
    SNode *p = (SNode *)malloc(sizeof(SNode));
    if (!p)
        exit(OVERFLOW);
    // p->e = 元素值; // 替换元素值为实际需要赋值的值
    p->next = nullptr;
    return p;
}
void LinkedStack::push(SElemType e)
{
    SNode *p = createNode();
    p->e = e;
    p->next = top; // 新来的链接在前面
    top = p;
}
SElemType LinkedStack::pop()
{
    if (isEmpty())
        return NONE;      // 栈为空则退出程序
    SElemType e = top->e; // 获取栈顶元素的值
    SNode *p = top;       // 记录当前栈顶元素
    top = p->next;        // 更新栈顶指针为下一个节点
    free(p);              // 释放原栈顶节点的内存空间
    return e;             // 返回弹出的元素值
}
