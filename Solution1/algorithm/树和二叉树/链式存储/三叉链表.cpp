#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct TriTNode
{
    TElemType data;
    struct TriTNode *lchild, *rchild; // ���Һ���ָ��
    struct TriTNode *parent;          // ˫��ָ��
} TriTNode, *TriTree;

void CreateTriTree(TriTree *T)
{
    TElemType ch;
    scanf("%d", &ch);
    if (ch == 0) // ���Ǻ�������������
                 // ����0��ʾ�սڵ�
        *T = NULL;
    else
    {
        *T = (TriTree)malloc(sizeof(TriTNode));
        if (!(*T))
            exit(1); // �ڴ����ʧ��
        (*T)->data = ch;
        (*T)->lchild = NULL;            // ��ʼ��������Ϊ��
        (*T)->rchild = NULL;            // ��ʼ��������Ϊ��
        (*T)->parent = NULL;            // ��ʼ��˫��ָ��Ϊ��
        CreateTriTree(&((*T)->lchild)); // �ݹ鴴��������
        if ((*T)->lchild != NULL)
            (*T)->lchild->parent = *T;  // ��������˫��ָ��ָ��*T�����д�����ǽ��ӽڵ��parent������ӵ��˸��ڵ�����
        CreateTriTree(&((*T)->rchild)); // �ݹ鴴��������
        if ((*T)->rchild != NULL)
            (*T)->rchild->parent = *T; // ��������˫��ָ��ָ��*T
    }
}

int main()
{
    TriTree T;
    printf("�������������ĸ��ڵ����ݣ�");
    CreateTriTree(&T);
    // ����������ĸ��ڵ������Լ����Һ�������
    if (T != NULL)
    {
        printf("���ڵ�����Ϊ��%d\n", T->data);
        if (T->lchild != NULL)
            printf("��������Ϊ��%d\n", T->lchild->data);
        else
            printf("û�����ӡ�\n");
        if (T->rchild != NULL)
            printf("�Һ�������Ϊ��%d\n", T->rchild->data);
        else
            printf("û���Һ��ӡ�\n");
    }
    return 0;
}
