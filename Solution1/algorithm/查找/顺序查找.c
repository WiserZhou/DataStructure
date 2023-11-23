#include <stdio.h>
#include <stdlib.h>

#define keyType int

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

// �������ұ�
void Create(SSTable **st, int length)
{
    *st = (SSTable *)malloc(sizeof(SSTable));
    if (!(*st))
    {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    (*st)->length = length;
    (*st)->elem = (ElemType *)malloc((length + 1) * sizeof(ElemType)); // Ϊ���鿪���㹻���Ԫ��������������ݵĴ洢
    if (!(*st)->elem)
    {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    printf("������е�����Ԫ�أ�\n");
    for (int i = 1; i <= length; i++)
    {
        scanf("%d", &((*st)->elem[i].key));
    }
}

// ���ұ���ҵĹ��ܺ���������keyΪ�ؼ���
int Search_seq(SSTable *st, keyType key)
{
    st->elem[0].key = key; // ���ؼ�����Ϊһ������Ԫ�ش�ŵ����ұ�ĵ�һ��λ�ã�������ڵ�����
    int i = st->length;
    for (; st->elem[i].key != key; --i)
        ;
    return i; // ���ص��Ǻ��йؼ���key������Ԫ���ڲ��ұ��е�λ��
}

// �ͷŶ�̬������ڴ�
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
    printf("������������ݵĹؼ��֣�\n");
    int key;
    scanf("%d", &key);
    int location = Search_seq(st, key);
    if (location == 0)
    {
        printf("����ʧ��\n");
    }
    else
    {
        printf("�����ڲ��ұ��е�λ��Ϊ��%d\n", location);
    }
    Destroy(st); // �ͷŶ�̬������ڴ�
    return 0;
}
