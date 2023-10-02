#include <vector>
#include <string>
#include <iostream>
// using namespace std;
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

/**
 * S为主串，T为模式串
 */
int index_KMP_string(const std::string &S, const std::string &T, int pos = 0)
{
    int m = T.length(); // 获取模式串 T 的长度
    int n = S.length(); // 获取主串 S 的长度

    if (m == 0)
        return 0; // 如果模式串为空，则直接返回 0

    std::vector<int> next(m); // 创建一个大小为 m 的整型向量 next，用于存储 next 数组
    computeNext(T, next);     // 调用 computeNext 函数计算模式串 T 的 next 数组，并将结果存储在 next 向量中

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

int main()
{
    std::string s1 = "hello";
    std::string s2 = "22hell2o world";
    std::cout << index_KMP_string(s2, s1, 0) << std::endl;
    return 0;
}
