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
        pre_e = L.elem[cur_e - 1]; // ֱ������������pre��ֵ
}
/**
 * insert the element at the specified location
 */
Status ListInsert(SqlList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1) // �������length+1��λ�õĻ������൱�������׷��һ��Ԫ�أ���������ġ�
        return ERROR;
    if (L.length >= L.listSize)
    {
        ElemType *newBase = (ElemType *)realloc(L.elem, (L.listSize + LIST_INCREMENT) * sizeof(ElemType)); // �������ö�̬�����
        // �ռ䣬��һ��������ָ����󣬵ڶ����������������õ�����Ŀռ䡣
        if (!newBase)
            exit(OVERFLOW);
        L.elem = newBase;
        L.listSize += LIST_INCREMENT;
    }
    ElemType *q = &(L.elem[i - 1]);
    for (ElemType *p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;
    // ������ƣ��㷨��ʱ�临�Ӷȸ��ƶ���Ԫ���йأ����Ӷ�ΪO(n)��

    *q = e;     // ������ϣ����λ�õ�ֵΪ����ֵ
    ++L.length; // �ӳ�
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
 * ȷ��Ԫ�ص�λ��
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

int main()
{
    SqlList list;
    InitList_Sq(list);
    cout << list.length << endl;
    cout << ListInsert(list, 1, 2) << endl;
    cout << list.elem[0] << endl;
    return 0;
}