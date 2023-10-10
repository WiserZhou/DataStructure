#include ".\unity.h"
#include <stack>
typedef int TElemType;

typedef struct TreeNode
{
    TElemType data;
    struct TreeNode *left, *right;

} BiTree, *BiTreePtr;

void PreOrderRecurTraverse(BiTreePtr T)
{
    if (T == nullptr)
        return;
    cout << T->data << " ";
    PreOrderRecurTraverse(T->left);
    PreOrderRecurTraverse(T->right);
}

void InOrderRecurTraverse(BiTreePtr T)
{
    if (T == nullptr)
        return;
    InOrderRecurTraverse(T->left);
    cout << T->data << " ";
    InOrderRecurTraverse(T->right);
}

void PostOrderRecurTraverse(BiTreePtr T)
{
    if (T == nullptr)
        return;
    PostOrderRecurTraverse(T->left);
    PostOrderRecurTraverse(T->right);
    cout << T->data << " ";
}

void PreOrderTraverse(BiTreePtr T)
{
    if (T == nullptr)
        return;
    stack<BiTreePtr> S;
    BiTreePtr node = T;
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

void InOrderTraverse(BiTreePtr T)
{
    if (T == nullptr)
        return;
    stack<BiTreePtr> S;
    BiTreePtr node = T;
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

void PostOrderTraverse(BiTreePtr T)
{
    if (T == nullptr)
        return;
    stack<BiTreePtr> S;
    BiTreePtr node = T;
    BiTreePtr lastNode = nullptr;
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

void createTreePre(BiTreePtr &T)
{
    char ch;
    cin >> ch;
    if (ch != '\n')
    {
        T = (BiTreePtr)malloc(sizeof(BiTree));
        T->data = ch;
        createTreePre(T->left);
        createTreePre(T->right);
    }
    else
        T = nullptr;
}

int depth(BiTreePtr T)
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

int numLeaf(BiTreePtr T)
{
    if (!T)
        return 0;
    if (!T->left && !T->right)
        return 1;
    else
        return numLeaf(T->left) + numLeaf(T->right);
}