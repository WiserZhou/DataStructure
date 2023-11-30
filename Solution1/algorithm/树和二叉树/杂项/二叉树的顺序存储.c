

#include <stdio.h>

#define MAX_SIZE 100

// 声明数组作为顺序存储的二叉树
char binaryTree[MAX_SIZE];

// 初始化二叉树
void initBinaryTree()
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        binaryTree[i] = '0'; // 用 '0' 表示数组元素为空
    }
}

// 创建二叉树，就是将元素存入数组当中，相当于进行了二叉树的赋值操作
void createBinaryTree(char data, int index)
{
    binaryTree[index] = data;
}

// 访问二叉树节点
void visitNode(char data)
{
    printf("%c ", data);
}

// 先序遍历二叉树
void preOrderTraversal(int index)
{
    if (binaryTree[index] != '0')
    {
        visitNode(binaryTree[index]);
        preOrderTraversal(2 * index + 1); // 左子节点
        preOrderTraversal(2 * index + 2); // 右子节点
    }
}

// 中序遍历二叉树
void inOrderTraversal(int index)
{
    if (binaryTree[index] != '0')
    {
        inOrderTraversal(2 * index + 1); // 左子节点
        visitNode(binaryTree[index]);
        inOrderTraversal(2 * index + 2); // 右子节点
    }
}

// 后序遍历二叉树
void postOrderTraversal(int index)
{
    if (binaryTree[index] != '0')
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
    // createBinaryTree(1, 0);  // 要想使用上面的例子，需要将char类型的数组转换为int类型的数组，
    // 然后将判断的条件改成一个你不会用到的数据，比如-1，那么后面的相关先序中序，后序遍历的条件就会改变了，也只需要改变那些条件即可
    // createBinaryTree(2, 1);
    // createBinaryTree(3, 2);
    // createBinaryTree(4, 3);
    // createBinaryTree(5, 4);
    createBinaryTree('A',0);  //这个就是课件上面的树的ppt第29页的例子
    createBinaryTree('B',1);
    createBinaryTree('D',2);
    createBinaryTree('C',3);
    createBinaryTree('E',6);
    createBinaryTree('F',13);


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