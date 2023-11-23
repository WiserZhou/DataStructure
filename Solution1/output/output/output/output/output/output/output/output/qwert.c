#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct TreeNode
{
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findLowestPriorityOperator(char *expr, int start, int end)
{
    int priority = 0;
    int lowestPriority = INT_MAX;
    int lowestPriorityPos = -1;
    for (int i = start; i <= end; i++)
    {
        if (expr[i] == '(')
        {
            priority += 2;
        }
        else if (expr[i] == ')')
        {
            priority -= 2;
        }
        else if (expr[i] == '+' || expr[i] == '-')
        {
            int currPriority = priority + 1;
            if (currPriority <= lowestPriority)
            {
                lowestPriority = currPriority;
                lowestPriorityPos = i;
            }
        }
        else if (expr[i] == '*' || expr[i] == '/')
        {
            int currPriority = priority + 2;
            if (currPriority <= lowestPriority)
            {
                lowestPriority = currPriority;
                lowestPriorityPos = i;
            }
        }
    }
    return lowestPriorityPos;
}

struct TreeNode *buildTreeNode(char *expr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int pos = findLowestPriorityOperator(expr, start, end);
    if (pos == -1)
    {
        for (int i = 0; i <= end - start; i++)
        {
            if (expr[start + i] != '(' && expr[start + i] != ')')
            {
                struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                node->val = expr[start + i];
                node->left = NULL;
                node->right = NULL;
                return node;
            }
        }
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = expr[pos];
    root->left = buildTreeNode(expr, start, pos - 1);
    root->right = buildTreeNode(expr, pos + 1, end);
    return root;
}

void preorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->val);
}

void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%c", root->val);
    inorderTraversal(root->right);
}

int main()
{
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    struct TreeNode *root = buildTreeNode(expr, 0, strlen(expr) - 1);
    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);

    return 0;
}

