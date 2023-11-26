#include <iostream>
using namespace std;

void adjust(int list[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        int index = i;
        for (int j = 2 * i; j <= n; j *= 2)
        {
            if (j + 1 <= n && list[j + 1] > list[j])
                j++;
            if (list[j] > list[i])
                swap(list[j], list[i]);
            else
                break;
            i = j;
        }
        i = index;
    }
}

int main()
{
    int list[6] = {0, 4, 3, 2, 1, 7};
    for (int i = 5; i >= 2; i--)
    {
        adjust(list, i);
        swap(list[1], list[i]);
    }

    for (int c : list)
        cout << c << endl;
}