#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100 // ջ����
#define STACKINCREMENT 10   // ջ����

typedef int SElemType; // ����ջ��Ԫ��Ϊ��������

typedef struct
{
    SElemType *base; // ����ַ
    SElemType *top;  // ջ��ָ��
    int stacksize;   // ջ����
} SqStack;

// ��ʼ��ջ
int InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
    {
        return 0;
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return 1;
}

// ѹջ����
int Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        // �·�����ڴ��ַ���� S.base
        if (!S.base)
        {
            return 0;
        }
        // ��ʱ�ٽ�topָ��ָ���µ�ջ����Ȼ���ٽ�ջ���������Ͳ��ᷢ�������
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    // �� e ��ֵ���� S.top ָ����ڴ��ַ������ S.top ָ������ƶ�һ��λ�ã�ָ����һ��ջ��Ԫ�صĵ�ַ
    return 1;
}

// ��ջ����
int Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)  // ˵����ʱջ��
    {
        return 0;
    }
    else
    {
        e = *(--S.top);
    }
    return 1;
}

int main()
{
    SqStack S;
    SElemType e;

    // ��ʼ��ջ
    if (!InitStack(S))
    {
        printf("��ʼ��ջʧ�ܣ�\n");
        return -1;
    }

    // ѹ��Ԫ��
    for (int i = 1; i <= 10; i++)
    {
        if (!Push(S, i))
        {
            printf("ѹ��Ԫ�� %d ʧ�ܣ�\n", i);
            return -1;
        }
    }

    // ����Ԫ��
    while (Pop(S, e))
    {
        printf("%d ", e);
    }
    printf("\n");

    return 0;
}
