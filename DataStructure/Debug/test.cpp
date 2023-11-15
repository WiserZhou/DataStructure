typedef struct Node
{
    int elem;
    struct Node *next;
} Node, *LIST;

// 倒置单链表
//  将头结点后面的第二个结点插入到头结点后第一个结点的前面，相当于倒置了
void Reverse(LIST L)
{
    LIST p, q;
    p = L->next->next;
    L->next->next = nullptr;
    while (p != nullptr)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

/**编写一个算法,将一个头结点指针为A的单链表A分解成两个单链表A和B。其头结点指针分别为A和B。使得
 * A链表中含有原链表A中序号为奇数的元素。B链表中含有原链表A中序号为偶数的元素。保持原来的相对顺序。*/
void Disassemble(LIST &A, LIST &B)
{
    LIST r, p, q;
    B->next = nullptr;                         // 将链表B置空
    r = B;                                     // 将r指向B
    p = A->next;                               // 将p指向第一个结点
    while (p != nullptr && p->next != nullptr) // 如果A有两个结点，进行分解操作，只有一个或者零个就没有必要进行拆解
    {
        q = p->next;       // q指向偶数
        p->next = q->next; // 将q从原链删除
        r->next = q;       // 将q连接到B上
        r = q;             // 让r指针后移，始终保持在B的最后面，方便进行插入操作
        p = p->next;       // p指向奇数
    }
    r->next = nullptr; // 终止B
}

// 例3：假定用一个循环单链表表示队列，该队
// 列只设一个队尾指针rear，不设头指针，不设
// 头结点：
//  写出：
//  (1)入队算法(入队元素为x)；
//  (2)出队算法。
typedef int ElemType;
#include "../header/unity.h"

/**
 * 注意区分此时的没有头结点，那么考虑极端情况是否有结点
 */
void ENQUEUE(ElemType x, Node *rear)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node)); // 生成新结点
    p->elem = x;                      // x存入新结点

    if (rear == nullptr)
    {
        rear = p;
        rear->next = rear;
    }
    else
    {
        p->next = rear->next;
        rear->next = p;
        rear = p; // 做完操作后，记得要进行重置，保持尾指针位置不变
    }
}

void DEQUEUE(Node *rear)
{
    Node *p;
    if (rear == nullptr) // 如果尾指针为空
        return;
    else
    {
        p = rear->next;
        if (rear == rear->next) // 如果只有一个结点
            rear = nullptr;
        else
        {
            rear->next = p->next;
            delete p;
        }
    }
}