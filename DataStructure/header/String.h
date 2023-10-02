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
    int m = T.length();
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < m - 1) // 因为第一个位置已经被标记为-1了，所以接下来只需要循环m-1次即可
    {
        if (j == -1 || T[i] == T[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int index_KMP_string(const std::string &S, const std::string &T, int pos)
{

    int m = T.length();
    int n = S.length();
    if (m == 0)
        return 0;
    std::vector<int> next(m);
    computeNext(T, next);
    int i = pos;
    int j = 0;
    while (i < n && j < m) // 循环的次数都是长度
    {
        if (j == -1 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j == m)
        return i - m;
    else
        return -1;
}
