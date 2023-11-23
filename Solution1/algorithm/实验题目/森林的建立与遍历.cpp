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
// 输出结点的数据值
void In(TNode *p)
{
    if (p == nullptr)
        return;
    In(p->ch);
    if (p->data != '/')
        cout << p->data;
    In(p->bro);
}
// 先序遍历的递归算法
void pre(TNode *p)
{
    if (p == nullptr)
        return;
    if (p->data != '/')
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
    if (p->data != '/')
        cout << p->data;
    while (!q.empty())
    {
        TNode *s = q.front();
        q.pop();
        if (s->ch != nullptr)
        {
            s = s->ch;
            if (s->data != '/')
                cout << s->data;
            q.push(s);
            while (s->bro != nullptr)
            {
                s = s->bro;
                if (s->data != '/')
                    cout << s->data;
                q.push(s);
            }
        }
    }
}
void pushBranch(TNode *&T, TNode *&s)
{
    if (T->ch == nullptr)
    {
        T->ch = s;
    }
    else
    {
        TNode *p = T->ch;
        while (p->bro != nullptr)
            p = p->bro;
        p->bro = s;
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
    if (T)
    {
        string s = str;
        str.push_back(T->data);
        showPath(T->ch, str); // 遍历孩子的时候要在字符串上加上一个新的字符，保证是向深处遍历
        if (T->bro)
            showPath(T->bro, s); // 这里就算没有兄弟结点，也不可以输出str，因为兄弟的尽头不是叶子结点
    }
    else
    {
        str.erase(0, 1);  // 这句话就是树和森林建立的之后的区别，我们在建立森林的时候，就是把根节点变成了“/",到时候在建立好树之后
        // 把第一个根节点删除就好了，然后深度也减1就行了，其实本质上没有啥区别的
        cout << str << "\n";
        return;
    }
}
int main()
{
    queue<TNode *> q;
    string s;
    cin >> s;
    q.push(new TNode(s[2]));  // 创建一个新的节点，该节点的值为 s 的第三个字符（即 s[2]），并将其添加到队列 q 中
    TNode *T = q.front();
    cin >> s;
    while (!q.empty() && s[2] != '#')
    {
        TNode *character = q.front();
        if (s[0] == character->data)
        {
            TNode *ss = new TNode(s[2]);
            pushBranch(character, ss);
            q.push(ss);
            cin >> s;
        }
        else
        {
            q.pop();
        }
    }
    pre(T);
    cout << "\n";
    In(T);
    cout << "\n";
    layer(T);
    cout << '\n';
    cout << depth(T) - 1;
    cout << "\n";
    cout << NumOfLeaf(T) << "\n";
    string str;
    showPath(T, str);
    return 0;
}