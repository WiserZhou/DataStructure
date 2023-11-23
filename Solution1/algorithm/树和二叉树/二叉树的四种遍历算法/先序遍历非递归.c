

// 使用顺序栈来模拟递归调用的过程，通过不断地弹栈和压栈来遍历树结构

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TElemType int
int top = -1; // top变量时刻表示栈顶元素所在位置,全局变量

// 构造结点的结构体
typedef struct BiTNode
{
    TElemType data;                  // 数据域
    struct BiTNode *lchild;         // 左孩子指针
    struct BiTNode *rchild;         // 右孩子指针
} BiTNode, *BiTree;

// 初始化树的函数
void CreateBiTree(BiTree *T)
{
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

// 先序遍历使用的进栈函数
void push(BiTNode **a, BiTNode *elem)
// BiTNode **a：表示一个指向指针数组的指针，该指针数组用于表示栈结构
// BiTNode *elem：表示要压入栈中的二叉树节点指针
{
    a[++top] = elem;
    // top 变量代表栈顶元素所在的位置，初始值为 -1
}

// 弹栈函数
void pop()
{
    if (top == -1)
    {
        return;
    }
    top--;
}

// 模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode *elem)
{
    printf("%d ", elem->data);
}

// 拿到栈顶元素
BiTNode *getTop(BiTNode **a)
// BiTNode **a：表示一个指向指针数组的指针，该指针数组用于表示栈结构
{
    return a[top];
}

// 先序遍历非递归算法
void PreOrderTraverse(BiTree Tree)
{
    BiTNode *a[20]; // 定义一个顺序栈
    BiTNode *p;     // 临时指针
    push(a, Tree);  // 根结点进栈
    while (top != -1)
    {
        p = getTop(a); // 取栈顶元素，第一次取到的就是根节点的元素
        pop();         // 弹栈
        while (p)
        {
            displayElem(p); // 调用结点的操作函数,这句代码就是打印出元素的代码,打印出来，但是左孩子没有进栈
            // 如果该结点有右孩子，右孩子进栈
            if (p->rchild)
            {
                push(a, p->rchild);
            }
            p = p->lchild; // 一直指向根结点最后一个左孩子
        }
    }
}

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("先序遍历: \n");
    PreOrderTraverse(Tree);
    return 0;
}