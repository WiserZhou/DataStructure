// 假定用一个循环单链表表示队列，该队
// 列只设一个队尾指针rear，不设头指针，不设
// 头结点：
//  写出：
//  (1)入队算法(入队元素为x)；
//  (2)出队算法

void ENQUEUE(elementtype x, node *rear)
{
    node *p;
    p = (node *)malloc(sizeof(node)); // 生成新结点
    p->element = x;                   // x存入新结点

    if (rear == NULL)
    { // 如果队列为空（即rear为NULL），则将rear指向新结点p，并将p的next指向自身，然后返回
        rear = p;
        rear->next = rear;
    }
    else
    { // 将p的next指向rear->next，将rear->next指向新结点p，最后将rear指向新结点p
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}

void DEQUEUE(node *rear)
{
    node *p;
    if (rear == NULL)
        error("队列空");
    else
    {
        p = rear->next;
        if (rear == rear->next) // 表示该链表中只有一个结点
        {                       // only one node
            rear = NULL;
        }
        else
        {
            rear->next = p->next; // 将rear的下一个结点指向p的后继结点
        }
        free(p); // 释放p所指的结点
    }
}
