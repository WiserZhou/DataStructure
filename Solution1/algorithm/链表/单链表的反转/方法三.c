


// ���뷨��ת����
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
        // ����head֮��Ľڵ�
        struct ListNode *next = head->next;
        // ��head�ڵ���뵽dummy�ڵ�֮��
        head->next = dummy;
        dummy = head;
        // �ƶ�headָ�뵽��һ���ڵ�
        head = next;
    }

    return dummy;
}

int main(void)
{
    // ��������
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

    // ��ת����
    struct ListNode *reversedHead = reverseList(head);

    // ��ӡ��ת�������
    struct ListNode *p = reversedHead;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    // �ͷ�����ڵ���ڴ�
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}