

#include <stdio.h>

#define MAX_SIZE 100

// 声明数组作为顺序存储的二叉树
int binaryTree[MAX_SIZE];

// 初始化二叉树
void initBinaryTree()
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        binaryTree[i] = -1; // 用 -1 表示数组元素为空
    }
}

// 创建二叉树
void createBinaryTree(int data, int index)
{
    binaryTree[index] = data;
}

// 访问二叉树节点
void visitNode(int data)
{
    printf("%d ", data);
}

// 先序遍历二叉树
void preOrderTraversal(int index)
{
    if (binaryTree[index] != -1)
    {
        visitNode(binaryTree[index]);
        preOrderTraversal(2 * index + 1); // 左子节点
        preOrderTraversal(2 * index + 2); // 右子节点
    }
}

// 中序遍历二叉树
void inOrderTraversal(int index)
{
    if (binaryTree[index] != -1)
    {
        inOrderTraversal(2 * index + 1); // 左子节点
        visitNode(binaryTree[index]);
        inOrderTraversal(2 * index + 2); // 右子节点
    }
}

// 后序遍历二叉树
void postOrderTraversal(int index)
{
    if (binaryTree[index] != -1)
    {
        postOrderTraversal(2 * index + 1); // 左子节点
        postOrderTraversal(2 * index + 2); // 右子节点
        visitNode(binaryTree[index]);
    }
}

int main()
{
    initBinaryTree();

    // 创建二叉树节点数据
    createBinaryTree(1, 0);
    createBinaryTree(2, 1);
    createBinaryTree(3, 2);
    createBinaryTree(4, 3);
    createBinaryTree(5, 4);

    printf("先序遍历: ");
    preOrderTraversal(0);
    printf("\n");

    printf("中序遍历: ");
    inOrderTraversal(0);
    printf("\n");

    printf("后序遍历: ");
    postOrderTraversal(0);
    printf("\n");

    return 0;
}