#include <iostream>
using namespace std;

struct Node
{
    int coefficient;
    int index;
    struct Node *next;
    Node(int coefficient, int index) : coefficient(coefficient), index(index), next(nullptr) {}
    Node() {}
};

void read(Node *&pre)
{
    int a, b;

    while (cin >> a >> b)
    {
        Node *p = new Node(a, b);

        pre->next = p;
        pre = p;
    }
}

void traverse(Node *head)
{
    Node *pre = head->next;
    bool flag = false;
    while (pre)
    {
        if (pre->index != 0)
        {
            if (flag)
                cout << " ";
            cout << pre->coefficient * pre->index << " " << pre->index - 1;
            flag = true;
        }
        pre = pre->next;
    }
    if (!flag)
        cout << "0 0";
}

void destroy(Node *head)
{
    Node *pre = head;
    Node *cur = head->next;
    while (cur)
    {
        delete pre;
        pre = cur;
        cur = cur->next;
    }
    delete pre;
}

int main()
{
    Node *head = new Node;
    Node *pre = head;

    read(pre);

    traverse(head);

    destroy(head);

    return 0;
}
