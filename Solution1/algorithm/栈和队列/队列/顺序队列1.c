

// ���о������������ص㣺
// ���ݴӶ��е�һ�˽�����һ�˳���
// ���ݵ���Ӻͳ�����ѭ"�Ƚ��ȳ�"��ԭ��

// ����˳����еĵײ�ʹ�õ������飬�����Ԥ������һ���㹻����ڴ�ռ��ʼ��˳����С�
// ����֮�⣬Ϊ������˳����������ݴӶ�β������ͷ�����Ƚ��ȳ���Ҫ��
// ����Ҫ��������ָ�루top �� rear���ֱ�����ָ��˳������еĶ�ͷԪ�غͶ�βԪ��

#include <stdio.h>

// Ԫ����ջ����
int enQueue(int *a, int rear, int data)
{
    a[rear] = data;
    rear++; // βָ������ƶ�һλ
    return rear;
}

// չʾ����Ԫ�صĲ���
void show(int *a, int front, int rear)
{
    printf("��ʱ����Ԫ��Ϊ��");
    if (front == rear)
    {
        printf("�����ǿ�Ԫ�ء�");
    }
    else
    {
        while (front != rear)
        {
            printf("%d ", a[front]);
            front++;
        }
    }
}

// Ԫ�س�ջ����
int deQueue(int *a, int front, int rear)
{
    front = 0;
    // ��� front==rear����ʾ����Ϊ��
    while (front != rear)
    {
        printf("����Ԫ�أ�%d\n", a[front]);
        front++;
    }
    return front;
}

int main()
{
    int a[100];
    int front, rear;
    // ���ö�ͷָ��Ͷ�βָ�룬��������û��Ԫ��ʱ����ͷ�Ͷ�βָ��ͬһ���ַ
    front = rear = 0;
    // ���
    int n;
    printf("���������Ԫ�ظ���:");
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        rear = enQueue(a, rear, i);
    }
    show(a, front, rear);
    printf("\n");
    // printf("%d",front);   ��������ӡ��ֵΪ0��˵���βεĸı䲻��Ӱ�쵽ʵ��
    // ����
    front = deQueue(a, front, rear); // ��front��ס�����ķ���ֵ�Ż�ı�frontʵ�ε�ֵ
    show(a, front, rear);
    return 0;
}
// �����������ڵ�����
// ����˳����������ݲ��ϵؽ��ӳ��ӹ����У���˳����е�λ�ò��Ϻ��ơ�
// ˳��������������ɵ�Ӱ���ǣ�
// ˳�����֮ǰ������洢�ռ佫�޷��ٱ�ʹ�ã�����˿ռ��˷ѣ�
// ���˳�������Ŀռ䲻�㹻����ֱ����ɳ��������� a ����������������

