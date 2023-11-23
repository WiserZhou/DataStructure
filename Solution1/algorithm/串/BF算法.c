

// BF算法（串模式匹配算法）
// http://c.biancheng.net/view/3364.html
#include <stdio.h>
#include <string.h>
// 串普通模式匹配算法的实现函数，其中 B是伪主串，A是伪子串
int mate(char *B, char *A)
{
    unsigned int i = 0, j = 0;
    while (i < strlen(B) && j < strlen(A))
    {
        if (B[i] == A[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    // 跳出循环有两种可能，i=strlen(B)说明已经遍历完主串，匹配失败；j=strlen(A),说明子串遍历完成，在主串中成功匹配
    if (j == strlen(A))
    {
        return i - strlen(A) + 1;
    }
    // 运行到此，为i==strlen(B)的情况
    return 0;
}
int main()
{
    int number = mate("ababcabcacbab", "abcac");
    printf("%d", number);
    return 0;
}