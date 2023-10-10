#include ".\unity.h"
#include <stack>
typedef int TElemType;
/**
 * 二叉树的结构定义
 */
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *left, *right;

} BiTNode, *BiTree;
/**
 * 先序递归遍历二叉树
 */
void PreOrderBiRecurTraverse(BiTree T)
{
    if (T == nullptr)
        return;
    cout << T->data << " ";
    PreOrderBiRecurTraverse(T->left);
    PreOrderBiRecurTraverse(T->right);
}
/**
 * 中序递归遍历二叉树
 */
void InOrderBiRecurTraverse(BiTree T)
{
    if (T == nullptr)
        return;
    InOrderBiRecurTraverse(T->left);
    cout << T->data << " ";
    InOrderBiRecurTraverse(T->right);
}
/**
 * 后序递归遍历二叉树
 */
void PostOrderBiRecurTraverse(BiTree T)
{
    if (T == nullptr)
        return;
    PostOrderBiRecurTraverse(T->left);
    PostOrderBiRecurTraverse(T->right);
    cout << T->data << " ";
}
/**
 * 先序非递归遍历二叉树
 */
void PreOrderBiTraverse(BiTree T)
{
    if (T == nullptr)
        return;
    stack<BiTree> S;
    BiTree node = T;
    while (node != nullptr || !S.empty())
    {
        while (node != nullptr)
        {
            cout << node->data << " ";
            S.push(node);
            node = node->left;
        }
        if (!S.empty())
        {
            node = S.top();
            S.pop();
            node = node->right;
        }
    }
}
/**
 * 中序非递归遍历二叉树
 */
void InOrderBiTraverse(BiTree T)
{
    if (T == nullptr)
        return;
    stack<BiTree> S;
    BiTree node = T;
    while (node != nullptr || !S.empty())
    {
        while (node != nullptr)
        {
            S.push(node);
            node = node->left;
        }
        if (!S.empty())
        {
            node = S.top();
            S.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}
/**
 * 后序非递归遍历二叉树
 */
void PostOrderBiTraverse(BiTree T)
{
    if (T == nullptr)
        return;
    stack<BiTree> S;
    BiTree node = T;
    BiTree lastNode = nullptr;
    while (node != nullptr || !S.empty())
    {
        while (node != nullptr)
        {
            S.push(node);
            node = node->left;
        }
        node = S.top();

        if (node->right == nullptr || node->right == lastNode)
        {

            S.pop();
            cout << node->data << " ";
            lastNode = node;
            node = nullptr;
        }
        else
            node = node->right;
    }
}
/**
 * 利用先缀表达式建立二叉树
 */
void createTreePre(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch != '\n')
    {
        T = (BiTree)malloc(sizeof(BiTree));
        T->data = ch;
        createTreePre(T->left);
        createTreePre(T->right);
    }
    else
        T = nullptr;
}
/**
 * 求解二叉树的深度
 */
int depth(BiTree T)
{
    if (T)
    {
        int depth1 = 1 + depth(T->left);
        int depth2 = 1 + depth(T->right);
        return depth1 > depth2 ? depth1 : depth2;
    }
    else
        return 0;
}

/**
 * 求解二叉树的叶子数
 */
int numLeaf(BiTree T)
{
    if (!T)
        return 0;
    if (!T->left && !T->right)
        return 1;
    else
        return numLeaf(T->left) + numLeaf(T->right);
}
/**
 * 复制二叉树
 */
BiTNode *CopyBiTree(BiTNode *T)
{

    if (!T)
        return NULL;

    BiTree newRightPtr, newLeftPtr;

    if (T->left)
        newLeftPtr = CopyBiTree(T->left); // 复制左子树
    else
        newLeftPtr = NULL;
        
    if (T->right)
        newRightPtr = CopyBiTree(T->right); // 复制右子树
    else
        newRightPtr = NULL;

    BiTree newTree = (BiTree)malloc(sizeof(BiTNode));
    newTree->data = T->data;
    newTree->left = newLeftPtr;
    newTree->right = newRightPtr;

    return newTree;
} // CopyTree

/**
 * 三叉链表的定义
 */
typedef struct TriTNode
{
    TElemType data;
    struct TriTNode *left, *right, *parent;
} TriTNode, *TriTree;
/**
 * 双亲链表的结构定义
 */
typedef struct BPTNode
{ // 结点结构
    TElemType data;
    int *parent; // 指向双亲的指针
    char LRTag;  // 左、右孩子标志域
} BPTNode;

#define MAX_TREE_SIZE 100

/**
 * 双亲树的结构定义
 */
typedef struct BPTree
{ // 树结构
    BPTNode nodes[MAX_TREE_SIZE];
    int num_node; // 结点数目
    int root;     // 根结点的位置
} BPTree;