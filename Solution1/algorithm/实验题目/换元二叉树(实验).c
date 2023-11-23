
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int find_index(char *str, char ch)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            return i;
    }
    return -1;
}

TreeNode *build_tree(char *preorder, char *inorder, int start, int end)
{
    static int pre_index = 0;

    if (start > end)
        return NULL;

    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = preorder[pre_index++];
    node->left = NULL;
    node->right = NULL;

    if (start == end)
        return node;

    int in_index = find_index(inorder, node->data);

    node->left = build_tree(preorder, inorder, start, in_index - 1);
    node->right = build_tree(preorder, inorder, in_index + 1, end);

    return node;
}

int get_tree_height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left_height = get_tree_height(root->left);
    int right_height = get_tree_height(root->right);

    return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    char preorder[51];
    char inorder[51];
    scanf("%s", preorder);
    scanf("%s", inorder);

    TreeNode *root = build_tree(preorder, inorder, 0, n - 1);
    int height = get_tree_height(root);

    printf("%d\n", height);

    return 0;
}