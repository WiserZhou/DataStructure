

// ��ջ������������������ջ�ͳ�ջ��

// ������ͷ����Ϊջ����һ�ˣ����Ա�����ʵ������ "��ջ" �� "��ջ" ����ʱ��������������ĺ�ʱ������
#include <stdio.h>
#include <stdlib.h>

// �����еĽڵ�ṹ
typedef struct lineStack
{
    int data;
    struct lineStack *next; // ָ��ͬ���ͽṹ���ָ��next
} lineStack;

// stackΪ��ǰ����ջ��a��ʾ��ջԪ��
lineStack *push(lineStack *stack, int a)
{
    // �����洢��Ԫ�صĽڵ�
    lineStack *line = (lineStack *)malloc(sizeof(lineStack));
    line->data = a;
    // �½ڵ���ͷ�ڵ㽨���߼���ϵ
    line->next = stack;
    // ����ͷָ���ָ��
    stack = line; // ����ջ����ͷ�ڵ㣬����һ��
    return stack;
}

// ջ��Ԫ�س���ջ��ʵ�ֺ���
lineStack *pop(lineStack *stack)
{
    if (stack) // ջ����Ԫ��
    {
        // ����һ����ָ��ָ��ջ���ڵ�
        lineStack *p = stack;
        // ����ͷָ��
        stack = stack->next;
        printf("��ջԪ�أ�%d ", p->data);
        if (stack) // ʹ�� if �ж���䣬�������û�ִ��"ջ�ѿ�ȴ��Ҫ���ݳ�ջ"���������
        {
            printf("��ջ��Ԫ�أ�%d\n", stack->data);
        }
        else
        {
            printf("ջ�ѿ�\n");
        }
        free(p); // �ͷ�ջ��Ԫ��
    }
    else
    {
        printf("ջ��û��Ԫ��");
        return stack;
    }
    return stack;
}

int main()
{
    lineStack *stack = NULL;
    int m;
    printf("������Ҫ��ջ��Ԫ�ظ�����");
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        stack = push(stack, i);
    }
    printf("������Ҫ��ջ��Ԫ�ظ�����");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        stack = pop(stack);
    }
    return 0;
}