#include <iostream>
using namespace std;
class Person
{
private:
    // 数据成员
    int age;
    bool sex;
    int *price;

public:
    // 静态类的使用
    static int time;
    static Person person_x;
    Person *person_y;
    // 静态类成员可以用来作为默认参数
    void Time(int tem_time = time)
    {
        cout << tem_time << "\n";
    }
    // 静态类成员函数只能访问静态类成员变量
    static void output()
    {
        cout << time << "\n";
    }
    // 默认构造函数必须出现，不然在定义类的时候必须实现构造函数
    Person() {}
    // 构造函数，其中的this引用本身的变量，this不允许用在静态类成员函数里
    Person(int age, bool sex)
    {
        this->age = age;
        this->sex = sex;
    }
    // 对应析构函数的构造函数类型，存在new分配的空间
    Person(int price)
    {
        this->price = new int;
        *(this->price) = price;
    }
    // 复制构造函数，将其它类的成员复制到现有类对象中
    Person(Person &copy_Person)
    {
        this->age = copy_Person.age;
        this->sex = copy_Person.sex;
    }
    // 析构函数，退出模块
    ~Person()
    {
        delete price;
    }
    // 成员函数
    inline void set_age(int age)
    {
        this->age = age;
    }
    // 利用const定义常成员函数，则此函数无法更改参数
    inline int get_age() const
    {
        return age;
    }
    // 将成员函数的实现放在类体外面，但是在类体内要声明成员函数
    inline void set_sex(bool sex);
    inline bool get_sex() const;
    // 嵌套类，在仅在外围类域内起作用，外部无法访问，没必要访问
    class node
    {
    public:
        int x;

    private:
        int y;
    };
};
// 实现类体内的成员函数，需要在函数名前面加上类名域
inline void Person::set_sex(bool sex)
{
    this->sex = sex;
}
inline bool Person::get_sex() const
{
    return sex;
}
// 静态类成员变量只能在全局中进行初始化，不允许在任何局部作用域中初始化
// 静态类成员变量在初始化的时候，必须声明类型
int Person::time = 20;
void psx()
{
    // 局部类，在函数外不可使用和访问
    class ps
    {
    public:
        int y;
    };
    ps p;
    p.y = 2;
    cout << p.y;
}
int main()
{

    Person p;
    p.set_age(18);
    cout << p.get_age() + (Person::time);
    return 0;
}
