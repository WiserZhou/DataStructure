

#include <stdio.h>
#include <stdlib.h>
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
    // 创建根结点，并为其分配内存空间
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    // 创建左子树并设置其数据域为2
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    // 创建右子树并设置其数据域为3
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    // 创建左子树的左孩子并设置其数据域为4
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    // 创建左子树的右孩子并设置其数据域为5
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    // 创建右子树的左孩子并设置其数据域为6
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    // 创建右子树的右孩子并设置其数据域为7
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    // 设置其他结点的左右孩子指针为NULL
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
}

// 模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

// 中序遍历
void INOrderTraverse(BiTree T)
{
    if (T)
    {
        // 递归遍历左子树
        INOrderTraverse(T->lchild);
        // 调用操作结点数据的函数方法
        displayElem(T);
        // 递归遍历右子树
        INOrderTraverse(T->rchild);
    }
    return;
}

int main()
{
    BiTree Tree;
    // 创建二叉树
    CreateBiTree(&Tree);
    printf("中序遍历算法输出结果: \n");
    INOrderTraverse(Tree);
    return 0;
}