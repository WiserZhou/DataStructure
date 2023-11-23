#include <iostream>
using namespace std;

class Circle
{
public:
    Circle(double r);
    double Area() const { return PI * dRadius * dRadius; }
    double GetRadius() const { return dRadius; }              // 常成员函数
    void SetRadius(double r) { dRadius = r; }                 // 设置圆的半径

private:
    double dRadius;
    const double PI;                // 表示圆周率，常数据成员
};

Circle::Circle(double r) : PI(3.14)
{
    dRadius = r;
}
int main()
{
    const Circle unit(1);
    cout << "单位圆的面积为:" << unit.Area() << endl;
    Circle c(3);
    cout << "半径为:" << c.GetRadius() << "的圆的面积:" << c.Area() << endl;
    c.SetRadius(3.5);
    cout << "半径为:" << c.GetRadius() << "的圆的面积:" << c.Area() << endl;
    system("pause");
    return 0;
}