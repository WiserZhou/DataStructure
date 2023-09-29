#include "..\header\unity.h"
#include "..\header\Stack.h"
#include <string>
#include <stack>
// void displayStack(Stack S)
// {
//     ElemType *p = S.top;
//     while (p > S.base)
//         cout << (char)*--p << " ";
// }
#define BINARY 8
void BinaryTransfer()
{
    Stack S;
    int N;
    cout << "input a number which you want to transfer: ";
    cin >> N;
    while (N)
    {
        S.push(N % BINARY); // 将N对进制取余，得到的就是转换的结果
        N /= BINARY;
        // Nx =an×Y"+...+a2×Y^2 +a1xy^1+a0xy^0
    }
    // SElemType e;
    while (!S.isEmpty())
        cout << S.pop();
    S.clear();
}

// int main()
// {
//     BinaryTransfer();
//     return 0;
// }

Status checkBracket()
{
    Stack S;
    // initStack(S);
    SElemType e;
    string s;
    getline(cin, s);
    unsigned i = 0;
    while (i < s.length())
    {
        char ch = s[i++];
        switch (ch)
        {
            // case表达式不可以连续使用逻辑判断符
        case '(':
        case '{':
        case '[':
            S.push(ch);
            break;
        case ')':
            if (S.isEmpty())
                return FALSE;
            e = S.pop();
            if (e != '(')
                return FALSE;
            break;
        case ']':
            if (S.isEmpty())
                return FALSE;
            e = S.pop();
            if (e != '[')
                return FALSE;
            break;
        case '}':
            if (S.isEmpty())
                return FALSE;
            e = S.pop();
            if (e != '{')
                return FALSE;
            break;
        default:
            break;
        }
    }
    if (S.isEmpty())
        return TRUE;
    else
        return FALSE;
}
// int main()
// {
//     cout << checkBracket();
//     return 0;
// }
void LineEdit()
{
    Stack S;
    // SElemType e;
    // initStack(S);
    char ch = getchar();
    while (ch != EOF && ch != '!') // EOF通过ctrl+Z输入
    {
        while (ch != EOF && ch != '\n')
        {
            switch (ch)
            {
            case '#':
                S.pop();
                break;
            case '@':
                S.clear();
                break;
            default:
                S.push(ch);
                break;
            }
            ch = getchar();
        }
        S.display();
        cout << endl;
        S.clear();
        if (ch != EOF)
            ch = getchar();
    }
    S.destroy();
}
// int main()
// {
//     LineEdit();
//     return 0;
// }
typedef struct PosType
{
    int x;
    int y;
} PosType;
typedef struct
{
    int ord;      // 通道块在路径上的序号
    PosType seat; // 通道块在迷宫中的坐标位置
    int di;       // 从此通道块走向下一个通道块的方向
} SElem;
typedef int MazeType[12][12];
MazeType maze = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 二维数组typedef方法
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
void setSElem(SElem &e, int cur_step, PosType cur_pos, int di)
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
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
Status mazePath(PosType start, PosType end)
{
    ofstream outFile("output.txt", ios::app);
    SElem e;
    stack<SElem> S;
    // initStack(S);
    PosType cur_pos = start;
    int cur_step = 1;
    do
    {
        outFile << cur_pos;
        if (Pass(cur_pos))
        {
            outFile << "yes" << endl;
            FootPrint(cur_pos);
            setSElem(e, cur_step, cur_pos, 1);
            S.push(e);
            if (equal(cur_pos, end))
                return TRUE;
            cur_pos = NextPos(cur_pos, 1);
            cur_step++;
        }
        else
        {
            outFile << "no";
            if (!S.empty())
            {
                e = S.top();
                S.pop();
                while (e.di == 4 && !S.empty())
                {
                    MarkPrint(e.seat);
                    e = S.top();
                    S.pop();
                }
                if (e.di < 4)
                {
                    e.di++;
                    S.push(e);
                    cur_pos = NextPos(e.seat, e.di);
                }
            }
        }
    } while (!S.empty());
    outFile.close();
    return FALSE;
}
int main()
{
    PosType start = {1, 1};
    PosType end = {8, 8};
    cout << mazePath(start, end);
}
