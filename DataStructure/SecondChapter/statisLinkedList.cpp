#include "..\header\unity.h"
typedef int ElemType;

#define MAXSIZE 100
typedef struct
{
    ElemType data;
    int next;
} SLinkList[MAXSIZE];

void initSLinkList(SLinkList L)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        L[i].next = i + 1;
    }
    L[MAXSIZE - 1].next = 0;
}

// 上述代码会将L数组中所有元素的next值初始化为它们的下一个元素的下标，并将最后一个元素的next值设置为0，表示链表尾部。

int insertElem(SLinkList L, ElemType e, int pos)
{
    int i, j, k;
    k = MAXSIZE - 1; // 找到空闲节点的下标
    if (k == 0 || pos < 1)
        return 0; // 链表已满或插入位置无效
    for (i = 1; i < pos && k != 0; i++)
    {
        k = L[k].next; // 查找要插入位置的前驱节点
    }
    if (k == 0)
        return 0;  // 插入位置无效
    j = L[k].next; // 获取要插入位置的原节点下标
    L[k].next = k; // 插入新节点
    L[k].data = e;
    L[k].next = j;
    return 1;
}

// 上述代码会在指定位置（pos）插入新元素（e），如果插入位置无效或链表已满，则返回0，插入成功返回1。

int deleteElem(SLinkList L, int pos)
{
    int i, j, k;
    if (pos < 1 || pos >= MAXSIZE)
        return 0;    // 删除位置无效
    k = MAXSIZE - 1; // 找到尾节点下标
    for (i = 1; i < pos && k != 0; i++)
    {
        k = L[k].next; // 查找要删除节点的前驱节点
    }
    if (k == 0 || L[k].next == 0)
        return 0;          // 删除位置无效
    j = L[k].next;         // 获取要删除节点的下一个节点
    L[k].next = L[j].next; // 删除节点
    L[j].next = 0;
    return 1;
}

// 上述代码会删除指定位置（pos）的元素，如果删除位置无效，则返回0，删除成功返回1。

int searchElem(SLinkList L, ElemType e)
{
    int i = L[MAXSIZE - 1].next;
    while (i != 0 && L[i].data != e)
    {
        i = L[i].next;
    }
    return i;
}

// 上述代码会遍历整个静态链表，查找值为e的元素，如果找到则返回元素在L数组中的下标，否则返回0。