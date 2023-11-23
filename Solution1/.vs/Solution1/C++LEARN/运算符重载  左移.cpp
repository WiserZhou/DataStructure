#include <iostream>
using namespace std;

// 左移运算符重载
class Person
{
    friend ostream &operator<<(ostream &out, Person &p);

public:
    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }

private:
    // 利用成员函数重载 左移运算符 p.operator<<(cout)  简化版本 p<<cout
    // 不会利用成员函数重载<<运算符,应为无法 cout在左侧
    // void operator<<()
    // {
    // }
    int m_A;
    int m_B;
};

// 只能利用全局函数重载左移运算符
// void operator<<(ostream &cout, Person &p) // 本质 operator<<(cout ,p) 简化 cout<<p
// {
//     cout << "m_A=" << p.m_A << "  m_B=" << p.m_B << endl;
        //无法在调用该函数的后面追加另外的语句
// }

ostream &operator<<(ostream &out, Person &p) // 本质 operator<<(cout ,p) 简化 cout<<p
{
    out << "m_A=" << p.m_A << "  m_B=" << p.m_B; // 这里&out =cout 及out为cout的一个别名
    return out;
}
void test01()
{
    Person p(10,10);
    
    cout << p << endl;// 链式编程思想
}
int main()
{
    test01();
    system("pause");
    return 0;
}