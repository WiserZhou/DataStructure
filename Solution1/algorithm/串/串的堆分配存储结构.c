

//  http://c.biancheng.net/view/3362.html
//  ��C ������˵������Ὣ�ڴ��Ϊ 4 �����򣬷ֱ�Ϊ������ջ�����������ʹ�����
//  �������ڴ�ռ���Ҫ����Ա�ֶ�ʹ�� malloc �������룬�����ڲ��ú�Ҫ�ֶ�ͨ�� free ���������ͷš�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // char *a1 = NULL;
    // char *a2 = NULL;
    // a1 = (char *)malloc(10 * sizeof(char));
    // strcpy(a1, "data.bian"); // ���ַ���"data.bian"���Ƹ�a1
    // a2 = (char *)malloc(10 * sizeof(char));
    // strcpy(a2, "cheng.net");

    char *a1 = (char *)malloc(100 * sizeof(char));
    printf("Please input a Stirng:");
    scanf("%s", a1);
    char *a2 = (char *)malloc(100 * sizeof(char));
    printf("Please input another Stirng:");
    scanf("%s", a2);
    int lengthA1 = strlen(a1); // a1���ĳ���
    int lengthA2 = strlen(a2); // a2���ĳ���
    // ���Խ��ϲ��Ĵ��洢�� a1 �У���� a1 �ռ䲻��������realloc��̬����
    if (lengthA1 < lengthA1 + lengthA2)
    {
        a1 = (char *)realloc(a1, (lengthA1 + lengthA2 + 1) * sizeof(char));
    }
    // �ϲ��������� a1 ��
    for (int i = lengthA1; i < lengthA1 + lengthA2; i++)
    {
        a1[i] = a2[i - lengthA1]; // ����ط��Ļ���������ѭ�����и�ֵ
    }
    // ����ĩβҪ��� \0���������
    a1[lengthA1 + lengthA2] = '\0';
    printf("%s", a1);
    // ���궯̬����Ҫ�����ͷ�
    free(a1);
    free(a2);
    return 0;
}

// �����и� a1 �� a2 ��ֵʱ��ʹ���� strcpy ���ƺ��������ﲻ��ֱ���� a1 ="data.biancheng"�������������
// ������ϢΪ "û�� malloc �Ŀռ䲻�� free"��
// ��Ϊ strcpy �����ǽ��ַ������Ƶ�����Ĵ洢�ռ��У�
// ��ֱ�Ӹ�ֵ���ַ����洢�ڱ���ڴ�ռ䣨������һ���������������������У�������ָ�� a1 �� a2 ��ָ��
// Ҳ����˵��֮ǰ��̬����Ĵ洢�ռ���Ȼ�����ˣ������û���ؾͶ��ˡ�