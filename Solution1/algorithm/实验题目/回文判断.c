

// һ���ַ�����ջ����һ������У����õ�ջ���Ⱥ������л��ĵ��ж�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ڵ�ṹ
typedef struct Node
{
    char data;         // �ڵ�����
    struct Node *next; // ָ����һ���ڵ��ָ��
} Node;

// ����ջ�ṹ
typedef struct
{
    Node *top; // ָ��ջ����ָ��
} Stack;

// �����ڵ�
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // ����ڵ��ڴ�ռ�
    newNode->data = data;                         // ���ýڵ�����
    newNode->next = NULL;                         // ����һ���ڵ�ָ����Ϊ��
    return newNode;
}

// �ж�ջ�Ƿ�Ϊ��
int isStackEmpty(Stack *stack)
{
    return stack->top == NULL; // ���ջ��ָ��Ϊ�գ���ʾջΪ��
}

// ��ջ�����ջ������������
void push(Stack *stack, char data)
{
    Node *newNode = createNode(data); // �����½ڵ�
    newNode->next = stack->top;       // ��ջ��ָ��ָ��Ľڵ���Ϊ�½ڵ����һ���ڵ�
    stack->top = newNode;             // ����ջ��ָ��Ϊ�½ڵ�
}

// ��ջ
char pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("ջΪ��\n");
        return '\0';
    }                        // ���ջΪ�����ӡ��ʾ��Ϣ�����ؿ��ַ�
    Node *temp = stack->top; // �洢ջ��ָ��
    char data = temp->data;  // �洢ջ���ڵ�����
    stack->top = temp->next; // ����ջ��ָ��Ϊ��һ���ڵ�
    free(temp);              // �ͷű������Ľڵ��ڴ�ռ�
    return data;             // ���ر�����������
}

// ������нṹ
typedef struct
{
    Node *front; // ָ�����ͷ����ָ��
    Node *rear;  // ָ�����β����ָ��
} Queue;

// ��������
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue)); // ��������ڴ�ռ�
    queue->front = queue->rear = NULL;             // ��ʼ������ͷ����β��ָ��Ϊ��
    return queue;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL; // �������ͷ��ָ��Ϊ�գ���ʾ����Ϊ��
}

// �����
void enqueue(Queue *queue, char data)
{
    Node *newNode = createNode(data); // �����½ڵ�
    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode; // �������Ϊ�գ��½ڵ����ͷ���ڵ�����β���ڵ�
    }
    else
    {
        queue->rear->next = newNode; // ������в�Ϊ�գ����½ڵ���Ϊβ���ڵ����һ���ڵ�
        queue->rear = newNode;       // ����β��ָ��Ϊ�½ڵ�
    }
}

// ������
char dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("����Ϊ��\n");
        return '\0';
    }                          // �������Ϊ�����ӡ��ʾ��Ϣ�����ؿ��ַ�
    Node *temp = queue->front; // �洢����ͷ��ָ��
    char data = temp->data;    // �洢����ͷ���ڵ�����
    queue->front = temp->next; // ���¶���ͷ��ָ��Ϊ��һ���ڵ�
    if (queue->front == NULL)
    {
        queue->rear = NULL; // ���ͷ��ָ��Ϊ�գ���ʾ������Ϊ�գ�ͬʱ����β��ָ��Ϊ��
    }
    free(temp);  // �ͷű������еĽڵ��ڴ�ռ�
    return data; // ���ر������е�����
}

// �ж��ַ������Ƿ�Ϊ����
int isPalindrome(char *sequence)
{
    int length = strlen(sequence); // ��ȡ�ַ����еĳ���
    Stack stack;                   // ����ջ
    Queue *queue = createQueue();  // ��������

    // ���ַ����е�ÿ���ַ��ֱ���ջ�������
    for (int i = 0; i < length; i++)
    {
        push(&stack, sequence[i]);   // ���ַ���ջ
        enqueue(queue, sequence[i]); // ���ַ������
    }

    // ���γ�ջ�ͳ����н��бȽ�
    while (!isStackEmpty(&stack) && !isQueueEmpty(queue))
    {
        char stackChar = pop(&stack);    // ��ջ
        char queueChar = dequeue(queue); // ������
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
    scanf("%s", sequence); // �ӱ�׼�����ȡ�ַ�����
    // if (isPalindrome(sequence))
    // {
    //     printf("1\n");
    // }
    // else
    // {
    //     printf("0\n");
    // }
    printf("%d",isPalindrome(sequence));
    return 0;
}