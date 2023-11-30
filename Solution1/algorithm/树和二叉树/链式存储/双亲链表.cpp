#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct BPTNode // 结点结构
{
    TElemType data;
    struct BPTNode *parent; // 指向双亲的指针
    char LRTag;             // 左、右孩子标志域
} BPTNode;

typedef struct BPTree // 树结构
{
    BPTNode nodes[MAX_TREE_SIZE];
    int num_node; // 结点数目
    int root;     // 根结点的位置
} BPTree;

void InitBPTree(BPTree *T)
{
    T->num_node = 0; // 初始化结点数目为0
    T->root = -1;    // 初始化根节点位置为-1，表示为空树
}

int CreateBPTree(BPTree *T, TElemType e)
{
    if (T->num_node >= MAX_TREE_SIZE)
        return -1; // 结点数目已达到最大容量，无法插入新结点

    T->nodes[T->num_node].data = e;      // 设置新结点的数据域
    T->nodes[T->num_node].parent = NULL; // 初始化双亲指针为空
    T->nodes[T->num_node].LRTag = 'N';   // 初始化左、右孩子标志域为‘N’，表示无左右孩子

    return T->num_node++; // 返回新结点在数组中的下标，并将结点数目加一
}

void SetLChild(BPTree *T, int p, int c)
{
    T->nodes[p].LRTag = 'L';             // 设置p结点的左孩子标志域为‘L’，表示有左孩子
    T->nodes[c].parent = &(T->nodes[p]); // 设置c结点的双亲指针指向p结点
}

void SetRChild(BPTree *T, int p, int c)
{
    T->nodes[p].LRTag = 'R';             // 设置p结点的右孩子标志域为‘R’，表示有右孩子
    T->nodes[c].parent = &(T->nodes[p]); // 设置c结点的双亲指针指向p结点
}

int main()
{
    BPTree T;
    InitBPTree(&T);

    // 创建根节点和两个子节点
    int root = CreateBPTree(&T, 1);
    int lchild = CreateBPTree(&T, 2);
    int rchild = CreateBPTree(&T, 3);
    printf("根节点数据为：%d\n", T.nodes[root].data);
    // 设置左右子节点
    SetLChild(&T, root, lchild);
    if (T.nodes[root].LRTag == 'L')
        printf("左孩子数据为：%d\n", T.nodes[lchild].data);
    else
        printf("没有左孩子。\n");
    SetRChild(&T, root, rchild); // 在前面的代码中是吧root的LRTag设置成为了'L'，但是下面的代码又会把LRTag设置成'R'
    if (T.nodes[root].LRTag == 'R')
        printf("右孩子数据为：%d\n", T.nodes[rchild].data);
    else
        printf("没有右孩子。\n");
    return 0;
}
