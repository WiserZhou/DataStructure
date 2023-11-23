


// 插入法反转链表
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *dummy = NULL;

    while (head != NULL)
    {
        // 保存head之后的节点
        struct ListNode *next = head->next;
        // 把head节点插入到dummy节点之后
        head->next = dummy;
        dummy = head;
        // 移动head指针到下一个节点
        head = next;
    }

    return dummy;
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