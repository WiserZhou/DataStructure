#include <iostream>
using namespace std;
int maxTri(int a, int b, int c)
{
    return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}
int maxSum(int data[], int first, int end)
{
    if (first == end)
        return data[first];
    else
    {
        int sum = 0;
        int mid = (first + end) / 2;
        /**
         * �����з�Ϊ����ұߺ��м����࣬�϶�����һ��֮������������У�����Ŀ������ҵ�����֮�е����ֵ��Ȼ��ÿһ���ٽ��еݹ��ѯ���õ�
         * ��С���������ֵ��Ȼ����кϲ������յõ���ϵ����ֵ��
         * */
<<<<<<< HEAD
        int sumLeft = maxSum(data, first, mid);    // ���1
        int sumRight = maxSum(data, mid + 1, end); // ���2
        //! ע��������������м��ϲ������н������ұߵ��������� mid+1 ��ʼ��
=======

        int sumLeft = maxSum(data, first, mid);    // ���1
        int sumRight = maxSum(data, mid + 1, end); // ���2
        //! ע��������������м��ϲ������н������ұߵ��������� mid+1 ��ʼ��
        

>>>>>>> cd5ff6773acab791dbd21fea97e848fb8e5d8fbc
        // ���3��
        int s1 = 0, lefts = 0;
        for (int i = mid; i >= first; i--)
        {
            lefts += data[i];
            if (lefts > s1)
                s1 = lefts;
        }
        int s2 = 0, rights = 0;
        for (int i = mid + 1; i <= end; i++) // ע�����mid+1����������߷ֿ������ݲ������н���
        {
            rights += data[i];
            if (rights > s2)
                s2 = rights;
        }
        sum = s1 + s2;
        return maxTri(sum, sumLeft, sumRight);
    }
}

int main(int argc, char *argv[])
{
    int data[20] = {0, -20, 11, -4, 13, -5, -2}; // ��0��λ�ò���
    printf("����Ӷκͣ�%d", maxSum(data, 1, 6));
    // system("pause");
    return 0;
}