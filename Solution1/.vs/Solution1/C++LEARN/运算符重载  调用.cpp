#include <iostream>
using namespace std;
#include <string>

// 函数调用运算符重载

// 打印输出类

class MyPrint
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};
// 一般函数调用运算符
void MyPrint02(string test)
{
    cout << test << endl;
}
void test01()
{
    MyPrint myPrint;

    myPrint("Hello World!");   // 由于使用起来非常类似于函数调用，因此称为仿函数
    MyPrint02("Hello World!"); // 函数调用
}

// 仿函数非常的灵活，无固定的写法
// 加法类
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};
class MyMultiple
{
public:
    int operator()(int a, int b)
    {
        return a * b;
    }
};
void test02()
{
    MyAdd myadd;
    int ret = myadd(100, 100);
    cout << "ret=" << ret << endl;

    // 匿名函数对象
    cout << MyAdd()(100, 100) << endl;
    cout << MyMultiple()(100, 100) << endl;
}

int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}