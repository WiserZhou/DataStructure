#include <stdio.h>
#include <string.h>

#define MAX_L 1000 // ��������ַ�������
#define NUM 100    // ��������ַ�������

int main()
{
    int num;
    scanf("%d", &num);  // �����ַ�������
    int i, max_l = 0;   // ����ѭ������i������ַ�������max_l
    char s[NUM][MAX_L]; // �����ַ�������s�����ڴ洢������ַ���
    for (i = 0; i < num; i++)
    {
        scanf("%s", s[i]); // �����ַ���������������s
        int length = strlen(s[i]);
        if (length > max_l)
            max_l = length; // ��������ַ�������
    }
    char ans[MAX_L];
    scanf("%s", ans);        // ������ַ���
    int a[NUM][MAX_L] = {0}; // �����ά����a�����ڴ洢���ַ����������ַ�����ͬ���ֵĳ���
    // ���������ַ������飬������ͬ���ֵĳ���
    for (i = 0; i < num; i++)
    {
        int length = strlen(s[i]);
        for (int j = 0; j < length; j++)
        {
            unsigned int cnt = 0;
            int b;
            for (b = j; cnt < strlen(ans) && b < length; b++)
            {
                if (s[i][b] == ans[cnt])
                {
                    cnt++;
                    a[i][j] = cnt; // ����ͬ���ֵĳ��ȴ�������a
                }
                else
                {
                    break;
                }
            }
        }
    }
    int max1 = 0, max2 = 0, max_ans = 0; // ���������ͬ���ֳ��ȵ��ַ����±��λ���±�
    // ������a���ҵ�������ͬ���ֳ��ȼ����Ӧ���ַ����±��λ���±�
    for (i = 0; i < num; i++)
    {
        for (int j = 0; j < max_l; j++)
        {
            if (a[i][j] > max_ans)
            {
                max_ans = a[i][j];
                max1 = i;
                max2 = j + 1;
            }
        }
    }
    if (max_ans != 0)
    {
        double gd = ((double)max_ans / strlen(ans)) * 100.0; // ������ͬ���ֵİٷֱ�
        printf("%d %d %.2lf%%", max1 + 1, max2, gd);         // ����������ͬ���ֵİٷֱ�
    }
    else
    {
        printf("0 0 0.00%%"); // ��û����ͬ���֣������0��0.00%
    }
    return 0; // �������
}