

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define TElemType int
int top = -1; // top����ʱ�̱�ʾջ��Ԫ������λ��

// ������Ľṹ��
typedef struct BiTNode
{
    TElemType data;                  // ������
    struct BiTNode *lchild, *rchild; // ���Һ���ָ��
} BiTNode, *BiTree;

// ��ʼ�����ĺ���
void CreateBiTree(BiTree *T)
{
    // ���������
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    // ����������
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = NULL;
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    // ����������
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    // ���������������Һ���ָ��ΪNULL
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

// ǰ����������ʹ�õĽ�ջ����
void push(BiTNode **a, BiTNode *elem)
{
    a[++top] = elem;
}

// ��ջ����
void pop()
{
    if (top == -1)
    {
        return;
    }
    top--;
}

// ģ��������Ԫ�صĺ����������㱾�����ֵ
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

// �õ�ջ��Ԫ��
BiTNode *getTop(BiTNode **a)
{
    return a[top];
}

// ��������ǵݹ��㷨
void InOrderTraverse1(BiTree Tree)
{
    BiTNode *a[20]; // ����һ��˳��ջ
    BiTNode *p;     // ��ʱָ��
    push(a, Tree);  // ������ջ
    while (top != -1)
    { // top != -1 ˵��ջ�ڲ�Ϊ�գ������������
        while ((p = getTop(a)) && p)
        {                       // ȡջ��Ԫ�أ��Ҳ���Ϊ NULL
            push(a, p->lchild); // ���ý������ӽ�ջ�����û�����ӣ�NULL��ջ
        }
        pop(); // ����ѭ����ջ��Ԫ�ؿ϶�ΪNULL����NULL��ջ
        if (top != -1)
        {
            p = getTop(a); // ȡջ��Ԫ��
            pop();         // ջ��Ԫ�ص�ջ
            displayElem(p);
            push(a, p->rchild); // ��pָ��Ľ����Һ��ӽ�ջ
        }
    }
}

// �������ʵ�ֵ���һ�ַ���
void InOrderTraverse2(BiTree Tree)
{
    BiTNode *a[20]; // ����һ��˳��ջ
    BiTNode *p;     // ��ʱָ��
    p = Tree;
    // ��pΪNULL����ջΪ��ʱ���������������
    while (p || top != -1)
    {
        // ���p��ΪNULL������ѹջ��������������
        if (p)
        {
            push(a, p);
            p = p->lchild;
        }
        // ���p==NULL������������������ɣ���Ҫ������һ�����������
        else
        {
            p = getTop(a);
            pop();
            displayElem(p);
            p = p->rchild;
        }
    }
}

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("��������㷨1: \n");
    InOrderTraverse1(Tree);
    printf("\n��������㷨2: \n");
    InOrderTraverse2(Tree);
    return 0;
}