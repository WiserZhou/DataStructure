

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int QElemType;
typedef int Status;
typedef struct QNode
{ // 结点类型
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// 链队列数据类型的实现
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

// 初始化算法
Status initQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return ERROR;
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return e;
}

Status QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear ? TRUE : FALSE;
}

int main()
{
    int a[MAXSIZE] = {0};
    int result[MAXSIZE] = {0};
    int i = 0;
    do
    {
        scanf("%d", &a[i++]);
    } while (getchar() != '\n' && i < MAXSIZE); // 这种输入的方法对于输入的数量不确定时很好用！！！！
    LinkQueue Q1, Q2;
    initQueue(Q1);
    initQueue(Q2);
    for (int j = 0; j < i; j += 2)
        EnQueue(Q1, a[j]);
    for (int j = 1; j < i; j += 2)
        EnQueue(Q2, a[j]);
    QElemType e1 = 0, e2 = 0, count = 0;
    while (!QueueEmpty(Q1) && !QueueEmpty(Q2))
    {
        DeQueue(Q1, e1);
        DeQueue(Q2, e2);
        if (e2 != 0)
        {
            result[count++] = e1 * e2;
            result[count++] = --e2;
        }
        else
        {
            result[count++] = 0;
            result[count++] = 0;
        }
    }
    if (count > 2)
    {
        int j = 0;
        while (result[j] != 0)
            printf("%d ", result[j++]);
        if (result[j - 2] == 1)
            printf("0");
    }
    else
        for (int j = 0; j < count; ++j)
            printf("%d ", result[j]);
    return 0;
}
