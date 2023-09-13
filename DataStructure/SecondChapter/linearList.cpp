
#include "..\header\unity.h"



typedef struct
{
    ElemType *elem;
    int length;
    int listSize;
} SqList;

/**
 * init the sequential list
 */

Status initSqList(SqList &L)
{
    if (L.listSize != 0)
        destroySqList(L);
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.listSize = LIST_INIT_SIZE;
    return OK;
}
/**
 * destroy the sequential list
 */
Status destroySqList(SqList &L)
{
    free(L.elem);
    L.length = 0;
    L.listSize = 0;
    return OK;
}
/**
 * clear the previous data in the SqList
 */
Status clearSqList(SqList &L)
{
    return initSqList(L);
}
/**
 * judge whether the sequential list is empty or not
 */
bool SqListEmpty(SqList L)
{
    if (L.length == 0)
        return true;
    else
        return false;
}
/**
 * get the length of the sequential list
 */
int SqListLength(SqList L)
{
    return L.length;
}
/**
 * get the specified element in the list
 */
Status getElem(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    else
    {
        e = L.elem[i - 1];
        return OK;
    }
}
/**
 * return the element's location in the sequential list
 */
int locateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e)) //  *运算符先获取p指向的内容，然后再执行++，但是++的运算符优先级高于*
        ++i;
    if (i <= L.length)
        return i;
    else
        return NONE;
}
/**
 * write a function to judge the equal properties
 */
Status equal(ElemType a, ElemType b)
{
    if (a == b)
        return true;
    else
        return false;
}
/**
 * get the prior element of someone
 */
Status priorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    int location = locateElem(L, cur_e, equal);
    if (location == 0)
        return ERROR;
    else if (location == 1)
        return NONE;
    else
    {
        pre_e = L.elem[location - 1];
        return OK;
    }
}

/**
 * get the next element of someone
 */
Status nextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    int location = locateElem(L, cur_e, equal);
    if (location == 0)
        return ERROR;
    else if (location == L.length)
        return NONE;
    else
    {
        next_e = L.elem[location + 1];
        return OK;
    }
}
/**
 * insert the specified element in the list
 */
Status insertElem(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length >= L.listSize)
    {
        ElemType *newList = (ElemType *)realloc(L.elem, L.listSize + sizeof(ElemType) * LIST_INCREMENT);
        if (!newList)
            exit(OVERFLOW);
        else
        {
            L.elem = newList;
            L.listSize += LIST_INCREMENT;
        }
    }
    ElemType *p = &L.elem[i - 1];
    ElemType *q = L.elem + L.length - 1;
    for (; q >= p; q--)
        *(q + 1) = *q;
    *p = e;
    L.length++;
    return OK;
}
/**
 * delete the specified element
 */
Status deleteElem(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    else
    {
        e = L.elem[i - 1];
        ElemType *p = &L.elem[i - 1];
        ElemType *q = L.elem + L.length - 1;
        for (p++; p <= q; p++)
        {
            *(p - 1) = *p;
        }
        L.length--;
        return OK;
    }
}
/**
 * traverse the list
 */
Status traverseList(SqList L, Status (*visit)(ElemType e))
{
    for (int i = 0; i < L.length; i++)
    {
        if (!(*visit)(L.elem[i]))
            return ERROR;
    }
    return OK;
}
/**
 * merge the different list
 */
Status MergeList(SqList La, SqList Lb, SqList &Lc)
{
    ElemType *pa = La.elem;
    ElemType *pa_last = La.elem + La.length - 1;
    ElemType *pb = Lb.elem;
    ElemType *pb_last = Lb.elem + Lb.length - 1;
    ElemType *pc = Lc.elem;

    Lc.length = La.length + Lb.length;
    Lc.listSize = Lc.length + LIST_INCREMENT;
    if (pc != nullptr)
        free(pc);
    pc = (ElemType *)malloc(Lc.listSize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW);
    while (pa <= pa_last && pb <= pb_last) // 归并排序，要求原数组已经进行了排序
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
    return OK;
}
/**
 * union the list
 */
Status unionList(SqList &La, SqList Lb)
{
    for (int i = 0; i < Lb.length; i++)
    {
        int location = locateElem(La, Lb.elem[i], equal);
        if (location < 1 || location > La.length)
            insertElem(La, La.length + 1, Lb.elem[i - 1]);
    }
    return OK;
}