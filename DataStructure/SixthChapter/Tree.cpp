// #include "..\header\unity.h"

// Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
// {
//     if (T)
//     {
//         if (visit(T->data))
//         {
//             if (PreOrderTraverse(T->lchild, visit))
//             {
//                 if (PreOrderTraverse(T->rchild, visit))
//                     return OK;
//             }
//         }
//         return ERROR;
//     }
//     else
//         return OK;
// }

// void PreOrder(BiTree T)
// {
//     BiTNode *q, *p = T;
//     STACK S;
//     InitStack(S);
//     if (p != NULL)
//         PUSH(S, p);
//     while (!isEmpty(S))
//     {
//         POP(S, q);
//         visit(q);
//         if (q->rchild)
//             PUSH(S, q->rchild);
//         if (q->lchild)
//             PUSH(S, q->lchild);
//     }
// }

// int Depth(BiTree T)
// {
//     if (!T)
//         depthval = 0;
//     else
//     {
//         depthLeft = Depth(T->lchild);
//     }
// }

// void CrtExptree(BiTree &T, char exp[])
// {
//     InitStack(S);
//     Push(S, '#');
//     InitStack(PTR);
//     p = exp; // 利用指针读取C风格的字符串
//     ch = *p;
//     while (!(GetTop(S) == '#' && ch == '#'))
//     {
//         if (!IN(ch, OP))
//             CrtNode(t, ch);
//         // 建叶子结点并入栈
//         else
//         {
//             ....
//         }
//         if (ch != '#')
//         {
//             p++;
//             ch = *p;
//         }
//     } // while
//     Pop(PTR, T);
// } // CrtExptree

// switch (ch)
// {
// case '(':
//     Push(S, ch);
//     break;
// case ')':
//     Pop(S, c);
//     while (c != '(')
//     {
//         CrtSubtree(t, c);
//         Pop(S, c);
//     }
//     break;
// default:
// }

// void CrtNode(BiTree &T, char ch)
// {
//     T = (BiTNode *)malloc(sizeof(BiTNode));
//     T->data = ch;
//     T->lchild = T->rchild = NULL;
//     Push(PTR, T);
// }

// void CrtSubtree(Bitree &T, char c)
// {
//     T = (BiTNode *)malloc(sizeof(BiTNode));
//     T->data = c;
//     Pop(PTR, rc);
//     T->rchild = rc;
//     Pop(PTR, lc);
//     T->lchild = lc;
//     Push(PTR, T);
// }

// Status LevelOrderTraverse(BiTree T)
// {
//     Queue Q;
//     InitQueue(Q);
//     if (T)
//         Enqueue(Q, T);
//     while (!QueueEmpty(Q))
//     {
//         DeQueue(Q, &E);
//         visit(E);
//         if (E->lchild)
//             EnQueue(Q, E->lchild);
//         if (E->rchild)
//             EnQueue(Q, E->rchild);
//     }
// }

// typedef enum
// {
//     Link,
//     Thread
// } PointerThr;

// void InThreading(BiThrTree p)
// {
//     if (p)
//     {
//         InThreading(p->lchild);
//         if (!p->lchild)
//         {
//             p->LTag = Thread;
//             p->lchild = pre;
//         }
//         if (!pre->rchild)
//         {
//             pre->RTag = Thread;
//             pre->rchild = p;
//         }
//         pre = p;
//         InThreading(p->rchild);
//     }
// }

#include <iostream>
#include <stack>
using namespace std;
#define END '#'
typedef struct Node
{
    char ch;
    struct Node *l_child;
    struct Node *r_child;
} *Tree, TNode;

void CreateTree(Tree &T)
{
    char ch;
    cin >> ch;
    if (ch != END)
    {
        T = (Tree)malloc(sizeof(TNode));
        T->ch = ch;
        CreateTree(T->l_child);
        CreateTree(T->r_child);
    }
    else
        T = nullptr;
}

void PreOrder(Tree T)
{
    if (T)
    {
        cout << T->ch;
        PreOrder(T->l_child);
        PreOrder(T->r_child);
    }
    // cout << "\n";
}
void InOrder(Tree T)
{
    if (T)
    {
        InOrder(T->l_child);
        cout << T->ch;
        InOrder(T->r_child);
    }
}
void ReOrder(Tree T)
{
    if (T)
    {
        ReOrder(T->l_child);
        ReOrder(T->r_child);
        cout << T->ch;
    }
}
void InOrderNoRecursion(Tree T)
{
    stack<Tree> S;
    Tree p = T;
    while (p || !S.empty())
    {
        if (p)
        {
            S.push(p);
            p = p->l_child; // 根指针进栈，访问他的左子树
        }
        else
        {
            p = S.top();
            S.pop(); // 根指针退栈，访问他的右子树
            cout << p->ch;
            p = p->r_child;
        }
    }
    // return OK;
}

int depth(Tree T)
{
    if (T)
    {
        int depth1 = 1 + depth(T->l_child);
        int depth2 = 1 + depth(T->r_child);
        return depth1 > depth2 ? depth1 : depth2;
    }
    else
        return 0;
}

int numLeaf(Tree T)
{
    if (!T)
        return 0;
    if (!T->l_child && !T->r_child)
        return 1;
    else
        return numLeaf(T->l_child) + numLeaf(T->r_child);
}

int main()
{
    Tree T;
    CreateTree(T);
    PreOrder(T);
    cout << "\n";
    InOrder(T);
    cout << "\n";
    ReOrder(T);
    cout << "\n";
    cout << numLeaf(T) << "\n";
    cout << depth(T) << "\n";
    InOrderNoRecursion(T);
    cout << "\n";
    return 0;
}