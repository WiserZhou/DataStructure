#include <iostream>
#include <cstdlib>
using namespace std;
// 声明类 student
class student
{
private:
    int age;

protected:
    int lang;

public:
    int math;
    student() // 构造函数
    {
        age = 0;
        lang = 0;
        math = 0;
    }
    void set_age(int a1)
    {
        age = a1;
    }
    void show_age()
    {
        cout << "age=" << age << endl;
    }
};

// 以protected类型从类student继承成为新的类s1
class s1 : protected student
{
public:
    void set_lang(int v3)
    {
        lang = v3; // 可直接设置类型为protected的数据成员lang
    }
    void set_math(int v4)
    {
        math = v4; // 可直接设置类型为public的数据成员math
    }
    void setage(int v5)
    {
        // 无法直接存取private类型的数据成员age，必须通过调用set_age成员来设置数据成员age
        set_age(v5);
    }
    void show_data()
    {
        // 必须通过调用show_age()成员函数来获取age值并在屏幕上显示
        show_age();
        // 将数据成员lang和math显示在屏幕上
        cout << "lang=" << lang << endl;
        cout << "math=" << math << endl;
    }
};
// 以private类型从类student继承成为新的类s2
class s2 : private student
{
public:
    void set_lang(int z3)
    {
        lang = z3;
    }
    void set_math(int z4)
    {
        math = z4;
    }
    void setage(int z5)
    {
        set_age(z5);
    }
    void show_data()
    {
        show_age();
        cout << "lang=" << lang << endl;
        cout << "math=" << math << endl;
    }
};
// 以public类型从类student继承成为新的类s3
class s3 : public student
{
public:
    void set_lang(int z3)
    {
        lang = z3;
    }
    void set_math(int z4)
    {
        math = z4;
    }
    void setage(int z5)
    {
        set_age(z5);
    }
    void show_data()
    {
        show_age();
        cout << "lang=" << lang << endl;
        cout << "math=" << math << endl;
    }
};
int main()
{
    // 声明对象 obj1;
    s1 obj1;
    // 可通过调用setage成员函数来调用类 student 内public类型的成员函数set_age()
    obj1.setage(10);
    // 可直接存取类student内的protected类型的数据成员lang
    obj1.set_lang(90);
    // 可直接存取类student内的public类型的数据成员math
    obj1.set_math(88);
obj1.show_data();

    s2 obj2;
    obj2.setage(20);
    obj2.set_math(120);
    obj2.set_lang(95);
    obj2.show_data();

    s3 obj3;
    obj3.setage(25);
    obj3.set_lang(100);
    obj3.set_math(150);
    obj3.show_data();
    system("pause");
    return 0;
}