#include <iostream>
using namespace std;
// extern 变量与跨文件的声明

extern int x; // 再此必须加上extern修饰词，不过不会实际分配内存

void foo(void)
{
    x = 1;
}
void print()
{
    cout << "I am the goat!" << endl;
}