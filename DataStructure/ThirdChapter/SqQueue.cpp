// #include "..\header\unity.h"

// #define MAX_Q_SIZE 100
// typedef struct
// {
//     QElemType *base;
//     int front;
//     int rear;

// } SqQueue;
// Status initQueue(SqQueue &Q)
// {
//     Q.base = (QElemType *)malloc(sizeof(QElemType) * MAX_Q_SIZE);
//     if (!Q.base)
//         exit(OVERFLOW);
//     Q.front = Q.rear = 0;
//     return OK;
// }
// int QueueLength(SqQueue Q)
// {
//     return (Q.rear - Q.front + MAX_Q_SIZE) % MAX_Q_SIZE;//Q.rear是在MAX_Q_SIZE的基础之上的值，对他进行取余十分合适
// }
// Status enQueue(SqQueue &Q, QElemType e)
// {
//     if ((Q.rear + 1) % MAX_Q_SIZE == Q.front)//判断队满
//         return ERROR;
//     Q.base[Q.rear] = e;
//     Q.rear = (Q.rear + 1) % MAX_Q_SIZE; // 使用取余操作，使其永远在循环的队列之中
//     return OK;
// }
// Status deQueue(SqQueue &Q, QElemType &e)
// {
//     if (Q.front == Q.rear)
//         return ERROR;
//     e = Q.base[Q.front];
//     Q.front = (Q.front + 1) % MAX_Q_SIZE;
//     return OK;
// }