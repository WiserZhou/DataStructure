

// ˳�������һ��ʵ�ַ�����
// �����ö����е�Ԫ��ɾ���������ָ��ָ��ԭ�����׵�ַ��������ɿռ���˷�

// ���еĳ��ȴ�С����rear-front�� 
// ������ѭ�������У����������rear-front���ͻ���һ��������֣���������ָ��ָ��ͬһ����ʱ��
// �޷���������Ϊ�����ǿյģ�����rear�Ѿ�����һȦ�����ˣ���������������� 
// so����Ҫ��һ���յ�λ�ã����λ�ò����κ�Ԫ�أ����þ���Ϊ������ӿպͶ�����

#include <stdio.h>
#define max 100 // ��ʾ˳�������Ŀռ��С

// ����������Ԫ��
int enQueue(int *a, int front, int rear, int data)
{
    // ����ж���䣬���rear����max����ֱ�ӽ����a[0]���¿�ʼ�洢�����rear+1��front�غϣ����ʾ��������
    if ((rear + 1) % max == front)
    {
        printf("�ռ�����");
        return rear;
    }
    a[rear % max] = data;
    rear++;
    return rear;
}

// չʾ����Ԫ�صĲ���
void show(int *a, int front, int rear)
{
    printf("��ʱ����Ԫ��Ϊ��");
    if (front == rear % max)
    {
        printf("�����ǿ�Ԫ�ء�");
    }
    else
    {
        while (front != rear % max)
        {
            printf("%d ", a[front]);
            front++;
        }
    }
    printf("\n");
}

// ������ɾ��Ԫ��
int deQueue(int *a, int front, int rear)
{
    // ���front==rear����ʾ����Ϊ��
    if (front == rear % max)
    {
        printf("����Ϊ��");
        return front;
    }
    printf("%d ", a[front]);
    // front����ֱ�� +1������+1��ͬmax���бȽϣ����=max����ֱ����ת�� a[0]
    front = (front + 1) % max;
    return front;
}

int main()
{
    int a[max];
    int front, rear;
    // ���ö�ͷָ��Ͷ�βָ�룬��������û��Ԫ��ʱ����ͷ�Ͷ�βָ��ͬһ���ַ
    front = rear = 0;
    // ���
    int m;
    printf("������һ��С��100������:");
    scanf("%d", &m);
    for (int i = 1; i < m + 1; i++)
    {
        rear = enQueue(a, front, rear, i);
    }
    show(a, front, rear);

    printf("ɾ������Ԫ�غ�: ");
    for (int i = 1; i < m + 1; i++)
    {
        front = deQueue(a, front, rear);
    }
    show(a, front, rear);
    return 0;
}



// ʹ�ô˷�����Ҫע����ǣ�˳��������ж������Ƿ�����ʱ���������������
// ������Ϊ��ʱ�����е�ͷָ����ڶ��е�βָ�룻
// ��������Աʱ�����е�ͷָ����ڶ��е�βָ�룻

// ˳����еĴ洢״̬��ͬ�������ж�������ͬ��
// Ϊ�˶���������֣���򵥵Ľ���취�ǣ������������е�һ���洢�ռ䣬
// �ж�������Ա�������ǣ�βָ�����һ��λ�ú�ͷָ����������˵���������ˣ��������е� 18 ����ʾ��