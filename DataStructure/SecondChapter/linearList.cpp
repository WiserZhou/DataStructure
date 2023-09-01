/**
 * 顺序存储结构的线性表
 * */
#include <cstdio>
#define MAX_SIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType; // Elem可以是任何类型的数据，这里以int为例子

typedef struct
{
    ElemType data[MAX_SIZE];
    int length;
} SqList, *SqListPtr;
/**
 * 初始化线性表
 * */
Status initSqList(SqListPtr L)
{
    L->length = 0;
    return OK;
}
/**
 * 销毁线性表
 */
Status destroyList()
{
}
/**
 * 判断线性表是否为空
 * */
Status ListSqListEmpty(SqList L)
{
    if (L.length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/**
 * 使线性表L为空表
 * */
Status ClearSqList(SqListPtr L)
{
    L->length = 0;
    return OK;
}
/**
 * 获取线性表L的长度
 * */
int SqListLength(SqList L)
{
    return L.length;
}
/**
 * 一个一个找罢了
 * 顺序存储结构的线性表的获取元素操作 时间复杂度为O(1) 用e返回其值
 * */
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}
/**
 * 返回线性表L中第一个与e相等的元素的位置，若找不到，返回0
 * */
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        { // 这里以int为例子 就直接进行比较了
            return i + 1;
        }
    }
    return 0;
}
/**
 * 就像排队一样，插了一个人进来其他人就要往后挪
 * 在L的第i个元素之前插入数据元素e，L的长度加1
 * */
Status SqListInsert(SqListPtr L, int i, ElemType e)
{
    if (L->length == MAX_SIZE || i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    if (i <= L->length)
    { // 如果不是插入到最后一个位置，插入数据的位置后的数据往后挪
        for (int k = L->length - 1; k >= i - 1; k--)
        {
            L->data[k + 1] = L->data[k + 1];
        }
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}
/**
 * 删除L的第i个元素，并用e返回删除的元素，L的长度减1
 * */
Status SqListDelete(SqListPtr L, int i, ElemType *e)
{
    if (L->length == 0 || i < 1 || i > L->length)
    {
        return ERROR;
    }
    *e = L->data[i - 1];
    if (i < L->length)
    { // 如果删除的不是最后一个位置，删除数据的位置后的数据往前挪
        for (int k = i; k < L->length; k++)
        {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--; // 并不是不用真正意义上的删除，那个数据还存在，后面可能会被覆盖罢了
    return OK;
}
/**
 * 合并线性表并且除去相同元素
 * */
void UnionSqList(SqListPtr La, SqList Lb)
{
    int la_len = SqListLength(*La);
    int lb_len = SqListLength(Lb);
    ElemType e;
    for (int i = 0; i < lb_len; i++)
    {
        GetElem(Lb, i + 1, &e);
        if (!LocateElem(*La, e))
        {
            SqListInsert(La, ++la_len, e);
        }
    }
}
int main(int argc, char const **argv)
{
    SqList La, Lb;
    ElemType e;
    for (int i = 0; i < 10; i++)
    {
        SqListInsert(&La, i + 1, i + 1);
        SqListInsert(&Lb, i + 1, i + 11);
    }
    UnionSqList(&La, Lb);
    SqListDelete(&La, 20, &e);
    printf("%d\n", e);
    int la_len = SqListLength(La);
    for (int i = 0; i < la_len; i++)
    {
        GetElem(La, i + 1, &e);
        printf("%d ", e);
    }
    return 0;
}
