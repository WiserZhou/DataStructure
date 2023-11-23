#include <iostream>
#include <cstdlib>
using namespace std;
//static 与外部变量最大的不同为: 只限于在同一个程序文件中使用,并无法跨越不同的程序文件
int Factorial(int);// 阶乘运算函数
static int fact_no;// 声明静态外部变量

int main()
{
    int number, answer;

    cout << "请输入数值求阶乘:";
    cin >> number;
    answer = Factorial(number);// 调用函数
    cout << number << "!=" << answer << endl;
    cout << "fact_no =" << fact_no << endl;

    system("pause");
    return 0;
}


// 参数: number 指定数值进行阶乘运算
//  返回值：阶乘运算结果 
int Factorial(int number)
{
    int i;
    fact_no = 1;// 在前面已声明静态外部变量,可直接使用
    for (i = 1; i <= number; i++)
        fact_no = fact_no * i;
    return fact_no;
}