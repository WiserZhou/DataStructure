#include <iostream>
#include <string>
using namespace std;

// 函数重载切记要避免二义性，只能以参数作为唯一的区别。
// 返回值，函数名，作用域必须一样！

// 不能函数重载的几种情况   https://blog.csdn.net/shltsh/article/details/45938663
char *getData(char *);
int getData(int);
float getData(float);
double getData(double);
int main()
{
    char *cVal = "荣钦科技"; // 定义不同的数据类型
    int iVal = 2004;
    float fVal = 2.3f;
    double dVal = 2.123;
    cout << "执行 char* getData(char*) =>" << getData(cVal) << endl;
    cout << "执行 int getData(char*) =>" << getData(iVal) << endl;
    cout << "执行 float getData(char*) =>" << getData(fVal) << endl;
    cout << "执行 double getData(char*) =>" << getData(dVal) << endl;

    system("pause");
    return 0;
}
// 定义重载函数内容
char *getData(char *cVal)
{
    return cVal;
}
int getData(int iVal)
{
    return iVal;
}
float getData(float fVal)
{
    return fVal;
}
double getData(double dVal)
{
    return dVal;
}