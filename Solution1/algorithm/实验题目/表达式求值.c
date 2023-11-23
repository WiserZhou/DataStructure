

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ����ջ�Ľṹ��
typedef struct
{
    int top;
    int capacity;
    int *array;
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
    Stack *operandStack = createStack(100);
    Stack *operatorStack = createStack(100);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isspace(expression[i]))
            continue;

        if (isdigit(expression[i]))
        { // ��������֣��������ַ�ת��Ϊ��������ջ
            int operand = expression[i] - '0';
            while (isdigit(expression[i + 1]))
            {
                operand = operand * 10 + (expression[i + 1] - '0');
                i++;
            }
            push(operandStack, operand);
        }
        else if (expression[i] == '(')
        { // ����������ţ�ֱ����ջ
            push(operatorStack, expression[i]);
        }
        else if (expression[i] == ')')
        { // ����������ţ�ִ����Ӧ�Ĳ���
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(')
            {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char operator= pop(operatorStack);
                int result = executeOperation(operand1, operator, operand2);
                push(operandStack, result);
            }
            pop(operatorStack); // ����������
        }
        else
        { // �������������������ȼ�ִ����Ӧ�Ĳ���
            while (!isEmpty(operatorStack) && getPriority(peek(operatorStack)) >= getPriority(expression[i]))
            {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char operator= pop(operatorStack);
                int result = executeOperation(operand1, operator, operand2);
                push(operandStack, result);
            }
            push(operatorStack, expression[i]);
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
    free(operandStack->array);
    free(operandStack);
    free(operatorStack->array);
    free(operatorStack);

    return finalResult;
}

int main()
{
    char expression[100];
    fgets(expression, sizeof(expression), stdin);

    // ����β��ӿ��ַ�
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n')
        expression[len - 1] = '\0';

    int result = evaluateExpression(expression);
    printf("%d\n", result);

    return 0;
}