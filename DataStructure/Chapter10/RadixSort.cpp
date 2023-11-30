#include <iostream>
#include <queue>
#include <cmath>

// 结点定义
struct records
{
    int key; // 关键字
    // 其他数据成员
};

// 基数排序
void radixsort(int figure, std::queue<records> &A)
{
    std::queue<records> Q[10];

    for (int pass = 1; pass <= figure; pass++)
    {
        // 将A中的所有元素都放到Q中
        while (!A.empty())
        {
            records data = A.front();
            A.pop();

            int r = (data.key / static_cast<int>(std::pow(10, pass - 1))) % 10; // 获取第pass位的值
            Q[r].push(data);
        }

        // 将Q中的元素依次放入A中
        for (int i = 1; i <= 9; i++)
        {
            while (!Q[i].empty())
            {
                A.push(Q[i].front());       
                Q[i].pop();
            }
        }
    }
}

// 收集算法
void Concatenate(std::queue<records> &Q0, std::queue<records> &Q1)
{
    if (!Q1.empty())
    {
        while (!Q1.empty())
        {
            Q0.push(Q1.front());
            Q1.pop();
        }
    }
}

int main()
{
    // 示例用法
    std::queue<records> myQueue;
    // 添加一些数据到队列中
    myQueue.push({732});
    myQueue.push({541});
    myQueue.push({126});
    myQueue.push({389});

    // 调用基数排序
    radixsort(3, myQueue);

    // 输出排序后的结果
    while (!myQueue.empty())
    {
        std::cout << myQueue.front().key << " ";
        myQueue.pop();
    }

    return 0;
}
