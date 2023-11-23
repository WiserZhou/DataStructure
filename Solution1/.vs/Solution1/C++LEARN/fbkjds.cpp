#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);    // 从键盘输入一行字符串
    int num_start = -1; // 记录数字子串的起始位置
    int num_end = -1;   // 记录数字子串的终止位置
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        { // 如果当前字符为数字
            if (num_start == -1)
            { // 如果还未开始记录数字子串，更新起始位置
                num_start = i;
            }
        }
        else
        { // 如果当前字符不是数字
            if (num_start != -1)
            { // 如果正在记录数字子串，更新终止位置
                num_end = i - 1;
                break; // 找到第一个数字子串，结束循环
            }
        }
    }
    if (num_start == -1)
    { // 如果没有找到数字子串
        cout << "no number found." << endl;
    }
    else
    {
        string num_str = s.substr(num_start, num_end - num_start + 1); // 取出数字子串
        int num = stoi(num_str) + 100;                                 // 将其转化为整数并加上100
        cout << num << endl;
    }
    return 0;
}