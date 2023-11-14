#include <stdio.h>

// 定义一个枚举类型，包含了星期的常量值
enum Weekday
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    // 声明一个枚举变量并赋值
    enum Weekday today = 222;

    // 使用switch语句处理枚举变量
    switch (today)
    {
    case Monday:
        printf("Today is Monday.\n");
        break;
    case Tuesday:
        printf("Today is Tuesday.\n");
        break;
    case Wednesday:
        printf("Today is Wednesday.\n");
        break;
    case Thursday:
        printf("Today is Thursday.\n");
        break;
    case Friday:
        printf("Today is Friday.\n");
        break;
    case Saturday:
        printf("Today is Saturday.\n");
        break;
    case Sunday:
        printf("Today is Sunday.\n");
        break;
    default:
        printf("Invalid day.\n");
    }

    return 0;
}