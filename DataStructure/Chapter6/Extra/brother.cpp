#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
struct TNode
{
    char data;
    struct TNode *ch, *bro;
    TNode(char data) : data(data), ch(nullptr), bro(nullptr) {}
};

void In(TNode *p)
{
    if (p == nullptr)
        return;

    In(p->ch);
    cout << p->data;
    In(p->bro);
}
void pre(TNode *p)
{
    if (p == nullptr)
        return;
    cout << p->data;
    pre(p->ch);
    pre(p->bro);
}
void post(TNode *p)
{
    if (p == nullptr)
        return;
    post(p->ch);
    post(p->bro);
    cout << p->data;
}
int depth(TNode *T)
{
    if (T == nullptr)
        return 0;
    else
    {
        int depth1 = 1 + depth(T->ch);
        int depth2 = depth(T->bro);
        return depth1 > depth2 ? depth1 : depth2;
    }
}

void layer(TNode *p)
{
    if (p == nullptr)
        return;
    queue<TNode *> q;
    q.push(p);
    while (!q.empty())
    {
        TNode *s = q.front();
        cout << s->data;
        q.pop();

        if (s->ch != nullptr)
        {
            s = s->ch;
            q.push(s);

            while (s->bro != nullptr)
            {
                s = s->bro;
                q.push(s);
            }
        }
    }
}
int NumOfLeaf(TNode *T)
{
    if (T == nullptr)
        return 0;
    if (T->ch == nullptr)
        return 1 + NumOfLeaf(T->bro);
    else
        return NumOfLeaf(T->ch) + NumOfLeaf(T->bro);
}
void showPath(TNode *T, string str)
{
    while (T)
    {
        str.push_back(T->data);
        if (!T->ch)
            cout << str << endl;
        else
            showPath(T->ch, str);

        str.erase(str.end() - 1);
        T = T->bro;
    }
}
int main()
{
    queue<TNode *> Q;
    TNode *p, *T, *r, *b;

    char fa, in, ch;
    for (cin >> fa >> in >> ch; ch != '#' || fa != '#'; cin >> fa >> in >> ch)
    {
        p = new TNode(ch);
        Q.push(p);

        if (fa == '#')
            T = p;
        else
        {
            b = Q.front();

            while (b->data != fa)
            {
                Q.pop();
                b = Q.front();
            }

            if (!(b->ch))
            {
                b->ch = p;
                r = p;
            }
            else
            {
                r->bro = p;
                r = p;
            }
        }
    }

    pre(T);
    cout << "\n";
    // In(T);
    // cout << "\n";
    In(T);
    cout << "\n";
    layer(T);
    cout << '\n';
    cout << depth(T);
    cout << "\n";
    cout << NumOfLeaf(T) << "\n";
    string str;
    showPath(T, str);
    // cout << "\n";
    return 0;
}