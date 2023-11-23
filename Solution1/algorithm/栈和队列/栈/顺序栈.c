#include <stdio.h>
// 元素elem进栈,a为数组,top值为当前栈的栈顶位置
int push(int *a, int top, int elem)
{
    a[++top] = elem; // 等价于先执行 ++top，再执行 a[top]=elem。
    return top;
}
// 数据元素出栈
// top有两种赋值方法，top=-1，到时候入栈时要先++，再元素入栈，top=0时，先入栈，再++
int pop(int *a, int top)
{
    if (top == -1)
    {
        printf("空栈");
        return -1;
    }
    printf("弹栈元素：%d\n", a[top]);
    top--;
    return top;
}
int main()
{
    int a[100];
    int top = -1; // 这里的top设置为的是-1，操作时要先++，再进行入栈
    int m;
    printf("Please input the number that you want to add to the stack:");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        top = push(a, top, i);
    printf("the elems that out of the stack are:\n");
    for (int i = 0; i < m; i++)
        top = pop(a, top);
    return 0;
}

