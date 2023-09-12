#include "..\header\unity.h"

typedef struct
{
    ElemType *base;
    /**
     * top指向的是最后一个栈顶元素的后一个位置，其中没有元素，为空。
     */
    ElemType *top;
    int stackSize;
} Stack;
bool emptyStack(Stack S)
{
    if (S.top == S.base)
        return true;
    else
        return false;
}
Status initStack(Stack &S)
{
    S.base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stackSize = STACK_INIT_SIZE;
    return OK;
}
Status getPop(Stack S, ElemType &e)
{
    if (emptyStack(S))
        return NONE;
    e = *(S.top - 1);
    return OK;
}

Status push(Stack &S, ElemType e)
{
    if (S.top - S.base >= S.stackSize)
    {
        S.base = (ElemType *)realloc(S.base, sizeof(ElemType) * (STACK_INCREMENT + S.stackSize));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stackSize;   // 栈底位置改变，重新定义栈顶位置
        S.stackSize += STACK_INCREMENT; // 此时增加的是一个元素的空间大小
    }
    *S.top++ = e; // 将top指针向后移动一个距离，始终保持top指针指向的是最后一个栈顶元素的后一位
    return OK;
}
Status pop(Stack &S, ElemType &e)
{
    if (emptyStack(S))
        return NONE;
    e = *--S.top; // 说明：此处容易使人迷惑，实际上此元素并没真正删除，仍在S.top中，但是如果插入元素，就会被更新，就像是删除了一样
    return OK;
}

Status destroyStack(Stack &S)
{
    while (!emptyStack(S))
        free(S.base);
    S.base = nullptr;
    S.top = nullptr;
    S.stackSize = 0;
    return OK;
}
Status clearStack(Stack &S)
{
    S.top = S.base;
    return OK;
}
LEN lengthStack(Stack S)
{
    return (S.top - S.base);
}

bool noneStack(Stack S)
{
    if (S.base == nullptr)
        return false;
    else
        return true;
}

Status traverseStack(Stack &S, Status (*visit)(ElemType e))
{
    if (noneStack(S))
        return ERROR;
    if (emptyStack(S))
        return NONE;
    ElemType *p = S.top;
    while (p > S.base)
        visit(*--p);
    return OK;
}
void displayStack(Stack S)
{
    ElemType *p = S.top;
    while (p > S.base)
        cout << (char)*--p << " ";
}
void BinaryTransfer()
{
    Stack S;
    initStack(S);
    int N;
    cout << "input a number which you want to transfer: ";
    cin >> N;
    while (N)
    {
        push(S, N % BINARY); // 将N对进制取余，得到的就是转换的结果
        N /= BINARY;
        // Nx =an×Y"+...+a2×Y^2 +a1xy^1+a0xy^0
    }
    ElemType e;
    while (!emptyStack(S))
    {
        pop(S, e);
        cout << e;
    }
    clearStack(S);
}

Status checkBracket()
{
    char ch;
    Stack S;
    initStack(S);
    ElemType e;
    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
            // case表达式不可以连续使用逻辑判断符
        case '(':
        case '{':
        case '[':
            push(S, ch);
            break;
        case ')':
            if (emptyStack(S))
                return FALSE;
            pop(S, e);
            if (e != '(')
                return FALSE;
            break;
        case ']':
            if (emptyStack(S))
                return FALSE;
            pop(S, e);
            if (e != '[')
                return FALSE;
            break;
        case '}':
            if (emptyStack(S))
                return FALSE;
            pop(S, e);
            if (e != '{')
                return FALSE;
            break;
        default:
            break;
        }
    }
    if (emptyStack(S))
        return TRUE;
    else
        return FALSE;
}

void LineEdit()
{
    Stack S;
    ElemType e;
    initStack(S);
    char ch = getchar();
    while (ch != EOF && ch != '!') // EOF通过ctrl+Z输入
    {
        while (ch != EOF && ch != '\n')
        {
            switch (ch)
            {
            case '#':
                pop(S, e);

                break;
            case '@':
                clearStack(S);
                break;
            default:
                push(S, ch);
                break;
            }
            ch = getchar();
        }
        displayStack(S);
        clearStack(S);
        if (ch != EOF)
            ch = getchar();
    }
    destroyStack(S);
}
int main()
{
    LineEdit();
}