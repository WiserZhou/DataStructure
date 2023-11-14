#include "..\header\String.h"
#define MAX_LEN 255                         // 用户可在255以内定义最大串长
typedef unsigned char SString[MAX_LEN + 1]; // 0号单元存放串的长度

typedef struct
{

    char *ch;
    // 若是非空串，则按串长分配存储区，
    // 否则ch为NULL
    int length;
    // 串长度
} HString;

#define CHUNK_SIZE 80

// 若使用链表的话，char占8位，指针占32位，实际利用的只有8位，利用率8/(32+8) = 20%，过低，所以要扩大char的空间，变成块链
typedef struct Chunk
{ // 结点结构
    char ch[CHUNK_SIZE];
    struct Chunk *next;
} Chunk;
typedef struct
{                       // 串的链表结构
    Chunk *head, *tail; // 串的头和尾指针
    int cur_len;        // 串的当前长度
} LString;

/**
 * 若主串S中存在和串T值相同的子串返回它在主串S中第pos个字符之后第一次出现的位置；否则函数值为0。
 * 串S和T存在，T是非空串，1≤pos≤StrLength(S)。
 */
int Index(SString S, SString T, int pos)
{
    int i = pos;
    int j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        } // 继续比较后继字符
        else
        {
            i = i - j + 2; // i-j是i与j的差值，再+1就是i当前的位置，再+1就是下一个位置，由j_now - j_start == T[0] == i_now - i_start，得i_now - j_now == i_start - j_start
            // == i_start -1 ，此时i-j+2 == i_start -1 +2 == i_start + 1
            j = 1;
        } // 指针后退重新开始匹配
    }

    if (j > T[0])        // 如果j超过了T[0]，那么说明字符串T已经匹配完全
        return i - T[0]; // T[0]就是j此时与开始的差值，同时也是i此时与开始的时候位置的差值，j_now - j_start == T[0] == i_now - i_start ，i_now - T[0] == i_start
    else
        return 0;

} // Index

int Index_KMP(SString S, SString T, int pos)
{
    int next[T[0]]{};
    get_next(T, next);

    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0])
        if (j == 0 || S[i] == T[j]) // 当j=0的时候表示第一次匹配j==1就不相同，那么只能让i向后移一位
        {
            i++;
            j++;
        }
        else if (j == 1) // 分出来的j==1的情况，此时第一个位置的字符就不相同，巧妙的使用next数组置为0，也可以让i后移
        {
            i++;
        }
        else
            j = next[j]; // i不变,j后退
    if (j > T[0])
        return i - T[0]; // 匹配成功
    else
        return 0; // 返回不匹配标志
}
/**
 * 代码中if的含义就是在next[j]=k的情况下,如果T[j]==T[k],则next[j+1]=k+1或者k=0时，让next[j+1]=1，表示j>1时候不存在相同的最
 * 长前后缀串即++k后k=1即next公式的其他情况
 * 初值j=1，k=0：表示一开始就匹配不上，是迭代计算next值的基础。
 */
void get_next(SString T, int next[])
{
    int j = 1, k = 0;
    next[1] = 0;
    while (j < T[0])
    {
        if (k == 0 || T[j] == T[k])
        {
            ++j;
            ++k;
            next[j] = k;
        } /*next[++j]=++k*/
        else
            k = next[k]; /*T[j]≠T[k]时，k跳转到next[k]*/
    }
}