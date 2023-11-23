

// ʹ��˫�˶��У��������е����⣩
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ڵ�ṹ
typedef struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
} Node;

// ����˫�˶��нṹ
typedef struct
{
    Node *front;
    Node *rear;
} Deque;

// �����ڵ�
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// ����˫�˶���
Deque *createDeque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// �ж�˫�˶����Ƿ�Ϊ��
int isDequeEmpty(Deque *deque)
{
    return deque->front == NULL;
}

// ��˫�˶���ǰ�˲���Ԫ��
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

// ��˫�˶��к�˲���Ԫ��
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

// ��˫�˶���ǰ��ɾ��Ԫ��
char deleteFront(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("˫�˶���Ϊ��\n");
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

// ��˫�˶��к��ɾ��Ԫ��
char deleteRear(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("˫�˶���Ϊ��\n");
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

// �ж��ַ������Ƿ�Ϊ����
int isPalindrome(char *sequence)
{
    int length = strlen(sequence);
    Deque *deque = createDeque();

    // ���ַ����е�ÿ���ַ��ֱ��ǰ�˺ͺ�˲���˫�˶���
    for (int i = 0; i < length; i++)
    {
        insertFront(deque, sequence[i]);
        insertRear(deque, sequence[i]);
    }

    // ��ǰ�˺ͺ������ɾ��Ԫ�ؽ��бȽ�
    while (!isDequeEmpty(deque))
    {
        char frontChar = deleteFront(deque);
        char rearChar = deleteRear(deque);
        if (frontChar != rearChar)
        {
            return 0; // ����Ƚϲ��ȣ����ǻ���
        }
    }

    return 1; // ����Ƚ�ȫ����ȣ����ǻ���
}

int main()
{
    char sequence[100];

    printf("������һ���ַ�����: ");
    scanf("%s", sequence);

    if (isPalindrome(sequence))
    {
        printf("�ǻ���\n");
    }
    else
    {
        printf("���ǻ���\n");
    }

    return 0;
}