#include <iostream>
#include <stack>
#include "TreeStructure.h"
using namespace std;

/**
 * 先序遍历（PreOrderTraverse）：从树的根节点开始，先访问根节点，然后递归地先序遍历左子树，最后递归地先序遍历右子树。
 * 中序遍历（InOrderTraverse）：从树的根节点开始，递归地中序遍历左子树，然后访问根节点，最后递归地中序遍历右子树。
 * 后序遍历（PostOrderTraverse）：从树的根节点开始，递归地后序遍历左子树，然后递归地后序遍历右子树，最后访问根节点。
 * 层序遍历（LevelOrderTraverse）：从树的根节点开始，按照层级顺序逐层访问树的节点，通常使用队列来实现。
 */

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

#include <queue>
/**
 * 层次遍历二叉树，使用队列实现
 */
void LevelOrderTraverse(TreeNode *root, void (*visit)(TElemType e))
{
    queue<TreeNode *> Q;

    if (root)
        Q.push(root);

    while (!Q.empty())
    {
        TreeNode *current = Q.front();
        Q.pop();

        // 访问当前结点（你的 visit 函数）
        visit(current->data);

        if (current->lchild)
            Q.push(current->lchild);

        if (current->rchild)
            Q.push(current->rchild);
    }
}
