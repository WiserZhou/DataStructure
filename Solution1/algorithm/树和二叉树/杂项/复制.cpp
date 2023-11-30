

#include <iostream>
#include <cstdlib>

// ����������ڵ�ṹ
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

// ����һ���µĶ������ڵ�
BiTNode *GetTreeNode(int item, BiTNode *lptr, BiTNode *rptr)
{
    BiTNode *T;   // ��ҪΪT�����㣬Ȼ���ٽ�����صĲ���
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
        exit(1);
    T->data = item;
    T->lchild = lptr;
    T->rchild = rptr;
    return T;
}

// ���ƶ��������õݹ���д�� 
BiTNode *CopyTree(BiTNode *T)
{
    if (!T) // �������һ����������û�и��Ƶı�Ҫ
        return NULL;

    BiTNode *newlptr; // ��������T��������
    BiTNode *newrptr; // ��������T��������
    if (T->lchild)
        newlptr = CopyTree(T->lchild); // ����������
    else
        newlptr = NULL;

    if (T->rchild)
        newrptr = CopyTree(T->rchild); // ����������
    else
        newrptr = NULL;

    BiTNode *newT = GetTreeNode(T->data, newlptr, newrptr);
    return newT;
}

// ���������������������֤���ƽ����
void InOrderTraversal(BiTree T)
{
    if (T)
    {
        InOrderTraversal(T->lchild);
        std::cout << T->data << " ";
        InOrderTraversal(T->rchild);
    }
}

int main()
{
    // ����ԭʼ������
    BiTNode node1, node2, node3;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;
    node1.lchild = &node2;
    node1.rchild = &node3;
    node2.lchild = nullptr;
    node2.rchild = nullptr;
    node3.lchild = nullptr;
    node3.rchild = nullptr;

    // ���ƶ�����
    BiTNode *newTree = CopyTree(&node1);

    // ��֤���ƽ��
    std::cout << "ԭʼ������������������";
    InOrderTraversal(&node1);
    std::cout << std::endl;

    std::cout << "���ƵĶ�����������������";
    InOrderTraversal(newTree);
    std::cout << std::endl;

    return 0;
}
