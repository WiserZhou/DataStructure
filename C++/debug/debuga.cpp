#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::cout << "��ʼ��С: " << numbers.size() << std::endl;

    numbers.resize(8); // ���ӵ�8��Ԫ�أ�Ĭ�Ϲ���

    std::cout << "�µĴ�С: " << numbers.size() << std::endl;
    std::cout << "�µ�Ԫ��: ";
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    numbers.resize(3); // ��С��3��Ԫ��

    std::cout << "�µĴ�С: " << numbers.size() << std::endl;
    std::cout << "�µ�Ԫ��: ";
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
