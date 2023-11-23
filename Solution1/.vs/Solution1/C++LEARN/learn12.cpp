#include <iostream>
#include <cmath>
#include <string>
#include "learn13.cpp"
using namespace std;
int x; // 声明x为全局变量,会实际分配内存
int main()
{
    foo(); // 调用另一个程序文件中的函数
    cout << "x = " << x << endl;
    print();
    system("pause");
    return 0;
}