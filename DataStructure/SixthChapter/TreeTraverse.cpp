#include <iostream>
#include <stack>
using namespace std;

/**
 * 先序遍历（PreOrderTraverse）：从树的根节点开始，先访问根节点，然后递归地先序遍历左子树，最后递归地先序遍历右子树。
 * 中序遍历（InOrderTraverse）：从树的根节点开始，递归地中序遍历左子树，然后访问根节点，最后递归地中序遍历右子树。
 * 后序遍历（PostOrderTraverse）：从树的根节点开始，递归地后序遍历左子树，然后递归地后序遍历右子树，最后访问根节点。
 * 层序遍历（LevelOrderTraverse）：从树的根节点开始，按照层级顺序逐层访问树的节点，通常使用队列来实现。
 */
typedef int TElemType;
#define MAX_TREE_SIZE 100
// 二叉树的最大结点数
/**
 * 二叉树的顺序存储
 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 二叉树的顺序存储
// 0号单元存储根结点

// 使用满二叉树和当前的树进行一一对应

/**
 * 二叉链表
 */
typedef struct BiTNode
{ // 结点结构
    TElemType data;
    struct BiTNode *lchild, *rchild;
    // 左右孩子指针
} TreeNode, *BiTree;

/**
 * 三叉链表
 */
typedef struct TriTNode
{ // 结点结构
    TElemType data;
    struct TriTNode *lchild, *rchild;
    // 左右孩子指针
    struct TriTNode *parent; // 双亲指针
} TriTNode, *TriTree;

/**
 * 双亲链表的结点结构
 */
typedef struct BPTNode
{ // 结点结构
    TElemType data;
    int *parent; // 指向双亲的指针
    char LRTag;  // 左、右孩子标志域
} BPTNode;

/**
 * 双亲链表的树结构
 */
typedef struct BPTree
{ // 树结构
    BPTNode nodes[MAX_TREE_SIZE];
    int num_node; // 结点数目
    int root;     // 根结点的位置
} BPTree;

void PreOrderTraversalRecursion(BiTree T, void (*visit)(TElemType &e))
{
    if (T)
    {
        // 访问结点
        visit(T->data);
        PreOrderTraversalRecursion(T->lchild, visit); // 遍历左子树
        PreOrderTraversalRecursion(T->rchild, visit); // 遍历右子树
    }
}

void InOrderTraversalRecursion(BiTree T, void (*visit)(TElemType &e))
{
    if (T)
    {

        InOrderTraversalRecursion(T->lchild, visit); // 遍历左子树
        visit(T->data);
        InOrderTraversalRecursion(T->rchild, visit); // 遍历右子树
    }
}
void PostOrderTraversalRecursion(BiTree T, void (*visit)(TElemType &e))
{
    if (T)
    {

        PostOrderTraversalRecursion(T->lchild, visit); // 遍历左子树
        PostOrderTraversalRecursion(T->rchild, visit); // 遍历右子树
        visit(T->data);
    }
}

/**
 * 先序遍历的非递归算法
 * 利用栈的后进先出特性，先遍历其左子树，边遍历边visit中结点，直到头，然后检查其是否有右结点，有的话移动到右结点上继续进行遍历
 */
void PreOrderTraversal(TreeNode *root, void (*visit)(TElemType e))
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st; // 创建一个栈
    TreeNode *node = root;

    while (node != nullptr || !st.empty()) // 当前指针指向非空表示此段直接遍历未结束，栈非空表示遍历未终止
    {
        while (node != nullptr)
        {
            visit(node->data);
            st.push(node);       // 将根节点压入栈
            node = node->lchild; // 移动到左子树
        }

        if (!st.empty())
        {
            node = st.top(); // 弹出栈顶节点并访问其右子树
            st.pop();
            node = node->rchild; // 移动到右子树
        }
    }
}

/**
 * 中序遍历的非递归算法。
 * 利用栈的先进后出的特性，先移动到最左边，然后边弹出边检查是否有右子树，如果没有的话，访问完毕之后就后退；如果有，就进入其右子树重新跑到最左边，再次进行检查
 */
void InOrderTraversal(TreeNode *root, void (*visit)(TElemType e))
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st; // 创建一个栈
    TreeNode *node = root;

    while (node != nullptr || !st.empty())
    {
        while (node != nullptr)
        {
            st.push(node);       // 将结点压入栈
            node = node->lchild; // 移动到左子树
        }

        if (!st.empty())
        {
            node = st.top(); // 弹出栈顶结点并访问
            st.pop();
            visit(node->data);
            node = node->rchild; // 移动到右子树
        }
    }
}

/**
 * 后序遍历的非递归算法
 * 利用栈的后进先出特性，先找到最左边的结点，然后弹出栈顶结点，查看其是否有右子树，如果没有的话，那么直接访问此结点即可；如果有且访问过，那么也可以哦访问此结点；
 * 如果没有访问过，那么进入其右子树重新进行遍历
 * 在这里只有上一次访问的是他的右子树或者右子树是空的，那么才可以访问根结点
 */
void PostOrderTraversal(TreeNode *root, void (*visit)(TElemType e))
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st; // 创建一个栈
    TreeNode *node = root;
    TreeNode *lastVisited = nullptr; // 上次访问的节点

    while (node != nullptr || !st.empty()) // 为了全部将所有的左子树全部遍历，防止出现遗漏
    {
        while (node != nullptr)
        {
            st.push(node);       // 将节点压入栈
            node = node->lchild; // 移动到左子树
        }

        node = st.top(); // 查看栈顶节点

        if (node->rchild == nullptr || node->rchild == lastVisited) // 只有右边没有或者右边已经遍历完成后，再进行遍历中结点
        {
            st.pop(); // 弹出栈顶节点并访问
            visit(node->data);
            lastVisited = node;
            node = nullptr; // 回退到上一级节点
        }
        else
        {
            node = node->rchild; // 移动到右子树
        }
    }
}
void PreOrderTraversal(BiTree T, void (*visit)(TElemType e))
{
    BiTNode *q, *p = T;
    stack<BiTNode *> S; // 使用 C++ 的 stack 来代替原来的栈
    if (p != NULL)
    {
        S.push(p); // 将根节点压入栈
    }
    while (!S.empty())
    {
        q = S.top();
        S.pop();        // 弹出栈顶元素
        visit(q->data); // 访问节点数据
        if (q->rchild != NULL)
        {
            S.push(q->rchild); // 将右子树压入栈
        }
        if (q->lchild != NULL)
        {
            S.push(q->lchild); // 将左子树压入栈，注意入栈顺序，先右后左
        }
    }
}

BiTNode *GoFarLeft(BiTree T, stack<BiTNode *> *S)
{
    if (!T)
        return NULL;
    while (T->lchild)
    {
        S->push(T);
        T = T->lchild;
    }
    return T;
}

void InOrderGo(BiTree T, void (*visit)(TElemType &e), stack<BiTNode *> *S)
{
    BiTNode *t = GoFarLeft(T, S); // 找到最左下的结点
    while (t)
    {
        visit(t->data);
        if (t->rchild)
        {
            t = GoFarLeft(t->rchild, S);
        }
        else if (!S->empty())
        {
            t = S->top();
            S->pop();
        }
        else
        {
            t = NULL; // 栈空表明遍历结束
        }
    }
}

void visit(TElemType e)
{
    cout << e << endl;
}
int main()
{
    // 创建一个二叉树
    TreeNode *root = new TreeNode();
    root->data = 1;

    TreeNode *node2 = new TreeNode();
    node2->data = 2;

    TreeNode *node3 = new TreeNode();
    node3->data = 3;

    TreeNode *node4 = new TreeNode();
    node4->data = 4;

    TreeNode *node5 = new TreeNode();
    node5->data = 5;

    root->lchild = node2;
    root->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;

    // 先序遍历
    cout << "PreOrder traversal: ";
    PreOrderTraversal(root, visit);
    cout << endl;

    // 中序遍历
    cout << "InOrder traversal: ";
    InOrderTraversal(root, visit);
    cout << endl;

    // 后序遍历
    cout << "PostOrder traversal: ";
    PostOrderTraversal(root, visit);
    cout << endl;

    return 0;
}
