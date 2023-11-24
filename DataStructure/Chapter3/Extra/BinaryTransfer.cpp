using namespace std;
#include <iostream>
#include <stack>
typedef int ElemType;
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ERROR -2
#define OVERFLOW -1
char transfer(int x)
{
    if (x < 10)
        return x + '0';
    else if (x == 10)
        return 'A';
    else if (x == 11)
        return 'B';
    else if (x == 12)
        return 'C';
    else if (x == 13)
        return 'D';
    else if (x == 14)
        return 'E';
    else
        return 'F';
}
int main()
{
    stack<int> S;
    int a, b;
    scanf("%d%d", &a, &b);
    while (a)
    {
        int e = a % b;
        a /= b;
        S.push(e);
    }
    while (!S.empty())
    {
        printf("%c", transfer(S.top()));
        S.pop();
    }
    return 0;
}