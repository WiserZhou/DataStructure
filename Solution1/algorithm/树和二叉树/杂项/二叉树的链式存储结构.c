

#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
#define TElemType int // �ڵ���������
typedef struct BiTNode
{
    TElemType data;         // ������
    struct BiTNode *lchild; // ����ָ��
    struct BiTNode *rchild; // �Һ���ָ��
} BiTNode, *BiTree;

// ����������
void CreateBiTree(BiTree *T) // ������һ��ָ�� BiTree ָ���ָ�� *T�������洢�������ĸ��ڵ�
{
    // �������ڵ�
    *T = (BiTNode *)malloc(sizeof(BiTNode)); // ���ÿռ���Ϊ�������ĸ��ڵ�
    (*T)->data = 1;                          // ���ڵ��������ֵΪ 1

    // ����������
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    // Ϊ���ڵ������ָ������ڴ�ռ䣬����ת��Ϊ BiTNode �ṹ���ָ�����͡�
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
    (*T)->lchild->rchild = NULL;

    // ����������
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = NULL;
    (*T)->rchild->rchild = NULL;
}

int main()
{
    BiTree Tree; // ������һ����Ϊ Tree �ı���������Ϊ BiTree����ָ���������ָ��
    CreateBiTree(&Tree);

    printf("%d\n", Tree->lchild->lchild->data);
    printf("%d\n", Tree->data);
    printf("%d\n", Tree->lchild->data);
    printf("%d", Tree->rchild->data);

    return 0;
}