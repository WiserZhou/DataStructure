

// ��ʽ���м���������
// ��ʽ���У����"������"����ʹ������ʵ�ֵĶ��д洢�ṹ��
// http://c.biancheng.net/view/3354.html

#include <stdio.h>
#include <stdlib.h>

// �����еĽڵ�ṹ
typedef struct QNode
{
    int data;
    struct QNode *next; // һ��ָ��ͬ���ͽṹ���ָ��next
} QNode;

// ������ʽ���еĺ���
QNode *initQueue()
{
    // ����һ��ͷ�ڵ�
    QNode *queue = (QNode *)malloc(sizeof(QNode)); // ����ռ�
    queue->data = 1;                               // ��ͷ�ڵ㸳ֵΪ1;
    // ��ͷ�ڵ���г�ʼ��
    queue->next = NULL;
    return queue; // ���ش���ͷ�ڵ������
}

// ����������Ԫ�أ����Ԫ���õ��ľ���βָ��
QNode *enQueue(QNode *rear, int data)
{
    // 1���ýڵ�������Ԫ��
    QNode *enElem = (QNode *)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    // 2���½ڵ���rear�ڵ㽨���߼���ϵ
    rear->next = enElem;
    // 3��rearָ���½ڵ�
    rear = enElem;
    // �����µ�rear��Ϊ������Ԫ�������׼��
    return rear;
}

// ɾ�������е�Ԫ��,ɾ��Ԫ�صĻ����õ��ľ���βָ��
QNode *DeQueue(QNode *top, QNode *rear)
{
    if (top == rear) // ˵�������д�ʱֻ�����һ��Ԫ����
    {
        printf("���һ��Ԫ��%d������\n", top->data);
        return top;
    }
    else
    {
        QNode *p = top;
        printf("%d\n", p->data);
        top = p->next; // ʹͷָ��ָ��ǰλ�õ���һλ
        free(p);       // �ͷŵ�ԭ���Ŀռ䣬��ʡ�ڴ�
        return top;
    }
}

void show(QNode *top, QNode *rear)
{
    if (top == rear)
    {
        printf("��ʱ������û��Ԫ�ء�\n");
    }
    else
    {
        printf("��ʱ�����е�Ԫ��Ϊ��");
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
    top = rear = initQueue(); // ����ͷ���
    printf("���е��еĳ�ʼԪ��Ϊ %d\n", top->data);
    int m;
    printf("����������е�Ԫ�ظ�����");
    scanf("%d", &m);
    // ������������ӽ�㣬ʹ��β�巨��ӵ�ͬʱ����βָ����Ҫָ����������һ��Ԫ��
    for (int i = 2; i <= m + 1; i++)
    {
        printf("Ԫ��%d��ʼ�����;\n", i);
        rear = enQueue(rear, i);
        show(top, rear);
    }
    // show(top, rear);
    //  show(top, rear);
    //  �����ɣ���������Ԫ�ؿ�ʼ������
    printf("��������Ԫ�ؿ�ʼ������:\n");
    for (int i = 1; i <= m + 1; i++)
    {
        printf("�����е�Ԫ��Ϊ��");
        top = DeQueue(top, rear);
        show(top, rear);
    }

    return 0;
}