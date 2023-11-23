

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // ����isdigit����

// ����ڵ�ṹ
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// ����ջ�ṹ
typedef struct
{
    Node *top;
} Stack;

// �����ڵ�
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// �ж�ջ�Ƿ�Ϊ��
int isStackEmpty(Stack *stack)
{
    return stack->top == NULL;
}

// ��ջ
void push(Stack *stack, int data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// ��ջ
int pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("ջΪ��\n");
        return 0;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// ��ȡջ��Ԫ��
int peek(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("ջΪ��\n");
        return 0;
    }
    return stack->top->data;
}

// �����������ȼ�
int checkPrecedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

// ִ�ж�Ԫ����
int performOperation(char operator, int operand1, int operand2)
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
        if (operand2 != 0)
        {
            return operand1 / operand2;
        }
        else
        {
            printf("����Ϊ��\n");
            return 0;
        }
    default:
        printf("��Ч�����\n");
        return 0;
    }
}

// ��ֵ����
int evaluateExpression(char *expression)
{
    Stack operandStack;
    Stack operatorStack;
    int i;

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (isspace(expression[i]))
        {
            continue; // ���Կո�
        }
        else if (isdigit(expression[i]))
        {
            int operand = 0;
            while (isdigit(expression[i]))
            {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(&operandStack, operand);
        }
        else if (expression[i] == '(')
        {
            push(&operatorStack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!isStackEmpty(&operatorStack) && peek(&operatorStack) != '(')
            {
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                char operator= pop(&operatorStack);
                int result = performOperation(operator, operand1, operand2);
                push(&operandStack, result);
            }
            if (!isStackEmpty(&operatorStack) && peek(&operatorStack) != '(')
            {
                printf("���Ų�ƥ��\n");
                return 0;
            }
            else
            {
                pop(&operatorStack); // ����������
            }
        }
        else
        {
            while (!isStackEmpty(&operatorStack) && checkPrecedence(expression[i]) <= checkPrecedence(peek(&operatorStack)))
            {
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                char operator= pop(&operatorStack);
                int result = performOperation(operator, operand1, operand2);
                push(&operandStack, result);
            }
            push(&operatorStack, expression[i]);
        }
    }

    while (!isStackEmpty(&operatorStack))
    {
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);
        char operator= pop(&operatorStack);
        int result = performOperation(operator, operand1, operand2);
        push(&operandStack, result);
    }

    return pop(&operandStack);
}

int main()
{
    char expression[100];

    printf("������һ���������ʽ: ");
    fgets(expression, 100, stdin);

    int result = evaluateExpression(expression);
    printf("���ʽ��ֵΪ��%d\n", result);

    return 0;
}