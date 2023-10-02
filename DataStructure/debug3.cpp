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
    return 0;
}
