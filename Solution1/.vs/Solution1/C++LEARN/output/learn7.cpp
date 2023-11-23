#include <iostream>
#include <cstdlib>
using namespace std;
/*

    函数指针:
    void (*ptr)(void); --ptr 为函数指针，而此函数本身无返回值与参数
    int (*ptr)(int);   --  本身返回整数值，并接受整数参数
    char* (*ptr)(char*); --本身返回字符指针，并接受字符指针作为参数

    int *ptr(int);   -- ptr函数原型声明，可返回整形指针，可接受整数参数
    char* ptr(char*);  -- 函数原型声明，可返回字符指针，可接受字符指针参数
*/
void print_word1(char *);//函数原型声明
void print_word2(char *);
int main()
{
    void (*ptr)(char *);//函数指针声明
    ptr = print_word1;//将print_word1的内存地址赋值给ptr指针
    ptr("hello");
    cout << "---------------------" << endl;
    ptr = print_word2;
    ptr("Good bye!");
    system("pause");
    return 0;
}
void print_word1(char *str)
{
    cout << "printf_word1函数" << endl;
    cout << str << endl;
}

void print_word2(char *str)
{
    cout << "printf_word2函数" << endl;
    cout << str << endl;
}