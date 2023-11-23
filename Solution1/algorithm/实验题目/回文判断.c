

// 一个字符串入栈，另一个入队列，利用弹栈的先后来进行回文的判断
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义节点结构
typedef struct Node
{
    char data;         // 节点数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 定义栈结构
typedef struct
{
    Node *top; // 指向栈顶的指针
} Stack;

// 创建节点
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // 分配节点内存空间
    newNode->data = data;                         // 设置节点数据
    newNode->next = NULL;                         // 将下一个节点指针设为空
    return newNode;
}

// 判断栈是否为空
int isStackEmpty(Stack *stack)
{
    return stack->top == NULL; // 如果栈顶指针为空，表示栈为空
}

// 入栈，这个栈不会满出来的
void push(Stack *stack, char data)
{
    Node *newNode = createNode(data); // 创建新节点
    newNode->next = stack->top;       // 将栈顶指针指向的节点作为新节点的下一个节点
    stack->top = newNode;             // 更新栈顶指针为新节点
}

// 出栈
char pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("栈为空\n");
        return '\0';
    }                        // 如果栈为空则打印提示信息，返回空字符
    Node *temp = stack->top; // 存储栈顶指针
    char data = temp->data;  // 存储栈顶节点数据
    stack->top = temp->next; // 更新栈顶指针为下一个节点
    free(temp);              // 释放被弹出的节点内存空间
    return data;             // 返回被弹出的数据
}

// 定义队列结构
typedef struct
{
    Node *front; // 指向队列头部的指针
    Node *rear;  // 指向队列尾部的指针
} Queue;

// 创建队列
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue)); // 分配队列内存空间
    queue->front = queue->rear = NULL;             // 初始化队列头部和尾部指针为空
    return queue;
}

// 判断队列是否为空
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL; // 如果队列头部指针为空，表示队列为空
}

// 入队列
void enqueue(Queue *queue, char data)
{
    Node *newNode = createNode(data); // 创建新节点
    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode; // 如果队列为空，新节点既是头部节点又是尾部节点
    }
    else
    {
        queue->rear->next = newNode; // 如果队列不为空，将新节点作为尾部节点的下一个节点
        queue->rear = newNode;       // 更新尾部指针为新节点
    }
}

// 出队列
char dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("队列为空\n");
        return '\0';
    }                          // 如果队列为空则打印提示信息，返回空字符
    Node *temp = queue->front; // 存储队列头部指针
    char data = temp->data;    // 存储队列头部节点数据
    queue->front = temp->next; // 更新队列头部指针为下一个节点
    if (queue->front == NULL)
    {
        queue->rear = NULL; // 如果头部指针为空，表示队列已为空，同时更新尾部指针为空
    }
    free(temp);  // 释放被出队列的节点内存空间
    return data; // 返回被出队列的数据
}

// 判断字符序列是否为回文
int isPalindrome(char *sequence)
{
    int length = strlen(sequence); // 获取字符序列的长度
    Stack stack;                   // 定义栈
    Queue *queue = createQueue();  // 创建队列

    // 将字符序列的每个字符分别入栈和入队列
    for (int i = 0; i < length; i++)
    {
        push(&stack, sequence[i]);   // 将字符入栈
        enqueue(queue, sequence[i]); // 将字符入队列
    }

    // 依次出栈和出队列进行比较
    while (!isStackEmpty(&stack) && !isQueueEmpty(queue))
    {
        char stackChar = pop(&stack);    // 出栈
        char queueChar = dequeue(queue); // 出队列
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
    scanf("%s", sequence); // 从标准输入读取字符序列

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