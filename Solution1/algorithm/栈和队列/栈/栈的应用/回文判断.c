


// 使用栈和队列
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义节点结构
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

// 定义栈结构
typedef struct
{
    Node *top;
} Stack;

// 创建节点
Node *createNode(char data)
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
void push(Stack *stack, char data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈
char pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("栈为空\n");
        return '\0';
    }
    Node *temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// 定义队列结构
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// 创建队列
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 判断队列是否为空
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// 入队列
void enqueue(Queue *queue, char data)
{
    Node *newNode = createNode(data);
    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队列
char dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("队列为空\n");
        return '\0';
    }
    Node *temp = queue->front;
    char data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// 判断字符序列是否为回文
int isPalindrome(char *sequence)
{
    int length = strlen(sequence);
    Stack stack;
    Queue *queue = createQueue();

    // 将字符序列的每个字符分别入栈和入队列
    for (int i = 0; i < length; i++)
    {
        push(&stack, sequence[i]);
        enqueue(queue, sequence[i]);
    }

    // 依次出栈和出队列进行比较
    while (!isStackEmpty(&stack) && !isQueueEmpty(queue))
    {
        char stackChar = pop(&stack);
        char queueChar = dequeue(queue);
        if (stackChar != queueChar)
        {
            return 0; // 如果比较不等，则不是回文
        }
    }

    return 1; // 如果比较全部相等，则是回文
}

int main()
{
    char sequence[100];
    scanf("%s", sequence);

    if (isPalindrome(sequence))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}