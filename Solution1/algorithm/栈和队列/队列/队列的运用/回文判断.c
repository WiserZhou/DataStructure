

// 使用双端队列：（代码有点问题）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义节点结构
typedef struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
} Node;

// 定义双端队列结构
typedef struct
{
    Node *front;
    Node *rear;
} Deque;

// 创建节点
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 创建双端队列
Deque *createDeque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// 判断双端队列是否为空
int isDequeEmpty(Deque *deque)
{
    return deque->front == NULL;
}

// 在双端队列前端插入元素
void insertFront(Deque *deque, char data)
{
    Node *newNode = createNode(data);
    if (isDequeEmpty(deque))
    {
        deque->front = deque->rear = newNode;
    }
    else
    {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// 在双端队列后端插入元素
void insertRear(Deque *deque, char data)
{
    Node *newNode = createNode(data);
    if (isDequeEmpty(deque))
    {
        deque->front = deque->rear = newNode;
    }
    else
    {
        deque->rear->next = newNode;
        newNode->prev = deque->rear;
        deque->rear = newNode;
    }
}

// 从双端队列前端删除元素
char deleteFront(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("双端队列为空\n");
        return '\0';
    }
    Node *temp = deque->front;
    char data = temp->data;
    deque->front = temp->next;
    if (deque->front == NULL)
    {
        deque->rear = NULL;
    }
    else
    {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

// 从双端队列后端删除元素
char deleteRear(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("双端队列为空\n");
        return '\0';
    }
    Node *temp = deque->rear;
    char data = temp->data;
    deque->rear = temp->prev;
    if (deque->rear == NULL)
    {
        deque->front = NULL;
    }
    else
    {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

// 判断字符序列是否为回文
int isPalindrome(char *sequence)
{
    int length = strlen(sequence);
    Deque *deque = createDeque();

    // 将字符序列的每个字符分别从前端和后端插入双端队列
    for (int i = 0; i < length; i++)
    {
        insertFront(deque, sequence[i]);
        insertRear(deque, sequence[i]);
    }

    // 从前端和后端依次删除元素进行比较
    while (!isDequeEmpty(deque))
    {
        char frontChar = deleteFront(deque);
        char rearChar = deleteRear(deque);
        if (frontChar != rearChar)
        {
            return 0; // 如果比较不等，则不是回文
        }
    }

    return 1; // 如果比较全部相等，则是回文
}

int main()
{
    char sequence[100];

    printf("请输入一个字符序列: ");
    scanf("%s", sequence);

    if (isPalindrome(sequence))
    {
        printf("是回文\n");
    }
    else
    {
        printf("不是回文\n");
    }

    return 0;
}