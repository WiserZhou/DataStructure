#include "..\header\unity.h"

typedef int ElemType;

typedef struct DuLNode
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
    for (int j = 0; j < i; j++)
    {
        p = p->next;
        if (p->next == NULL)
            return ERROR;
    }
    s->prior = p->prior;
    s->next = p;
    p->prior->next = s;
    p->prior = s;
    return OK;
}
Status deleteElem(DuLinkList &L, int i, ElemType &e)
{
    DuLinkList p = L;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
        if (p->next == NULL)
            return ERROR;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}
