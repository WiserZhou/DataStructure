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

class LinkQueue
{
private:
    QueuePtr front;
    QueuePtr rear;
    QueuePtr createNode();

public:
    LinkQueue();
    ~LinkQueue();
    void push(QElemType e);
    QElemType pop();
    bool isEmpty();
};
bool LinkQueue::isEmpty()
{
    return front == rear;
}
QElemType LinkQueue::pop()
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

void LinkQueue::push(QElemType e)
{
    QueuePtr p = createNode();
    p->e = e;
    p->next = nullptr;
    rear->next = p;
    rear = p;
}
LinkQueue::~LinkQueue()
{
    while (!front)
    {
        rear = front->next;
        free(front);
        front = rear;
    }
}
QueuePtr LinkQueue::createNode()
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    return p;
}
LinkQueue::LinkQueue()
{
    QueuePtr p = createNode();
    rear = front = p;
    front->next = nullptr;
}
