#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::cout << "初始大小: " << numbers.size() << std::endl;

    numbers.resize(8); // 增加到8个元素，默认构造

    std::cout << "新的大小: " << numbers.size() << std::endl;
    std::cout << "新的元素: ";
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    numbers.resize(3); // 缩小到3个元素

    std::cout << "新的大小: " << numbers.size() << std::endl;
    std::cout << "新的元素: ";
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
