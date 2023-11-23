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
    keyType key; // ���ұ���ÿ������Ԫ�ص�ֵ
    // �����Ҫ�������������������
} ElemType;
typedef struct
{
    ElemType *elem; // ��Ų��ұ�������Ԫ�ص�����
    int length;     // ��¼���ұ������ݵ�������
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
    printf("HelloŶ");
    return 0;
}