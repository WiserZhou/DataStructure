#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
    endl是用来 完成换行并刷新缓冲区的

    flush是用来 直接刷新缓冲区的

    cout << unitbuf// 这里unitbuf 不执行任何动作，而是设置这个cout输出流 在接下来的每次操作之后都进行刷新缓冲区

    cout << nounitbuf// 这里nounitbuf则是让cout 回到正常的缓冲方式

    ends:
    C++STL官方对std::ends的解释是：“此操纵符典型地为 std::ostrstream
    在关联输出缓冲区需要为空终止，以作为 C 字符串处理时使用。
    不同于 std::endl ，此操纵符不冲入流。”也就是说ends不会立马刷新缓冲区，其作用是输出一个字符串 和一个空字符
*/
int main()
{
    // cout << "hhhha" << endl; //输出一个字符串 然后 再换行 刷新缓冲区
    // cout << "hhhhb" << flush; //输出一个字符串 然后 直接刷新缓冲区
    // cout << "hhhhc" << ends; //输出一个字符串 和一个空字符 不会立马刷新缓冲区
    // cout << unitbuf; // 这样的话 设置 cout 接下来的操作都进行一次刷新缓冲区
    // cout << "hhhd";  // 这里会刷新缓冲区
    // cout << nounitbuf; //这里则让cout回到正常的缓冲方式

    ofstream out_file("test.txt", ofstream::trunc); // 这里创建一个文件用来输出写入，以trunc的方式打开，每次打开都会清空文件里的数据
    for (size_t i = 0; i != 5; ++i)
    {
        string t;
        cin >> t;
        // out_file <<t;  //这里并没有设置什么操纵符来刷新缓冲区
        out_file << t << endl;  //这里用到endl 换行并且刷新存入缓冲区里的数据 真正的写入 
        // out_file << t <<flush; //flush 刷新缓冲区 没有换行 文本就显示一行
         //out_file << t << ends;  //ends 的输出再加上空字符也就是 一个空格 ，但不是立马输出的。
    }
    return 0;
}