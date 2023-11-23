

// 二叉树的先序遍历采用的是递归的思想，因此可以递归实现
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define TElemType int

// 构造结点的结构体
typedef struct BiTNode
{
    TElemType data;         // 数据域
    struct BiTNode *lchild; // 左孩子指针
    struct BiTNode *rchild; // 右孩子指针
} BiTNode, *BiTree;

// 初始化树的函数
void CreateBiTree(BiTree *T)
{
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

// 模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

//  递归是通过函数调用栈实现的，每次递归调用会将当前函数的状态（包括参数、局部变量、返回地址等）压入调用栈中，然后进入下一层递归
// 先序遍历，用递归实现的
void PreOrderTraverse(BiTree T)
{
    if (T) // 节点不为空时
    {
        displayElem(T);              // 调用操作结点数据的函数方法
        PreOrderTraverse(T->lchild); // 访问该结点的左孩子
        PreOrderTraverse(T->rchild); // 访问该结点的右孩子
    }
    // 如果结点为空，返回上一层
    return;
    // 提前结束当前函数的执行，并立即返回到上一层。这样就实现了在空结点时返回到上一个结点的功能。
}

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("先序遍历: \n");
    PreOrderTraverse(Tree);
}