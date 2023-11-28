#include <iostream>
#include <vector>

void shellSort(std::vector<char> &arr)
{
    int n = arr.size();
    int gap = 4; // 初始步长设定为数组长度的一半

    while (gap > 0)
    {
        for (int i = gap; i < n; ++i)
        {
            char temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        std::cout << "排序后的数组: ";
        for (char ch : arr)
        {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
        return;
        gap /= 2; // 缩小步长
    }
}

int main()
{
    std::vector<char> arr = {'Q', 'H', 'C', 'Y', 'P', 'A', 'M', 'S', 'R', 'D', 'F', 'X'};

    std::cout << "原始数组: ";
    for (char ch : arr)
    {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    shellSort(arr);

    return 0;
}
