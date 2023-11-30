

// 串的定长顺序存储结构，可以简单地理解为采用 "固定长度的顺序存储结构" 来存储字符串，因此限定了其底层实现只能使用静态数组。
// 使用定长顺序存储结构存储字符串时，需结合目标字符串的长度，预先申请足够大的内存空间。

// https://blog.csdn.net/Leeds1993/article/details/60956971
// C语言常用字符串操作函数总结

// 函数名: strncpy
// 功  能: 将字符串src前n个字符拷贝到字符串dest
// 用  法: char *strncpy(char *dest, const char *src, size_t n);
// 返回值: 返回参数dest的字符串起始地址

// void *memcpy(void *dest, const void *src, size_t n);
// 该函数接受三个参数：
// dest：指向目标内存空间的指针，表示复制后数据存放的位置。
//     src：指向源内存空间的指针，表示要被复制的数据所在的位置。
//         n：要复制的字节数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int main()
{
    char str[N];
    char String[N];
    char *str1 = "data.biancheng.net";
    strcpy(str, str1);
    strncpy(String, str, 3);
    String[3] = '\0';
    printf("%s\n", str);
    printf("%s\n", String);
    printf("%s\n", str1);
    // printf("%d",strlen(str1));
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAXSTRLEN 255
// typedef unsigned char Sstring[MAXSTRLEN + 1];

// int main()
// {
//     Sstring str, String;
//     Sstring str1 = "data.biancheng.net";

//     strcpy(str, str1);

//     memcpy(String, str, 3);
//     String[3] = '\0';

//     printf("%s\n", str);
//     printf("%s\n", String);
//     printf("%s\n", str1);

//     return 0;
// }