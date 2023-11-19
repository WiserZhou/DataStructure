#include "TreeStructure.h"
#include "../header/unity.h"

// 生成一个二叉树的结点(其数据域为item, 左指针域为lchild, 右指针域为rchild)
BiTNode *GetTreeNode(TElemType item, BiTNode *lchild, BiTNode *rchild)
{
    BiTree T;
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
        exit(1);
    T->data = item;
    T->lchild = lchild;
    T->rchild = rchild;
    return T;
}

BiTNode *CopyTree(BiTNode *T)
{
    BiTree newLeftPtr;
    BiTree newRightPtr;

    if (!T)
        return NULL;

    if (T->lchild)
        newLeftPtr = CopyTree(T->lchild); // 复制左子树
    else
        newLeftPtr = NULL;

    if (T->rchild)
        newRightPtr = CopyTree(T->rchild); // 复制右子树
    else
        newRightPtr = NULL;

    BiTree newTree = GetTreeNode(T->data, newLeftPtr, newRightPtr);

    return newTree;
} // CopyTree