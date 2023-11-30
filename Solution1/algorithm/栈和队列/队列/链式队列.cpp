#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

// 队列结点的数据类型，这里假设为int
typedef int QElemType;

// 队列结点的结构体
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// 链式队列的结构体
typedef struct
{
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
} LinkQueue;

// 初始化队列Q
int InitQueue(LinkQueue &Q)
{
    // 构造一个空队列Q
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW); // 存储分配失败
    Q.front->next = NULL;
    return OK;
}

// 入队操作，在队尾插入元素e,将元素插入尾部，移动的是尾指针
int EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW); // 存储分配失败
    p->data = e;
    p->next = NULL;
    Q.rear->next = p; // 和该指针连接起来
    Q.rear = p;       // 尾指针后移
    return OK;
}

// 出队操作，删除队头元素，并用e返回其值
int DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return ERROR; // 队列空
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) // 判断出队一个元素后是否变成了空队列
        Q.rear = Q.front;
    free(p);
    return OK;
}

// 销毁队列Q，释放队列所占用的内存空间
void DestroyQueue(LinkQueue &Q)
{
    while (Q.front) // 通过循环一个个的删除其中的节点
    {
        QueuePtr p = Q.front;
        Q.front = Q.front->next;
        free(p);
    }
    Q.rear = NULL;
}

// 判断队列Q是否为空，为空返回1，不为空返回0
int QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear ? 1 : 0;
}

// 求队列Q的长度，即队列中元素的个数
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

// 取队头元素，并通过参数e返回其值
int GetHead(LinkQueue Q, QElemType &e)
{
    if (Q.front == Q.rear)
    {
        return ERROR; // 队列为空
    }
    e = Q.front->next->data;
    return OK;
}

// 清空队列Q，即删除队列中所有元素
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

// 遍历队列Q，对每个元素调用函数visit进行访问
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
    // 初始化队列Q
    LinkQueue Q;
    InitQueue(Q);

    // 入队操作
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);

    // 出队操作
    int e;
    DeQueue(Q, e);
    printf("DeQueue: %d\n", e);

    DeQueue(Q, e);
    printf("DeQueue: %d\n", e);

    DeQueue(Q, e);
    printf("DeQueue: %d\n", e);

    // 再次尝试出队
    if (DeQueue(Q, e) == ERROR)
    {
        printf("DeQueue failed! The queue is empty.\n");
    }

    return 0;
}
