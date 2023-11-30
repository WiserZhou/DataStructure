#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100   // 最大队列长度
typedef int QElemType; // 假设队列元素类型为int

typedef struct
{
    QElemType *base; // 动态分配存储空间
    int front;       // 头指针，若队列不空，指向队列头元素
    int rear;        // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;

typedef enum
{
    OK,
    ERROR,
    OVERFLOW
} Status;

Status InitQueue(SqQueue &Q)
{
    // 构造一个空队列Q
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW); // 存储分配失败
    Q.front = Q.rear = 0;
    return OK;
}
// 元素入队列
Status EnQueue(SqQueue &Q, QElemType e)
{
    // 插入元素e为Q的新的队尾元素
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR; // 队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;   // 保证 rear 始终在 [0, MAXQSIZE-1] 的范围内，实现循环队列的效果
    return OK;
}
// 元素出队列
Status DeQueue(SqQueue &Q, QElemType &e)
{
    // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK; 否则返回ERROR
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;  // 保证 front 始终在 [0, MAXQSIZE-1] 的范围内，实现循环队列的效果
    return OK;
}

int QueueLength(SqQueue Q)  // 这是获取队列长度的算法
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

int main()
{
    SqQueue Q;
    QElemType e;
    // 初始化队列
    InitQueue(Q);
    // 入队操作
    for (int i = 0; i < 5; i++)
    {
        EnQueue(Q, i);
    }
    // 出队操作
    while (DeQueue(Q, e) == OK)
    {
        printf("%d ", e);
    }
    return 0;
}
