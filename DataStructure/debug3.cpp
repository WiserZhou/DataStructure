#include <vector>
#include <string>
#include <iostream>
// using namespace std;
#include ".\header\String.h"

/**
 * S为主串，T为模式串
 */

int main()
{
    std::string s1 = "ababab";
    std::string s2 = "22helabababl2o world";
    std::cout << index_KMP_string(s2, s1, 0) << std::endl;

    String s3;
    s3[0] = 2;
    s3[1] = 'a';
    s3[2] = 'b';

    String s4;
    s4[0] = 1;
    s4[1] = 'b';
    std::cout << index_KMP(s3, s4, 1);
    return 0;
}
