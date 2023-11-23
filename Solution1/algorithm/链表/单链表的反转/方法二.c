


// 使用递归实现反转
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    // 当链表为空或者只有一个节点时，无需反转
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *newHead = reverseList(head->next);
    // 反转当前节点和下一个节点的指针关系
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main(void)
{
    // 创建链表
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fourth = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;

    // 反转链表
    struct ListNode *reversedHead = reverseList(head);

    // 打印反转后的链表
    struct ListNode *p = reversedHead;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    // 释放链表节点的内存
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}