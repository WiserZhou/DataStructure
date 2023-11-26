#include <iostream>
#include <vector>

void sortColors(std::vector<int> &nums)
{
    // 初始化三个指针，分别表示红色、白色和蓝色的边界
    int low = 0, mid = 0, high = nums.size() - 1;

    // 遍历数组，直到中间指针超过蓝色边界
    while (mid <= high)
    {
        // 如果当前元素为红色(0)，交换当前元素和红色边界元素，同时移动红色和中间指针
        if (nums[mid] == 0)
        {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        // 如果当前元素为白色(1)，只需移动中间指针
        else if (nums[mid] == 1)
        {
            mid++;
        }
        // 如果当前元素为蓝色(2)，交换当前元素和蓝色边界元素，同时移动蓝色边界指针
        else
        {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    // 示例用法
    std::vector<int> colors = {2, 0, 2, 1, 1, 0};

    std::cout << "Original Array: ";
    for (int color : colors)
    {
        std::cout << color << " ";
    }

    // 调用排序函数
    sortColors(colors);

    std::cout << "\nSorted Array: ";
    for (int color : colors)
    {
        std::cout << color << " ";
    }

    return 0;
}
