

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����������ڵ�Ľṹ��
typedef struct Node
{
    char data;          // �����򣬴洢�ڵ������
    struct Node *left;  // ���ӽڵ�
    struct Node *right; // ���ӽڵ�
} Node;

// ͨ���������к��������й���������
Node *buildTree(char *preorder, int preStart, int preEnd, char *inorder, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    // �������ڵ�
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = preorder[preStart];
    root->left = NULL;
    root->right = NULL;

    // �������������ҵ����ڵ������
    int rootIndex = inStart;
    while (rootIndex <= inEnd && inorder[rootIndex] != root->data)
    {
        rootIndex++;
    }

    // ����������
    root->left = buildTree(preorder, preStart + 1, preStart + (rootIndex - inStart), inorder, inStart, rootIndex - 1);

    // ����������
    root->right = buildTree(preorder, preStart + (rootIndex - inStart) + 1, preEnd, inorder, rootIndex + 1, inEnd);

    return root;
}

// ��ȡ��������������
int getMaxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = getMaxDepth(root->left);   // ��������������
    int rightDepth = getMaxDepth(root->right); // ��������������

    // ��������������ȵĽϴ�ֵ���ϸ��ڵ㱾������1
    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
}

// �����������Ҷ�ӽڵ�����
int countLeaves(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // �����Ҷ�ӽڵ㣬����1
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    // �ݹ��������������������Ҷ�ӽڵ��������������ܺ�
    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    char preorder[100];   // ���ڴ洢�������е��ַ�����
    char inorder[100];    // ���ڴ洢�������е��ַ�����
    int depth, leafCount; // ����������Ⱥ�Ҷ�ӽڵ�����

    // ��ȡ�������к���������
    fgets(preorder, 100, stdin);
    fgets(inorder, 100, stdin);

    // ȥ�����з�
    preorder[strcspn(preorder, "\n")] = '\0';
    inorder[strcspn(inorder, "\n")] = '\0';

    // ����������
    Node *root = buildTree(preorder, 0, strlen(preorder) - 1, inorder, 0, strlen(inorder) - 1);

    // ������Ⱥ�Ҷ�ӽڵ�����
    depth = getMaxDepth(root);
    leafCount = countLeaves(root);

    printf("%d\n%d\n", depth, leafCount);

    return 0;
}