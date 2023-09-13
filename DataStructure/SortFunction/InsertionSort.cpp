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

        while (j >= 0 && a[j] > key)
        {                    // 进行类型转换
            a[j + 1] = a[j]; // 在这里j最大就是i，所以刚好到a[i]的位置，不会导致索引超过界限。
            j--;
        }
        // 既然不能将a[i]插入到中间，但是可以让数组后面的给自己让位，这样自己就可以相当于插入其中了。

        a[j + 1] = key;
    }
}

int main()
{
    vector<int> data = {5, 2, 4, 6, 1, 3};
    insertSort(data);

    for (unsigned int i = 0; i < data.size(); i++) // 使用vector可以方便的测量数组的大小。
    {                                              // 使用无符号整数类型
        cout << data[i] << " ";
    }

    return 0;
}
