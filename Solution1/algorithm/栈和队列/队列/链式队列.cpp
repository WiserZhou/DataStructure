#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

// ���н����������ͣ��������Ϊint
typedef int QElemType;

// ���н��Ľṹ��
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// ��ʽ���еĽṹ��
typedef struct
{
    QueuePtr front; // ��ͷָ��
    QueuePtr rear;  // ��βָ��
} LinkQueue;

// ��ʼ������Q
int InitQueue(LinkQueue &Q)
{
    // ����һ���ն���Q
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW); // �洢����ʧ��
    Q.front->next = NULL;
    return OK;
}

// ��Ӳ������ڶ�β����Ԫ��e,��Ԫ�ز���β�����ƶ�����βָ��
int EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW); // �洢����ʧ��
    p->data = e;
    p->next = NULL;
    Q.rear->next = p; // �͸�ָ����������
    Q.rear = p;       // βָ�����
    return OK;
}

// ���Ӳ�����ɾ����ͷԪ�أ�����e������ֵ
int DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return ERROR; // ���п�
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) // �жϳ���һ��Ԫ�غ��Ƿ����˿ն���
        Q.rear = Q.front;
    free(p);
    return OK;
}

// ���ٶ���Q���ͷŶ�����ռ�õ��ڴ�ռ�
void DestroyQueue(LinkQueue &Q)
{
    while (Q.front) // ͨ��ѭ��һ������ɾ�����еĽڵ�
    {
        QueuePtr p = Q.front;
        Q.front = Q.front->next;
        free(p);
    }
    Q.rear = NULL;
}

// �ж϶���Q�Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
int QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear ? 1 : 0;
}

// �����Q�ĳ��ȣ���������Ԫ�صĸ���
int QueueLength(LinkQueue Q)
{
    int length = 0;
    QueuePtr p = Q.front->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// ȡ��ͷԪ�أ���ͨ������e������ֵ
int GetHead(LinkQueue Q, QElemType &e)
{
    if (Q.front == Q.rear)
    {
        return ERROR; // ����Ϊ��
    }
    e = Q.front->next->data;
    return OK;
}

// ��ն���Q����ɾ������������Ԫ��
void ClearQueue(LinkQueue &Q)
{
    QueuePtr p = Q.front->next;
    while (p)
    {
        QueuePtr temp = p;
        p = p->next;
        free(temp);
    }
    Q.front->next = NULL;
    Q.rear = Q.front;
}

// ��������Q����ÿ��Ԫ�ص��ú���visit���з���
void QueueTraverse(LinkQueue Q, void (*visit)(QElemType))
{
    QueuePtr p = Q.front->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
}

int main()
{
    // ��ʼ������Q
    LinkQueue Q;
    InitQueue(Q);

    // ��Ӳ���
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);

    // ���Ӳ���
    int e;
    DeQueue(Q, e);
    printf("DeQueue: %d\n", e);

    DeQueue(Q, e);
    printf("DeQueue: %d\n", e);

    DeQueue(Q, e);
    printf("DeQueue: %d\n", e);

    // �ٴγ��Գ���
    if (DeQueue(Q, e) == ERROR)
    {
        printf("DeQueue failed! The queue is empty.\n");
    }

    return 0;
}
