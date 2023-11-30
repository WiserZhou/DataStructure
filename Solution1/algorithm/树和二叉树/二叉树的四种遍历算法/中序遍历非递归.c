

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TElemType int
int top = -1; // top变量时刻表示栈顶元素所在位置

// 构造结点的结构体
typedef struct BiTNode
{
    TElemType data;                  // 数据域
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 初始化树的函数
void CreateBiTree(BiTree *T)
{
    // 创建根结点
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    // 创建左子树
    (*T)->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = NULL;
    (*T)->lchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    // 创建右子树
    (*T)->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    // 设置其他结点的左右孩子指针为NULL
    (*T)->lchild->lchild = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

// 前序和中序遍历使用的进栈函数
void push(BiTNode **a, BiTNode *elem)
{
    a[++top] = elem;
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
{
    return a[top];
}

// 中序遍历非递归算法
void InOrderTraverse1(BiTree Tree)
{
    BiTNode *a[20]; // 定义一个顺序栈
    BiTNode *p;     // 临时指针
    push(a, Tree);  // 根结点进栈
    while (top != -1)
    { // top != -1 说明栈内不为空，程序继续运行
        while ((p = getTop(a)) && p)
        {                       // 取栈顶元素，且不能为 NULL
            push(a, p->lchild); // 将该结点的左孩子进栈，如果没有左孩子，NULL进栈
        }
        pop(); // 跳出循环，栈顶元素肯定为NULL，将NULL弹栈
        if (top != -1)
        {
            p = getTop(a); // 取栈顶元素
            pop();         // 栈顶元素弹栈
            displayElem(p);
            push(a, p->rchild); // 将p指向的结点的右孩子进栈
        }
    }
}

// 中序遍历实现的另一种方法
void InOrderTraverse2(BiTree Tree)
{
    BiTNode *a[20]; // 定义一个顺序栈
    BiTNode *p;     // 临时指针
    p = Tree;
    // 当p为NULL或者栈为空时，表明树遍历完成
    while (p || top != -1)
    {
        // 如果p不为NULL，将其压栈并遍历其左子树
        if (p)
        {
            push(a, p);
            p = p->lchild;
        }
        // 如果p==NULL，表明左子树遍历完成，需要遍历上一层结点的右子树
        else
        {
            p = getTop(a);
            pop();
            displayElem(p);
            p = p->rchild;
        }
    }
}

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("中序遍历算法1: \n");
    InOrderTraverse1(Tree);
    printf("\n中序遍历算法2: \n");
    InOrderTraverse2(Tree);
    return 0;
}

Status InorderTraverse(BiTree T, Status (*Visit)(TElemType e))
{
    InitStack(S);
    push(S, T);
    while (!StackEmpty(S))
    {
        while (GetTop(S, p) && p)
            Push(S, p->lchild); // 向左走到尽头
// 通过 GetTop 函数获取栈顶元素 p，如果 p 不为空，则将 p 的左子树沿着左儿子节点一路压入栈中，直到左子树为空或者到达左子树的最左端
        Pop(S, p);              // 空指针退栈
        if (!StackEmpty(S))     // 访问结点，向右一步
// 如果栈不为空，则访问 p 节点，即调用 Visit 函数，并将 p 的右子树压入栈中
        {
            Pop(S, p);  // 把当前的节点弹出来
            if (!Visit(p->data))
                return ERROR;
            push(S, p->rchild);
        }
    }
    return OK;
}