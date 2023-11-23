#include <iostream>
using namespace std;

// 赋值运算符重载
class Person
{

public:
    Person(int age)
    {
        m_Age = new int(age); // 把数据创建在堆区
    }
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    // 重载 赋值运算符
    Person &operator=(Person &p)
    {
        // 编译器提供的是浅拷贝
        // m_Age=p.m_Age;

        // 应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }

        // 深拷贝的操作-------重新申请一块内存
        m_Age = new int(*p.m_Age);

        // 返回对象的指针
        return *this;
    }
    int *m_Age;
};
void test01()
{
    Person p1(18);

    Person p2(20);

    Person p3(30);

    p3 = p2 = p1; // 赋值操作
    cout << "p1's age is " << *p1.m_Age << endl;

    cout << "p2's age is " << *p2.m_Age << endl;

    cout << "p3's age is " << *p3.m_Age << endl;
}
int main()
{
    test01();
    // int a = 10;
    // int b = 20;
    // int c = 30;
    // c = b = a;
    // cout << c << "  " << b << "  " << a << endl;

    system("pause");
    return 0;
}