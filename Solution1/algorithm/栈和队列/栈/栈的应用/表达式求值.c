

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // 包含isdigit函数

// 定义节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 定义栈结构
typedef struct
{
    Node *top;
} Stack;

// 创建节点
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 判断栈是否为空
int isStackEmpty(Stack *stack)
{
    return stack->top == NULL;
}

// 入栈
void push(Stack *stack, int data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈
int pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("栈为空\n");
        return 0;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// 获取栈顶元素
int peek(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("栈为空\n");
        return 0;
    }
    return stack->top->data;
}

// 检查运算符优先级
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

// 执行二元运算
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
            printf("除数为零\n");
            return 0;
        }
    default:
        printf("无效运算符\n");
        return 0;
    }
}

// 求值函数
int evaluateExpression(char *expression)
{
    Stack operandStack;
    Stack operatorStack;
    int i;

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (isspace(expression[i]))
        {
            continue; // 忽略空格
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
                printf("括号不匹配\n");
                return 0;
            }
            else
            {
                pop(&operatorStack); // 弹出左括号
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

    printf("请输入一个整数表达式: ");
    fgets(expression, 100, stdin);

    int result = evaluateExpression(expression);
    printf("表达式的值为：%d\n", result);

    return 0;
}