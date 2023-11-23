#include <stdio.h>
#include <stdlib.h>
#define keytype int
#define maxblock 10
typedef struct
{
    keytype key;
    int addr;
} indextype;
typedef struct
{
    indextype index[maxblock];
    int block;
} INtable;

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

int SEARCH(SSTable ST, INtable IX, keytype key)
{
    int i = 0, s, e;
    while ((key > IX.index[i].key) && (i < IX.block))
        i++;
    if (i < IX.block)
    {
        s = IX.index[i].addr;
        i == IX.block - 1 ? e = ST.length - 1 : e = IX.index[i + 1].addr - 1;
        while (key != ST.elem[s].key && (s <= e))
            s = s + 1;
        if (s <= e)
            return s;
    }
    return -1;
}
int main(){
    printf("Hello哦");
    return 0;
}