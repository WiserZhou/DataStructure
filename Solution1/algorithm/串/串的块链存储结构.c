


// http://c.biancheng.net/view/3363.html
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define linkNum 3 // ȫ�����������нڵ�洢���ݵĸ���

typedef struct Link
{
    char a[linkNum];   // ������ɴ�� linkNum ������
    struct Link *next; // ����ָ����ָ��ֱ�Ӻ��Ԫ��
} link;                // nkΪ�ڵ�����ÿ���ڵ㶼��һ�� link �ṹ��

link *initLink(link *head, char *str);
void displayLink(link *head);
int main()
{
    link *head = NULL;
    head = initLink(head, "data.biancheng.net");
    displayLink(head);
    return 0;
}

// ��ʼ����������headΪͷָ�룬strΪ�洢���ַ���
link *initLink(link *head, char *str)
{
    int length = strlen(str);
    // �����ַ����ĳ��ȣ������������ʹ�ýڵ�ĸ���
    int num = length / linkNum;   
    if (length % linkNum)
    {
        num++;
    }
    // ��������ʼ����Ԫ�ڵ�
    head = (link *)malloc(sizeof(link));
    head->next = NULL;
    link *temp = head;
    // ��ʼ������
    for (int i = 0; i < num; i++)
    {
        int j = 0;
        for (; j < linkNum; j++)
        {
            if (i * linkNum + j < length)
            {
                temp->a[j] = str[i * linkNum + j];
            }
            else
                temp->a[j] = '#';
        }
        if (i * linkNum + j < length)
        {
            link *newlink = (link *)malloc(sizeof(link));
            newlink->next = NULL;
            temp->next = newlink;
            temp = newlink;
        }
    }
    return head;
}

// �������
void displayLink(link *head)
{
    link *temp = head;
    while (temp)  // ����ѭ��������
    {
        for (int i = 0; i < linkNum; i++)
        {
            printf("%c", temp->a[i]);
        }
        temp = temp->next;
    }
}