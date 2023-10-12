#include <iostream>
#include <stack>
using namespace std;
// #define END '#'
typedef enum
{
    Link,
    Thread
} PtrTag;
typedef struct TNode
{
    char ch;
    struct TNode *left;
    struct TNode *right;
    // TNode(char ch) : ch(ch), left(nullptr), right(nullptr) {}
} *Tree, TNode;
typedef struct STNode
{
    char ch;
    struct STNode *left, *right;
    PtrTag LTag, RTag;
} *STree, STNode;

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
STree pre;
STree transfer(Tree T)
{
    if (T)
    {
        STree p = (STree)malloc(sizeof(STNode));
        p->ch = T->ch;
        // cout << p->ch << "%%%%" << endl;
        if (T->left != nullptr)
        {
            p->LTag = Link;
            p->left = transfer(T->left);
        }
        else
        {
            p->LTag = Thread;
            p->left = nullptr;
        }
        if (T->right != nullptr)
        {
            p->RTag = Link;
            p->right = transfer(T->right);
        }
        else
        {
            p->RTag = Thread;
            p->right = nullptr;
        }

        return p;
    }
    else
        return nullptr;
}

void Threading(STree &Thr)
{
    if (Thr)
    {
        Threading(Thr->left);
        if (Thr->left == nullptr && Thr->LTag == Thread)
        {
            Thr->left = pre;
        }
        if (pre->right == nullptr && pre->RTag == Thread)
        {
            pre->right = Thr;
        }
        pre = Thr;
        Threading(Thr->right);
    }
}
void ThreadTree(STree &Thr, Tree T)
{
    STree q = transfer(T);
    Thr = (STree)malloc(sizeof(STNode));
    Thr->LTag = Link;
    // Thr->left = nullptr;
    Thr->RTag = Thread;
    Thr->right = Thr;
    if (!T)
        Thr->left = Thr;
    else
    {
        Thr->left = q;
        pre = Thr;
        Threading(q);
        pre->RTag = Thread;
        pre->right = Thr;
    }
}
void InOrder(STree Thr)
{
    STree p = Thr->left;

    while (p != Thr)
    {
        while (p->LTag == Link)
            p = p->left;
        cout << p->ch;
        while (p->RTag == Thread && p != Thr)
        {
            p = p->right;
            cout << p->ch;
        }
        p = p->right;
    }
}
int Num(Tree T)
{
    if (T->left == nullptr && T->right == nullptr)
        return 0;
    else if (T->left == nullptr && T->right != nullptr)
        return 1 + Num(T->right);
    else if (T->left != nullptr && T->right == nullptr)
        return 1 + Num(T->left);
    else
    {
        return Num(T->left) + Num(T->right);
    }
}
int main()
{
    Tree T;
    createTreePre(T);
    STree Thr;
    ThreadTree(Thr, T);
    InOrder(Thr);
    cout << "\n";
    cout << 1 + Num(T);
    return 0;
}