#include ".\unity.h"
typedef int TElemType;

#define MAX_TREE_SIZE 100
typedef TElemType SqBiTree[MAX_TREE_SIZE];
// SqBiTree bt;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *l_child, *r_child;
} BiTNode, *BiTree;

Status PrintElement(TElemType e)
{
    cout << e << endl;
    return OK;
}

/**
 * 先序遍历二叉树的递归算法
 */
Status PreOrderTraverseRecursion(BiTree T, Status (*visit)(TElemType e))
{
    if (T)
    {
        if (visit(T->data))
        {
            if (PreOrderTraverseRecursion(T->l_child, visit))
            {
                if (PreOrderTraverseRecursion(T->r_child, visit))
                {
                    return OK;
                }
            }
        }
        return ERROR; // 返回错误以便于回退
    }
    else
        return OK;
}

Status InOrderTraverseRecursion(BiTree T, Status (*visit)(TElemType e))
{
    if (T)
    {

        if (InOrderTraverseRecursion(T->l_child, visit))
        {
            if (visit(T->data))
            {
                if (InOrderTraverseRecursion(T->r_child, visit))
                {
                    return OK;
                }
            }
        }
        return ERROR;
    }
    else
        return OK;
}

#include <stack>
// 中序遍历的非递归算法
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    stack<BiTree> S;
    S.push(T); // 将结点压入栈

    while (!S.empty())
    {
        while (S.top()->l_child)
            S.push(S.top()->l_child); // 向左走到尽头

        if (!S.empty())
        {
            BiTree p = S.top();
            S.pop();
            if (!visit(p->data)) // 遍历根节点
                return ERROR;
            S.push(p->r_child); // 右子树进栈
        }
    }
    return OK;
}

Status InOrderTraverse2(BiTree T, Status (*visit)(TElemType e))
{
    stack<BiTree> S;
    BiTree p = T;
    while (p || !S.empty())
    {
        if (p)
        {
            S.push(p);
            p = p->l_child; // 根指针进栈，访问他的左子树
        }
        else
        {
            p = S.top();
            S.pop(); // 根指针退栈，访问他的右子树
            if (!visit(p->data))
                return ERROR;
            p = p->r_child;
        }
    }
    return OK;
}

// 先序递归建立二叉树
Status CreateBiTreePreOrderRecursion(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == ' ')
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTreePreOrderRecursion(T->l_child);
        CreateBiTreePreOrderRecursion(T->r_child);
    }
    return OK;
}
