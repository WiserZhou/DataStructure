#include <iostream>
#include <vector>
using namespace std;
#define LIST_INIT_SIZE 100
#define OVERFLOW 1
#define ERROR 0
#define LIST_INCREMENT 10
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
/**
 * create the new struct SqList
 */
typedef struct
{
    ElemType *elem;
    int length;
    int listSize;
} SqlList;
/**
 * init Sq_List
 */
Status InitList_Sq(SqlList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return OK;
}
/**
 * destroy the list
 */
Status DestroyList(SqlList &L)
{
    free(L.elem);
    return OK;
}
/**
 * judge the list is or not empty
 */
Status ListEmpty(SqlList L)
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}
/**
 * return the length of the list
 */
Status ListLength(SqlList L)
{
    return L.length;
}
/**
 * get the value of the prior element
 */
Status PriorElem(SqlList L, int cur_e, ElemType &pre_e)
{
    if (cur_e <= 0 || L.length == 0 || cur_e > L.length)
        return ERROR;
    else
        pre_e = L.elem[cur_e - 1]; // 直接用引用设置pre的值
}
/**
 * insert the element at the specified location
 */
Status ListInsert(SqlList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1) // 如果是在length+1的位置的话，就相当于在最后追加一个元素，这是允许的。
        return ERROR;
    if (L.length >= L.listSize)
    {
        ElemType *newBase = (ElemType *)realloc(L.elem, (L.listSize + LIST_INCREMENT) * sizeof(ElemType)); // 重新设置动态数组的
        // 空间，第一个参数是指针对象，第二个参数是重新设置的数组的空间。
        if (!newBase)
            exit(OVERFLOW);
        L.elem = newBase;
        L.listSize += LIST_INCREMENT;
    }
    ElemType *q = &(L.elem[i - 1]);
    for (ElemType *p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;
    // 整体后移，算法的时间复杂度跟移动的元素有关，复杂度为O(n)，

    *q = e;     // 设置所希望的位置的值为传入值
    ++L.length; // 加长
    return OK;
}
Status listDelete(SqlList &L, int i, ElemType &e)
{
    if ((i < 1) || (i > L.length))
        return ERROR;
    ElemType *p = &(L.elem[i - 1]);
    e = *p;
    ElemType *q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    --L.length;
    return OK;
}
/**
 * 确定元素的位置
 */
Status locateElem(SqlList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
}
/**
 * 顺序表的合并
 */
void MergeList(SqlList La, SqlList Lb, SqlList &Lc)
{
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    Lc.listSize = Lc.length = La.length + Lb.length;
    ElemType *pc = Lc.elem = (ElemType *)malloc(Lc.listSize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW);
    ElemType *pa_last = La.elem + La.length - 1;
    ElemType *pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last)
    {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while (pa <= pa_last)
        *pc++ = *pa++;
    while (pb <= pb_last)
        *pc++ = *pb++;
}
void Union(SqlList &La, SqlList Lb)
{
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
    for (int i = 0; i < Lb_len; i++)
    {
        GetElem(Lb, i, e);
        if (!locateElem(La, e, equal))
            ListInsert(La, ++La_len, e);
    }
}
int main()
{
    SqlList list;
    InitList_Sq(list);
    cout << list.length << endl;
    cout << ListInsert(list, 1, 2) << endl;
    cout << list.elem[0] << endl;
    return 0;
}