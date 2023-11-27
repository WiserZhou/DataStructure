typedef int QElemType;
#define MAX_Q_SIZE 100 // 最大队列长度
typedef struct
{
    QElemType *base; // 动态分配存储空间
    int front;       // 头指针，若队列不空，指向队列头元素
    int rear;        // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;
#include "../header/unity.h"

Status InitQueue(SqQueue &Q)
{
    // 构造一个空队列Q
    Q.base = (QElemType *)malloc(MAX_Q_SIZE * sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW);
    // 存储分配失败
    Q.front = Q.rear = 0; // 初始的时候队头和队尾指针都指向0号空间
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e)
{
    // 插入元素e为Q的新的队尾元素
    if ((Q.rear + 1) % MAX_Q_SIZE == Q.front)
        return ERROR; // 队列满

    Q.base[Q.rear] = e; // 队尾位置的元素添加

    Q.rear = (Q.rear + 1) % MAX_Q_SIZE; // 后移

    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    // 若队列不空，则删除Q的队头元素，
    // 用e返回其值，并返回OK; 否则返回ERROR
    if (Q.front == Q.rear) // 队空，没有可以删除的
        return ERROR;

    e = Q.base[Q.front]; // 将队头的元素值获取

    Q.front = (Q.front + 1) % MAX_Q_SIZE; // 将队头指针后移，相当于删除一个元素，以后尾指针移到此处的时候可以将其覆盖
    return OK;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAX_Q_SIZE) % MAX_Q_SIZE; // 对于取余来说，添加一个新的取余数对最终取值无影响
}