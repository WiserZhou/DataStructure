


// ʹ��ջ�Ͷ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ڵ�ṹ
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

// ����ջ�ṹ
typedef struct
{
    Node *top;
} Stack;

// �����ڵ�
Node *createNode(char data)
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
void push(Stack *stack, char data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// ��ջ
char pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("ջΪ��\n");
        return '\0';
    }
    Node *temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// ������нṹ
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// ��������
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// �����
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

// ������
char dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("����Ϊ��\n");
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

// �ж��ַ������Ƿ�Ϊ����
int isPalindrome(char *sequence)
{
    int length = strlen(sequence);
    Stack stack;
    Queue *queue = createQueue();

    // ���ַ����е�ÿ���ַ��ֱ���ջ�������
    for (int i = 0; i < length; i++)
    {
        push(&stack, sequence[i]);
        enqueue(queue, sequence[i]);
    }

    // ���γ�ջ�ͳ����н��бȽ�
    while (!isStackEmpty(&stack) && !isQueueEmpty(queue))
    {
        char stackChar = pop(&stack);
        char queueChar = dequeue(queue);
        if (stackChar != queueChar)
        {
            return 0; // ����Ƚϲ��ȣ����ǻ���
        }
    }

    return 1; // ����Ƚ�ȫ����ȣ����ǻ���
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