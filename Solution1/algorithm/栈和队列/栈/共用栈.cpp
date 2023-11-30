#include <iostream>
using namespace std;

const int m = 100;    // ����mΪջ���������
typedef int ElemType; // ����ջ��Ԫ������Ϊint

typedef struct
{
    ElemType v[m];
    int top[2]; // ջ��ָ��
} STACK;

// ��ʼ��ջ
void InitStack(STACK &S)
{
    S.top[0] = -1;  // ������ѧ����ջ
    S.top[1] = m;   // ������ѧ��ջ���෴��
}

// ��ջ����
int PUSH(STACK &S, ElemType x, int i)   // i��ʾ���ĸ�ջ������ص���ջ����
{
    if ((S.top[1] - S.top[0]) == 1) // ջ��
        return -1;                  // ��ʾ�����ջ��
    else
    {
        switch (i)
        {
        case 0:
            S.v[++S.top[0]] = x;   // ��΢��һ��ͼ�Ϳ��Կ�����
            break;
        case 1:
            S.v[--S.top[1]] = x;   // ��ǰ����������mΪջ������������������ȡֵΪ0~m-1
            break;
        default:
            return -1; // ��ʾջ�Ŵ���
        }
        return 0; // ��ʾ��ջ�ɹ�
    }
}

// ��ջ����
int POP(STACK &S, ElemType &x, int i)
{
    if (i == 0)
    {
        if (S.top[0] == -1)
            return -1; // ��ʾ�����ջΪ��
        else
        {
            x = S.v[S.top[0]];
            S.top[0]--;
            return 0; // ��ʾ��ջ�ɹ�
        }
    }
    else if (i == 1)
    {
        if (S.top[1] == m)
            return -1; // ��ʾ�����ջΪ��
        else
        {
            x = S.v[S.top[1]];
            S.top[1]++;
            return 0; // ��ʾ��ջ�ɹ�
        }
    }
    else
    {
        return -1; // ��ʾջ�Ŵ���
    }
}

int main()
{
    STACK S;
    InitStack(S); // ��ʼ��ջ
    // ��ջ����ʾ��
    int result = PUSH(S, 10, 0); // ��Ԫ��10��ջ��ջ0
    if (result == -1)
    {
        cout << "��ջʧ�ܻ�ջ����" << endl;
    }
    else
    {
        cout << "��ջ�ɹ�" << endl;
    }

    result = PUSH(S, 20, 1); // ��Ԫ��20��ջ��ջ1
    if (result == -1)
    {
        cout << "��ջʧ�ܻ�ջ����" << endl;
    }
    else
    {
        cout << "��ջ�ɹ�" << endl;
    }

    // ��ջ����ʾ��
    ElemType x;
    result = POP(S, x, 0); // ��ջ0�г�ջ
    if (result == -1)
    {
        cout << "��ջʧ�ܻ�ջΪ��" << endl;
    }
    else
    {
        cout << "��ջ�ɹ�����ջԪ��Ϊ��" << x << endl;
    }

    result = POP(S, x, 1); // ��ջ1�г�ջ
    if (result == -1)
    {
        cout << "��ջʧ�ܻ�ջΪ��" << endl;
    }
    else
    {
        cout << "��ջ�ɹ�����ջԪ��Ϊ��" << x << endl;
    }

    return 0;
}
