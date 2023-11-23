

// 链式队列及基本操作
// 链式队列，简称"链队列"，即使用链表实现的队列存储结构。
// http://c.biancheng.net/view/3354.html

#include <stdio.h>
#include <stdlib.h>

// 链表中的节点结构
typedef struct QNode
{
    int data;
    struct QNode *next; // 一个指向同类型结构体的指针next
} QNode;

// 创建链式队列的函数
QNode *initQueue()
{
    // 创建一个头节点
    QNode *queue = (QNode *)malloc(sizeof(QNode)); // 申请空间
    queue->data = 1;                               // 给头节点赋值为1;
    // 对头节点进行初始化
    queue->next = NULL;
    return queue; // 返回带有头节点的链表
}

// 向队列中添加元素，添加元素用到的就是尾指针
QNode *enQueue(QNode *rear, int data)
{
    // 1、用节点包裹入队元素
    QNode *enElem = (QNode *)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    // 2、新节点与rear节点建立逻辑关系
    rear->next = enElem;
    // 3、rear指向新节点
    rear = enElem;
    // 返回新的rear，为后续新元素入队做准备
    return rear;
}

// 删除队列中的元素,删除元素的话，用到的就是尾指针
QNode *DeQueue(QNode *top, QNode *rear)
{
    if (top == rear) // 说明队列中此时只有最后一个元素了
    {
        printf("最后一个元素%d出队列\n", top->data);
        return top;
    }
    else
    {
        QNode *p = top;
        printf("%d\n", p->data);
        top = p->next; // 使头指针指向当前位置的下一位
        free(p);       // 释放掉原来的空间，节省内存
        return top;
    }
}

void show(QNode *top, QNode *rear)
{
    if (top == rear)
    {
        printf("此时队列中没有元素。\n");
    }
    else
    {
        printf("此时队列中的元素为：");
        QNode *p = top;
        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != rear);
        printf("%d ", p->data);
        printf("\n");
    }
}

int main()
{
    QNode *top, *rear;
    top = rear = initQueue(); // 创建头结点
    printf("队列当中的初始元素为 %d\n", top->data);
    int m;
    printf("请输入入队列的元素个数：");
    scanf("%d", &m);
    // 向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    for (int i = 2; i <= m + 1; i++)
    {
        printf("元素%d开始入队列;\n", i);
        rear = enQueue(rear, i);
        show(top, rear);
    }
    // show(top, rear);
    //  show(top, rear);
    //  入队完成，所有数据元素开始出队列
    printf("所有数据元素开始出队列:\n");
    for (int i = 1; i <= m + 1; i++)
    {
        printf("出队列的元素为：");
        top = DeQueue(top, rear);
        show(top, rear);
    }

    return 0;
}