#include <iostream>
#include <vector>

void rotateArrayRight(std::vector<int> &A, int k)
{
    int n = A.size();
    k = k % n; // 处理 k 大于数组长度的情况

    if (n == 0 || k == 0)
    {
        return;
    }

    int temp = A[0]; // 用于存储被替换的元素
    int start = 0;   // 当前轮换的起始位置

    for (int i = 0; i < n; ++i)
    {
        int nextIndex = (start + k) % n; // 计算下一个位置
        std::swap(temp, A[nextIndex]);   // 将当前位置的元素保存到 temp，并将目标位置的元素移到当前位置
        start = nextIndex;               // 更新当前轮换的起始位置

        if (start == 0)
        {              // 如果回到起始位置，说明一轮循环完成
            start = 1; // 起始位置向前移动一位，开始下一轮
        }
    }
}

int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5};
    int k = 2;

    rotateArrayRight(A, k);

    // 输出结果
    for (int i = 0; i < A.size(); ++i)
    {
        std::cout << A[i] << " ";
    }

    return 0;
}
