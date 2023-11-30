#include <iostream>
using namespace std;

// 定义二叉树节点结构
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 计算叶子节点个数
void CountLeaf(BiTree T, int &count)
{
    if (T)
    {
        if ((!T->lchild) && (!T->rchild)) // 叶子结点就是既没有左孩子也没有右孩子的节点
        {
            count++; // 对叶子结点计数
        }
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    }
}

// 返回二叉树的深度
int Depth(BiTree T)
{
    int depthval, depthLeft, depthRight;
    if (!T)
    {
        depthval = 0;
    }
    else
    {
        depthLeft = Depth(T->lchild);  // 左子树的深度
        depthRight = Depth(T->rchild); // 右子树的深度
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthval;
}

int main()
{
    // 创建一个简单的二叉树作为示例
    BiTNode node1, node2, node3, node4, node5;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;
    node4.data = 4;
    node5.data = 5;
    node1.lchild = &node2;
    node1.rchild = &node3;
    node2.lchild = &node4;
    node2.rchild = nullptr;
    node3.lchild = &node5;
    node3.rchild = nullptr;
    node4.lchild = nullptr;
    node4.rchild = nullptr;
    node5.lchild = nullptr;
    node5.rchild = nullptr;

    // 调用函数计算叶子节点个数
    int leafCount = 0;
    CountLeaf(&node1, leafCount);
    cout << "叶子节点个数：" << leafCount << endl;

    // 调用函数计算二叉树深度
    int treeDepth = Depth(&node1);
    cout << "二叉树深度：" << treeDepth << endl;

    return 0;
}
