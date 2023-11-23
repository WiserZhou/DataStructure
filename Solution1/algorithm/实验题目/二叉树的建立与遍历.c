

#include <stdio.h>
#include <stdlib.h>

// ������������Ľṹ��
typedef struct TreeNode
{
    char data;              // ������
    struct TreeNode *left;  // ������ָ��
    struct TreeNode *right; // ������ָ��
} TreeNode;

// ���ݴ��յ���׺������һ�ö�����
TreeNode *createBinaryTree(char *str, int *index)
{
    if (str[*index] == '#')
    {
        (*index)++;
        return NULL;
    }
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode)); // �����µĽ��
    newNode->data = str[(*index)++];                          // �洢��������
    newNode->left = createBinaryTree(str, index);             // �ݹ鴴��������
    newNode->right = createBinaryTree(str, index);            // �ݹ鴴��������
    return newNode;
}

// �������
void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);       // ��ӡ��������
    preorderTraversal(root->left);  // �ݹ����������
    preorderTraversal(root->right); // �ݹ����������
}

// �������
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);  // �ݹ����������
    printf("%c", root->data);      // ��ӡ��������
    inorderTraversal(root->right); // �ݹ����������
}

// �������
void postorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);  // �ݹ����������
    postorderTraversal(root->right); // �ݹ����������
    printf("%c", root->data);        // ��ӡ��������
}

// ����Ҷ�ӽڵ�����
int countLeafNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right); // �ݹ��������������������Ҷ�ӽڵ������������
}

// ��������������
int calculateDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = calculateDepth(root->left);   // �ݹ���������������
    int rightDepth = calculateDepth(root->right); // �ݹ���������������
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth); // ������������Ⱥ���������ȵĽϴ�ֵ��1
}

// �ǵݹ��������
void nonRecInorderTraversal(TreeNode *root)
{
    TreeNode *stack[100]; // ����һ��������Ϊջ���洢���������еĽ��
    int top = -1;         // ջ��ָ�룬��ʼΪ-1
    TreeNode *current = root; // ��ǰ���ָ�룬��ʼΪ�����
    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;  // ����ǰ�����ջ
            current = current->left; // ����������
        }
        if (top != -1)
        {
            current = stack[top--]; // ��ջһ����㲢����
            printf("%c", current->data);
            current = current->right; // ����������
        }
    }
}

int main()
{
    char str[100]; // �洢���յ���׺��
    scanf("%s", str);

    int index = 0;                                  // ������������ʾ��ǰ��ȡ���ַ��ڴ��յ���׺���е�λ��
    TreeNode *root = createBinaryTree(str, &index); // ����������

    // �������������
    preorderTraversal(root);
    printf("\n");

    // �������������
    inorderTraversal(root);
    printf("\n");

    // �������������
    postorderTraversal(root);
    printf("\n");

    // ���Ҷ�ӽڵ������
    int leafNodes = countLeafNodes(root);
    printf("%d\n", leafNodes);

    // ��������������
    int depth = calculateDepth(root);
    printf("%d\n", depth);

    // ����ǵݹ�����������
    nonRecInorderTraversal(root);
    printf("\n");

    return 0;
}