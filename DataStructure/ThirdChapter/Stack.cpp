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
// void displayStack(Stack S)
// {
//     ElemType *p = S.top;
//     while (p > S.base)
//         cout << (char)*--p << " ";
// }
// void BinaryTransfer()
// {
//     Stack S;
//     initStack(S);
//     int N;
//     cout << "input a number which you want to transfer: ";
//     cin >> N;
//     while (N)
//     {
//         push(S, N % BINARY); // 将N对进制取余，得到的就是转换的结果
//         N /= BINARY;
//         // Nx =an×Y"+...+a2×Y^2 +a1xy^1+a0xy^0
//     }
//     ElemType e;
//     while (!emptyStack(S))
//     {
//         pop(S, e);
//         cout << e;
//     }
//     clearStack(S);
// }

// Status checkBracket()
// {
//     char ch;
//     Stack S;
//     initStack(S);
//     ElemType e;
//     while ((ch = getchar()) != '\n')
//     {
//         switch (ch)
//         {
//             // case表达式不可以连续使用逻辑判断符
//         case '(':
//         case '{':
//         case '[':
//             push(S, ch);
//             break;
//         case ')':
//             if (emptyStack(S))
//                 return FALSE;
//             pop(S, e);
//             if (e != '(')
//                 return FALSE;
//             break;
//         case ']':
//             if (emptyStack(S))
//                 return FALSE;
//             pop(S, e);
//             if (e != '[')
//                 return FALSE;
//             break;
//         case '}':
//             if (emptyStack(S))
//                 return FALSE;
//             pop(S, e);
//             if (e != '{')
//                 return FALSE;
//             break;
//         default:
//             break;
//         }
//     }
//     if (emptyStack(S))
//         return TRUE;
//     else
//         return FALSE;
// }

// void LineEdit()
// {
//     Stack S;
//     ElemType e;
//     initStack(S);
//     char ch = getchar();
//     while (ch != EOF && ch != '!') // EOF通过ctrl+Z输入
//     {
//         while (ch != EOF && ch != '\n')
//         {
//             switch (ch)
//             {
//             case '#':
//                 pop(S, e);
//                 break;
//             case '@':
//                 clearStack(S);
//                 break;
//             default:
//                 push(S, ch);
//                 break;
//             }
//             ch = getchar();
//         }
//         displayStack(S);
//         cout << endl;
//         clearStack(S);
//         if (ch != EOF)
//             ch = getchar();
//     }
//     destroyStack(S);
// }

typedef int MazeType[11][11];
MazeType maze = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                 {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                 {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                 {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                 {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                 {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                 {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                 {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
bool Pass(PosType curpos)
{
    if (maze[curpos.y][curpos.x] == 0)
        return true;
    else
        return false;
}
void FootPrint(PosType curpos)
{
    maze[curpos.y][curpos.x] = 1;
}
void setSElem(ElemType &e, int cur_step, PosType cur_pos, int di)
{
    e.ord = cur_step;
    e.seat = cur_pos;
    e.di = di;
}
bool equal(PosType a, PosType b)
{
    if ((a.x == b.x) && (a.y == b.y))
        return true;
    else
        return false;
}
PosType NextPos(PosType cur_pos, int di)
{
    switch (di)
    {
    case 1:
        cur_pos.x += 1;

        break;
    case 2:
        cur_pos.y += 1;
        break;
    case 3:
        cur_pos.x -= 1;
        break;
    case 4:
        cur_pos.y -= 1;
        break;
    default:
        break;
    }
    return cur_pos;
}
void MarkPrint(PosType seat)
{
    maze[seat.y][seat.x] = 1;
}
ostream &operator<<(ostream &os, const PosType &p)
{
    os << "(" << p.x << ", " << p.y << ")" << endl;
    return os;
}
Status mazePath(PosType start, PosType end)
{
    ElemType e;
    Stack S;
    initStack(S);
    PosType cur_pos = start;
    int cur_step = 1;
    do
    {
        if (Pass(cur_pos))
        {
            cout << cur_pos;
            FootPrint(cur_pos);
            setSElem(e, cur_step, cur_pos, 1);
            push(S, e);
            if (equal(cur_pos, end))
                return TRUE;
            cur_pos = NextPos(cur_pos, 1);
            cur_step++;
        }
        else
        {
            if (!emptyStack(S))
            {
                pop(S, e);
                while (e.di == 4 && !emptyStack(S))
                {
                    MarkPrint(e.seat);
                    pop(S, e);
                }
                if (e.di < 4)
                {
                    e.di++;
                    push(S, e);
                    cur_pos = NextPos(e.seat, e.di);
                }
            }
        }
    } while (!emptyStack(S));
    return FALSE;
}
int main()
{
    PosType start = {1, 1};
    PosType end = {8, 8};
    cout << mazePath(start, end);
}
