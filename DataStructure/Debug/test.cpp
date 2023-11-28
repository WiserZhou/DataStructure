#include <iostream>

using namespace std;

int main()
{

    int a[11] = {5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int left = 0;
    int right = 10;
    int c;
    cin >> c;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (c > a[mid])
            left = mid + 1;
        else if (c < a[mid])
            right = mid - 1;
        else
        {
            cout << "find";
            return 0;
        }
    }
    return 0;
}