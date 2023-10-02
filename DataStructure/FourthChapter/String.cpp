// #include "..\header\unity.h"
#include "..\header\String.h"



// #include <cstring>
// #define MAX_LEN 255 // 规定串的长度
// using SString = unsigned char[MAX_LEN + 1];
// typedef struct
// {
//     char *ch;
//     int length;
// } HString; // 堆储存

// #define CHUNKSIZE 80
// typedef struct Chunk
// {
//     char ch[CHUNKSIZE];
//     struct Chunk *next;
// } Chunk;

// typedef struct
// {
//     Chunk *head, *tail;
//     int cur_len;
// } LString;
// // 串的块链储存

// int index(SString S, SString T, int pos)
// {
//     int i = pos;
//     int j = 1;
//     while (i <= S[0] && j <= T[0])
//     {
//         if (S[i] == T[j])
//         {
//             i++;
//             j++;
//         }
//         else
//         {
//             i = i - j + 2; // i-j+1+1，i-j的结果是i的前一个位置，+1得到i的原位置，+1得到i的下一个位置
//             j = 1;
//         }
//     }
//     if (j < T[0])
//         return i - T[0];
//     else
//         return 0;
// }

// void getNext(SString T, int *next)
// {
//     int i = 1;
//     next[1] = 0;
//     int j = 0;
//     while (i < T[0])
//     {
//         if (j == 0 || T[i] == T[j])
//         {
//             ++i;
//             ++j;
//             if (T[i] != T[j])
//                 next[i] = j;
//             else
//                 next[i] = next[j]; // 优化,既然两个位置的前面的值都是一样的，那么相对于i进行比较的效果也是一样的，所以可以直接使用前面的值
//         }
//         else
//             j = next[j];
//     }
// }

// int index_KMP(SString S, SString T, int pos)
// {
//     ofstream outFile("output.txt", ios::app);
//     int next[MAX_LEN] = {};
//     getNext(T, next);
//     for (int i = 1; i <= T[0]; i++)
//     {
//         outFile << next[i] << endl;
//     }
//     outFile.close();
//     int i = pos;
//     int j = 1;
//     while (i <= S[0] && j <= T[0])
//     {
//         if (j == 0 || S[i] == T[j])
//         {
//             ++i;
//             ++j;
//         }
//         else
//             j = next[j];
//     }
//     if (j > T[0])
//         return i - T[0];
//     else
//         return 0;
// }
