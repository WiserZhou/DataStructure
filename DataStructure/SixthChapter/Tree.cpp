#include <iostream>
#include <stack>
using namespace std;
// #define END '#'
typedef struct TNode
{
    char ch;
    struct TNode *left;
    struct TNode *right;
    // TNode(char ch) : ch(ch), left(nullptr), right(nullptr) {}
} *Tree, TNode;

void createTreePre(Tree &T)
{
    char ch;
    cin >> ch;
    if (ch != '#')
    {
        T = (Tree)malloc(sizeof(TNode));
        T->ch = ch;
        createTreePre(T->left);
        createTreePre(T->right);
    }
    else
        T = nullptr;
}

void InOrder(Tree T)
{
    if (T == nullptr)
        return;
    // cout << " sss";
    InOrder(T->left);
    cout << T->ch;
    InOrder(T->right);
}
int main()
{
    Tree T;
    createTreePre(T);
    InOrder(T);
    return 0;
}