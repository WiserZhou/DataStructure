

// BF�㷨����ģʽƥ���㷨��
// http://c.biancheng.net/view/3364.html
#include <stdio.h>
#include <string.h>
// ����ͨģʽƥ���㷨��ʵ�ֺ��������� B��α������A��α�Ӵ�
int mate(char *B, char *A)
{
    unsigned int i = 0, j = 0;
    while (i < strlen(B) && j < strlen(A))
    {
        if (B[i] == A[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    // ����ѭ�������ֿ��ܣ�i=strlen(B)˵���Ѿ�������������ƥ��ʧ�ܣ�j=strlen(A),˵���Ӵ�������ɣ��������гɹ�ƥ��
    if (j == strlen(A))
    {
        return i - strlen(A) + 1;
    }
    // ���е��ˣ�Ϊi==strlen(B)�����
    return 0;
}
int main()
{
    int number = mate("ababcabcacbab", "abcac");
    printf("%d", number);
    return 0;
}