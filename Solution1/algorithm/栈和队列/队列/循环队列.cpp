#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100   // �����г���
typedef int QElemType; // �������Ԫ������Ϊint

typedef struct
{
    QElemType *base; // ��̬����洢�ռ�
    int front;       // ͷָ�룬�����в��գ�ָ�����ͷԪ��
    int rear;        // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
} SqQueue;

typedef enum
{
    OK,
    ERROR,
    OVERFLOW
} Status;

Status InitQueue(SqQueue &Q)
{
    // ����һ���ն���Q
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW); // �洢����ʧ��
    Q.front = Q.rear = 0;
    return OK;
}
// Ԫ�������
Status EnQueue(SqQueue &Q, QElemType e)
{
    // ����Ԫ��eΪQ���µĶ�βԪ��
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR; // ������
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;   // ��֤ rear ʼ���� [0, MAXQSIZE-1] �ķ�Χ�ڣ�ʵ��ѭ�����е�Ч��
    return OK;
}
// Ԫ�س�����
Status DeQueue(SqQueue &Q, QElemType &e)
{
    // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK; ���򷵻�ERROR
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;  // ��֤ front ʼ���� [0, MAXQSIZE-1] �ķ�Χ�ڣ�ʵ��ѭ�����е�Ч��
    return OK;
}

int QueueLength(SqQueue Q)  // ���ǻ�ȡ���г��ȵ��㷨
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

int main()
{
    SqQueue Q;
    QElemType e;
    // ��ʼ������
    InitQueue(Q);
    // ��Ӳ���
    for (int i = 0; i < 5; i++)
    {
        EnQueue(Q, i);
    }
    // ���Ӳ���
    while (DeQueue(Q, e) == OK)
    {
        printf("%d ", e);
    }
    return 0;
}
