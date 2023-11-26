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
 * *对于前序和后序，就如同遍历一样将中间赋值的代码调换位置即可
 */
void InThreading(BiThrTree &Thr)
{
    if (Thr)
    {
        InThreading(Thr->lchild);

        if (Thr->lchild == nullptr && Thr->LTag == Thread)
        {
            Thr->lchild = pre;
        }
        if (pre->rchild == nullptr && pre->RTag == Thread)
        {
            pre->rchild = Thr;
        }
        pre = Thr;

        InThreading(Thr->rchild);
    }
}
// 头结点的左指针： 在线索树中，头结点的左指针指向树的根节点。
// 头结点的右指针： 头结点的右指针指向中序遍历下的"最后一个"结点。这里的"最后一个"结点是指中序遍历下的最右
// 侧的结点，也可以说是最右侧的叶子结点。这个右指针的作用是为了在中序遍历中，
// 遍历到最后一个结点时，能够通过头结点的右指针回到头结点，形成一个循环。
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

        InThreading(q);

        pre->RTag = Thread; // 最后的pre指向最后一个有值的结点，他的后继自然是头结点
        pre->rchild = Thr;

        Thr->rchild = pre; // 将线索链表的尾节点的右指针指向头节点，以形成一个环。这样可以方便地遍历整个线性结构。
    }
}

// 中序遍历线索树
void InOrderThreading(BiThrTree Thr)
{
    BiThrTree p = Thr->lchild; // 从根节点的左孩子开始遍历
    while (p != Thr)           // 循环直到达到线索二叉树的末尾
    {
        while (p->LTag == Link)
            p = p->lchild; // 移动到最左边的节点
        cout << p->data;   // 输出当前节点的数据
        while (p->RTag == Thread && p->rchild != Thr)
        {
            p = p->rchild;   // 使用右线索移动到下一个节点
            cout << p->data; // 输出当前节点的数据
        }
        p = p->rchild; // 移动到右孩子，以继续中序遍历
    }
    cout << "\n"; // 输出具有线索的节点总数
}
