#include <stdio.h>
#include <string.h>

#define MAX_L 1000 // 定义最大字符串长度
#define NUM 100    // 定义最大字符串数量

int main()
{
    int num;
    scanf("%d", &num);  // 输入字符串数量
    int i, max_l = 0;   // 定义循环变量i和最大字符串长度max_l
    char s[NUM][MAX_L]; // 定义字符串数组s，用于存储输入的字符串
    for (i = 0; i < num; i++)
    {
        scanf("%s", s[i]); // 输入字符串，并存入数组s
        int length = strlen(s[i]);
        if (length > max_l)
            max_l = length; // 计算最大字符串长度
    }
    char ans[MAX_L];
    scanf("%s", ans);        // 输入答案字符串
    int a[NUM][MAX_L] = {0}; // 定义二维数组a，用于存储答案字符串与输入字符串相同部分的长度
    // 遍历输入字符串数组，计算相同部分的长度
    for (i = 0; i < num; i++)
    {
        int length = strlen(s[i]);
        for (int j = 0; j < length; j++)
        {
            unsigned int cnt = 0;
            int b;
            for (b = j; cnt < strlen(ans) && b < length; b++)
            {
                if (s[i][b] == ans[cnt])
                {
                    cnt++;
                    a[i][j] = cnt; // 将相同部分的长度存入数组a
                }
                else
                {
                    break;
                }
            }
        }
    }
    int max1 = 0, max2 = 0, max_ans = 0; // 定义最大相同部分长度的字符串下标和位置下标
    // 在数组a中找到最大的相同部分长度及其对应的字符串下标和位置下标
    for (i = 0; i < num; i++)
    {
        for (int j = 0; j < max_l; j++)
        {
            if (a[i][j] > max_ans)
            {
                max_ans = a[i][j];
                max1 = i;
                max2 = j + 1;
            }
        }
    }
    if (max_ans != 0)
    {
        double gd = ((double)max_ans / strlen(ans)) * 100.0; // 计算相同部分的百分比
        printf("%d %d %.2lf%%", max1 + 1, max2, gd);         // 输出结果及相同部分的百分比
    }
    else
    {
        printf("0 0 0.00%%"); // 若没有相同部分，则输出0和0.00%
    }
    return 0; // 程序结束
}