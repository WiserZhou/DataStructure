

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

typedef char DataType;
typedef struct CSNode
{
    DataType data;
    struct CSNode *firstchild, *nextchild;
} CSNode, *CSTree;

// ��ʼ����
void InitCSTree(CSTree *CST)
{
    (*CST) = NULL;
    printf("�ѳ�ʼ����\n");
}

// ������
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

// ���������
void PreOrderTraverse(CSTree CST)
{
    if (CST)
    {
        printf("%c ", CST->data);
        PreOrderTraverse(CST->firstchild);
        PreOrderTraverse(CST->nextchild);
    }
}

// ���������
void PostOrderTraverse(CSTree CST)
{
    if (CST)
    {
        PostOrderTraverse(CST->firstchild);
        PostOrderTraverse(CST->nextchild);
        printf("%c ", CST->data);
    }
}

//  ���������
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

    // ��������:RAD#E##B#CFG#H#K#####
    printf("�����빹������:");
    CreateCSTree(&CST);

    printf("�������:");
    PreOrderTraverse(CST);
    printf("\n");

    printf("�������:");
    PostOrderTraverse(CST);
    printf("\n");

    printf("%d", TreeDepth(CST));
    system("pause");
    return 0;
}
