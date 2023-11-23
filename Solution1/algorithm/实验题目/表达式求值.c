

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 定义栈的结构体
typedef struct
{
    int top;
    int capacity;
    int *array;
} Stack;

// 创建栈
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// 判断栈是否为空
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// 入栈
void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// 出栈
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("栈为空，无法出栈\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// 获取栈顶元素
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("栈为空\n");
        return -1;
    }
    return stack->array[stack->top];
}

// 判断运算符的优先级
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

// 执行操作
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

// 对整数表达式求值
int evaluateExpression(char *expression)
{
    Stack *operandStack = createStack(100);
    Stack *operatorStack = createStack(100);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isspace(expression[i]))
            continue;

        if (isdigit(expression[i]))
        { // 如果是数字，将数字字符转换为整数并入栈
            int operand = expression[i] - '0';
            while (isdigit(expression[i + 1]))
            {
                operand = operand * 10 + (expression[i + 1] - '0');
                i++;
            }
            push(operandStack, operand);
        }
        else if (expression[i] == '(')
        { // 如果是左括号，直接入栈
            push(operatorStack, expression[i]);
        }
        else if (expression[i] == ')')
        { // 如果是右括号，执行相应的操作
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(')
            {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char operator= pop(operatorStack);
                int result = executeOperation(operand1, operator, operand2);
                push(operandStack, result);
            }
            pop(operatorStack); // 弹出左括号
        }
        else
        { // 如果是运算符，根据优先级执行相应的操作
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
    { // 处理剩余的运算符和操作数
        int operand2 = pop(operandStack);
        int operand1 = pop(operandStack);
        char operator= pop(operatorStack);
        int result = executeOperation(operand1, operator, operand2);
        push(operandStack, result);
    }

    int finalResult = peek(operandStack); // 获取最终计算结果
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

    // 在行尾添加空字符
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n')
        expression[len - 1] = '\0';

    int result = evaluateExpression(expression);
    printf("%d\n", result);

    return 0;
}