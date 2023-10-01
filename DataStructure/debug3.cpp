#include ".\header\String.h"
using namespace std;
int main()
{
    String str1;
    str1[0] = 2;
    str1[1] = 'a';
    str1[2] = 'b';

    String str2;
    str2[0] = 1;
    str2[1] = 'a';

    String str3;

    int flag = concat(str1, str2, str3);
    if (flag == 0)
    {
        std::cout << "Concatenation failed." << std::endl;
    }
    else
    {
        std::cout << "flag: " << flag << endl;
        std::cout << "Concatenation succeeded." << std::endl;
        std::cout << "Length: " << int(str3[0]) << std::endl;
        for (int i = 1; i <= str3[0]; i++)
        {
            std::cout << str3[i] << std::endl;
        }
    }

    return 0;
}