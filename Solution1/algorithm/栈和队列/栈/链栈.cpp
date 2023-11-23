#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;

typedef struct SNode
{
    SElemType data;     // ������
    struct SNode *next; // ����
} SNode, *LinkStack;

// ��ʼ��ջ
void InitStack(LinkStack &S)
{
    S = (SNode *)malloc(sizeof(SNode));
    if (!S)
    {
        exit(1); // �洢����ʧ��
    }
    S->next = NULL;
}

// ��ջ����
void Push(LinkStack &S, SElemType e)
{
    SNode *p = (SNode *)malloc(sizeof(SNode));
    if (!p)
    {
        exit(1); // �洢����ʧ��
    }
    p->data = e;
    p->next = S->next;// �������һ��Ҫд����һ�д����ǰ�棬��Ȼ��S->next����Ͷ�ʧ��
    S->next = p;
}

// ��ջ����
void Pop(LinkStack &S, SElemType &e)
{
    if (S->next == NULL)
    {
        // ջΪ�գ���ջʧ��
        e = -1; // ����ʹ��-1��Ϊ��ջʧ�ܵı�־
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

    // ��ʼ��ջ
    InitStack(S);

    // ��ջ����
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);

    // ��ջ����
    Pop(S, value);
    printf("%d\n", value); // ���: 3

    Pop(S, value);
    printf("%d\n", value); // ���: 2

    Pop(S, value);
    printf("%d\n", value); // ���: 1

    // ��ջʧ��ʾ��
    Pop(S, value);
    if (value == -1)
    {
        printf("��ջʧ��\n");
    }

    return 0;
}
