#include <iostream>
#include <random>
#include <cmath>
using namespace std;
/**
 * 蒙特卡洛方法计算圆周率π的值
 */
int main()
{
    int num = 0;
    int sum = 0;

    // 创建随机数引擎
    std::random_device rd;
    std::mt19937 gen(rd());

    // 创建均匀分布的实数生成器
    std::uniform_real_distribution<double> dis(0, 1);

    while (1)
    {
        // 生成随机数
        double random_num = dis(gen);
        double random_num2 = dis(gen);

        if (random_num * random_num + random_num2 * random_num2 <= 1)
        {
            num++;
        }
        sum++;
        cout << num / static_cast<double>(sum) * 4 << endl;
    }

    return 0;
}
