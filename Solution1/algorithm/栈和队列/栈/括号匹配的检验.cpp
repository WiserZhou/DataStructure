#include <stdio.h>
// ����ջ�ṹ
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
// ��ʼ��ջ
void InitStack(Stack *S)
{
    S->top = -1;
}
// ��ջ
Status Push(Stack *S, char ch)
{
    if (S->top == STACK_SIZE - 1)
    {
        return FALSE; // ջ��������ջʧ��
    }
    S->data[++(S->top)] = ch;
    return TRUE;
}
// ��ջ
Status Pop(Stack *S, char *ch)
{
    if (S->top == -1)
    {
        return FALSE; // ջΪ�գ���ջʧ��
    }
    *ch = S->data[(S->top)--];
    return TRUE;
}
// �ж�ջ�Ƿ�Ϊ��
Status StackEmpty(Stack *S)
{
    return S->top == -1 ? TRUE : FALSE;
}
// ����ƥ������㷨
Status check()
{
    Stack S;
    char ch, e;
    InitStack(&S);
    while ((ch = getchar()) != '#')    // �����Ҫ�Ǽ������ƥ��ģ������������ص��ַ��Ļ���������뵽��������
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
    printf("�������������У���'#'��������");
    if (check())
    {
        printf("����ƥ����ȷ\n");
    }
    else
    {
        printf("����ƥ�����\n");
    }
    return 0;
}
