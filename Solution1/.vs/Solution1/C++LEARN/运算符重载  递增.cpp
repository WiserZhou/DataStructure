#include <iostream>
using namespace std;
// 重载递增运算符

// 自定义整型
class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger(int a) { m_Num = a; }
    // 重载前置++运算符
    MyInteger &operator++() // 这是返回引用,为了一直对一个数据进行递增操作
    {
        // 先进行++运算
        m_Num++;
        // 再将自身做返回
        return *this; // 用this把自身做一个解引用
    }
    // MyInteger operator++() // 这是返回值,无法一直对一个数据进行操作
    // {
    //     m_Num++;
    //     return *this;
    // }
    // 重载后置++运算符
    // void operator++(int)  int 代表占位参数，可以用于区分前置和后置递增
    MyInteger operator++(int) // 后置递增一定要返回的是值
    {
        // 先 记录一下当时的结果
        MyInteger temp = *this; // 如果局部函数在此条语句结束之后就会被释放掉，再返回其引用就是非法操作
        // 后 递增
        m_Num++;
        // 最后将记录结果做返回
        return temp; // 不能返回的是引用，因为这里返回的是局部的对象的引用
    }

private:
    int m_Num;
};

// 重载<<运算符
ostream &operator<<(ostream &cout, MyInteger myint)
{
    cout << myint.m_Num;
    return cout;
}
void test01()
{
    MyInteger myint(5);
    cout << ++(++myint) << endl;
    cout << myint << endl;
}
void test02()
{
    MyInteger myint(8);
    cout << myint++ << endl;
    cout << myint << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}