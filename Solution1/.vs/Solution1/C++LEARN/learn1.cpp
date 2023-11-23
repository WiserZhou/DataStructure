#include <iostream>
#include <string>
using namespace std;
int main()
{

    // cin  1.输入一个数字或字符   2. 接收一个字符串，遇“空格”、“TAB”、“回车”就结束
    /*
    1、cin.getline()实际上有三个参数，cin.getline(接收字符串的变量,接收字符个数,结束字符)
    2、当第三个参数省略时，系统默认为'\0'
    3、如果将例子中cin.getline()改为cin.getline(m,5,'a');当输入jlkjkljkl时输出jklj，输入jkaljkljkl时，输出jk
    */
    // getline() 接收一个字符串，可以接收空格并输出，需包含“#include<string>”
    // cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数
    /*
    当同时使用cin>>,getline()时，需要注意的是，在cin>>输入流完成之后，getline()之前，需要通过

    str="\n";
    getline(cin,str);
    的方式将回车符作为输入流cin以清除缓存，如果不这样做的话，在控制台上就不会出现getline()的输入提示，
    而直接跳过，因为程序默认地将之前的变量作为输入流。
    */
    char m[20];
    cin.getline(m, 5); // 接收5个字符到m中，其中最后一个为'\0'，所以只看到4个字符输出；
    cout << m << endl;
}