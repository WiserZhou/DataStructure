#include <iostream>
#include <string>
using namespace std;
typedef struct TNode
{
    char data;
    struct TNode *ch, *bro;
} TNode, *Tree;

void search(Tree &T)
{
}
int main()
{
    string s;
    getline(cin, s);

    Tree T = (Tree)malloc(sizeof(TNode));
    T->data = s[2];
    bool flag = false;
    // cout<<s[2];
    while (!s.empty())
    {
        if (s[0] == T->data)
        {
            Tree p = (Tree)malloc(sizeof(TNode));
            p->data = s[2];
            if (T->ch == nullptr)
            {
                T->ch = p;
            }
            else
            {
                Tree child = T->ch;
                while (child->bro != nullptr)
                    child = child->bro;
                child->bro = p;
            }
        }
        else
        {
            if (!flag && T->ch && s[0] == T->ch->data)
            {
                T = T->ch;
            }
            else if (flag && T->bro && s[0] == T->bro->data)
            {
                T = T->bro;
                flag = false;
            }
            else
            {
            }
        }
        getline(cin, s);
    }
}


