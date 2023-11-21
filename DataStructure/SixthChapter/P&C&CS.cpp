#define MAX_TREE_SIZE 100 // 树的最大节点数量
typedef int ElemType;
/**
 * 双亲链表表示法
 */
typedef struct
{
    char data;  // 节点数据
    int parent; // 双亲节点的索引
} PTNode;
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE]; // 节点数组
    int r, n;                    // 根结点的位置和当前节点数目
} PTree;

/**
 * 孩子链表表示法
 */
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} *ChildPtr;
typedef struct
{
    ElemType data;
    ChildPtr firstChild;
    // 孩子链的头指针
} CTBox;
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // 结点数和根结点的位置
} CTree;

/**
 * 孩子兄弟表示法
 */
typedef struct CSNode
{
    ElemType data;
    struct CSNode
        *firstChild,
        *nextSibling;
} CSNode, *CSTree;

int TreeDepth(CSTree T)
{
    if (!T)
        return 0;
    else
    {
        int h1 = 1 + TreeDepth(T->firstChild); // 孩子结点往深处走，要+1，兄弟结点是同层，深度不增加
        int h2 = TreeDepth(T->nextSibling);
        return h1 > h2 ? h1 : h2;
    }
} // TreeDepth

#include <stack>
#include <iostream>
#include <vector>
void OutPath(CSTree T, std::stack<int> &S)
{
    // 输出森林中所有从根到叶的路径
    while (T)
    {
        S.push(T->data);

        if (!T->firstChild)
            PrintPath(S);
        else
            OutPath(T->firstChild, S);

        S.pop();
        T = T->nextSibling; // 往右走前要出栈，因为右链域是兄弟，不能把叶子结点的值带到兄弟分支上去
    }
}
void PrintPath(std::stack<int> S)
{
    // 将栈中的元素放入临时容器（vector）中
    std::vector<int> tempVector;
    while (!S.empty())
    {
        tempVector.push_back(S.top());
        S.pop();
    }

    // 逆序输出元素，以恢复栈的原始顺序
    for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
#include <queue>
void CreateTree(CSTree &T)
{
    T = nullptr;
    char fa, ch;
    CSTree p, r, s;

    std::queue<CSTree> Q;

    for (std::cin >> fa >> ch; ch != '#'; std::cin >> fa >> ch)
    {
        p = CreateTreeNode(ch);

        Q.push(p);

        if (fa == '#')
            T = p;
        else
        {
            s = Q.front();

            while (s->data != fa)
            {
                Q.pop();
                s = Q.front();
            }

            if (!(s->firstChild))
            {
                s->firstChild = p;
                r = p;
            }
            else
            {
                r->nextSibling = p;
                r = p;
            }
        }
    }
}
CSNode *CreateTreeNode(char ch)
{
    CSNode *p = new CSNode;
    p = new CSNode; // Assuming GetTreeNode(ch) is equivalent to creating a new node
    p->data = ch;
    p->firstChild = nullptr;
    p->nextSibling = nullptr;
    return p;
}