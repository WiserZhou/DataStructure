#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> &a)
{
    unsigned int len = a.size(); // �����ȸ�Ϊ�޷�����������

    for (unsigned int i = 1; i < len; i++)
    { // ʹ���޷�����������
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {                    // ��������ת��
            a[j + 1] = a[j]; // ������j������i�����Ըպõ�a[i]��λ�ã����ᵼ�������������ޡ�
            j--;
        }
        // ��Ȼ���ܽ�a[i]���뵽�м䣬���ǿ������������ĸ��Լ���λ�������Լ��Ϳ����൱�ڲ��������ˡ�

        a[j + 1] = key;
    }
}

int main()
{
    vector<int> data = {5, 2, 4, 6, 1, 3};
    insertSort(data);

    for (unsigned int i = 0; i < data.size(); i++) // ʹ��vector���Է���Ĳ�������Ĵ�С��
    {                                              // ʹ���޷�����������
        cout << data[i] << " ";
    }

    return 0;
}
