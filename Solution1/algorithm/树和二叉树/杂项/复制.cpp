

#include <iostream>
#include <cstdlib>

// 定义二叉树节点结构
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

// 创建一个新的二叉树节点
BiTNode *GetTreeNode(int item, BiTNode *lptr, BiTNode *rptr)
{
    BiTNode *T;   // 先要为T申请结点，然后再进行相关的操作
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
        exit(1);
    T->data = item;
    T->lchild = lptr;
    T->rchild = rptr;
    return T;
}

// 复制二叉树，用递归来写的 
BiTNode *CopyTree(BiTNode *T)
{
    if (!T) // 传入的是一个空子树，没有复制的必要
        return NULL;

    BiTNode *newlptr; // 用来复制T的左子树
    BiTNode *newrptr; // 用来复制T的右子树
    if (T->lchild)
        newlptr = CopyTree(T->lchild); // 复制左子树
    else
        newlptr = NULL;

    if (T->rchild)
        newrptr = CopyTree(T->rchild); // 复制右子树
    else
        newrptr = NULL;

    BiTNode *newT = GetTreeNode(T->data, newlptr, newrptr);
    return newT;
}

// 中序遍历二叉树（用于验证复制结果）
void InOrderTraversal(BiTree T)
{
    if (T)
    {
        InOrderTraversal(T->lchild);
        std::cout << T->data << " ";
        InOrderTraversal(T->rchild);
    }
}

int main()
{
    // 创建原始二叉树
    BiTNode node1, node2, node3;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;
    node1.lchild = &node2;
    node1.rchild = &node3;
    node2.lchild = nullptr;
    node2.rchild = nullptr;
    node3.lchild = nullptr;
    node3.rchild = nullptr;

    // 复制二叉树
    BiTNode *newTree = CopyTree(&node1);

    // 验证复制结果
    std::cout << "原始二叉树中序遍历结果：";
    InOrderTraversal(&node1);
    std::cout << std::endl;

    std::cout << "复制的二叉树中序遍历结果：";
    InOrderTraversal(newTree);
    std::cout << std::endl;

    return 0;
}
