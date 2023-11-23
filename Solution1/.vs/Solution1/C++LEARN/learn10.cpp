#include <iostream>
#include <cstdlib>
using namespace std;
/*
    main()函数参数的传递
    int main(int argc,char *argv[])
    argc : 表示命令行参数的个数。
    argv : 为不定长度的字符串指针数组，传递的数据都为字符串格式
*/
int main(int argc, char *argv[])
{
    int i;
    if (argc == 1)
        cout << "未指定参数!" << endl;
    else
    {
        cout << "所输入的参数为:" << endl;
        for (int i = 0; i < argc; i++)
        {
            cout << argv[i] << endl;
        }
    }
    system("pause");
    return 0;
}