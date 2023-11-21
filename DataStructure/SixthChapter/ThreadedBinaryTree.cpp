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
/**
 * 中序线索化
 */
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

    if (!(Thr = (BiThrTree)malloc(sizeof(BiThrNode))))
        exit(1); // 创建头结点

    Thr->LTag = Link;
    // Thr->lchild = nullptr;
    Thr->RTag = Thread;
    Thr->rchild = Thr; // 右指针回指

    if (!T)
        Thr->lchild = Thr;
    else
    {
        Thr->lchild = q;
        pre = Thr; // 最开始的pre指向头结点

        Threading(q);

        pre->RTag = Thread; // 最后的pre指向最后一个有值的结点，他的后继自然是头结点
        pre->rchild = Thr;

        Thr->rchild = pre; // 将线索链表的尾节点的右指针指向头节点，以形成一个环。这样可以方便地遍历整个线性结构。
    }
}

void InOrder(BiThrTree Thr)
{
    int num = 1;               // Initialize a counter for nodes with threads
    BiThrTree p = Thr->lchild; // Start with the left child of the root

    while (p != Thr) // Loop until we reach the end of the threaded binary tree
    {
        while (p->LTag == Link)
            p = p->lchild; // Move to the leftmost node

        if (p->RTag + p->LTag == 1)
            num++; // If the node has either a left or right thread, increment the counter

        cout << p->data; // Output the data of the current node

        while (p->RTag == Thread && p->rchild != Thr)
        {
            p = p->rchild; // Move to the next node using the right thread

            if (p->RTag + p->LTag == 1)
                num++; // If the node has either a left or right thread, increment the counter

            cout << p->data; // Output the data of the current node
        }

        p = p->rchild; // Move to the right child to continue the in-order traversal
    }

    cout << "\n"
         << num; // Output the total count of nodes with threads
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