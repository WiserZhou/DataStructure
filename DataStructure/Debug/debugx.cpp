#include <iostream>
using namespace std;

void set(int *a)
{
    int b = 3;
    int *p = &b;
    a = p;
}
int main()
{
    int a = 2;
    int *n = &a;
    set(n);
    cout << *n;
}