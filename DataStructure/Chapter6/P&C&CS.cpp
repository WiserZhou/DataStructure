#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
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
    int child; // 存储的是索引
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

// 输出从根到叶子结点的路径
void OutPath(CSTree T, string str)
{
    while (T)
    {
        str.push_back(T->data);

        if (!T->firstChild)
            cout << str << endl;
        else
            OutPath(T->firstChild, str);

        str.erase(str.end() - 1);
        T = T->nextSibling; // 往右走前要出栈，因为右链域是兄弟，不能把叶子结点的值带到兄弟分支上去
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
// 森林转化为二叉树
void CreateTree(CSTree &T)
{
    T = nullptr;
    char fa, ch;
    CSTree p, r, s;

    queue<CSTree> Q;

    for (cin >> fa >> ch; ch != '#'; cin >> fa >> ch)
    {
        p = CreateTreeNode(ch);

        Q.push(p);

        if (fa == '#')
            T = p;
        else
        {
            s = Q.front();

            while (s->data != fa) // 获得与输入的二元组匹配的父结点，使用循环，如果不匹配就一直进行
            {
                Q.pop();
                s = Q.front();
            }

            if (!(s->firstChild))
                s->firstChild = p; // 对于s，表示当前正在遍历的结点，让新结点p直接作为他的左孩子
            else
                r->nextSibling = p; // 让新结点p连接到当前正在进行连接操作的结点r上
            r = p;                  // r用来表示正在进行连接的结点的位置，注意此时连接兄弟的是他的孩子，而不是他本身
        }
    }
}
// 计算叶子结点的数量
int NumOfLeaf(CSTree T)
{
    if (T == nullptr)
        return 0;
    if (T->firstChild == nullptr)
        return 1 + NumOfLeaf(T->nextSibling);
    else
        return NumOfLeaf(T->firstChild) + NumOfLeaf(T->nextSibling);
}
// 层次遍历
void LevelTraversal(CSTree p)
{
    if (p == nullptr)
        return;
    queue<CSNode *> q;
    q.push(p);
    while (!q.empty())
    {
        CSTree s = q.front();
        cout << s->data;
        q.pop();

        if (s->firstChild != nullptr)
        {
            s = s->firstChild;
            q.push(s);

            while (s->nextSibling != nullptr)
            {
                s = s->nextSibling;
                q.push(s);
            }
        }
    }
}