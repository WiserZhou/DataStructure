

// #include "../header/Queue.h"
void radixsort(int figure, QUEUE &A)
{ // 关键字链表用队列存储
    QUEUE Q[10];
    records data;
    int pass, r, i; // pass用于位数循环,r取位数
    for (pass = 1; pass <= firure; pass++)
    {
        for (i = 0; i <= 9; i++)
            MAKENULL(Q[i])
        while (!EMPTY(A))
        {
            data = FRONT(A);                           // 获取A中的需要处理的数据给data
            DEQUEUE(A);                                // data从A中出队
            r = ((data.key / pow(10, pass - 1)) % 10); // 计算第pass位的值给r
            ENQUEUE(data, Q[r]);                       // 把data插入队列Q[r]
        }
        for (i = 1; i <= 9; i++)
            CONCATENATE(Q[0], Q[i]); // 收集
        A = Q[0];                    // 收集的结果赋给A
    }
}