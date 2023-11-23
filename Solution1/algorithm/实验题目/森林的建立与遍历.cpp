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
// �����������ֵ
void In(TNode *p)
{
    if (p == nullptr)
        return;
    In(p->ch);
    if (p->data != '/')
        cout << p->data;
    In(p->bro);
}
// ��������ĵݹ��㷨
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
        showPath(T->ch, str); // �������ӵ�ʱ��Ҫ���ַ����ϼ���һ���µ��ַ�����֤���������
        if (T->bro)
            showPath(T->bro, s); // �������û���ֵܽ�㣬Ҳ���������str����Ϊ�ֵܵľ�ͷ����Ҷ�ӽ��
    }
    else
    {
        str.erase(0, 1);  // ��仰��������ɭ�ֽ�����֮������������ڽ���ɭ�ֵ�ʱ�򣬾��ǰѸ��ڵ����ˡ�/",��ʱ���ڽ�������֮��
        // �ѵ�һ�����ڵ�ɾ���ͺ��ˣ�Ȼ�����Ҳ��1�����ˣ���ʵ������û��ɶ�����
        cout << str << "\n";
        return;
    }
}
int main()
{
    queue<TNode *> q;
    string s;
    cin >> s;
    q.push(new TNode(s[2]));  // ����һ���µĽڵ㣬�ýڵ��ֵΪ s �ĵ������ַ����� s[2]������������ӵ����� q ��
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