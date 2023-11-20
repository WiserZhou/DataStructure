#include <iostream>
#include <stack>
using namespace std;
#include "TreeStructure.h"
typedef enum
{
    Link,
    Thread
} PointerThr;
// Link==0:指针，Thread==1:线索
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild; // 左右指针
    PointerThr LTag, RTag;             // 左右标志
} BiThrNode, *BiThrTree;

void createTreePre(BiTree &T)
{
    TElemType data;
    cin >> data;
    if (data != '#')
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = data;
        createTreePre(T->lchild);
        createTreePre(T->rchild);
    }
    else
        T = nullptr;
}
BiThrTree pre;
BiThrTree transfer(BiTree T)
{
    if (T)
    {
        BiThrTree p = (BiThrTree)malloc(sizeof(BiThrNode));
        p->data = T->data;
        // cout << p->data << "%%%%" << endl;
        if (T->lchild != nullptr)
        {
            p->LTag = Link;
            p->lchild = transfer(T->lchild);
        }
        else
        {
            p->LTag = Thread;
            p->lchild = nullptr;
        }
        if (T->rchild != nullptr)
        {
            p->RTag = Link;
            p->rchild = transfer(T->rchild);
        }
        else
        {
            p->RTag = Thread;
            p->rchild = nullptr;
        }

        return p;
    }
    else
        return nullptr;
}

void Threading(BiThrTree &Thr)
{
    if (Thr)
    {
        Threading(Thr->lchild);
        if (Thr->lchild == nullptr && Thr->LTag == Thread)
        {
            Thr->lchild = pre;
        }
        if (pre->rchild == nullptr && pre->RTag == Thread)
        {
            pre->rchild = Thr;
        }
        pre = Thr;
        Threading(Thr->rchild);
    }
}
void ThreadTree(BiThrTree &Thr, BiTree T)
{
    BiThrTree q = transfer(T);
    Thr = (BiThrTree)malloc(sizeof(BiThrNode));
    Thr->LTag = Link;
    // Thr->lchild = nullptr;
    Thr->RTag = Thread;
    Thr->rchild = Thr;
    if (!T)
        Thr->lchild = Thr;
    else
    {
        Thr->lchild = q;
        pre = Thr;
        Threading(q);
        pre->RTag = Thread;
        pre->rchild = Thr;
    }
}
void InOrder(BiThrTree Thr)
{
    int num = 1;
    BiThrTree p = Thr->lchild;

    while (p != Thr)
    {
        while (p->LTag == Link)
            p = p->lchild;
        if (p->RTag + p->LTag == 1)
            num++;
        cout << p->data;
        while (p->RTag == Thread && p->rchild != Thr)
        {
            p = p->rchild;
            if (p->RTag + p->LTag == 1)
                num++;
            cout << p->data;
        }
        p = p->rchild;
    }
    cout << "\n"
         << num;
}
int Num(BiTree T)
{
    if (T->lchild == nullptr && T->rchild == nullptr)
        return 0;
    else if (T->lchild == nullptr && T->rchild != nullptr)
        return 1 + Num(T->rchild);
    else if (T->lchild != nullptr && T->rchild == nullptr)
        return 1 + Num(T->lchild);
    else
    {
        return Num(T->lchild) + Num(T->rchild);
    }
}

int main()
{
    BiTree T;
    createTreePre(T);
    BiThrTree Thr;
    ThreadTree(Thr, T);
    InOrder(Thr);

    return 0;
}