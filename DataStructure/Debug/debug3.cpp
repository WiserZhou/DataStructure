#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef struct MGraph
{
    int arc[7][7];
    char vertex[7];
    int vexNum, arcNum;
} MGraph;

void DFS(MGraph G, int v, bool visit[])
{
    visit[v] = true;
    cout << G.vertex[v] << endl;
    for (int i = 1; i <= G.vexNum; i++)
    {
        if (!visit[i] && G.arc[v][i] != INT32_MAX)
        {
            DFS(G, i, visit);
        }
    }
}
int Num(MGraph G)
{
    vector<bool> visit(G.vexNum + 1, false);
    int num = 0;
    for (int i = 1; i <= G.vexNum; i++)
    {
        if (!visit[i])
        {
            num++;
            DFS(G, i, visit);
        }
    }
    return num;
}
typedef char InfoType;
#include "../header/unity.h"
#define MAXSIZE 1000 // 待排顺序表最大长度
typedef int KeyType; // 关键字类型为整数类型
typedef struct
{
    KeyType key;    // 关键字项
    InfoType *info; // 其它数据项
} RcdType;          // 记录类型 Record Type

typedef struct
{
    RcdType r[MAXSIZE + 1];
    InfoType *info;
    int length;
} HeapType;

void HeapAdjust(HeapType &H, int s, int m)
{
    RcdType rc = H.r[s];
    for (int j = 2 * s; j <= m; j *= s)
    {
        if (j + 1 <= m && H.r[j].key < H.r[j + 1].key)
            j++;
        if (rc.key >= H.r[j].key)
            break;
        H.r[s] = H.r[j];
        s = j;
    }
    H.r[s] = rc;
}

void HeapSort(HeapType &H)
{
    for (int i = H.length / 2; i >= 1; i--)
    {
        HeapAdjust(H, i, H.length);
    }
    for (int i = H.length; i > 1; i--)
    {
        swap(H.r[1], H.r[i]);
        HeapAdjust(H, 1, i - 1);
    }
}

typedef char InfoType;
#include "../header/unity.h"
#define MAXSIZE 1000 // 待排顺序表最大长度
typedef int KeyType; // 关键字类型为整数类型
typedef struct
{
    KeyType key;    // 关键字项
    InfoType *info; // 其它数据项
} RcdType;          // 记录类型 Record Type
typedef struct
{
    RcdType r[MAXSIZE + 1]; // r[0]闲置
    int length;             // 顺序表长度
} SqList;                   // 顺序表类型

void Merge(SqList &L, int s, int m, int e)
{
    SqList M;
    int index1 = s;
    int index2 = m + 1;
    int mix = s;
    while (index1 <= m && index2 <= e)
    {
        if (L.r[index1].key <= L.r[index2].key)
            M.r[mix++] = L.r[index1++];
        else
            M.r[mix++] = L.r[index2++]
    }
    while (index1 <= m)
        M.r[mix++] = L.r[index1++];
    while (index2 <= e)
        M.r[mix++] = L.r[index2++];

    mix = s;
    while (s <= e)
        L.r[s++] = M.r[mix++];
}

void MergeSort(SqList &L, int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        MergeSort(L, s, mid);
        MergeSort(L, mid, e);
        Merge(L, s, mid, e);
    }
}
void Merge_K(SqList &L, int l)
{
    int i = 1;
    while (i + 2 * l - 1 <= L.length)
    {
        Merge(L, i, i + l - 1, i + 2 * l - 1);
        i += 2 * l;
    }
    if (i + l - 1 <= L.length)
    {
        Merge(L, i, i + l - 1, L.length);
    }
    else
    {
        while (i <= L.length)
        {
            Merge(L, i, L.length, L.length);
        }
    }
}

void MergeSortK(SqList &L, int s, int e)
{
    int l = 1;
    while (l < L.length)
    {
        Merge_K(L, l);
        l *= 2;
    }
}

void InsertSort(SqList &L)
{
    for (int i = 2; i <= L.length; i++)
    {
        if (L.r[i].key < L.r[i - 1])
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[i - 1];
            int j = i - 2;
            while (L.r[j].key > L.r[0].key)
            {
                L.r[j + 1] = L.r[j];
                j--;
            }
            L.r[j + 1] = L.r[0];
        }
    }
}

void Shell_delta(SqList &L, int dk)
{
    for (int i = 1 + dk; i <= L.length; i++)
    {
        if (L.r[i].key < L.r[i - dk])
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[i - dk];
            int j = i - 2 * dk;
            while (L.r[0].key < L.r[j].key && j > 0)
            {
                L.r[j + dk] = L.r[j];
                j -= dk;
            }
            L.r[j + dk] = L.r[0];
        }
    }
}

void Shell(SqList &L, int delta[])
{
    for (int i = 0; i < n; i++)
    {
        Shell_delta(L, delta[i]);
    }
}

void BiInsertSort(SqList &L)
{
    for (int i = 2; i <= L.length; i++)
    {
        if (L.r[i].key < L.r[i - 1].key)
        {
            L.r[0] = L.r[i];
            int left = 1;
            int right = i - 1;

            while (left <= right)
            {
                int mid = (left + right) / 2;

                if (L.r[0].key < L.r[mid].key)
                {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            for (int j = i - 1; j >= right + 1; j--)
                L.r[j + 1] = L.r[j];
            L.r[right + 1] = L.r[0];
        }
    }
}