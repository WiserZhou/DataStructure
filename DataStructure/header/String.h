#include <cstring>
#include <iostream>

const int MAX_LEN = 255;
using String = unsigned char[MAX_LEN + 1];

/**
 * 从位置pos开始复制，如果超过了空间，就会截断
 */
bool copy(String &str1, int pos, const String &str2)
{
    int len1 = (int)str1[0];
    int len2 = (int)str2[0];
    int i;
    int pos2 = 1;
    for (i = pos; i < pos + len2 && i <= MAX_LEN; i++)
    {
        str1[i] = str2[pos2++];
    }
    if (i > MAX_LEN)
    {
        len1 += i - pos;
        str1[0] = len1;
        return false;
    }
    len1 += len2;
    str1[0] = len1;
    return true;
}
// 将str1和str2连接到str3上
/**
 * 返回0表示第一个拼接就出现了问题，
 * 返回1表示第二个拼接出了问题，
 * 返回2表示都没有发生截断
 */
int concat(const String &str1, const String &str2, String &str3, int pos)
{
    int len1 = (int)str1[0];
    // int len2 = (int)str2[0];
    int flag = 0;
    memset(str3, 0, sizeof(str3));
    if (copy(str3, pos, str1))
        flag = 1;
    else
        return flag;
    if (copy(str3, pos + len1, str2))
        flag = 2;
    else
        return flag;
    return flag;
}

// 求得str2的pos位置开始len长的子字符串
bool subString(String &str1, const String &str2, int pos, int len)
{
    // int len1 = (int)str1[0];
    int len2 = (int)str2[0];
    if (pos < 1 || pos > len2 || len < 0 || len > len2 - pos + 1)
        return false;
    for (int i = 0; i < len; i++)
        str1[i + 1] = str2[pos + i];
    str1[0] = len;
    return true;
}

typedef struct
{
    char *ch;
    int length;
} HString;
#define OVERFLOW -2
/**
 * 在这里不存在索引0的位置储存长度
 * pos表示的是从1开始的位置
 */
bool insertString(HString &S, int pos, HString T)
{
    if (pos < 1 || pos > S.length + 1)
        return false;
    if (T.length)
    {
        if (!(S.ch == (char *)realloc(S.ch, (S.length + T.length) * sizeof(char))))
            exit(OVERFLOW);
        for (int i = S.length - 1; i >= pos - 1; --i)      // 将pos-1位置开始的整个所有的顺序元素都往后进行挪动
            S.ch[i + T.length] = S.ch[i];                  // 挪动位置为+T.length
        for (int i = pos - 1; i < pos + T.length - 1; i++) // 从pos-1的位置开始赋值
            S.ch[i] = T.ch[i - pos + 1];
        S.length += T.length;
    }
    return true;
}

// 将chars的内容赋值到T中
bool assignString(HString &T, char *chars)
{
    if (T.ch)
        free(T.ch);
    int i;
    for (i = 0; chars[i] != '\0'; ++i) // 得到chars的长度
        ;
    if (!i)
    {
        T.ch = nullptr;
        T.length = 0;
    }
    else
    {
        if (!(T.ch = (char *)malloc(sizeof(char) * i)))
            exit(OVERFLOW);
        for (int j = 0; j < i; j++)
        {
            T.ch[j] = chars[j];
        }
        T.length = i;
    }
    return true;
}

int lengthString(HString S)
{
    return S.length;
}

// 比较两个字符串的大小
int compareString(HString S, HString T)
{
    for (int i = 0; i < S.length && i < T.length; i++)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;
}

// 清空
bool clearString(HString &S)
{
    if (S.ch)
    {
        free(S.ch);
        S.ch = nullptr;
    }
    S.length = 0;
    return true;
}

// 串的块链储存，Chunk表示每一个块，LString表示一条链
#define CHUNKSIZE 80
typedef struct Chunk
{
    char ch[CHUNKSIZE];
    struct Chunk *next;
} Chunk;

typedef struct
{
    Chunk *head, *tail;
    int cur_len;
} LString;

/**
 * 从S的pos位置开始寻找和T相同的字符串
 * 如果匹配成功，就返回匹配成功的初始位置，否则，返回0
 */
int index(String S, String T, int pos)
{
    int i = pos;
    int j = 1;
    while (i <= S[0] && j <= T[0]) // 在正常范围内的值都要+1，超出范围的值都不必+1
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2; // i-j+1是匹配开始的位置，再+1就是下一个位置
            j = 1;
        }
    }
    if (j > T[0])
        return i - T[0]; // 此时i刚好多1，正好减去T[0]就是想要的结果
    else
        return 0;
}

#include <string>
#include <vector>

void computeNext(const std::string &T, std::vector<int> &next)
{
    int m = T.length(); // 计算模式串 T 的长度 m
    int i = 0;          // 初始化 i 为 0
    int j = -1;         // 初始化 j 为 -1，表示不存在前缀和后缀相等的情况
    next[0] = -1;       // next 数组的第 0 个元素赋值为 -1

    while (i < m - 1) // 循环处理 next 数组的第 1 个到第 m - 1 个元素
    {
        if (j == -1 || T[i] == T[j]) // 如果前缀和后缀相等
        {
            ++i; // i 和 j 同时前进一步
            ++j;
            next[i] = j; // 设置 next 数组的当前位置为 j
        }
        else // 如果不相等
        {
            j = next[j]; // 将 j 指向 next[j]，即从前缀的最长匹配位置开始重新匹配
        }
    }
}
void computeNext_prior(const std::string &T, std::vector<int> &next)
{
    int m = T.length(); // 获取模式串 T 的长度
    int i = 0;          // 初始化 i 变量为 0
    int j = -1;         // 初始化 j 变量为 -1，表示当前还没有匹配到任何字符
    next[0] = -1;       // 将 next[0] 设为 -1，方便后面计算

    while (i < m - 1) // 循环条件为 i 小于 m - 1，因为 next[m-1] 已经在上一步初始化为 -1 了
    {
        if (j == -1 || T[i] == T[j]) // 如果 j 已经为 -1 或者当前位置的字符和 j 所指的字符相同，则更新 next 数组
        {
            ++i;              // 继续向后匹配模式串
            ++j;              // j 向后移动一位，表示当前匹配到了 j 所指的字符
            if (T[i] != T[j]) // 如果当前位置的字符和 j 所指的字符不同，说明需要更新 next 数组
            {
                // std::cout << "!=" << i << j << std::endl;
                next[i] = j;
            } // 直接将当前位置的 next 值设为 j，表示接下来可以跳过前面已经匹配成功的 j 个字符
            else
            {
                // std::cout << "==" << i << j << std::endl;
                next[i] = next[j]; // 如果是因为相等得到的 next 值，那么直接回溯到之前的 next 值
            }
        }
        else // 如果当前位置的字符和 j 所指的字符不同，则回溯 j 指向的字符的 next 值
        {
            // std::cout << "!!=" << i << j << std::endl;
            j = next[j];
        }
    }
}
#include <iostream>
int index_KMP_string(const std::string &S, const std::string &T, int pos = 0)
{
    int m = T.length(); // 获取模式串 T 的长度
    int n = S.length(); // 获取主串 S 的长度

    if (m == 0)
        return 0; // 如果模式串为空，则直接返回 0

    std::vector<int> next(m);   // 创建一个大小为 m 的整型向量 next，用于存储 next 数组
    computeNext_prior(T, next); // 调用 computeNext 函数计算模式串 T 的 next 数组，并将结果存储在 next 向量中

    // for (int k = 0; k < m; k++)
    // {
    //     std::cout << "next+" << k << ":  " << next[k] << std::endl;
    // }

    int i = pos; // 初始化主串的索引 i，起始位置为 pos
    int j = 0;   // 初始化模式串的索引 j，初始值为 0

    while (i < n && j < m)
    {
        if (j == -1 || S[i] == T[j])
        {
            ++i; // 如果模式串的第一个字符就不匹配（j==-1），或者当前主串字符与模式串字符相等，则主串和模式串同时向后移动一位
            ++j;
        }
        else
            j = next[j]; // 如果当前主串字符与模式串字符不匹配，则根据 next 数组移动模式串索引
    }

    if (j == m)
        return i - m; // 如果模式串索引 j 等于模式串长度 m，表示找到了完全匹配的子串，返回子串在主串中的起始位置

    return -1; // 未找到匹配的子串，返回 -1
}