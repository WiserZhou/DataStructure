


// �������붨���������ṹ�壬triple ��ʾϡ������еķ���Ԫ�أ�TSMatrix ��ʾ����ϡ�����display �����������ϡ�����Ĵ洢��

// �� main �����У�������һ��ϡ����� M������ʼ���������Ժͷ���Ԫ�ء�Ȼ����� display ���������ϡ�����Ĵ洢�����
#include <stdio.h>
#define number 3 // ����ϡ�����ķ���Ԫ�ظ���

typedef struct
{
    int i, j; // ����Ԫ���ھ����е��кź��к�
    int data; // ����Ԫ�ص�ֵ
} triple;

typedef struct
{
    triple data[number]; // ����Ԫ�����飬���ڴ洢ϡ�����ķ���Ԫ��
    int n, m;            // ���������������
    int num;             // ����ķ���Ԫ�ظ���
} TSMatrix;

// ����洢��ϡ�����
void display(TSMatrix M);

int main()
{
    TSMatrix M;
    M.m = 3;            // ���������
    M.n = 3;            // ���������
    M.num = 3;          // ����ķ���Ԫ�ظ���
    M.data[0].i = 1;    // ��һ������Ԫ�ص��к�
    M.data[0].j = 1;    // ��һ������Ԫ�ص��к�
    M.data[0].data = 1; // ��һ������Ԫ�ص�ֵ
    M.data[1].i = 2;    // �ڶ�������Ԫ�ص��к�
    M.data[1].j = 3;    // �ڶ�������Ԫ�ص��к�
    M.data[1].data = 5; // �ڶ�������Ԫ�ص�ֵ
    M.data[2].i = 3;    // ����������Ԫ�ص��к�
    M.data[2].j = 1;    // ����������Ԫ�ص��к�
    M.data[2].data = 3; // ����������Ԫ�ص�ֵ
    display(M);         // ������ʾ������ʾϡ�����
    return 0;
}

void display(TSMatrix M)
{
    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.m; j++)
        {
            int value = 0;
            for (int k = 0; k < M.num; k++)
            {
                if (i == M.data[k].i && j == M.data[k].j)
                {
                    printf("%d ", M.data[k].data); // ��ʾ����Ԫ�ص�ֵ
                    value = 1;
                    break;
                }
            }
            if (value == 0)
                printf("0 "); // �����ǰλ�ò��Ƿ���Ԫ�أ�����ʾ0
        }
        printf("\n"); // ����
    }
}