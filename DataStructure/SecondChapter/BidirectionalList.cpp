#include "..\header\unity.h"

typedef int ElemType;

typedef struct DuLNode // 双向链表的结构
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

Status insertList(DuLinkList &L, int i, ElemType e)
{
    DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    DuLinkList p = L;
    int j = 1;

    while (p && j++ < i)
        p = p->next;
    if (!p || j > i)
        return ERROR;

    s->prior = p->prior; // 将s插入到p的前面
    s->next = p;
    p->prior->next = s;
    p->prior = s;

    return OK;
}
Status deleteElem(DuLinkList &L, int i, ElemType &e)
{
    DuLinkList p = L;
    int j = 1;

    while (p && j++ < i)
        p = p->next;
    if (!p || j > i)
        return ERROR;

    e = p->data;
    
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}
