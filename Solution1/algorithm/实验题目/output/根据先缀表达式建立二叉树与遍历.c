

#include <stdio.h>
#include <stdlib.h>

// ������������
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �����½��
TreeNode *createNode(char data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ������׺���ʽ����������
TreeNode *buildExpressionTree(char expression[], int *index)
{
    char data = expression[*index];
    (*index)++;
    if (data == '\0')
    {
        return NULL;
    }
    TreeNode *node = createNode(data);
    if (data == '+' || data == '-' || data == '*' || data == '/')
    {
        node->left = buildExpressionTree(expression, index);
        node->right = buildExpressionTree(expression, index);
    }

    return node;
}

// �������
void preorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// �������
void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%c", root->data);
        inorderTraversal(root->right);
    }
}

// �������
void postorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c", root->data);
    }
}

int main()
{
    char expression[100];
    scanf("%s", expression);

    int index = 0;
    TreeNode *root = buildExpressionTree(expression, &index);
    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}