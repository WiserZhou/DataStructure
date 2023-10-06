#include "..\header\unity.h"



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

int Depth(BiTree T)
{
    if (!T)
        depthval = 0;
    else
    {
        depthLeft = Depth(T->lchild);
    }
}

Status CreateBiTree(BiTree &T)
{
    scanf(&ch);
    if (ch == ' ')
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

void CrtExptree(BiTree &T, char exp[])
{
    InitStack(S);
    Push(S, '#');
    InitStack(PTR);
    p = exp; // 利用指针读取C风格的字符串
    ch = *p;
    while (!(GetTop(S) == '#' && ch == '#'))
    {
        if (!IN(ch, OP))
            CrtNode(t, ch);
        // 建叶子结点并入栈
        else
        {
            ....
        }
        if (ch != '#')
        {
            p++;
            ch = *p;
        }
    } // while
    Pop(PTR, T);
} // CrtExptree

switch (ch)
{
case '(':
    Push(S, ch);
    break;
case ')':
    Pop(S, c);
    while (c != '(')
    {
        CrtSubtree(t, c);
        Pop(S, c);
    }
    break;
default:
}

void CrtNode(BiTree &T, char ch)
{
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = ch;
    T->lchild = T->rchild = NULL;
    Push(PTR, T);
}

void CrtSubtree(Bitree &T, char c)
{
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = c;
    Pop(PTR, rc);
    T->rchild = rc;
    Pop(PTR, lc);
    T->lchild = lc;
    Push(PTR, T);
}

Status LevelOrderTraverse(BiTree T)
{
    Queue Q;
    InitQueue(Q);
    if (T)
        Enqueue(Q, T);
    while (!QueueEmpty(Q))
    {
        DeQueue(Q, &E);
        visit(E);
        if (E->lchild)
            EnQueue(Q, E->lchild);
        if (E->rchild)
            EnQueue(Q, E->rchild);
    }
}

typedef enum
{
    Link,
    Thread
} PointerThr;

void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}


