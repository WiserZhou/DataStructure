

// ѭ������(Լɪ��)�Ľ�����C����ʵ��

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next; // ָ��ͬ���ͽṹ���ָ��,��ָ����һ���˵����ݽṹ
} person;

// ��ʼ��ÿ���˵������Ϣ�����Ƕ�ѭ��������и�ֵ
person *initLink(int n)
{
    person *head = (person *)malloc(sizeof(person)); // ����ͷ���
    head->number = 1;
    head->next = NULL;
    person *cyclic = head;       // �ṹ��ָ��ָͷ��㣬ͨ���ƶ���ָ��ʵ�ֶ�ÿ���ڵ�������븳ֵ
    for (int i = 2; i <= n; i++) // ����i��2��ʼȡֵ�����ں����ĸ�ֵ����
    {
        person *body = (person *)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;   // ��������������
        cyclic = cyclic->next; // ָ��ָ��Ľ��������ƶ�һλ
    }
    cyclic->next = head; // ��β����
    return head;
}

// �޳����������Ľ�㣬����ѭ�������ɾ������
void findAndKillK(person *head, int k, int m)
{
    person *tail = head;
    // // �ҵ������һ��������һ����㣬Ϊɾ��������׼��
    // while (tail->next != head)
    // {
    //     tail = tail->next;
    // } // �ҵ�β�ڵ�
    person *p = head;
    // �ҵ����Ϊk���ˣ�����Ĵ�����Ҫ��Ҫ�ҵ���ʼ�����˵�λ��
    while (p->number != k)
    {
        tail = p;
        p = p->next;
    }
    // �ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�����ʱ��ѭ��������ֻ��һ�������
    while (p->next != p) // ѭ���˳�����������ѭ��������ֻ��һ���ڵ���
    {
        // �ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1���˵�λ��tail��������ɾ��������
        for (int i = 1; i < m; i++)
        {
            tail = p;
            p = p->next;
        }                     // �ҵ���m-1���˵�λ��tail��ͬʱpָ���m���˵�λ��
        tail->next = p->next; // �������Ͻ�p���ժ����
        printf("�����˵ı��Ϊ:%d\n", p->number);
        free(p);
        p = tail->next; // ����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
    }
    printf("���ʣ�µ�һ���˵ı��Ϊ:%d\n", p->number);
    free(p); // ����ڴ���������ͷ���������
}

int main()
{
    printf("����Բ���ϵ�����n:");
    int n;
    scanf("%d", &n);
    person *head = initLink(n);
    printf("�ӵ�k�˿�ʼ����(k>1��k<%d):", n);
    int k;
    scanf("%d", &k);
    printf("����m���˳���:");
    int m;
    scanf("%d", &m);
    findAndKillK(head, k, m);
    return 0;
}