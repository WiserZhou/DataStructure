

// 链栈及基本操作（包含入栈和出栈）

// 将链表头部作为栈顶的一端，可以避免在实现数据 "入栈" 和 "出栈" 操作时做大量遍历链表的耗时操作。
#include <stdio.h>
#include <stdlib.h>

// 链表中的节点结构
typedef struct lineStack
{
    int data;
    struct lineStack *next; // 指向同类型结构体的指针next
} lineStack;

// stack为当前的链栈，a表示入栈元素
lineStack *push(lineStack *stack, int a)
{
    // 创建存储新元素的节点
    lineStack *line = (lineStack *)malloc(sizeof(lineStack));
    line->data = a;
    // 新节点与头节点建立逻辑关系
    line->next = stack;
    // 更新头指针的指向
    stack = line; // 这里栈顶是头节点，方便一点
    return stack;
}

// 栈顶元素出链栈的实现函数
lineStack *pop(lineStack *stack)
{
    if (stack) // 栈中有元素
    {
        // 声明一个新指针指向栈顶节点
        lineStack *p = stack;
        // 更新头指针
        stack = stack->next;
        printf("出栈元素：%d ", p->data);
        if (stack) // 使用 if 判断语句，避免了用户执行"栈已空却还要数据出栈"错误操作。
        {
            printf("新栈顶元素：%d\n", stack->data);
        }
        else
        {
            printf("栈已空\n");
        }
        free(p); // 释放栈顶元素
    }
    else
    {
        printf("栈内没有元素");
        return stack;
    }
    return stack;
}

int main()
{
    lineStack *stack = NULL;
    int m;
    printf("请输入要入栈的元素个数：");
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        stack = push(stack, i);
    }
    printf("请输入要出栈的元素个数：");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        stack = pop(stack);
    }
    return 0;
}