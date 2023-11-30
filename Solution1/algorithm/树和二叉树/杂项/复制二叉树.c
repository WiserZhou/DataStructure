

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的结点结构体
struct Node
{
    int data;           // 结点的数据
    struct Node *left;  // 左子树指针
    struct Node *right; // 右子树指针
} Node;

// 创建新结点的函数
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // 为新结点分配内存空间
    newNode->data = data;                                              // 设置新结点的数据
    newNode->left = NULL;                                              // 设置左子树指针为空
    newNode->right = NULL;                                             // 设置右子树指针为空
    return newNode;                                                    // 返回新结点的指针
}

// 复制二叉树的函数，参数传入的是原始树的指针
struct Node *copyTree(struct Node *root)
{
    if (root == NULL)
    { // 如果原始树为空，则返回空指针
        return NULL;
    }
    struct Node *newRoot = createNode(root->data); // 创建一个新的结点，将原始树的数据赋值给新结点
    newRoot->left = copyTree(root->left);          // 递归复制原始树的左子树，并将返回的子树指针赋值给新结点的左子树指针
    newRoot->right = copyTree(root->right);        // 递归复制原始树的右子树，并将返回的子树指针赋值给新结点的右子树指针
    return newRoot;                                // 返回复制后的二叉树的根结点指针
}

// 中序遍历二叉树并打印结点数据,递归遍历操作
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);  // 先递归遍历左子树
        printf("%d ", root->data);     // 打印当前结点的数据
        inorderTraversal(root->right); // 再递归遍历右子树
    }
}

int main()
{
    // 创建原始二叉树
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("原始二叉树的中序遍历结果：");
    inorderTraversal(root);
    printf("\n");

    // 复制二叉树
    struct Node *newRoot = copyTree(root);

    printf("复制后的二叉树的中序遍历结果：");
    inorderTraversal(newRoot);
    printf("\n");

    return 0;
}