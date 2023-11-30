#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct BPTNode // ���ṹ
{
    TElemType data;
    struct BPTNode *parent; // ָ��˫�׵�ָ��
    char LRTag;             // ���Һ��ӱ�־��
} BPTNode;

typedef struct BPTree // ���ṹ
{
    BPTNode nodes[MAX_TREE_SIZE];
    int num_node; // �����Ŀ
    int root;     // ������λ��
} BPTree;

void InitBPTree(BPTree *T)
{
    T->num_node = 0; // ��ʼ�������ĿΪ0
    T->root = -1;    // ��ʼ�����ڵ�λ��Ϊ-1����ʾΪ����
}

int CreateBPTree(BPTree *T, TElemType e)
{
    if (T->num_node >= MAX_TREE_SIZE)
        return -1; // �����Ŀ�Ѵﵽ����������޷������½��

    T->nodes[T->num_node].data = e;      // �����½���������
    T->nodes[T->num_node].parent = NULL; // ��ʼ��˫��ָ��Ϊ��
    T->nodes[T->num_node].LRTag = 'N';   // ��ʼ�����Һ��ӱ�־��Ϊ��N������ʾ�����Һ���

    return T->num_node++; // �����½���������е��±꣬���������Ŀ��һ
}

void SetLChild(BPTree *T, int p, int c)
{
    T->nodes[p].LRTag = 'L';             // ����p�������ӱ�־��Ϊ��L������ʾ������
    T->nodes[c].parent = &(T->nodes[p]); // ����c����˫��ָ��ָ��p���
}

void SetRChild(BPTree *T, int p, int c)
{
    T->nodes[p].LRTag = 'R';             // ����p�����Һ��ӱ�־��Ϊ��R������ʾ���Һ���
    T->nodes[c].parent = &(T->nodes[p]); // ����c����˫��ָ��ָ��p���
}

int main()
{
    BPTree T;
    InitBPTree(&T);

    // �������ڵ�������ӽڵ�
    int root = CreateBPTree(&T, 1);
    int lchild = CreateBPTree(&T, 2);
    int rchild = CreateBPTree(&T, 3);
    printf("���ڵ�����Ϊ��%d\n", T.nodes[root].data);
    // ���������ӽڵ�
    SetLChild(&T, root, lchild);
    if (T.nodes[root].LRTag == 'L')
        printf("��������Ϊ��%d\n", T.nodes[lchild].data);
    else
        printf("û�����ӡ�\n");
    SetRChild(&T, root, rchild); // ��ǰ��Ĵ������ǰ�root��LRTag���ó�Ϊ��'L'����������Ĵ����ֻ��LRTag���ó�'R'
    if (T.nodes[root].LRTag == 'R')
        printf("�Һ�������Ϊ��%d\n", T.nodes[rchild].data);
    else
        printf("û���Һ��ӡ�\n");
    return 0;
}
