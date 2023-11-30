#include <iostream>
using namespace std;

const int m = 100;    // 假设m为栈的最大容量
typedef int ElemType; // 假设栈内元素类型为int

typedef struct
{
    ElemType v[m];
    int top[2]; // 栈顶指针
} STACK;

// 初始化栈
void InitStack(STACK &S)
{
    S.top[0] = -1;  // 是我们学过的栈
    S.top[1] = m;   // 和我们学的栈是相反的
}

// 入栈操作
int PUSH(STACK &S, ElemType x, int i)   // i表示对哪个栈进行相关的入栈操作
{
    if ((S.top[1] - S.top[0]) == 1) // 栈满
        return -1;                  // 表示出错或栈满
    else
    {
        switch (i)
        {
        case 0:
            S.v[++S.top[0]] = x;   // 稍微画一下图就可以看出来
            break;
        case 1:
            S.v[--S.top[1]] = x;   // 在前面我设置了m为栈的最大容量，故数组的取值为0~m-1
            break;
        default:
            return -1; // 表示栈号错误
        }
        return 0; // 表示入栈成功
    }
}

// 出栈操作
int POP(STACK &S, ElemType &x, int i)
{
    if (i == 0)
    {
        if (S.top[0] == -1)
            return -1; // 表示出错或栈为空
        else
        {
            x = S.v[S.top[0]];
            S.top[0]--;
            return 0; // 表示出栈成功
        }
    }
    else if (i == 1)
    {
        if (S.top[1] == m)
            return -1; // 表示出错或栈为空
        else
        {
            x = S.v[S.top[1]];
            S.top[1]++;
            return 0; // 表示出栈成功
        }
    }
    else
    {
        return -1; // 表示栈号错误
    }
}

int main()
{
    STACK S;
    InitStack(S); // 初始化栈
    // 入栈操作示例
    int result = PUSH(S, 10, 0); // 将元素10入栈到栈0
    if (result == -1)
    {
        cout << "入栈失败或栈已满" << endl;
    }
    else
    {
        cout << "入栈成功" << endl;
    }

    result = PUSH(S, 20, 1); // 将元素20入栈到栈1
    if (result == -1)
    {
        cout << "入栈失败或栈已满" << endl;
    }
    else
    {
        cout << "入栈成功" << endl;
    }

    // 出栈操作示例
    ElemType x;
    result = POP(S, x, 0); // 从栈0中出栈
    if (result == -1)
    {
        cout << "出栈失败或栈为空" << endl;
    }
    else
    {
        cout << "出栈成功，出栈元素为：" << x << endl;
    }

    result = POP(S, x, 1); // 从栈1中出栈
    if (result == -1)
    {
        cout << "出栈失败或栈为空" << endl;
    }
    else
    {
        cout << "出栈成功，出栈元素为：" << x << endl;
    }

    return 0;
}
