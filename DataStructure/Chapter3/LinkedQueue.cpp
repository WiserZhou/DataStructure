typedef int QElemType;
#include "../header/unity.h"
typedef struct QNode
{ // 结点类型
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{                   // 链队列类型
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
} LinkQueue;

// 链队列有头结点
Status InitQueue(LinkQueue &Q)
{
    // 构造一个空队列Q，此时队头和队尾指针都指向头结点
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW);
    // 存储分配失败
    Q.front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    // 插入元素在队尾，使用rear指针操作
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW); // 存储分配失败
    p->data = e;
    p->next = NULL;

    Q.rear->next = p;
    Q.rear = p;

    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear) // 如果是空的，就没有可以删除的
        return ERROR;

    QueuePtr p = Q.front->next;
    e = p->data;

    Q.front->next = p->next;

    if (Q.rear == p) // 注意从头删除的时候，考虑仅有一个结点时，会影响到尾指针
        Q.rear = Q.front;
    free(p);
    return OK;
}