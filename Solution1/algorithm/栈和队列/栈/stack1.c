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
// // C语言中没有直接支持引用的概念，但是可以通过指针来模拟引用传递

// // 构造一个空栈S
// Status InitStack(SqStack *S){
//     // S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));// 给栈S申请栈空间
//     // if(!S->base) exit(OVERFLOW);// 存储分配失败
//     // S->top=S->base;  // 设置栈顶地址和基地址的关系
//     // S->stacksize=STACK_INIT_SIZE;// 设置栈容量
//     S->top = -1;
//     return OK;
// }

// Status Push(SqStack *S ,SElemType e){
//     if(S->top-S->base>=S->stacksize) // 要先判断栈是否满的情况，如果栈满，则要给栈增加容量
//     {
//         S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));// realloc重新分配内存
//         if(!S->base) exit(OVERFLOW);// 存储分配失败
//         S->top=S->base+S->stacksize;
//         S->stacksize+=STACKINCREMENT;
//     }
//     *S->top++=e;
//     return OK;
// }

// Status Pop(SqStack *S,SElemType *e){
//     if(S->top==S->base) // 如果栈空,返回
//     return ERROR;
//     else {//  否则，记录栈顶前面位置的值，栈顶位置减1
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
//     printf("初始化后的线性栈的长度为：%d\n", getLength(S));

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Stack
{
    int data[MAXSIZE]; // 栈空间
    int top;           // 栈顶指针
} SeqStack;

/*==========================
函数声明
===========================*/
// void Init_SeqStack(SeqStack *s);
// int Empty_SeqStack(SeqStack *s);
// int Push_SeqStack(SeqStack *s, int x);
// void PrintStack(SeqStack *s);
// int Pop_SeqStack(SeqStack *s, int *x);
// int Gettop_SeqStack(SeqStack *s, int *x);

/*=============================
函数功能：顺序栈的初始化
==============================*/
void Init_SeqStack(SeqStack *s) // 将栈的顶指针设置为-1，在后面的入栈操作时，要先将顶指针++，再进行元素赋值的操作
{
    s->top = -1;
}

/*=============================
函数功能：顺序栈的判空
==============================*/
int Empty_SeqStack(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

/*=============================
函数功能：顺序栈的入栈
==============================*/
int Push_SeqStack(SeqStack *s, int m)
{
    if (s->top == MAXSIZE - 1) // 入栈是要判断一下是否是满栈的情况
        return 0;              // 栈满不能入栈
    else
    {
        s->top++;            // 指针先向上移
        s->data[s->top] = m; // 顶指针所指向的那个空间进行赋值
    }
    return 1;
}
/*=============================
函数功能：顺序栈的输出
==============================*/
void PrintStack(SeqStack *s)
{
    int i;
    if (Empty_SeqStack(s) == 1) // Empty_SeqStack(s)函数在判断出来s为空时，会返回 1
    {
        printf("顺序栈为空！");
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
函数功能：顺序栈的出栈
==============================*/
int Pop_SeqStack(SeqStack *s, int *x)
{
    if (Empty_SeqStack(s) == 1)
        return 0; // 栈空，不能出栈
    else
    {
        *x = s->data[s->top]; // 将栈顶元素放入变量x中
        s->top--;             // 栈顶元素出栈后，栈顶指针向下走一格，表示新的栈顶元素
    }
    return 1;
}

/*=============================
函数功能：顺序栈的栈顶元素的读取
==============================*/
int Gettop_SeqStack(SeqStack *s, int *x)
{
    if (Empty_SeqStack(s) == 1)
        return 0; // 栈空
    else
    {
        *x = s->data[s->top];
    }
    return 1;
}

int main()
{
    SeqStack s;
    int x;             // 出栈的时候读取到的值
    int data[MAXSIZE]; // 这一个数组的定义主要是为了使用PrintStack函数的时候使用的
    int n, m, i, j;
    Init_SeqStack(&s);
    Empty_SeqStack(&s);
    if (Empty_SeqStack(&s) == 1)
        printf("构造了一个空的栈\n");
    printf("请输入元素个数？\n");
    scanf("%d", &n);
    printf("请输入入栈的%d个元素的值:\n\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        Push_SeqStack(&s, m); // 上循环，为栈进行赋值操作（入栈）
    }
    printf("选择出栈多少元素：");
    scanf("%d", &j);
    if (j > n)
    {
        printf("栈中没有这么多的元素,出现错误");
        return 0;
    }
    else
    {
        printf("出栈的元素为:\n");
        for (i = 0; i < j; i++)
        {
            Pop_SeqStack(&s, &x); // x 记录的是出栈额的元素的数值
            printf("%4d", x);
        }
    }
    /*
    其实输出栈的函数可以选择使用PrintStack函数，这里我选择了使用出栈的函数Pop_SeqStack。
    */
    Gettop_SeqStack(&s, &x);
    printf("\n此时的栈顶元素读取到为%d\n", x);
    // PrintStack(&s);
    return 0;
}
