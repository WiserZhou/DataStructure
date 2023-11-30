#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int TElemType; // 假设二叉树节点存储的是 int 类型的数据

typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0号单元存储根节点

SqBiTree bt;
// 初始化二叉树，就是将所有的单元清零
void InitBiTree(SqBiTree bt)
{
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {
        bt[i] = 0;
    }
}

// 获取二叉树结点的值
TElemType Value(SqBiTree bt, int i)
{
    return bt[i];
}

// 设置二叉树结点的值
void Assign(SqBiTree bt, int i, TElemType value)
{
    bt[i] = value;
}

// 获取指定结点的左孩子结点的下标
int LeftChild(int i)   // 主要是数组的下标是从0开始的，导致这个地方和我们一般的二叉树的结点的关系不太一样
{
    return 2 * i + 1;
}

// 获取指定结点的右孩子结点的下标
int RightChild(int i)
{
    return 2 * i + 2;
}

// 获取指定结点的父结点的下标
int Parent(int i)
{
    return (i - 1) / 2;
}

int main()
{
    // 初始化二叉树
    InitBiTree(bt);

    // 设置根结点的值
    Assign(bt, 0, 1);

    // 设置左右孩子结点的值
    Assign(bt, LeftChild(0), 2);
    Assign(bt, RightChild(0), 3);

    // 获取根结点的值和左右孩子结点的值，并输出
    printf("根结点的值：%d\n", Value(bt, 0));
    printf("左孩子结点的值：%d\n", Value(bt, LeftChild(0)));
    printf("右孩子结点的值：%d\n", Value(bt, RightChild(0)));

    return 0;
}
