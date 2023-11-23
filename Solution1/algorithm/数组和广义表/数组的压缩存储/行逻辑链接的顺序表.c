

#include <stdio.h>
#define MAXSIZE 12500 // ���Ԫ�ظ���
#define MAXRC 100     // �������������
#define ElemType int  // Ԫ�����Ͷ���Ϊint

typedef struct
{
    int i, j;   // ����Ԫ�ص��кź��к�
    ElemType e; // ����Ԫ�ص�ֵ
} Triple;

typedef struct
{
    Triple data[MAXSIZE + 1]; // ����Ԫ�����飬���ڴ洢ϡ�����ķ���Ԫ��
    int rpos[MAXRC + 1];      // ÿ�е�һ������Ԫ����data�����е�λ��
    int mu, nu, tu;           // ������������Ԫ�ظ���
} RLSMatrix;

// ������������
void display(RLSMatrix M)
{
    for (int i = 1; i <= M.mu; i++)
    {
        for (int j = 1; j <= M.nu; j++)
        {
            int value = 0;
            if (i + 1 <= M.mu)
            {
                for (int k = M.rpos[i]; k < M.rpos[i + 1]; k++)
                {
                    if (i == M.data[k].i && j == M.data[k].j)
                    {
                        printf("%d ", M.data[k].e); // ��ʾ����Ԫ�ص�ֵ
                        value = 1;
                        break;
                    }
                }
                if (value == 0)
                {
                    printf("0 "); // �����ǰλ�ò��Ƿ���Ԫ�أ�����ʾ0
                }
            }
            else
            {
                for (int k = M.rpos[i]; k <= M.tu; k++)
                {
                    if (i == M.data[k].i && j == M.data[k].j)
                    {
                        printf("%d ", M.data[k].e); // ��ʾ����Ԫ�ص�ֵ
                        value = 1;
                        break;
                    }
                }
                if (value == 0)
                {
                    printf("0 "); // �����ǰλ�ò��Ƿ���Ԫ�أ�����ʾ0
                }
            }
        }
        printf("\n"); // ����
    }
}

int main(int argc, char *argv[])
{
    RLSMatrix M;
    M.tu = 4;      // ����ķ���Ԫ�ظ���
    M.mu = 3;      // ���������
    M.nu = 4;      // ���������
    M.rpos[1] = 1; // ÿ�е�һ������Ԫ����data�����е�λ��
    M.rpos[2] = 3;
    M.rpos[3] = 4;
    M.data[1].e = 3; // ��һ������Ԫ�ص�ֵ
    M.data[1].i = 1; // ��һ������Ԫ�ص��к�
    M.data[1].j = 2; // ��һ������Ԫ�ص��к�
    M.data[2].e = 5; // �ڶ�������Ԫ�ص�ֵ
    M.data[2].i = 1; // �ڶ�������Ԫ�ص��к�
    M.data[2].j = 4; // �ڶ�������Ԫ�ص��к�
    M.data[3].e = 1; // ����������Ԫ�ص�ֵ
    M.data[3].i = 2; // ����������Ԫ�ص��к�
    M.data[3].j = 3; // ����������Ԫ�ص��к�
    M.data[4].e = 2; // ���ĸ�����Ԫ�ص�ֵ
    M.data[4].i = 3; // ���ĸ�����Ԫ�ص��к�
    M.data[4].j = 1; // ���ĸ�����Ԫ�ص��к�

    // �������
    display(M);
    return 0;
}