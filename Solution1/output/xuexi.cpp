#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct Node; // Ç°ÏòÉùÃ÷

typedef struct Node
{
    char data;
    Node *lchild;
    Node *rbro;
} Node;

Node *createNode(char data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rbro = NULL;
    return node;
}

void xian(Node *node)
{
    if (node != NULL)
    {
        cout << node->data;
        xian(node->lchild);
        xian(node->rbro);
    }

    return;
}

void hou(Node *node)
{
    if (node != NULL)
    {
        hou(node->lchild);
        cout << node->data;
        hou(node->rbro);
    }

    return;
}
int maxDepth(Node *T)
{
    if (T == NULL)
        return 0;
    else
        return max(1 + maxDepth(T->lchild), maxDepth(T->rbro));
}

int countLeafNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->lchild == nullptr && root->rbro == nullptr)
    {
        return 1;
    }
    return countLeafNodes(root->lchild) + countLeafNodes(root->rbro);
}
string removeLastChar(const string &s)
{
    int length = s.length();

    if (length >= 1)
    {
        return s.substr(0, length - 1);
    }
    else
    {
        return "";
    }
}
void zimu(string s, Node *node)
{

    s = s + node->data;

    if (node->lchild != NULL)
    {
        zimu(s, node->lchild);
    }
    else
    {
        cout << s << endl;
    }
    if (node->rbro != NULL)
    {
        string temp = removeLastChar(s);
        zimu(temp, node->rbro);
    }
}
void levelOrde(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();
        cout << root->data;
        //   cout<<"++"<<endl;
        root = root->lchild;
        while (root)
        {
            q.push(root);
            root = root->rbro;
        }
    }
}
int main()
{
    Node *root, *temp;
    char pre, last;
    queue<Node *> dl;
    int flag = 0;
    string s;
    getline(cin, s);
    pre = s[0];
    last = s[2];
    root = createNode(last);
    dl.push(root);
    while (1)
    {
        if (flag == 0)
        {
            string s;
            getline(cin, s);
            pre = s[0];
            last = s[2];
            // cout<<"=="<<endl;
        }
        if (pre == '#' && last == '#')
        {
            // cout<<"===";
            xian(root);
            cout << endl;
            hou(root);
            cout << endl;
            levelOrde(root);
            cout << endl;
            cout << maxDepth(root) << endl;
            cout << countLeafNodes(root) << endl;
            zimu("", root);
            return 0;
        }
        Node *nw = createNode(last);
        Node *tp = dl.front();
        char tpdt = tp->data;
        // cout<<tpdt<<"++"<<endl;

        if (tpdt == pre)
        {
            dl.push(nw);
            tp->lchild = nw;
            // cout<<nw->data<<endl;
            while (1)
            {
                string is;
                getline(cin, is);
                char prein = is[0];
                char lastin = is[2];
                if (prein != tpdt)
                {
                    pre = prein;
                    last = lastin;
                    flag = 1;
                    break;
                }
                else
                {
                    temp = dl.back();
                    Node *nwin = createNode(lastin);
                    // Node *tp=dl.front();
                    dl.push(nwin);
                    temp->rbro = nwin;
                }
            }
        }
        dl.pop();
    }
}