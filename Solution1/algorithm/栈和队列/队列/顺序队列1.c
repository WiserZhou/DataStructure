

// 队列具有以下两个特点：
// 数据从队列的一端进，另一端出；
// 数据的入队和出队遵循"先进先出"的原则；

// 由于顺序队列的底层使用的是数组，因此需预先申请一块足够大的内存空间初始化顺序队列。
// 除此之外，为了满足顺序队列中数据从队尾进，队头出且先进先出的要求，
// 还需要定义两个指针（top 和 rear）分别用于指向顺序队列中的队头元素和队尾元素

#include <stdio.h>

// 元素入栈操作
int enQueue(int *a, int rear, int data)
{
    a[rear] = data;
    rear++; // 尾指针向后移动一位
    return rear;
}

// 展示队内元素的操作
void show(int *a, int front, int rear)
{
    printf("此时队内元素为：");
    if (front == rear)
    {
        printf("队中是空元素。");
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

// 元素出栈操作
int deQueue(int *a, int front, int rear)
{
    front = 0;
    // 如果 front==rear，表示队列为空
    while (front != rear)
    {
        printf("出队元素：%d\n", a[front]);
        front++;
    }
    return front;
}

int main()
{
    int a[100];
    int front, rear;
    // 设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front = rear = 0;
    // 入队
    int n;
    printf("请输入入队元素个数:");
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        rear = enQueue(a, rear, i);
    }
    show(a, front, rear);
    printf("\n");
    // printf("%d",front);   这条语句打印的值为0，说明形参的改变不会影响到实参
    // 出队
    front = deQueue(a, front, rear); // 用front接住函数的返回值才会改变front实参的值
    show(a, front, rear);
    return 0;
}
// 上述方法存在的问题
// 整个顺序队列在数据不断地进队出队过程中，在顺序表中的位置不断后移。
// 顺序队列整体后移造成的影响是：
// 顺序队列之前的数组存储空间将无法再被使用，造成了空间浪费；
// 如果顺序表申请的空间不足够大，则直接造成程序中数组 a 溢出，产生溢出错误；

