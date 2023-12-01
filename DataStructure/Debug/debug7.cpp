#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        char a;
        cin >> a;
        int b = a - 'A' + 1;
        b = b % 11;
        cout << b << endl;
    }
}
