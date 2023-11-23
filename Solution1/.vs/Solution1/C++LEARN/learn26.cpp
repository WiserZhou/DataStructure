#include <iostream>
using namespace std;
class ClassA
{
public:
    ClassA()
    {
        cout << "ClassA" << endl;
    }
    ClassA(int i)
    {

        cout << "ClassA" << i << endl;
    }
    ClassA(const ClassA &src)
    {
        cout << "ClassA copy" << endl;
    } // 拷贝构造函数
    ClassA &operator=(const ClassA &rhs)
    {
        cout << "call ClassA" << endl;
    }
    virtual ~ClassA()
    {
        cout << "DeleteClassA" << endl;
    }
    void hornet(int i = 7) const
    {
        cout << "hornet ClassA" << i << endl;
    }
};
class ClassB : public ClassA
{
public:
    ClassB() : ClassA(1)
    {
        cout << "ClassB" << endl;
    }
    ClassB &operator=(const ClassB &rhs)
    {
        cout << "call ClassB" << endl;
    }
    virtual ~ClassB()
    {
        cout << "Delete ClassB" << endl;
    }
    void hornet(int i = 9) const
    {
        cout << "hornet ClassB" << i << endl;
    }
};
void find(const ClassA &inKlep)
{
    ClassA theClassA;
    inKlep.hornet(2);
}
int main()
{
    ClassB deri;
    cout << endl;

    ClassA base = deri; // 程序将此自动改写为：ClassA base(deri)，使用拷贝构造函数进行构造
    // ClassA base;
    // base = deri;//这么写的话，表明base初始化的时候调用了空参构造，然后再进行重载赋值号赋值
    cout << endl;
    find(deri);
    cout << "Done!" << endl;
    return 0;
}
// ClassA1 // ClassB的默认构造里面调用了ClassA的参数构造
// ClassB  //ClassB的空参构造

// ClassA copy  //ClassA 的拷贝构造函数调用

// ClassA   //find函数内部的构造
// hornet ClassA2 //由于参数是ClassA类，所以只能调用属于父类的函数
// DeleteClassA//find内部的定义的临时类析构
// Done!
// DeleteClassA //程序终止，删除base
// Delete ClassB//删除deri的子类
// DeleteClassA //删除deri的父类，这表明先对后定义的对象进行析构，倒着进行，进行的时候，先调用子类的析构
