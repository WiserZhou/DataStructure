

//  http://c.biancheng.net/view/3362.html
//  就C 语言来说，程序会将内存分为 4 个区域，分别为堆区、栈区、数据区和代码区
//  堆区的内存空间需要程序员手动使用 malloc 函数申请，并且在不用后要手动通过 free 函数将其释放。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // char *a1 = NULL;
    // char *a2 = NULL;
    // a1 = (char *)malloc(10 * sizeof(char));
    // strcpy(a1, "data.bian"); // 将字符串"data.bian"复制给a1
    // a2 = (char *)malloc(10 * sizeof(char));
    // strcpy(a2, "cheng.net");

    char *a1 = (char *)malloc(100 * sizeof(char));
    printf("Please input a Stirng:");
    scanf("%s", a1);
    char *a2 = (char *)malloc(100 * sizeof(char));
    printf("Please input another Stirng:");
    scanf("%s", a2);
    int lengthA1 = strlen(a1); // a1串的长度
    int lengthA2 = strlen(a2); // a2串的长度
    // 尝试将合并的串存储在 a1 中，如果 a1 空间不够，则用realloc动态申请
    if (lengthA1 < lengthA1 + lengthA2)
    {
        a1 = (char *)realloc(a1, (lengthA1 + lengthA2 + 1) * sizeof(char));
    }
    // 合并两个串到 a1 中
    for (int i = lengthA1; i < lengthA1 + lengthA2; i++)
    {
        a1[i] = a2[i - lengthA1]; // 这个地方的话，就是上循环进行赋值
    }
    // 串的末尾要添加 \0，避免出错
    a1[lengthA1 + lengthA2] = '\0';
    printf("%s", a1);
    // 用完动态数组要立即释放
    free(a1);
    free(a2);
    return 0;
}

// 程序中给 a1 和 a2 赋值时，使用了 strcpy 复制函数。这里不能直接用 a1 ="data.biancheng"，程序编译会出错，
// 报错信息为 "没有 malloc 的空间不能 free"。
// 因为 strcpy 函数是将字符串复制到申请的存储空间中，
// 而直接赋值是字符串存储在别的内存空间（本身是一个常量，放在数据区）中，更改了指针 a1 和 a2 的指向，
// 也就是说，之前动态申请的存储空间虽然申请了，结果还没用呢就丢了。