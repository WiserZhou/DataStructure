

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TElemType int

// ������Ľṹ��
typedef struct BiTNode
{
    TElemType data;         // ������
    struct BiTNode *lchild; // ����ָ��
    struct BiTNode *rchild; // �Һ���ָ��
} BiTNode, *BiTree;

// ��ʼ�����ĺ���
void CreateBiTree(BiTree *T)
{
    // ��������㣬��Ϊ������ڴ�ռ�
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    // ������������������������Ϊ2
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    // ������������������������Ϊ3
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    // ���������������Ӳ�������������Ϊ4
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    // �������������Һ��Ӳ�������������Ϊ5
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    // ���������������Ӳ�������������Ϊ6
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    // �������������Һ��Ӳ�������������Ϊ7
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    // ���������������Һ���ָ��ΪNULL
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
}

// ģ��������Ԫ�صĺ����������㱾�����ֵ
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

// �������
void INOrderTraverse(BiTree T)
{
    if (T)
    {
        // �ݹ����������
        INOrderTraverse(T->lchild);
        // ���ò���������ݵĺ�������
        displayElem(T);
        // �ݹ����������
        INOrderTraverse(T->rchild);
    }
    return;
}

int main()
{
    BiTree Tree;
    // ����������
    CreateBiTree(&Tree);
    printf("��������㷨������: \n");
    INOrderTraverse(Tree);
    return 0;
}