#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> &a)
{
    unsigned int len = a.size(); // 将长度改为无符号整数类型

    for (unsigned int i = 1; i < len; i++)
    { // 使用无符号整数类型
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && (unsigned int)a[j] > (unsigned int)key)
        { // 进行类型转换
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

    for (unsigned int i = 0; i < data.size(); i++)
    { // 使用无符号整数类型
        cout << data[i] << " ";
    }

    return 0;
}
