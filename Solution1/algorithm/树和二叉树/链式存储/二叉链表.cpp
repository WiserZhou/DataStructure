#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// BiTNode是一个结构体类型，其包含了三个成员：data是节点存储的数据，lchild是指向左子节点的指针，rchild是指向右子节点的指针
// BiTree是一个指向BiTNode结构体的指针类型。它用于表示一棵二叉树的根节点。使用指针类型，可以更方便地对二叉树进行操作和遍历

// 创建二叉树
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%d", &ch);

    if (ch == 0) // 当输入的节点数据为0时，表示当前节点为空节点，递归创建左右子树的过程停止
    {            // 输入0表示空节点
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T))
        {
            exit(1); // 内存分配失败
        }

        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild)); // 递归创建左子树
        CreateBiTree(&((*T)->rchild)); // 递归创建右子树
    }
}

// 前序遍历
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }

    printf("%d ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

// 中序遍历
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }

    InOrderTraverse(T->lchild);
    printf("%d ", T->data);
    InOrderTraverse(T->rchild);
}

// 后序遍历
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }

    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d ", T->data);
}

// 销毁二叉树,需要对二叉树里面的结点进行相关的操作的，所以需要传入指针
void DestroyBiTree(BiTree *T)
{
    if (*T == NULL)
    {
        return;
    }

    DestroyBiTree(&((*T)->lchild));
    DestroyBiTree(&((*T)->rchild));
    free(*T);
    *T = NULL;
}

int main()
{
    BiTree T = NULL;
    printf("请输入二叉树的结点数据(输入0表示空节点):\n");
    CreateBiTree(&T);

    printf("前序遍历结果为：");
    PreOrderTraverse(T);
    printf("\n");

    printf("中序遍历结果为：");
    InOrderTraverse(T);
    printf("\n");

    printf("后序遍历结果为：");
    PostOrderTraverse(T);
    printf("\n");

    DestroyBiTree(&T);

    return 0;
}
