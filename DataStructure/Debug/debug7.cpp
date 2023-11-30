#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        int a;
        cin >> a;
        a = a % 13;
        cout << a << endl;
    }
}
