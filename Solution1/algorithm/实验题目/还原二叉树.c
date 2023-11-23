

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树节点的结构体
typedef struct Node
{
    char data;          // 数据域，存储节点的数据
    struct Node *left;  // 左子节点
    struct Node *right; // 右子节点
} Node;

// 通过先序序列和中序序列构建二叉树
Node *buildTree(char *preorder, int preStart, int preEnd, char *inorder, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    // 创建根节点
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = preorder[preStart];
    root->left = NULL;
    root->right = NULL;

    // 在中序序列中找到根节点的索引
    int rootIndex = inStart;
    while (rootIndex <= inEnd && inorder[rootIndex] != root->data)
    {
        rootIndex++;
    }

    // 构建左子树
    root->left = buildTree(preorder, preStart + 1, preStart + (rootIndex - inStart), inorder, inStart, rootIndex - 1);

    // 构建右子树
    root->right = buildTree(preorder, preStart + (rootIndex - inStart) + 1, preEnd, inorder, rootIndex + 1, inEnd);

    return root;
}

// 获取二叉树的最大深度
int getMaxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = getMaxDepth(root->left);   // 左子树的最大深度
    int rightDepth = getMaxDepth(root->right); // 右子树的最大深度

    // 返回左右子树深度的较大值加上根节点本身的深度1
    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
}

// 计算二叉树的叶子节点数量
int countLeaves(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // 如果是叶子节点，返回1
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    // 递归计算左子树和右子树的叶子节点数量，并返回总和
    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    char preorder[100];   // 用于存储先序序列的字符数组
    char inorder[100];    // 用于存储中序序列的字符数组
    int depth, leafCount; // 二叉树的深度和叶子节点数量

    // 读取先序序列和中序序列
    fgets(preorder, 100, stdin);
    fgets(inorder, 100, stdin);

    // 去除换行符
    preorder[strcspn(preorder, "\n")] = '\0';
    inorder[strcspn(inorder, "\n")] = '\0';

    // 构建二叉树
    Node *root = buildTree(preorder, 0, strlen(preorder) - 1, inorder, 0, strlen(inorder) - 1);

    // 计算深度和叶子节点数量
    depth = getMaxDepth(root);
    leafCount = countLeaves(root);

    printf("%d\n%d\n", depth, leafCount);

    return 0;
}