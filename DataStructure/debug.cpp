#include <iostream>
#include <stack>
using namespace std;
stack<char> optr; // 操作符
stack<int> opnd;  // 操作数
int compare(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
    else
        return 3;
}
int calculate(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
    else
        return 0;
}
int transInt(char c)
{
    return c - '0';
}
void merge()
{
    int a = opnd.top();
    opnd.pop();
    int b = opnd.top();
    opnd.pop();
    char d = optr.top();
    optr.pop();
    int e = calculate(b, a, d);
    opnd.push(e);
}
int main()
{
    bool flag = false;
    char c = getchar();
    // cout << "input:" << c << endl;
    while (c != '\n')
    {

        if (isdigit(c))
        {
            if (flag)
            {
                int a = opnd.top();
                opnd.pop();
                a = a * 10 + transInt(c);
                opnd.push(a);
            }
            else
            {
                opnd.push(transInt(c));
                flag = true;
                // cout << c << endl;
            }

            // cout << c << endl;
        }
        else
        {

            flag = false;
            if (c == ')')
            {
            back:
                merge(); // cout << "calculate(+,-): " << e << endl;
                if (optr.top() == '(')
                {
                    optr.pop(); // 弹出里面的‘('
                    // cout << "pop" << endl;
                }

                else
                    goto back;
            }
            else if (!optr.empty() && optr.top() != '(' && (c == '+' || c == '-'))
            {
                merge();
                // cout << "calculate(*,/): " << e << endl;
                optr.push(c);
                //  cout<<"*********"<<endl;
            }
            else
            {
                optr.push(c);
            }

            // cout << c << endl;
        }
        c = getchar();
        // cout << "input:" << c << endl;
    }
    while (!optr.empty())
    {
        merge();
    }
    cout << opnd.top();
    return 0;
}