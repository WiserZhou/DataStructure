// #include<stdio.h>
// #include<stdlib.h>

// #define STACK_INIT_SIZE 100
// #define STACKINCREMENT 10
// #define OK 1
// #define ERROR 0
// #define OVERFLOW -2
// typedef int SElemType;
// typedef int Status;

// typedef struct
// {
//     SElemType *base;
//     SElemType *top;
//     int stacksize;
// }SqStack;
// // SqStack S;
// // C������û��ֱ��֧�����õĸ�����ǿ���ͨ��ָ����ģ�����ô���

// // ����һ����ջS
// Status InitStack(SqStack *S){
//     // S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));// ��ջS����ջ�ռ�
//     // if(!S->base) exit(OVERFLOW);// �洢����ʧ��
//     // S->top=S->base;  // ����ջ����ַ�ͻ���ַ�Ĺ�ϵ
//     // S->stacksize=STACK_INIT_SIZE;// ����ջ����
//     S->top = -1;
//     return OK;
// }

// Status Push(SqStack *S ,SElemType e){
//     if(S->top-S->base>=S->stacksize) // Ҫ���ж�ջ�Ƿ�������������ջ������Ҫ��ջ��������
//     {
//         S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));// realloc���·����ڴ�
//         if(!S->base) exit(OVERFLOW);// �洢����ʧ��
//         S->top=S->base+S->stacksize;
//         S->stacksize+=STACKINCREMENT;
//     }
//     *S->top++=e;
//     return OK;
// }

// Status Pop(SqStack *S,SElemType *e){
//     if(S->top==S->base) // ���ջ��,����
//     return ERROR;
//     else {//  ���򣬼�¼ջ��ǰ��λ�õ�ֵ��ջ��λ�ü�1
//         e=*(S->top-1);
//         S->top--;
//     }
//     return OK;
// }

// int getLength(SqStack S){
//     return (S.top)+1;
// }

// int main(){
//     SqStack S;
//     InitStack(&S);
//     printf("��ʼ���������ջ�ĳ���Ϊ��%d\n", getLength(S));

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Stack
{
    int data[MAXSIZE]; // ջ�ռ�
    int top;           // ջ��ָ��
} SeqStack;

/*==========================
��������
===========================*/
// void Init_SeqStack(SeqStack *s);
// int Empty_SeqStack(SeqStack *s);
// int Push_SeqStack(SeqStack *s, int x);
// void PrintStack(SeqStack *s);
// int Pop_SeqStack(SeqStack *s, int *x);
// int Gettop_SeqStack(SeqStack *s, int *x);

/*=============================
�������ܣ�˳��ջ�ĳ�ʼ��
==============================*/
void Init_SeqStack(SeqStack *s) // ��ջ�Ķ�ָ������Ϊ-1���ں������ջ����ʱ��Ҫ�Ƚ���ָ��++���ٽ���Ԫ�ظ�ֵ�Ĳ���
{
    s->top = -1;
}

/*=============================
�������ܣ�˳��ջ���п�
==============================*/
int Empty_SeqStack(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

/*=============================
�������ܣ�˳��ջ����ջ
==============================*/
int Push_SeqStack(SeqStack *s, int m)
{
    if (s->top == MAXSIZE - 1) // ��ջ��Ҫ�ж�һ���Ƿ�����ջ�����
        return 0;              // ջ��������ջ
    else
    {
        s->top++;            // ָ����������
        s->data[s->top] = m; // ��ָ����ָ����Ǹ��ռ���и�ֵ
    }
    return 1;
}
/*=============================
�������ܣ�˳��ջ�����
==============================*/
void PrintStack(SeqStack *s)
{
    int i;
    if (Empty_SeqStack(s) == 1) // Empty_SeqStack(s)�������жϳ���sΪ��ʱ���᷵�� 1
    {
        printf("˳��ջΪ�գ�");
        exit(1);
    }
    else
        for (i = s->top; i >= 0; i--)
            printf("%4d", s->data[i]);
    // while (1)
    // {
    //     printf("%4d",s->data[s->top]);
    //     s->top--;
    //     if(s->top==-1) break;
    // }
}

/*=============================
�������ܣ�˳��ջ�ĳ�ջ
==============================*/
int Pop_SeqStack(SeqStack *s, int *x)
{
    if (Empty_SeqStack(s) == 1)
        return 0; // ջ�գ����ܳ�ջ
    else
    {
        *x = s->data[s->top]; // ��ջ��Ԫ�ط������x��
        s->top--;             // ջ��Ԫ�س�ջ��ջ��ָ��������һ�񣬱�ʾ�µ�ջ��Ԫ��
    }
    return 1;
}

/*=============================
�������ܣ�˳��ջ��ջ��Ԫ�صĶ�ȡ
==============================*/
int Gettop_SeqStack(SeqStack *s, int *x)
{
    if (Empty_SeqStack(s) == 1)
        return 0; // ջ��
    else
    {
        *x = s->data[s->top];
    }
    return 1;
}

int main()
{
    SeqStack s;
    int x;             // ��ջ��ʱ���ȡ����ֵ
    int data[MAXSIZE]; // ��һ������Ķ�����Ҫ��Ϊ��ʹ��PrintStack������ʱ��ʹ�õ�
    int n, m, i, j;
    Init_SeqStack(&s);
    Empty_SeqStack(&s);
    if (Empty_SeqStack(&s) == 1)
        printf("������һ���յ�ջ\n");
    printf("������Ԫ�ظ�����\n");
    scanf("%d", &n);
    printf("��������ջ��%d��Ԫ�ص�ֵ:\n\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        Push_SeqStack(&s, m); // ��ѭ����Ϊջ���и�ֵ��������ջ��
    }
    printf("ѡ���ջ����Ԫ�أ�");
    scanf("%d", &j);
    if (j > n)
    {
        printf("ջ��û����ô���Ԫ��,���ִ���");
        return 0;
    }
    else
    {
        printf("��ջ��Ԫ��Ϊ:\n");
        for (i = 0; i < j; i++)
        {
            Pop_SeqStack(&s, &x); // x ��¼���ǳ�ջ���Ԫ�ص���ֵ
            printf("%4d", x);
        }
    }
    /*
    ��ʵ���ջ�ĺ�������ѡ��ʹ��PrintStack������������ѡ����ʹ�ó�ջ�ĺ���Pop_SeqStack��
    */
    Gettop_SeqStack(&s, &x);
    printf("\n��ʱ��ջ��Ԫ�ض�ȡ��Ϊ%d\n", x);
    // PrintStack(&s);
    return 0;
}
