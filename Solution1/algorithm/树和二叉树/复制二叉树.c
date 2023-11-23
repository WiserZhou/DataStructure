

#include <stdio.h>
#include <stdlib.h>

// ����������Ľ��ṹ��
struct Node
{
    int data;           // ��������
    struct Node *left;  // ������ָ��
    struct Node *right; // ������ָ��
} Node;

// �����½��ĺ���
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Ϊ�½������ڴ�ռ�
    newNode->data = data;                                              // �����½�������
    newNode->left = NULL;                                              // ����������ָ��Ϊ��
    newNode->right = NULL;                                             // ����������ָ��Ϊ��
    return newNode;                                                    // �����½���ָ��
}

// ���ƶ������ĺ����������������ԭʼ����ָ��
struct Node *copyTree(struct Node *root)
{
    if (root == NULL)
    { // ���ԭʼ��Ϊ�գ��򷵻ؿ�ָ��
        return NULL;
    }
    struct Node *newRoot = createNode(root->data); // ����һ���µĽ�㣬��ԭʼ�������ݸ�ֵ���½��
    newRoot->left = copyTree(root->left);          // �ݹ鸴��ԭʼ�������������������ص�����ָ�븳ֵ���½���������ָ��
    newRoot->right = copyTree(root->right);        // �ݹ鸴��ԭʼ�������������������ص�����ָ�븳ֵ���½���������ָ��
    return newRoot;                                // ���ظ��ƺ�Ķ������ĸ����ָ��
}

// �����������������ӡ�������,�ݹ��������
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);  // �ȵݹ����������
        printf("%d ", root->data);     // ��ӡ��ǰ��������
        inorderTraversal(root->right); // �ٵݹ����������
    }
}

int main()
{
    // ����ԭʼ������
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("ԭʼ��������������������");
    inorderTraversal(root);
    printf("\n");

    // ���ƶ�����
    struct Node *newRoot = copyTree(root);

    printf("���ƺ�Ķ�������������������");
    inorderTraversal(newRoot);
    printf("\n");

    return 0;
}