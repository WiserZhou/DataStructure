

// 循环链表(约瑟夫环)的建立及C语言实现

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next; // 指向同类型结构体的指针,即指向下一个人的数据结构
} person;

// 初始化每个人的相关信息，就是对循环链表进行赋值
person *initLink(int n)
{
    person *head = (person *)malloc(sizeof(person)); // 开辟头结点
    head->number = 1;
    head->next = NULL;
    person *cyclic = head;       // 结构体指针指头结点，通过移动该指针实现对每个节点的链接与赋值
    for (int i = 2; i <= n; i++) // 这里i从2开始取值，便于后续的赋值操作
    {
        person *body = (person *)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;   // 连接起来这个结点
        cyclic = cyclic->next; // 指针指向的结点向后面移动一位
    }
    cyclic->next = head; // 首尾相连
    return head;
}

// 剔除符合条件的结点，就是循环链表的删除操作
void findAndKillK(person *head, int k, int m)
{
    person *tail = head;
    // // 找到链表第一个结点的上一个结点，为删除操作做准备
    // while (tail->next != head)
    // {
    //     tail = tail->next;
    // } // 找到尾节点
    person *p = head;
    // 找到编号为k的人，下面的代码主要是要找到开始报数人的位置
    while (p->number != k)
    {
        tail = p;
        p = p->next;
    }
    // 从编号为k的人开始，只有符合p->next==p时，说明链表中除了p结点，所有编号都出列了，即此时该循环链表中只有一个结点了
    while (p->next != p) // 循环退出的条件：该循环链表中只有一个节点了
    {
        // 找到从p报数1开始，报m的人，并且还要知道数m-1的人的位置tail，方便做删除操作。
        for (int i = 1; i < m; i++)
        {
            tail = p;
            p = p->next;
        }                     // 找到第m-1个人的位置tail，同时p指向第m个人的位置
        tail->next = p->next; // 从链表上将p结点摘下来
        printf("出列人的编号为:%d\n", p->number);
        free(p);
        p = tail->next; // 继续使用p指针指向出列编号的下一个编号，游戏继续
    }
    printf("最后剩下的一个人的编号为:%d\n", p->number);
    free(p); // 最后在代码走完后，释放整个链表
}

int main()
{
    printf("输入圆桌上的人数n:");
    int n;
    scanf("%d", &n);
    person *head = initLink(n);
    printf("从第k人开始报数(k>1且k<%d):", n);
    int k;
    scanf("%d", &k);
    printf("数到m的人出列:");
    int m;
    scanf("%d", &m);
    findAndKillK(head, k, m);
    return 0;
}