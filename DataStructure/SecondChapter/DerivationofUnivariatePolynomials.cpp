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
int main()
{
    int a, b;

    Node *head = new Node;
    Node *pre = head;
    while (EOF != scanf("%d%d", &a, &b))
    {
        // cout << a << " " << b << "\n";
        Node *p = new Node(a, b);

        pre->next = p;
        pre = p;
    }
    Node *end = pre;
    pre = head;
    bool flag = false;
    while (pre->next)
    {
        pre = pre->next;
        if (pre->index != 0)
        {
            if (pre != end)
                cout << pre->coefficient * pre->index << " " << pre->index - 1 << " ";
            else
                cout << pre->coefficient * pre->index << " " << pre->index - 1;
            flag = true;
        }
    }
    if (!flag)
        cout << "0"
             << " "
             << "0";
    return 0;
}