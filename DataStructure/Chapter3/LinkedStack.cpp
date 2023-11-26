#include "../header/unity.h"

/**
 * 链栈的构造中指针指向栈顶也就是链表的头部，在对链表的头部进行插入和删除相当于栈的栈顶
 */
typedef struct SNode
{
    SElemType data;     // 数据域
    struct SNode *next; // 链域
} SNode, *LinkStack;

void InitStack(LinkStack &S)
{
    // 注意头结点为栈顶位置，因为所有的操作都是从栈顶进行的，而且头结点好操作
    S = (SNode *)malloc(sizeof(SNode));
    if (!S)
        exit(OVERFLOW); // 存储分配失败
    S->next = NULL;
}

void Push(LinkStack &S, SElemType e)
{
    // 与顺序链表的头插法相同
    LinkStack p = (SNode *)malloc(sizeof(SNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

void Pop(LinkStack &S, SElemType &e)
{
    // 将头结点连接的下一个结点释放掉，将后面的结点连接上
    if (S->next == NULL)
        return;
    LinkStack p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
}