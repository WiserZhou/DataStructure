
#include "..\header\unity.h"

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status initList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(sizeof(LNode)));
    if (!L)
        exit(OVERFLOW);
    L->data = NULL;
    L->next = L; // 将最后一个结点的next指向头部指针
    return OK;
}