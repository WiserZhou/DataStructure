

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
#define TElemType int // 节点数据类型
typedef struct BiTNode
{
    TElemType data;         // 数据域
    struct BiTNode *lchild; // 左孩子指针
    struct BiTNode *rchild; // 右孩子指针
} BiTNode, *BiTree;

// 创建二叉树
void CreateBiTree(BiTree *T) // 参数是一个指向 BiTree 指针的指针 *T，用来存储二叉树的根节点
{
    // 创建根节点
    *T = (BiTNode *)malloc(sizeof(BiTNode)); // 将该空间作为二叉树的根节点
    (*T)->data = 1;                          // 根节点的数据域赋值为 1

    // 创建左子树
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    // 为根节点的左孩子指针分配内存空间，将其转换为 BiTNode 结构体的指针类型。
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
    (*T)->lchild->rchild = NULL;

    // 创建右子树
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = NULL;
    (*T)->rchild->rchild = NULL;
}

int main()
{
    BiTree Tree; // 声明了一个名为 Tree 的变量，类型为 BiTree，即指向二叉树的指针
    CreateBiTree(&Tree);

    printf("%d\n", Tree->lchild->lchild->data);
    printf("%d\n", Tree->data);
    printf("%d\n", Tree->lchild->data);
    printf("%d", Tree->rchild->data);

    return 0;
}