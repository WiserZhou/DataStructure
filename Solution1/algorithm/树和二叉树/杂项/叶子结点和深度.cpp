#include <iostream>
using namespace std;

// ����������ڵ�ṹ
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ����Ҷ�ӽڵ����
void CountLeaf(BiTree T, int &count)
{
    if (T)
    {
        if ((!T->lchild) && (!T->rchild)) // Ҷ�ӽ����Ǽ�û������Ҳû���Һ��ӵĽڵ�
        {
            count++; // ��Ҷ�ӽ�����
        }
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    }
}

// ���ض����������
int Depth(BiTree T)
{
    int depthval, depthLeft, depthRight;
    if (!T)
    {
        depthval = 0;
    }
    else
    {
        depthLeft = Depth(T->lchild);  // �����������
        depthRight = Depth(T->rchild); // �����������
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthval;
}

int main()
{
    // ����һ���򵥵Ķ�������Ϊʾ��
    BiTNode node1, node2, node3, node4, node5;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;
    node4.data = 4;
    node5.data = 5;
    node1.lchild = &node2;
    node1.rchild = &node3;
    node2.lchild = &node4;
    node2.rchild = nullptr;
    node3.lchild = &node5;
    node3.rchild = nullptr;
    node4.lchild = nullptr;
    node4.rchild = nullptr;
    node5.lchild = nullptr;
    node5.rchild = nullptr;

    // ���ú�������Ҷ�ӽڵ����
    int leafCount = 0;
    CountLeaf(&node1, leafCount);
    cout << "Ҷ�ӽڵ������" << leafCount << endl;

    // ���ú���������������
    int treeDepth = Depth(&node1);
    cout << "��������ȣ�" << treeDepth << endl;

    return 0;
}
