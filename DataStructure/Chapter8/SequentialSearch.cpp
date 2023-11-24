#include "search.h"

typedef struct
{
    ElemType *elem; // 数据元素存储空间基址，建表时按实际长度分配
    int length;     // 表的长度
} SSTable;

//倒序，从后往前找，在0的位置存要查找的数据，不必讨论越界问题
int Search_Seq(SSTable ST, KeyType key)
{
    // 在顺序表ST中顺序查找其关键字等于key的数据元素。
    // 若找到，则函数值为该元素在表中的位置，否则为0。
    ST.elem[0].key = key; // 设置哨兵
    int i;
    for (i = ST.length; ST.elem[i].key != key; --i)
        ;
    // 从后往前找
    return i; // 找不到时，i为0
} // Search_Seq
