#include <stdio.h>
#include <stdlib.h>

#define keyType int

typedef struct
{
    keyType key; // 查找表中每个数据元素的值
    // 如果需要，还可以添加其他属性
} ElemType;

typedef struct
{
    ElemType *elem; // 存放查找表中数据元素的数组
    int length;     // 记录查找表中数据的总数量
} SSTable;

// 创建查找表
void Create(SSTable **st, int length)
{
    *st = (SSTable *)malloc(sizeof(SSTable));
    if (!(*st))
    {
        printf("内存分配失败\n");
        exit(1);
    }
    (*st)->length = length;
    (*st)->elem = (ElemType *)malloc((length + 1) * sizeof(ElemType)); // 为数组开辟足够大的元素来进行相关数据的存储
    if (!(*st)->elem)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    printf("输入表中的数据元素：\n");
    for (int i = 1; i <= length; i++)
    {
        scanf("%d", &((*st)->elem[i].key));
    }
}

// 查找表查找的功能函数，其中key为关键字
int Search_seq(SSTable *st, keyType key)
{
    st->elem[0].key = key; // 将关键字作为一个数据元素存放到查找表的第一个位置，起监视哨的作用
    int i = st->length;
    for (; st->elem[i].key != key; --i)
        ;
    return i; // 返回的是含有关键字key的数据元素在查找表中的位置
}

// 释放动态分配的内存
void Destroy(SSTable *st)
{
    free(st->elem);
    free(st);
}

int main()
{
    SSTable *st;
    Create(&st, 6);
    getchar();
    printf("请输入查找数据的关键字：\n");
    int key;
    scanf("%d", &key);
    int location = Search_seq(st, key);
    if (location == 0)
    {
        printf("查找失败\n");
    }
    else
    {
        printf("数据在查找表中的位置为：%d\n", location);
    }
    Destroy(st); // 释放动态分配的内存
    return 0;
}
