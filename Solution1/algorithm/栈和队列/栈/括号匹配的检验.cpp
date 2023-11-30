#include <stdio.h>
// 定义栈结构
#define STACK_SIZE 100
typedef struct
{
    char data[STACK_SIZE];
    int top;
} Stack;
typedef enum
{
    FALSE,
    TRUE
} Status;
// 初始化栈
void InitStack(Stack *S)
{
    S->top = -1;
}
// 入栈
Status Push(Stack *S, char ch)
{
    if (S->top == STACK_SIZE - 1)
    {
        return FALSE; // 栈已满，入栈失败
    }
    S->data[++(S->top)] = ch;
    return TRUE;
}
// 出栈
Status Pop(Stack *S, char *ch)
{
    if (S->top == -1)
    {
        return FALSE; // 栈为空，出栈失败
    }
    *ch = S->data[(S->top)--];
    return TRUE;
}
// 判断栈是否为空
Status StackEmpty(Stack *S)
{
    return S->top == -1 ? TRUE : FALSE;
}
// 括号匹配检验算法
Status check()
{
    Stack S;
    char ch, e;
    InitStack(&S);
    while ((ch = getchar()) != '#')    // 这个主要是检查括号匹配的，所以输入的相关的字符的话，不会进入到这个里面的
    {
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            Push(&S, ch);
            break;
        case ')':
            if (StackEmpty(&S))
                return FALSE;
            else
            {
                Pop(&S, &e);
                if (e != '(')
                    return FALSE;
            }
            break;
        case ']':
            if (StackEmpty(&S))
                return FALSE;
            else
            {
                Pop(&S, &e);
                if (e != '[')
                    return FALSE;
            }
            break;
        case '}':
            if (StackEmpty(&S))
                return FALSE;
            else
            {
                Pop(&S, &e);
                if (e != '{')
                    return FALSE;
            }
            break;
        default:
            break;
        }
    }
    if (StackEmpty(&S))
        return TRUE;
    else
        return FALSE;
}
int main()
{
    printf("请输入括号序列（以'#'结束）：");
    if (check())
    {
        printf("括号匹配正确\n");
    }
    else
    {
        printf("括号匹配错误\n");
    }
    return 0;
}
