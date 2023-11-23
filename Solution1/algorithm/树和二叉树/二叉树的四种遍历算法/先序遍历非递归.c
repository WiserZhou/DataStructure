

// ʹ��˳��ջ��ģ��ݹ���õĹ��̣�ͨ�����ϵص�ջ��ѹջ���������ṹ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TElemType int
int top = -1; // top����ʱ�̱�ʾջ��Ԫ������λ��,ȫ�ֱ���

// ������Ľṹ��
typedef struct BiTNode
{
    TElemType data;                  // ������
    struct BiTNode *lchild;         // ����ָ��
    struct BiTNode *rchild;         // �Һ���ָ��
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

// �������ʹ�õĽ�ջ����
void push(BiTNode **a, BiTNode *elem)
// BiTNode **a����ʾһ��ָ��ָ�������ָ�룬��ָ���������ڱ�ʾջ�ṹ
// BiTNode *elem����ʾҪѹ��ջ�еĶ������ڵ�ָ��
{
    a[++top] = elem;
    // top ��������ջ��Ԫ�����ڵ�λ�ã���ʼֵΪ -1
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
// BiTNode **a����ʾһ��ָ��ָ�������ָ�룬��ָ���������ڱ�ʾջ�ṹ
{
    return a[top];
}

// ��������ǵݹ��㷨
void PreOrderTraverse(BiTree Tree)
{
    BiTNode *a[20]; // ����һ��˳��ջ
    BiTNode *p;     // ��ʱָ��
    push(a, Tree);  // ������ջ
    while (top != -1)
    {
        p = getTop(a); // ȡջ��Ԫ�أ���һ��ȡ���ľ��Ǹ��ڵ��Ԫ��
        pop();         // ��ջ
        while (p)
        {
            displayElem(p); // ���ý��Ĳ�������,��������Ǵ�ӡ��Ԫ�صĴ���,��ӡ��������������û�н�ջ
            // ����ý�����Һ��ӣ��Һ��ӽ�ջ
            if (p->rchild)
            {
                push(a, p->rchild);
            }
            p = p->lchild; // һֱָ���������һ������
        }
    }
}

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("�������: \n");
    PreOrderTraverse(Tree);
    return 0;
}