#include "..\header\unity.h"

Status InorderTraverse(BiTree T, Status (*visit)(TelemType e))
{
    initStack(S);
    Push(S, T);
    while (!StackEmpty(S))
    {
        while (GetTop(S, p) && p)
            Push(S, p->lchild);
        Pop(S, p);
        if (!StackEmpty(S))
        {
            Pop(S, p);
            if (!visit(p->data))
                return ERROR;
            Push(S, p->rchild);
        }
    }
    return OK;
}

Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if (T)
    {
        if (visit(T->data))
        {
            if (PreOrderTraverse(T->lchild, visit))
            {
                if (PreOrderTraverse(T->rchild, visit))
                    return OK;
            }
        }
        return ERROR;
    }
    else
        return OK;
}

void PreOrder(BiTree T)
{
    BiTNode *q, *p = T;
    STACK S;
    InitStack(S);
    if (p != NULL)
        PUSH(S, p);
    while (!isEmpty(S))
    {
        POP(S, q);
        visit(q);
        if (q->rchild)
            PUSH(S, q->rchild);
        if (q->lchild)
            PUSH(S, q->lchild);
    }
}


