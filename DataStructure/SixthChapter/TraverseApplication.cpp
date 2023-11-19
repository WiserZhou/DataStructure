#include "TreeStructure.h"
#include <iostream>
#include "../header/unity.h"
#include <stack>

void CountLeaf(BiTree T, int &count)
{
    if (T)
    {
        if ((!T->lchild) && (!T->rchild))
            count++; // 对叶子结点计数
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    } // if
} // CountLeaf

int Depth(BiTree T)
{ // 返回二叉树的深度
    int depth;
    if (!T)
        depth = 0;
    else
    {
        int depthLeft = Depth(T->lchild);
        int depthRight = Depth(T->rchild);
        depth = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depth;
}

// 生成一个二叉树的结点(其数据域为item, 左指针域为lchild, 右指针域为rchild)
BiTNode *GetTreeNode(TElemType item, BiTNode *lchild, BiTNode *rchild)
{
    BiTree T;
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
        exit(1);
    T->data = item;
    T->lchild = lchild;
    T->rchild = rchild;
    return T;
}

BiTNode *CopyTree(BiTNode *T)
{
    BiTree newLeftPtr;
    BiTree newRightPtr;

    if (!T)
        return NULL;

    if (T->lchild)
        newLeftPtr = CopyTree(T->lchild); // 复制左子树
    else
        newLeftPtr = NULL;

    if (T->rchild)
        newRightPtr = CopyTree(T->rchild); // 复制右子树
    else
        newRightPtr = NULL;

    BiTree newTree = GetTreeNode(T->data, newLeftPtr, newRightPtr);

    return newTree;
} // CopyTree

/**
 * 使用字符串的形式创建一个二叉树
 * 以空格表示无结点
 * A(B( ,C( , )),D( , ))
 * AB*C**D**
 * 去掉括号输入即可
 *
 * -(*(+(a,b),c),/(d,e))
 * -*+abc/de
 * 在先缀字符串中，字母就相当于空格
 */
Status CreateBiTree(BiTree &T)
{
    char ch;
    std::cin >> ch;
    if (ch == ' ')
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;            // 生成根结点
        CreateBiTree(T->lchild); // 构造左子树
        CreateBiTree(T->rchild); // 构造右子树
    }
    return OK;
} // CreateBiTree




bool IN(char ch, const char *OP)
{
    while (*OP != '\0')
    {
        if (ch == *OP)
        {
            return true;
        }
        OP++;
    }
    return false;
}

bool precede(char c1, char c2)
{
    int priority_c1, priority_c2;
    switch (c1)
    {
    case '+':
    case '-':
        priority_c1 = 1;
        break;
    case '*':
    case '/':
        priority_c1 = 2;
        break;
    default:
        priority_c1 = 0;
        break;
    }
    switch (c2)
    {
    case '+':
    case '-':
        priority_c2 = 1;
        break;
    case '*':
    case '/':
        priority_c2 = 2;
        break;
    default:
        priority_c2 = 0;
        break;
    }
    return priority_c1 >= priority_c2;
}

void CrtNode(BiTree &T, char ch, std::stack<BiTree> &PTR)
{
    T = new BiTNode;
    T->data = ch;
    T->lchild = T->rchild = NULL;
    PTR.push(T);
}

void CrtSubtree(BiTree &T, char c, std::stack<BiTree> &PTR)
{
    T = new BiTNode;
    T->data = c;
    BiTree rc, lc;
    rc = PTR.top();
    PTR.pop();
    T->rchild = rc;
    lc = PTR.top();
    PTR.pop();
    T->lchild = lc;
    PTR.push(T);
}

void CrtExptree(BiTree &T, char exp[])
{
    std::stack<char> S;
    std::stack<BiTree> PTR;
    char *p = exp;
    char ch = *p;
    const char *OP = "/*-+"; // 假设这是操作符集合
    while (!(S.top() == '#' && ch == '#'))
    {
        if (!IN(ch, OP))
        {
            CrtNode(T, ch, PTR);
        }
        else
        {
            switch (ch)
            {
            case '(':
                S.push(ch);
                break;
            case ')':
                char c = S.top();
                S.pop();
                while (c != '(')
                {
                    BiTree t;
                    CrtSubtree(t, c, PTR);
                    PTR.push(t);
                    c = S.top();
                    S.pop();
                }
                break;
            default:
                while (!S.empty() && precede(S.top(), ch))
                {
                    char c = S.top();
                    S.pop();
                    BiTree t;
                    CrtSubtree(t, c, PTR);
                    PTR.push(t);
                }
                if (ch != '#')
                    S.push(ch);
                break;
            }
        }
        if (ch != '#')
        {
            p++;
            ch = *p;
        }
    }
    T = PTR.top();
}
