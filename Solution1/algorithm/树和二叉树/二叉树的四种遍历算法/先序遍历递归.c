

// ������������������õ��ǵݹ��˼�룬��˿��Եݹ�ʵ��
#include <stdio.h>
#include<stdlib.h>
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

// ģ��������Ԫ�صĺ����������㱾�����ֵ
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

//  �ݹ���ͨ����������ջʵ�ֵģ�ÿ�εݹ���ûὫ��ǰ������״̬�������������ֲ����������ص�ַ�ȣ�ѹ�����ջ�У�Ȼ�������һ��ݹ�
// ����������õݹ�ʵ�ֵ�
void PreOrderTraverse(BiTree T)
{
    if (T) // �ڵ㲻Ϊ��ʱ
    {
        displayElem(T);              // ���ò���������ݵĺ�������
        PreOrderTraverse(T->lchild); // ���ʸý�������
        PreOrderTraverse(T->rchild); // ���ʸý����Һ���
    }
    // ������Ϊ�գ�������һ��
    return;
    // ��ǰ������ǰ������ִ�У����������ص���һ�㡣������ʵ�����ڿս��ʱ���ص���һ�����Ĺ��ܡ�
}

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("�������: \n");
    PreOrderTraverse(Tree);
}