#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// ����ջ�Ľṹ��
typedef struct
{
    int top; // ����ջ��ָ��
    int capacity;
    int *array; // ��������,���ٴ�С
} Stack;
// ����ջ
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
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
    {
        printf("ջ�������޷���ջ\n");
        return;
    }
    stack->array[++stack->top] = item;
}
// ��ջ
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("ջΪ�գ��޷���ջ\n");
        return -1;
    }
    return stack->array[stack->top--];
}
// ��ȡջ��Ԫ��
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("ջΪ��\n");
        return -1;
    }
    return stack->array[stack->top];
}
// �ж�����������ȼ�
int getPriority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
        return 0;
    default:
        return -1;
    }
}
// ִ�в���
int executeOperation(int operand1, char operator, int operand2)
{
    switch (operator)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}
// ���������ʽ��ֵ
int evaluateExpression(char *expression)
{
    Stack *operandStack = createStack(100);  // ���ڴ洢������
    Stack *operatorStack = createStack(100); // ���ڴ洢�����
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isspace(expression[i])) // ��������հ��ַ������������ַ�������������һ���ַ���
            continue;
        if (isdigit(expression[i]))
        { // ��������֣��������ַ�ת��Ϊ��������ջ
            int operand = expression[i] - '0';
            while (isdigit(expression[i + 1])) // �ٸ����� 21 �Ȱ�2�洢��ȥ�ˣ���ʱ������һ�����֣����2����ʮ���ˣ����д˲���
            {
                operand = operand * 10 + (expression[i + 1] - '0');
                i++;
            }
            push(operandStack, operand); // ������ѹ������ջ
        }
        else if (expression[i] == '(')
        { // ����������ţ�ֱ����ջ
            push(operatorStack, expression[i]);
        }
        else if (expression[i] == ')')
        {                                                                 // ����������ţ�ִ����Ӧ�Ĳ���
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(') // �������ջ��Ϊ����ջ��Ԫ�ز���������ʱ
            {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);  // ����������ջ��������Ԫ�أ��ֱ���Ϊ������2�Ͳ�����1
                char operator= pop(operatorStack); // ���������ջ���������
                int result = executeOperation(operand1, operator, operand2);
                push(operandStack, result);
            }                   // �ظ�,ֱ�������ջΪ�ջ�ջ��Ԫ��Ϊ������
            pop(operatorStack); // ����������
        }
        else
        {                                                                                                     // �������������������ȼ�ִ����Ӧ�Ĳ���
            while (!isEmpty(operatorStack) && getPriority(peek(operatorStack)) >= getPriority(expression[i])) // �������ջ��Ϊ���ҵ�ǰ����Ĳ����������ȼ�С�ڻ����ջ�������������ȼ�ʱ
            {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char operator= pop(operatorStack);
                int result = executeOperation(operand1, operator, operand2); // �������ȼ��ߵ��ȼ���
                push(operandStack, result);
            }                                   // �ظ�,ֱ�������ջΪ�ջ�ջ�������������ȼ�С�ڵ�ǰ����Ĳ����������ȼ�
            push(operatorStack, expression[i]); // Ҫ�����ȼ�С�Ļ����Ǿ���ֱ�ӰѸ������ֱ����ջ����
            // ����ǰ����Ĳ�����ѹ�������ջ��
        }
    }
    while (!isEmpty(operatorStack))
    { // ����ʣ���������Ͳ�����
        int operand2 = pop(operandStack);
        int operand1 = pop(operandStack);
        char operator= pop(operatorStack);
        int result = executeOperation(operand1, operator, operand2);
        push(operandStack, result);
    }
    int finalResult = peek(operandStack); // ��ȡ���ռ�����
    free(operandStack->array);            // ����ͷŵ�˳���ǲ��ܹ�д����
    free(operandStack);
    free(operatorStack->array);
    free(operatorStack);
    return finalResult;
}
int main()
{
    char expression[100];
    fgets(expression, sizeof(expression), stdin);
    // expression�Ǵ�������ַ������ַ����飬sizeof(expression)�Ǹ�����Ĵ�С��stdin�����׼������
    // ����β��ӿ��ַ�
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n')
        expression[len - 1] = '\0';
    int result = evaluateExpression(expression);
    printf("%d\n", result);
    return 0;
}