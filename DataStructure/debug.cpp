#include <iostream> //输入的表达式要以'#'结尾，如‘5+6*3/(3-1)#’
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

stack<char> optr;   // 运算符栈
stack<double> opnd; // 操作数栈

int getIndex(char theta) // 获取theta所对应的索引
{
    int index = 0;
    switch (theta)
    {
    case '+':
        index = 0;
        break;
    case '-':
        index = 1;
        break;
    case '*':
        index = 2;
        break;
    case '/':
        index = 3;
        break;
    case '(':
        index = 4;
        break;
    case ')':
        index = 5;
        break;
    case '\n':
        index = 6;
    default:
        break;
    }
    return index;
}
const char priority[7][8] = // 算符间的优先级关系
    {
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=', '0'},
        {'>', '>', '>', '>', '0', '>', '>'},
        {'<', '<', '<', '<', '<', '0', '='},
};

char getPriority(char theta1, char theta2) // 获取theta1与theta2之间的优先级
{

    int index1 = getIndex(theta1);
    int index2 = getIndex(theta2);
    return priority[index1][index2];
}

double calculate(double b, char theta, double a) // 计算b theta a
{
    switch (theta)
    {
    case '+':
        return b + a;
    case '-':
        return b - a;
    case '*':
        return b * a;
    case '/':
        return b / a;
    default:
        break;
    }
    return 0;
}

int main()
{
    optr.push('\n'); // 首先将'#'入栈optr
    int counter = 0; // 添加变量counter表示有多少个数字相继入栈，实现多位数的四则运算
    char c = getchar();
    while (c != '\n' || optr.top() != '\n') // 终止条件
    {
        if (isdigit(c)) // 如果c在'0'~'9'之间
        {
            if (counter == 1) // counter==1表示上一字符也是数字，所以要合并，比如12*12，要算12，而不是单独的1和2
            {
                double t = opnd.top();
                opnd.pop();
                opnd.push(t * 10 + (c - '0'));
                counter = 1;
            }
            else
            {
                opnd.push(c - '0'); // 将c对应的数值入栈opnd
                counter++;
            }
            c = getchar();
        }
        else
        {
            counter = 0;                        // counter置零
            switch (getPriority(optr.top(), c)) // 获取运算符栈optr栈顶元素与c之间的优先级，用'>'，'<'，'='表示
            {
            case '<': //<则将c入栈optr
                optr.push(c);
                c = getchar();
                break;
            case '=': //=将optr栈顶元素弹出，用于括号的处理
                optr.pop();
                c = getchar();
                break;
            case '>': //>则计算
                char theta = optr.top();
                optr.pop();
                double a = opnd.top();
                opnd.pop();
                double b = opnd.top();
                opnd.pop();
                opnd.push(calculate(b, theta, a));
                break;
            default:
                break;
            }
        }
    }
    int ans = opnd.top(); // 返回opnd栈顶元素的值
    cout << ans;
    return 0;
}