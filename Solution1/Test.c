

#include <stdio.h>

#define MAX_SIZE 100

// ����������Ϊ˳��洢�Ķ�����
int binaryTree[MAX_SIZE];

// ��ʼ��������
void initBinaryTree()
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        binaryTree[i] = -1; // �� -1 ��ʾ����Ԫ��Ϊ��
    }
}

// ����������
void createBinaryTree(int data, int index)
{
    binaryTree[index] = data;
}

// ���ʶ������ڵ�
void visitNode(int data)
{
    printf("%d ", data);
}

// �������������
void preOrderTraversal(int index)
{
    if (binaryTree[index] != -1)
    {
        visitNode(binaryTree[index]);
        preOrderTraversal(2 * index + 1); // ���ӽڵ�
        preOrderTraversal(2 * index + 2); // ���ӽڵ�
    }
}

// �������������
void inOrderTraversal(int index)
{
    if (binaryTree[index] != -1)
    {
        inOrderTraversal(2 * index + 1); // ���ӽڵ�
        visitNode(binaryTree[index]);
        inOrderTraversal(2 * index + 2); // ���ӽڵ�
    }
}

// �������������
void postOrderTraversal(int index)
{
    if (binaryTree[index] != -1)
    {
        postOrderTraversal(2 * index + 1); // ���ӽڵ�
        postOrderTraversal(2 * index + 2); // ���ӽڵ�
        visitNode(binaryTree[index]);
    }
}

int main()
{
    initBinaryTree();

    // �����������ڵ�����
    createBinaryTree(1, 0);
    createBinaryTree(2, 1);
    createBinaryTree(3, 2);
    createBinaryTree(4, 3);
    createBinaryTree(5, 4);

    printf("�������: ");
    preOrderTraversal(0);
    printf("\n");

    printf("�������: ");
    inOrderTraversal(0);
    printf("\n");

    printf("�������: ");
    postOrderTraversal(0);
    printf("\n");

    return 0;
}