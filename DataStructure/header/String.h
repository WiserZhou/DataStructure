#include <cstring>
#include <iostream>

const int MAX_LEN = 255;
using String = unsigned char[MAX_LEN + 1];

bool copy(String &str1, int pos, const String &str2)
{
    int len1 = (int)str1[0];
    int len2 = (int)str2[0];
    int i;
    int pos2 = 1;
    for (i = pos; i < pos + len2 && i <= MAX_LEN; i++)
    {
        str1[i] = str2[pos2++];
    }
    if (i > MAX_LEN)
    {
        len1 += i - pos;
        str1[0] = len1;
        return false;
    }
    len1 += len2;
    str1[0] = len1;
    return true;
}

int concat(const String &str1, const String &str2, String &str3)
{
    int len1 = str1[0];
    int len2 = str2[0];
    int flag = 0;
    memset(str3, 0, sizeof(str3));
    if (len1 + len2 <= MAX_LEN)
    {
        if (copy(str3, 1, str1))
        {

            flag = 1;
        }
        else
        {
            std::cout << "he";
            return flag;
        }
        if (copy(str3, 1 + len1, str2))
        {
            flag = 2;
        }
        else
        {
            return flag;
        }
    }
    return flag;
}
