#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;

typedef struct SNode
{
    SElemType data;     // 数据域
    struct SNode *next; // 链域
} SNode, *LinkStack;

// 初始化栈
void InitStack(LinkStack &S)
{
    S = (SNode *)malloc(sizeof(SNode));
    if (!S)
    {
        exit(1); // 存储分配失败
    }
    S->next = NULL;
}

// 入栈操作
void Push(LinkStack &S, SElemType e)
{
    SNode *p = (SNode *)malloc(sizeof(SNode));
    if (!p)
    {
        exit(1); // 存储分配失败
    }
    p->data = e;
    p->next = S->next;// 这个代码一定要写在下一行代码的前面，不然，S->next后面就丢失了
    S->next = p;
}

// 出栈操作
void Pop(LinkStack &S, SElemType &e)
{
    if (S->next == NULL)
    {
        // 栈为空，出栈失败
        e = -1; // 这里使用-1作为出栈失败的标志
        return;
    }
    SNode *p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
}

int main()
{
    LinkStack S;
    int value;

    // 初始化栈
    InitStack(S);

    // 入栈操作
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);

    // 出栈操作
    Pop(S, value);
    printf("%d\n", value); // 输出: 3

    Pop(S, value);
    printf("%d\n", value); // 输出: 2

    Pop(S, value);
    printf("%d\n", value); // 输出: 1

    // 出栈失败示例
    Pop(S, value);
    if (value == -1)
    {
        printf("出栈失败\n");
    }

    return 0;
}
