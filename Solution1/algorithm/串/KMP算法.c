

#include <stdio.h>
#include <string.h>
#define maxsize 100

void Nextval(char T[], int *next)
{
    int lenT = strlen(T);
    int k = -1;   // 前缀
    int j = 0;    // 后缀
    next[0] = -1; // 第一个数组的值是被默认了的，课件是选择的是从零开始，即把零号空间空出来存储串的长度
    while (j < lenT)
    {
        if (k == -1 || T[j] == T[k])
        {
            j++;
            k++;
            // 较之前next数组求法，改动在下面4行
            if (T[j] != T[k])
                next[j] = k; // 之前只有这一行
            else
                next[j] = next[k]; /*为不能出现T[j] = T[next[j]]，所以当出现时连续进行两次回溯，k = next[next[k]]  */
        }
        else
            k = next[k];
    }
}

int KMP(char S[], char T[]) // KMP算法的实现，传入两个数组
{
    int i = 0, j = 0, lenS, lenT;
    lenS = strlen(S);
    lenT = strlen(T);
    int next[maxsize];
    Nextval(T, next); // 先把next数组的各个数值给确定下来
    while (i < lenS && j < lenT)
    {
        if (j == -1 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j]; // 不匹配的话，就按照算出来的next数组进行子串指针的移动
        }
    }
    if (j == lenT)
    {
        printf("Match succeed!\n");
        return i - j; // 返回匹配成功的第一个位置
    }
    else
    {
        printf("Match failed!\n");
        return -1;
    }
}

// 暴力匹配算法，思想简单，但是时间复杂度比较的高
int BF(char S[], char T[])
{
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
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
    if (T[j] == '\0')
        return (i - j);
    else
        return -1;
}

int main()
{
    char S[maxsize], T[maxsize];
    int target;

    scanf("%s", S);
    scanf("%s", T);

    int target1 = BF(S, T);
    target = KMP(S, T);
    printf("Through the KMP the Position is %d\n", target);
    printf("Through the BF the Position is %d\n", target1);
    return 0;
}
