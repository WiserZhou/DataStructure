#include <iostream>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW 1
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
typedef int Status;

typedef struct
{
    char name[8];
    int age;
    char sex[2];
    float score;
} ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
} 

Status DestoryList(SqList &L)
{
    free(L.elem);
    return OK;
} 

Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

Status ListLength(SqList L)
{
    return L.length;
}

Status PriorElem(SqList L, int cur_e, ElemType &pre_e)
{
    if (cur_e <= 0 || L.length == 0 || cur_e > L.length)
        return ERROR;
    else
        pre_e = L.elem[cur_e - 1];
        return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
        if (i < 1 || i > L.length + 1)
        return ERROR;
        if (L.length >= L.listsize)
        {
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
        }
}

int main()
{
    SqList L;
    InitList_Sq(L);
}
