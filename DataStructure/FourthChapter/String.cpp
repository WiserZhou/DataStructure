#include "..\header\unity.h"
#include<cstring>
#define MAXSTRLEN 255                // 规定串的长度
typedef char SString[MAXSTRLEN + 1]; // 第0位储存串的长度

typedef struct
{
    char *ch;
    int length;
} HString; // 堆储存

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
// 串的块链储存

int index(SString S, SString T, int pos)
{
    int i = pos;
    int j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2; // i-j+1+1，i-j的结果是i的前一个位置，+1得到i的原位置，+1得到i的下一个位置
            j = 1;
        }
    }
    if (j < T[0])
        return i - T[0];
    else
        return 0;
}

void getNext(SString T, int *next)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int index_KMP(SString S, SString T, int pos)
{
    int next[MAXSTRLEN] = {};
    getNext(T, next);
    int i = pos;
    int j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}
int main()
{
    SString S1;
    SString T;
    strcpy(S1 + 1, "hello world");
    strcpy(T + 1, "world");
    S1[0] = strlen("hello world");
    T[0] = strlen("world");

    cout << index_KMP(S1, T, 1);
}