

#include <stdio.h>

#define MAX_SIZE 100

// ����������Ϊ˳��洢�Ķ�����
char binaryTree[MAX_SIZE];

// ��ʼ��������
void initBinaryTree()
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        binaryTree[i] = '0'; // �� '0' ��ʾ����Ԫ��Ϊ��
    }
}

// ���������������ǽ�Ԫ�ش������鵱�У��൱�ڽ����˶������ĸ�ֵ����
void createBinaryTree(char data, int index)
{
    binaryTree[index] = data;
}

// ���ʶ������ڵ�
void visitNode(char data)
{
    printf("%c ", data);
}

// �������������
void preOrderTraversal(int index)
{
    if (binaryTree[index] != '0')
    {
        visitNode(binaryTree[index]);
        preOrderTraversal(2 * index + 1); // ���ӽڵ�
        preOrderTraversal(2 * index + 2); // ���ӽڵ�
    }
}

// �������������
void inOrderTraversal(int index)
{
    if (binaryTree[index] != '0')
    {
        inOrderTraversal(2 * index + 1); // ���ӽڵ�
        visitNode(binaryTree[index]);
        inOrderTraversal(2 * index + 2); // ���ӽڵ�
    }
}

// �������������
void postOrderTraversal(int index)
{
    if (binaryTree[index] != '0')
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
    // createBinaryTree(1, 0);  // Ҫ��ʹ����������ӣ���Ҫ��char���͵�����ת��Ϊint���͵����飬
    // Ȼ���жϵ������ĳ�һ���㲻���õ������ݣ�����-1����ô���������������򣬺�������������ͻ�ı��ˣ�Ҳֻ��Ҫ�ı���Щ��������
    // createBinaryTree(2, 1);
    // createBinaryTree(3, 2);
    // createBinaryTree(4, 3);
    // createBinaryTree(5, 4);
    createBinaryTree('A',0);  //������ǿμ����������ppt��29ҳ������
    createBinaryTree('B',1);
    createBinaryTree('D',2);
    createBinaryTree('C',3);
    createBinaryTree('E',6);
    createBinaryTree('F',13);


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