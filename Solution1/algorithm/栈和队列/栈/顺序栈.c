#include <stdio.h>
// Ԫ��elem��ջ,aΪ����,topֵΪ��ǰջ��ջ��λ��
int push(int *a, int top, int elem)
{
    a[++top] = elem; // �ȼ�����ִ�� ++top����ִ�� a[top]=elem��
    return top;
}
// ����Ԫ�س�ջ
// top�����ָ�ֵ������top=-1����ʱ����ջʱҪ��++����Ԫ����ջ��top=0ʱ������ջ����++
int pop(int *a, int top)
{
    if (top == -1)
    {
        printf("��ջ");
        return -1;
    }
    printf("��ջԪ�أ�%d\n", a[top]);
    top--;
    return top;
}
int main()
{
    int a[100];
    int top = -1; // �����top����Ϊ����-1������ʱҪ��++���ٽ�����ջ
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

