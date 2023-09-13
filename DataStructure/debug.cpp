#include <bits/stdc++.h>
using namespace std;

void decimalToBinary(int decimalValue)
{
    stack<int> binaryStack;
    while (decimalValue > 0)
    {
        int remainder = decimalValue % 2;
        binaryStack.push(remainder);
        decimalValue /= 2;
    }

    while (!binaryStack.empty())
    {
        cout << binaryStack.top();
        binaryStack.pop();
    }
}
void decimalToOctal(int decimalValue)
{
    stack<int> octalStack;
    while (decimalValue > 0)
    {
        int remainder = decimalValue % 8;
        octalStack.push(remainder);
        decimalValue /= 8;
    }

    while (!octalStack.empty())
    {
        cout << octalStack.top();
        octalStack.pop();
    }
}

void decimalToHexadecimal(int decimalValue)
{
    stack<char> hexStack;
    while (decimalValue > 0)
    {
        int remainder = decimalValue % 16;

        if (remainder < 10)
        {
            hexStack.push(remainder + '0');
        }
        else
        {
            hexStack.push(remainder - 10 + 'A');
        }

        decimalValue /= 16;
    }

    while (!hexStack.empty())
    {
        cout << hexStack.top();
        hexStack.pop();
    }
}

int main()
{
    int decimalValue, base;
    cin >> decimalValue;
    cin >> base;
    if (base == 2)
    {
        decimalToBinary(decimalValue);
    }
    else if (base == 8)
    {
        decimalToOctal(decimalValue);
    }
    else if (base == 16)
    {
        decimalToHexadecimal(decimalValue);
    }

    cout << endl;
    system("pause");
    return 0;
}