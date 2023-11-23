

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

typedef char DataType;
typedef struct CSNode
{
    DataType data;
    struct CSNode *firstchild, *nextchild;
} CSNode, *CSTree;

// 初始化树
void InitCSTree(CSTree *CST)
{
    (*CST) = NULL;
    printf("已初始化树\n");
}

// 创建树
void CreateCSTree(CSTree *CST)
{
    DataType x;
    scanf("%c", &x);
    if (x == '#')
    {
        (*CST) = NULL;
    }
    else
    {
        (*CST) = (CSNode *)malloc(sizeof(CSNode));
        (*CST)->data = x;
        CreateCSTree(&(*CST)->firstchild);
        CreateCSTree(&(*CST)->nextchild);
    }
}

// 先序遍历树
void PreOrderTraverse(CSTree CST)
{
    if (CST)
    {
        printf("%c ", CST->data);
        PreOrderTraverse(CST->firstchild);
        PreOrderTraverse(CST->nextchild);
    }
}

// 后序遍历树
void PostOrderTraverse(CSTree CST)
{
    if (CST)
    {
        PostOrderTraverse(CST->firstchild);
        PostOrderTraverse(CST->nextchild);
        printf("%c ", CST->data);
    }
}

//  求树的深度
int TreeDepth(CSTree T)
{
    if (!T)
        return 0;
    else
    {
        int h1 = TreeDepth(T->firstchild);
        int h2 = TreeDepth(T->nextchild);
        return (max(h1 + 1, h2));
    }
}



int main()
{
    CSTree CST;
    InitCSTree(&CST);

    // 测试用例:RAD#E##B#CFG#H#K#####
    printf("请输入构建序列:");
    CreateCSTree(&CST);

    printf("先序遍历:");
    PreOrderTraverse(CST);
    printf("\n");

    printf("后序遍历:");
    PostOrderTraverse(CST);
    printf("\n");

    printf("%d", TreeDepth(CST));
    system("pause");
    return 0;
}
