

// ���Ķ���˳��洢�ṹ�����Լ򵥵����Ϊ���� "�̶����ȵ�˳��洢�ṹ" ���洢�ַ���������޶�����ײ�ʵ��ֻ��ʹ�þ�̬���顣
// ʹ�ö���˳��洢�ṹ�洢�ַ���ʱ������Ŀ���ַ����ĳ��ȣ�Ԥ�������㹻����ڴ�ռ䡣

// https://blog.csdn.net/Leeds1993/article/details/60956971
// C���Գ����ַ������������ܽ�


// ������: strncpy
// ��  ��: ���ַ���srcǰn���ַ��������ַ���dest
// ��  ��: char *strncpy(char *dest, const char *src, size_t n);
// ����ֵ: ���ز���dest���ַ�����ʼ��ַ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int main()
{
    char str[N];
    char String[N];
    char *str1= "data.biancheng.net";
    strcpy(str, str1);
    strncpy(String, str,3);
    String[3]='\0';
    printf("%s\n", str);
    printf("%s\n", String);
    printf("%s\n", str1);
    // printf("%d",strlen(str1));
    return 0;
}