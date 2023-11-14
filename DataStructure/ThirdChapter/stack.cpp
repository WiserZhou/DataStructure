//----- 栈的顺序存储表示 -----
#define STACK_INIT_SIZE 100 // 栈容量
#define STACK_INCREMENT 10  // 栈增量
#include "../header/unity.h"
typedef int SElemType;
typedef struct
{
    SElemType *base; // 基地址
    SElemType *top;  // 栈顶指针
    int stacksize;   // 栈容量
} SqStack;

Status InitStack(SqStack &S)
{
    // 构造一个空栈S
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(OVERFLOW); // 存储分配失败
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if (!S.base)
            exit(OVERFLOW);           // 存储分配失败
        S.top = S.base + S.stacksize; // top的位置是有元素的位置，不是存储空间的上限
        S.stacksize += STACK_INCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    else
    {
        e = *(S.top - 1);
        S.top--;
    }
    return OK;
}
bool StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return true;
    else
        return false;
}

// 进制转换
void conversion()
{
    SqStack S;
    int N;
    InitStack(S);
    scanf("%d", &N);
    while (N)
    {
        Push(S, N % 8);
        N = N / 8;
    }
    int e;
    while (!StackEmpty(S))
    {
        Pop(S, e);
        printf("%d", e);
    }
} // conversion

// 括号匹配检验
Status check()
{
    SqStack S;
    char ch;
    int e;
    InitStack(S);
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case '(' || '[' || '{':
            Push(S, ch);
            break;
        case ')':
            if (StackEmpty(S))
                return FALSE;
            else
            {
                Pop(S, e);
                if (e != '(')
                    return FALSE;
            }
            break;
        case ']':
            if (StackEmpty(S))
                return FALSE;
            else
            {
                Pop(S, e);
                if (e != '[')
                    return FALSE;
            }
            break;
        default:
            break;
        }
    }
    if (StackEmpty(S))
        return TRUE;
    else
        return FALSE;
}

// 迷宫求解的位移种类
struct moved
{
    int i, j; // 偏移量
} move[8];    // 8个方向

// 表达式求值
// c1为栈顶符号，c2为读入符号，c2>c1时，符号入栈，c2<=c1时，执行操作
// 设置两个栈，一个存操作数，一个存操作符，表达式起始符#，依次读入操作符和操作数，比较优先权之后进行操作，直到表达式操作完毕。

/**
 * 若c2>c1时，输入的操作符进栈。
 * 若c2==c1，也就是说‘（’与‘）’，或者‘#’与‘#’，因为诸如其他操作符*或者+都不会出现等于的问题
 * 若c2<c1，说明之前输入的操作符的优先级更高，弹出一个栈顶运算符，弹出两个栈顶操作数，进行计算操作，然后将值存入操作数栈。
 */

// 两个栈共享数组空间v[m]，它们的栈底分
// 别设在数组的两端，每个元素占一个分量，试写出
// 两个栈公用栈操作算法：push(i,x),pop(i)和
// top(i),其中i为0和1，用以指示栈号。
const int m = 100;
typedef struct
{
    SElemType v[m]; // 放置的空间
    int top[2];     // 栈顶指针
} STACK;

void InitStack(STACK &S)
{
    //在
    S.top[0] = -1;
    S.top[1] = m;
}

int PUSH(STACK &S, SElemType x, int i)
{
    // i等于0的时候表示操作数，1的时候表示操作符
    if ((S.top[1] - S.top[0]) == 1) // 满
        return ERROR;
    else
        switch (i)
        {
        case 0:
            S.v[++S.top[0]] = x;
            break;
        case 1:
            S.v[--S.top[1]] = x;
            break;
        default:
            return ERROR;
        }
}

int POP(STACK &S, SElemType &x, int i)
{
    if (i == 0)
        if (S.top[0] == -1)
            return ERROR;
        else
        {
            x = S.v[S.top[0]];
            S.top[0]--;
        }
    if (i == 1)
        if (S.top[1] == m)
            return ERROR;
        else
        {
            x = S.v[S.top[1]];
            S.top[0]++;
        }
}


