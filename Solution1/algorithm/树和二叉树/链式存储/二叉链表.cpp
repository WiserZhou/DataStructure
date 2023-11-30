#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// BiTNode��һ���ṹ�����ͣ��������������Ա��data�ǽڵ�洢�����ݣ�lchild��ָ�����ӽڵ��ָ�룬rchild��ָ�����ӽڵ��ָ��
// BiTree��һ��ָ��BiTNode�ṹ���ָ�����͡������ڱ�ʾһ�ö������ĸ��ڵ㡣ʹ��ָ�����ͣ����Ը�����ضԶ��������в����ͱ���

// ����������
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%d", &ch);

    if (ch == 0) // ������Ľڵ�����Ϊ0ʱ����ʾ��ǰ�ڵ�Ϊ�սڵ㣬�ݹ鴴�����������Ĺ���ֹͣ
    {            // ����0��ʾ�սڵ�
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T))
        {
            exit(1); // �ڴ����ʧ��
        }

        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild)); // �ݹ鴴��������
        CreateBiTree(&((*T)->rchild)); // �ݹ鴴��������
    }
}

// ǰ�����
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

// �������
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

// �������
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

// ���ٶ�����,��Ҫ�Զ���������Ľ�������صĲ����ģ�������Ҫ����ָ��
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
    printf("������������Ľ������(����0��ʾ�սڵ�):\n");
    CreateBiTree(&T);

    printf("ǰ��������Ϊ��");
    PreOrderTraverse(T);
    printf("\n");

    printf("����������Ϊ��");
    InOrderTraverse(T);
    printf("\n");

    printf("����������Ϊ��");
    PostOrderTraverse(T);
    printf("\n");

    DestroyBiTree(&T);

    return 0;
}
