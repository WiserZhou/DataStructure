

#include <stdio.h>
#include <stdlib.h>

// ����ջ�ṹ
typedef struct
{
    int top;      // ջ��ָ��
    int capacity; // ջ����
    int *array;   // �洢ջԪ�ص�����
} Stack;

// ����ջ
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));               // �����ڴ��Դ���ջ�ṹ
    stack->capacity = capacity;                                  // ����ջ����
    stack->top = -1;                                             // ��ʼ��ջ��ָ��Ϊ-1����ʾջΪ��
    stack->array = (int *)malloc(stack->capacity * sizeof(int)); // ����ջ��������洢�ռ�
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// ��ջ
void push(Stack *stack, int item)
{
    if (isFull(stack))
    { // ջ�������޷���ջ
        printf("ջ�������޷���ջ\n");
        return;
    }
    stack->array[++stack->top] = item; // ջ��ָ���1������Ԫ����ջ
}

// ��ջ
int pop(Stack *stack)
{
    if (isEmpty(stack))
    { // ջΪ��
        printf("ջΪ��\n");
        return -1;
    }
    return stack->array[stack->top--]; // ջ��ָ���1��������ջ��Ԫ��
}

// ʮ����ת������
void decimalToOtherBase(int decimal, int base)
{
    Stack *stack = createStack(100); // ����һ������Ϊ100��ջ

    if (decimal == 0)
    {
        printf("0"); // �����ת����ʮ������Ϊ0����ֱ�����0
        return;
    }

    while (decimal > 0)
    {
        int remainder = decimal % base; // ��������
        push(stack, remainder);         // ��������ջ
        decimal /= base;                // ʮ���������Խ�����������ʮ��������ֵ
    }

    while (!isEmpty(stack))
    {
        int digit = pop(stack); // ���γ�ջ�õ�ÿһλ��ֵ

        // �����16��������ֵ���ڵ���10���򽫶�Ӧ��ֵת���ɴ�д��ĸ���
        if (base == 16 && digit >= 10)
        {
            printf("%c", 'A' + digit - 10);
        }
        else
        {
            printf("%d", digit); // �����Ӧλ��ֵ
        }
    }

    free(stack->array); // �ͷ�ջ������ڴ�
    free(stack);        // �ͷ�ջ�ṹ���ڴ�
}

int main()
{
    int decimal, base;

    //printf("������һ��ʮ��������: ");
    scanf("%d", &decimal);

    //printf("������Ҫת���Ľ��ƣ�2��8��16��: ");
    scanf("%d", &base);

    //printf("ת�����Ϊ: ");
    decimalToOtherBase(decimal, base);
    printf("\n");

    return 0;
}