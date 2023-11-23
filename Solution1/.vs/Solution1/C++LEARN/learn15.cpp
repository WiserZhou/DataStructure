#include <iostream>
using namespace std;
// 如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。
// 对内联函数进行任何修改，都需要重新编译函数的所有客户端，
// 因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。
// 使用内联函数时，不会有实际的函数调用过程

// 内联函数定义

// http://c.biancheng.net/view/2201.html
inline int fun1(int a, int b, int c)
{
    return a + b + c;
}
int main()
{
    int a, b, c;
    cout << "input three number:";
    cin >> a >> b >> c;

    if (fun1(a, b, c) % 2 == 0)// 调用内联函数
        cout << a << "+" << b << "=" << a + b + c << "为偶数" << endl;
    else
        cout << a << "+" << b << "+" << c << a + b + c << "为奇数" << endl;

    system("pause");
    return 0;
}