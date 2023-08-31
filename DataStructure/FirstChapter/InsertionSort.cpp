#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> &a)
{
    int len = a.size();

    for (int i = 1; i < len; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main()
{
    vector<int> data = {5, 2, 4, 6, 1, 3};
    insertSort(data);

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}
