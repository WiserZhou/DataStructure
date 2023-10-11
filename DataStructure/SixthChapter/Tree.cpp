#include <iostream>
#include <stack>
using namespace std;
#define END '#'
typedef struct TNode
{
    char ch;
    struct TNode *left;
    struct TNode *right;
    // TNode() : ch(), left(nullptr), right(nullptr){};
} *Tree, TNode;

void CreateTreePre(Tree &T)
{
    char ch;
    cin >> ch;
    if (ch != END)
    {
        T = (Tree)malloc(sizeof(TNode));
        T->ch = ch;
        CreateTreePre(T->left);
        CreateTreePre(T->right);
    }
    else
        T = nullptr;
}
void CreateTreeIn(Tree &T)
{
    string s;
    getline(cin, s);
    stack<char> S;
    // char ch;
    // cin >> ch;
    int i = 0;
    
}
void PreOrder(Tree T)
{
    if (T)
    {
        cout << T->ch;
        PreOrder(T->left);
        PreOrder(T->right);
    }
    // cout << "\n";
}
void InOrder(Tree T)
{
    if (T)
    {
        InOrder(T->left);
        cout << T->ch;
        InOrder(T->right);
    }
}
void ReOrder(Tree T)
{
    if (T)
    {
        ReOrder(T->left);
        ReOrder(T->right);
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
            p = p->left; // 根指针进栈，访问他的左子树
        }
        else
        {
            p = S.top();
            S.pop(); // 根指针退栈，访问他的右子树
            cout << p->ch;
            p = p->right;
        }
    }
    // return OK;
}

int depth(Tree T)
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

int numLeaf(Tree T)
{
    if (!T)
        return 0;
    if (!T->left && !T->right)
        return 1;
    else
        return numLeaf(T->left) + numLeaf(T->right);
}

int main()
{
    Tree T;
    CreateTreePre(T);
    PreOrder(T);
    cout << "\n";
    InOrder(T);
    cout << "\n";
    ReOrder(T);
    cout << "\n";
    cout << numLeaf(T) << "\n";
    cout << depth(T) << "\n";
    InOrderNoRecursion(T);
    cout << "\n";
    return 0;
}