#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef int TElemType; // ����������ڵ�洢���� int ���͵�����

typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0�ŵ�Ԫ�洢���ڵ�

SqBiTree bt;
// ��ʼ�������������ǽ����еĵ�Ԫ����
void InitBiTree(SqBiTree bt)
{
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {
        bt[i] = 0;
    }
}

// ��ȡ����������ֵ
TElemType Value(SqBiTree bt, int i)
{
    return bt[i];
}

// ���ö���������ֵ
void Assign(SqBiTree bt, int i, TElemType value)
{
    bt[i] = value;
}

// ��ȡָ���������ӽ����±�
int LeftChild(int i)   // ��Ҫ��������±��Ǵ�0��ʼ�ģ���������ط�������һ��Ķ������Ľ��Ĺ�ϵ��̫һ��
{
    return 2 * i + 1;
}

// ��ȡָ�������Һ��ӽ����±�
int RightChild(int i)
{
    return 2 * i + 2;
}

// ��ȡָ�����ĸ������±�
int Parent(int i)
{
    return (i - 1) / 2;
}

int main()
{
    // ��ʼ��������
    InitBiTree(bt);

    // ���ø�����ֵ
    Assign(bt, 0, 1);

    // �������Һ��ӽ���ֵ
    Assign(bt, LeftChild(0), 2);
    Assign(bt, RightChild(0), 3);

    // ��ȡ������ֵ�����Һ��ӽ���ֵ�������
    printf("������ֵ��%d\n", Value(bt, 0));
    printf("���ӽ���ֵ��%d\n", Value(bt, LeftChild(0)));
    printf("�Һ��ӽ���ֵ��%d\n", Value(bt, RightChild(0)));

    return 0;
}
