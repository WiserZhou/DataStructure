

// 顺序队列另一种实现方法。
// 可以让队列中的元素删除完后，两个指针指向原来的首地址，不会造成空间的浪费

// 队列的长度大小就是rear-front。 
// 但是在循环队列中，如果还是用rear-front，就会有一个问题出现，就是两个指针指向同一个的时候，
// 无法区分是因为队列是空的，还是rear已经绕了一圈回来了（即队满的情况）。 
// so我们要加一个空的位置，这个位置不放任何元素，作用就是为了区别队空和队满。

#include <stdio.h>
#define max 100 // 表示顺序表申请的空间大小

// 向队列中添加元素
int enQueue(int *a, int front, int rear, int data)
{
    // 添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
    if ((rear + 1) % max == front)
    {
        printf("空间已满");
        return rear;
    }
    a[rear % max] = data;
    rear++;
    return rear;
}

// 展示队内元素的操作
void show(int *a, int front, int rear)
{
    printf("此时队内元素为：");
    if (front == rear % max)
    {
        printf("队中是空元素。");
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

// 队列中删除元素
int deQueue(int *a, int front, int rear)
{
    // 如果front==rear，表示队列为空
    if (front == rear % max)
    {
        printf("队列为空");
        return front;
    }
    printf("%d ", a[front]);
    // front不再直接 +1，而是+1后同max进行比较，如果=max，则直接跳转到 a[0]
    front = (front + 1) % max;
    return front;
}

int main()
{
    int a[max];
    int front, rear;
    // 设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front = rear = 0;
    // 入队
    int m;
    printf("请输入一个小于100的数字:");
    scanf("%d", &m);
    for (int i = 1; i < m + 1; i++)
    {
        rear = enQueue(a, front, rear, i);
    }
    show(a, front, rear);

    printf("删除所有元素后: ");
    for (int i = 1; i < m + 1; i++)
    {
        front = deQueue(a, front, rear);
    }
    show(a, front, rear);
    return 0;
}



// 使用此方法需要注意的是，顺序队列在判断数组是否已满时，出现下面情况：
// 当队列为空时，队列的头指针等于队列的尾指针；
// 当数组满员时，队列的头指针等于队列的尾指针；

// 顺序队列的存储状态不同，但是判断条件相同。
// 为了对其进行区分，最简单的解决办法是：牺牲掉数组中的一个存储空间，
// 判断数组满员的条件是：尾指针的下一个位置和头指针相遇，就说明数组满了，即程序中第 18 行所示。