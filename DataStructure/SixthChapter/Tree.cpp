
#include <iostream>
#include <stack>
using namespace std;
#define END '\n'
typedef struct Node
{
    char ch;
    struct Node *l_child;
    struct Node *r_child;
} *Tree, TNode;

void CreateTree(Tree &T)
{
    char ch;
    cin >> ch;
    if (ch != END)
    {
        T = (Tree)malloc(sizeof(TNode));
        T->ch = ch;
        CreateTree(T->l_child);
        CreateTree(T->r_child);
    }
    else
        T = nullptr;
}

void PreOrder(Tree T)
{
    if (T)
    {
        cout << T->ch;
        PreOrder(T->l_child);
        PreOrder(T->r_child);
    }
    // cout << "\n";
}
void InOrder(Tree T)
{
    if (T)
    {
        InOrder(T->l_child);
        cout << T->ch;
        InOrder(T->r_child);
    }
}
void ReOrder(Tree T)
{
    if (T)
    {
        ReOrder(T->l_child);
        ReOrder(T->r_child);
        cout << T->ch;
    }
}
void InOrderNoRecursion(Tree T)
{
    stack<Tree> S;
    Tree p = T;
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
            cout << p->ch;
            p = p->r_child;
        }
    }
    // return OK;
}

int depth(Tree T)
{
    if (T)
    {
        int depth1 = 1 + depth(T->l_child);
        int depth2 = 1 + depth(T->r_child);
        return depth1 > depth2 ? depth1 : depth2;
    }
    else
        return 0;
}

int numLeaf(Tree T)
{
    if (!T)
        return 0;
    if (!T->l_child && !T->r_child)
        return 1;
    else
        return numLeaf(T->l_child) + numLeaf(T->r_child);
}

int main()
{
    Tree T;
    CreateTree(T);
    PreOrder(T);
    cout << "\n";
    InOrder(T);
    cout << "\n";
    ReOrder(T);
    cout << "\n";
    // cout << numLeaf(T) << "\n";
    // cout << depth(T) << "\n";
    // InOrderNoRecursion(T);
    cout << "\n";
    return 0;
}