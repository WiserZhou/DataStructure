

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点的结构体
typedef struct TreeNode
{
    char data;              // 数据域
    struct TreeNode *left;  // 左子树指针
    struct TreeNode *right; // 右子树指针
} TreeNode;

// 根据带空的先缀串建立一棵二叉树
TreeNode *createBinaryTree(char *str, int *index)
{
    if (str[*index] == '#')
    {
        (*index)++;
        return NULL;
    }
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode)); // 创建新的结点
    newNode->data = str[(*index)++];                          // 存储结点的数据
    newNode->left = createBinaryTree(str, index);             // 递归创建左子树
    newNode->right = createBinaryTree(str, index);            // 递归创建右子树
    return newNode;
}

// 先序遍历
void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);       // 打印结点的数据
    preorderTraversal(root->left);  // 递归遍历左子树
    preorderTraversal(root->right); // 递归遍历右子树
}

// 中序遍历
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);  // 递归遍历左子树
    printf("%c", root->data);      // 打印结点的数据
    inorderTraversal(root->right); // 递归遍历右子树
}

// 后序遍历
void postorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);  // 递归遍历左子树
    postorderTraversal(root->right); // 递归遍历右子树
    printf("%c", root->data);        // 打印结点的数据
}

// 计算叶子节点数量
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
    return countLeafNodes(root->left) + countLeafNodes(root->right); // 递归计算左子树和右子树的叶子节点数量，并求和
}

// 计算二叉树的深度
int calculateDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = calculateDepth(root->left);   // 递归计算左子树的深度
    int rightDepth = calculateDepth(root->right); // 递归计算右子树的深度
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth); // 返回左子树深度和右子树深度的较大值加1
}

// 非递归中序遍历
void nonRecInorderTraversal(TreeNode *root)
{
    TreeNode *stack[100]; // 创建一个数组作为栈，存储遍历过程中的结点
    int top = -1;         // 栈顶指针，初始为-1
    TreeNode *current = root; // 当前结点指针，初始为根结点
    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;  // 将当前结点入栈
            current = current->left; // 遍历左子树
        }
        if (top != -1)
        {
            current = stack[top--]; // 出栈一个结点并访问
            printf("%c", current->data);
            current = current->right; // 遍历右子树
        }
    }
}

int main()
{
    char str[100]; // 存储带空的先缀串
    scanf("%s", str);

    int index = 0;                                  // 索引变量，表示当前读取的字符在带空的先缀串中的位置
    TreeNode *root = createBinaryTree(str, &index); // 创建二叉树

    // 输出先序遍历结果
    preorderTraversal(root);
    printf("\n");

    // 输出中序遍历结果
    inorderTraversal(root);
    printf("\n");

    // 输出后序遍历结果
    postorderTraversal(root);
    printf("\n");

    // 输出叶子节点的数量
    int leafNodes = countLeafNodes(root);
    printf("%d\n", leafNodes);

    // 输出二叉树的深度
    int depth = calculateDepth(root);
    printf("%d\n", depth);

    // 输出非递归中序遍历结果
    nonRecInorderTraversal(root);
    printf("\n");

    return 0;
}