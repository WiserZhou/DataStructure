/**
 * ˳��洢�ṹ�����Ա�
 * */
#include <cstdio>
#define MAX_SIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType; // Elem�������κ����͵����ݣ�������intΪ����

typedef struct
{
    ElemType data[MAX_SIZE];
    int length;
} SqList, *SqListPtr;
/**
 * ��ʼ�����Ա�
 * */
Status initSqList(SqListPtr L)
{
    L->length = 0;
    return OK;
}
/**
 * �������Ա�
 */
Status destroyList()
{
}
/**
 * �ж����Ա��Ƿ�Ϊ��
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
 * ʹ���Ա�LΪ�ձ�
 * */
Status ClearSqList(SqListPtr L)
{
    L->length = 0;
    return OK;
}
/**
 * ��ȡ���Ա�L�ĳ���
 * */
int SqListLength(SqList L)
{
    return L.length;
}
/**
 * һ��һ���Ұ���
 * ˳��洢�ṹ�����Ա�Ļ�ȡԪ�ز��� ʱ�临�Ӷ�ΪO(1) ��e������ֵ
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
 * �������Ա�L�е�һ����e��ȵ�Ԫ�ص�λ�ã����Ҳ���������0
 * */
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        { // ������intΪ���� ��ֱ�ӽ��бȽ���
            return i + 1;
        }
    }
    return 0;
}
/**
 * �����Ŷ�һ��������һ���˽��������˾�Ҫ����Ų
 * ��L�ĵ�i��Ԫ��֮ǰ��������Ԫ��e��L�ĳ��ȼ�1
 * */
Status SqListInsert(SqListPtr L, int i, ElemType e)
{
    if (L->length == MAX_SIZE || i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    if (i <= L->length)
    { // ������ǲ��뵽���һ��λ�ã��������ݵ�λ�ú����������Ų
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
 * ɾ��L�ĵ�i��Ԫ�أ�����e����ɾ����Ԫ�أ�L�ĳ��ȼ�1
 * */
Status SqListDelete(SqListPtr L, int i, ElemType *e)
{
    if (L->length == 0 || i < 1 || i > L->length)
    {
        return ERROR;
    }
    *e = L->data[i - 1];
    if (i < L->length)
    { // ���ɾ���Ĳ������һ��λ�ã�ɾ�����ݵ�λ�ú��������ǰŲ
        for (int k = i; k < L->length; k++)
        {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--; // �����ǲ������������ϵ�ɾ�����Ǹ����ݻ����ڣ�������ܻᱻ���ǰ���
    return OK;
}
/**
 * �ϲ����Ա��ҳ�ȥ��ͬԪ��
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
