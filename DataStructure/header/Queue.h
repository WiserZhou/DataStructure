#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define NONE 0
#include <cstdlib>
typedef int QElemType;
typedef struct QNode
{
    QElemType e;
    struct QNode *next;
} QNode, *QueuePtr;

class LinkedQueue
{
private:
    QueuePtr front;
    QueuePtr rear;
    QueuePtr createNode();

public:
    LinkedQueue();
    ~LinkedQueue();
    void push(QElemType e);
    QElemType pop();
    bool isEmpty();
};
bool LinkedQueue::isEmpty()
{
    return front == rear;
}
QElemType LinkedQueue::pop()
{
    if (isEmpty())
        return NONE;
    QueuePtr p = front->next;
    QElemType e = p->e;
    front->next = p->next;
    if (p == rear) // 注意删除元素的时候，最后一个rear结尾的指针需要额外处理
        rear = front;
    free(p);
}

void LinkedQueue::push(QElemType e)
{
    QueuePtr p = createNode();
    p->e = e;
    p->next = nullptr;
    rear->next = p;
    rear = p;
}
LinkedQueue::~LinkedQueue()
{
    while (!front)
    {
        rear = front->next;
        free(front);
        front = rear;
    }
}
QueuePtr LinkedQueue::createNode()
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    return p;
}
LinkedQueue::LinkedQueue()
{
    QueuePtr p = createNode();
    rear = front = p;
    front->next = nullptr;
}

class CircularQueue
{
private:
    QElemType *base;
    int front;
    int rear;
    inline int moveBack(int pos);
    inline int keepPositive(int x);
    static const int MAX_Q_SIZE = 100;

public:
    CircularQueue();
    ~CircularQueue();
    inline int length();
    void push(QElemType e);
    inline bool isFull();
    QElemType pop();
    bool isEmpty();
};
CircularQueue::~CircularQueue()
{
    free(base);
    front = rear = 0;
    
}
bool CircularQueue::isEmpty()
{
    return front == rear;
}
QElemType CircularQueue::pop()
{
    if (isEmpty())
        return NONE;
    QElemType e = base[front];
    front = moveBack(front);
}
inline int CircularQueue::keepPositive(int x)
{
    return (x + MAX_Q_SIZE) % MAX_Q_SIZE;
}
inline int CircularQueue::moveBack(int pos)
{
    return (pos + 1) % MAX_Q_SIZE;
}
inline bool CircularQueue::isFull()
{
    return moveBack(rear) == front;
}
void CircularQueue::push(QElemType e)
{
    if (isFull())
        return;
    base[rear] = e;
    rear = moveBack(rear);
}
inline int CircularQueue::length()
{
    return keepPositive(rear - front);
}
CircularQueue::CircularQueue()
{
    base = (QElemType *)malloc(sizeof(QElemType) * MAX_Q_SIZE);
    if (!base)
        exit(OVERFLOW);
    front = rear = 0;
}