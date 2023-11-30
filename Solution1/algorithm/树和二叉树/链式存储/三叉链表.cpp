#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct TriTNode
{
    TElemType data;
    struct TriTNode *lchild, *rchild; // 左右孩子指针
    struct TriTNode *parent;          // 双亲指针
} TriTNode, *TriTree;

void CreateTriTree(TriTree *T)
{
    TElemType ch;
    scanf("%d", &ch);
    if (ch == 0) // 这是函数结束的条件
                 // 输入0表示空节点
        *T = NULL;
    else
    {
        *T = (TriTree)malloc(sizeof(TriTNode));
        if (!(*T))
            exit(1); // 内存分配失败
        (*T)->data = ch;
        (*T)->lchild = NULL;            // 初始化左子树为空
        (*T)->rchild = NULL;            // 初始化右子树为空
        (*T)->parent = NULL;            // 初始化双亲指针为空
        CreateTriTree(&((*T)->lchild)); // 递归创建左子树
        if ((*T)->lchild != NULL)
            (*T)->lchild->parent = *T;  // 左子树的双亲指针指向*T，这行代码就是将子节点的parent结点连接到了父节点上面
        CreateTriTree(&((*T)->rchild)); // 递归创建右子树
        if ((*T)->rchild != NULL)
            (*T)->rchild->parent = *T; // 右子树的双亲指针指向*T
    }
}

int main()
{
    TriTree T;
    printf("请输入三叉树的根节点数据：");
    CreateTriTree(&T);
    // 输出三叉树的根节点数据以及左、右孩子数据
    if (T != NULL)
    {
        printf("根节点数据为：%d\n", T->data);
        if (T->lchild != NULL)
            printf("左孩子数据为：%d\n", T->lchild->data);
        else
            printf("没有左孩子。\n");
        if (T->rchild != NULL)
            printf("右孩子数据为：%d\n", T->rchild->data);
        else
            printf("没有右孩子。\n");
    }
    return 0;
}
