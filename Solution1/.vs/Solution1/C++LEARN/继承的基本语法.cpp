#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A = 10;
    int fun1()
    {
        cout << "this is Base fun1()" << endl;
    }
    int fun1(int a)
    {
        cout << "this is Base fun1(int a)" << endl;
    }
};
class Son1 : public Base1
{
public:
    int m_A = 200;
    int fun1()
    {
        cout << "this is Son fun1()" << endl;
    }
};
void test()
{
    Son1 a;
    cout << a.m_A << endl;
    cout << a.Base1::m_A << endl;
    cout << a.fun1() << endl;
    cout << a.Base1::fun1(100) << endl;
    cout << a.Base1::fun1() << endl;
}
int main()
{
    test();
    return 0;
}