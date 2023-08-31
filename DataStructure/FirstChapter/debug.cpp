#include <iostream>
using namespace std;
int *insertSort(int data[])
{
    int len = sizeof(data) / sizeof(data[0]);
    for (int j = 2; j <= len; j++)
    {
        int key = data[j];
        int i = j - 1;
        while (i > 0 && data[i] > key)
        {
            data[i + 1] = data[i];
            i = i - 1;
        }
        data[i + 1] = key;
    }
    return data;
}

int main()
{
    int data[] = {5, 2, 3, 6, 1, 3};
    int *p = insertSort(data);
    int len = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < len; i++)
    {
        cout << *(p + i);
    }
    return 0;
}