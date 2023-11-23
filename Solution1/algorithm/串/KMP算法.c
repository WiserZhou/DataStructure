

#include <stdio.h>
#include <string.h>
#define maxsize 100

void Nextval(char T[], int *next)
{
    int lenT = strlen(T);
    int k = -1; // ǰ׺
    int j = 0;  // ��׺
    next[0] = -1;
    while (j < lenT)
    {
        if (k == -1 || T[j] == T[k])
        {
            j++;
            k++;
            // ��֮ǰnext�����󷨣��Ķ�������4��
            if (T[j] != T[k])
            {
                next[j] = k; // ֮ǰֻ����һ��
            }
            else
            {
                next[j] = next[k]; /*Ϊ���ܳ���T[j] = T[ next[j ]]��
                                     ���Ե�����ʱ�����������λ��ݣ�k = next[next[k]]  */
            }
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP(char S[], char T[]) // KMP�㷨��ʵ�֣�������������
{
    int i = 0, j = 0, lenS, lenT;
    lenS = strlen(S);
    lenT = strlen(T);

    int next[maxsize];
    Nextval(T, next);

    while (i < lenS && j < lenT)
    {
        if (j == -1 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == lenT)
    {
        printf("Match succeed!\n");
        return i - j;
    }
    else
    {
        printf("Match failed!\n");
        return -1;
    }
}

// ����ƥ���㷨��˼��򵥣�����ʱ�临�ӶȱȽϵĸ�
int BF(char S[], char T[])
{
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
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
    if (T[j] == '\0')
        return (i - j);
    else
        return -1;
}

int main()
{
    char S[maxsize], T[maxsize];
    int target;

    scanf("%s", S);
    scanf("%s", T);

    int target1 = BF(S, T);
    target = KMP(S, T);
    printf("Through the KMP the Position is %d\n", target);
    printf("Through the BF the Position is %d\n", target1);
    return 0;
}
