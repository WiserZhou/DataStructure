#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e3 + 1;
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
inline bool check() {
    return opnd.size() >= 2 && optr.size() >= 1;
}
char s[N];
int main()
{
    bool flag = false;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        char c = s[i];
        // printf("%c|", c);
        if (isdigit(c))
        {
            int a = 0;
            if (flag) a = opnd.top(), opnd.pop();
            a = a * 10 + transInt(c);
            opnd.push(a);
            flag = true;
        }
        else
        {

            flag = false;
            if (c == ')')
            {
                while (check() && optr.top() != '(') merge(); // cout << "calculate(+,-): " << e << endl;
                if (optr.top() == '(')
                {
                    optr.pop(); 
                }
            }
            else if (check() && optr.top() != '(' && (c == '+' || c == '-'))
            {
                merge();
                optr.push(c);
            }
            else
            {
                if (c == '/' || c == '*') {
                    while (check() && (optr.top() == '*' || optr.top() == '/')) merge();
                }
                optr.push(c);
            }
        }
    }
    while (check() && optr.top() != '(')
    {
        merge();
    }
    cout << opnd.top();
    return 0;
}
/*
(1+3*4*5+2+2)
*/