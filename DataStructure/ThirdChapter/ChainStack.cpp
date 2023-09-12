#include "..\header\unity.h"

typedef struct SNode
{
    ElemType data;
    struct SNode *next;
} SNode, *LinkStack;

Status initStack(LinkStack &S)
{
    S = (SNode *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if (!S)
        exit(OVERFLOW);
    S->next = NULL;
    return OK;
}
Status push(LinkStack &S, ElemType e)
{
    SNode *p = (SNode *)malloc(sizeof(ElemType));
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = S->next;
    S->next = p;
    return OK;
}
Status pop(LinkStack S, ElemType &e)
{
    if (S->next == NULL)
        return NONE;
    SNode *p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
    p = nullptr;
    return OK;
}