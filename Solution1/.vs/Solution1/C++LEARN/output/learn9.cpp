#include <iostream>
#include <cstdlib>
using namespace std;
/*
    函数指针数组：
        声明； 数据类型(*函数指针名称[])(参数1 数据类型,参数2 数据类型,...);

*/
int add(int, int);                          // 函数声明
int sub(int, int);                          // 函数声明
int mul(int, int);                          // 函数声明
int (*pfunc[])(int, int) = {add, sub, mul}; // 声明函数指针数组,同时设置值
int main()
{
    char c[] = {'+', '-', '*'};
    int x, y, i;
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
    cout << "-----------------------" << endl;
    for (i = 0; i < 3; i++)
    {
        cout << x << c[i] << y << "=" << pfunc[i](x, y) << endl;
        // 在for循环中通过函数指针所指向的函数地址来地值来调用函数
    }
    cout << endl;
    cout << "----------------------" << endl;
    system("pause");
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}