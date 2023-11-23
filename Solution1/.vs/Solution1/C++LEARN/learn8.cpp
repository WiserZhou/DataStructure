#include <iostream>
#include <cstdlib>
using namespace std;
class A
{
public:
    int a1, a2;
    A()
    {
        a1 = 0;
        a2 = 0;
    }
    A(int aa1, int aa2)
    {
        a1 = aa1;
        a2 = aa2;
    }
    int add()
    {
        return a1 + a2;
    }
};
int main()
{
    A a;
    cin >> a.a1;
    cin >> a.a2;
    cout << "sum=" << a.add() << endl;
    return 0;
}
