

// ���Ķ���˳��洢�ṹ�����Լ򵥵����Ϊ���� "�̶����ȵ�˳��洢�ṹ" ���洢�ַ���������޶�����ײ�ʵ��ֻ��ʹ�þ�̬���顣
// ʹ�ö���˳��洢�ṹ�洢�ַ���ʱ������Ŀ���ַ����ĳ��ȣ�Ԥ�������㹻����ڴ�ռ䡣

// https://blog.csdn.net/Leeds1993/article/details/60956971
// C���Գ����ַ������������ܽ�

// ������: strncpy
// ��  ��: ���ַ���srcǰn���ַ��������ַ���dest
// ��  ��: char *strncpy(char *dest, const char *src, size_t n);
// ����ֵ: ���ز���dest���ַ�����ʼ��ַ

// void *memcpy(void *dest, const void *src, size_t n);
// �ú�����������������
// dest��ָ��Ŀ���ڴ�ռ��ָ�룬��ʾ���ƺ����ݴ�ŵ�λ�á�
//     src��ָ��Դ�ڴ�ռ��ָ�룬��ʾҪ�����Ƶ��������ڵ�λ�á�
//         n��Ҫ���Ƶ��ֽ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int main()
{
    char str[N];
    char String[N];
    char *str1 = "data.biancheng.net";
    strcpy(str, str1);
    strncpy(String, str, 3);
    String[3] = '\0';
    printf("%s\n", str);
    printf("%s\n", String);
    printf("%s\n", str1);
    // printf("%d",strlen(str1));
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAXSTRLEN 255
// typedef unsigned char Sstring[MAXSTRLEN + 1];

// int main()
// {
//     Sstring str, String;
//     Sstring str1 = "data.biancheng.net";

//     strcpy(str, str1);

//     memcpy(String, str, 3);
//     String[3] = '\0';

//     printf("%s\n", str);
//     printf("%s\n", String);
//     printf("%s\n", str1);

//     return 0;
// }