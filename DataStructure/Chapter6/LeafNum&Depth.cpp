#include "TreeStructure.h"
#include <iostream>
#include "../header/unity.h"
#include <stack>
#include <queue>

void CountLeaf(BiTree T, int &count)
{
    if (T)
    {
        if ((!T->lchild) && (!T->rchild))
            count++; // 对叶子结点计数
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    } // if
} // CountLeaf

int Depth(BiTree T)
{ // 返回二叉树的深度

    if (!T)
        return 0;
    else
    {
        int depthLeft = Depth(T->lchild);
        int depthRight = Depth(T->rchild);
        return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
}

// 判断二叉树是否完全二叉树，是则返回1，否则返回0
int IsCompleteBinaryTree(BiTNode *T)
{
    if (!T)
        return 1; // 空树是完全二叉树
    queue<BiTNode *> Q;
    bool flag = false;
    Q.push(T);

    while (!Q.empty())
    {
        BiTNode *p = Q.front();
        Q.pop();

        if (!p) // 当p是nullptr的时候，如果队列非空，那么他就不是完全二叉树，否则就跳出循环
        {
            if (!Q.empty())
                return 0;
        }
        else
        {
            Q.push(p->lchild);
            Q.push(p->rchild);
        }
    }

    return 1;
}
/**
 * 使用字符串的形式创建一个二叉树
 * 以空格表示无结点
 * A(B( ,C( , )),D( , ))
 * AB*C**D**
 * 去掉括号输入即可
 *
 * -(*(+(a,b),c),/(d,e))
 * -*+abc/de
 * 在先缀字符串中，字母就相当于空格
 */

Status CreateBiTree(BiTree &T)
{
    char ch;
    std::cin >> ch;
    if (ch == ' ')
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;            // 生成根结点
        CreateBiTree(T->lchild); // 构造左子树
        CreateBiTree(T->rchild); // 构造右子树
    }
    return OK;
} // CreateBiTree

/**
 * 这个函数的作用是判断字符 ch 是否在字符串 OP 中出现
 */
bool IN(char ch, const char *OP)
{
    while (*OP != '\0')
    {
        if (ch == *OP)
        {
            return true;
        }
        OP++;
    }
    return false;
}
/**
 * 这个函数的作用是比较两个操作符 c1 和 c2 的优先级大小
 */
bool precede(char c1, char c2)
{
    int priority_c1, priority_c2;
    switch (c1)
    {
    case '+':
    case '-':
        priority_c1 = 1;
        break;
    case '*':
    case '/':
        priority_c1 = 2;
        break;
    default:
        priority_c1 = 0;
        break;
    }
    switch (c2)
    {
    case '+':
    case '-':
        priority_c2 = 1;
        break;
    case '*':
    case '/':
        priority_c2 = 2;
        break;
    default:
        priority_c2 = 0;
        break;
    }
    return priority_c1 >= priority_c2;
}

/**
 * CreateNode
 * 这个函数的作用是创建一个值为ch的空结点，并让他入栈
 */
void CrtNode(BiTree &T, char ch, std::stack<BiTree> &PTR)
{
    T = new BiTNode;
    T->data = ch;
    T->lchild = T->rchild = nullptr;
    PTR.push(T);
}

/**
 * 这个函数的作用是创建一个包含两个子树的新节点，并将其添加到二叉树中。
 */
void CrtSubtree(BiTree &T, char c, std::stack<BiTree> &PTR)
{
    T = new BiTNode;
    T->data = c;

    BiTree rc, lc;

    rc = PTR.top();
    PTR.pop();
    T->rchild = rc;

    lc = PTR.top();
    PTR.pop();
    T->lchild = lc;

    PTR.push(T);
}

/**
 * 首先，定义了两个栈，一个用于存储操作符（S），一个用于存储操作数的子树（PTR）。同时将字符'#'入栈作为栈底的标识，并初始化变量ch为表达式字符串的第一个字符。
 * 通过循环处理表达式字符串，直到操作符栈顶为 '#' 且当前字符也为 '#'，即处理完整个表达式字符串。
 * 在循环中，首先判断当前字符是否为操作符，如果不是，则调用CrtNode函数创建一个节点，并将其压入操作数栈PTR中。
 * 如果当前字符是操作符，则根据不同的情况进行处理：
 * 如果是左括号'('，则直接入操作符栈S。
 * 如果是右括号')'，则从操作符栈S弹出操作符，构造相应的子树，并将子树压入操作数栈PTR，直到遇到左括号'('，然后将左括号'('弹出。
 * 如果是其他操作符，则根据操作符的优先级，从操作符栈S中弹出操作符，构造相应的子树，并将子树压入操作数栈PTR，重复这个过程直到当前操作符的优先级不高于栈顶操作符或者栈为空，然后将当前操作符入栈。
 * 最后将操作数栈PTR中剩余的树赋给T，即整个表达式树的根节点。
 * 这段代码实际上是根据传入的表达式字符串exp创建了一个表达式树，并将根节点保存在T中。整个过程通过栈来实现，其中利用栈来控制操作符的优先级和构建表达式树的结构。
 */
void CrtExpTree(BiTree &T, const char exp[])
{
    std::stack<char> S;      // 操作符栈
    std::stack<BiTree> PTR;  // 操作数栈
    S.push('#');             // 将 '#' 入栈作为栈底标识
    char ch = *exp;          // 从表达式字符串中取出第一个字符
    const char *OP = "/*-+"; // 假设这是操作符集合

    // 循环处理表达式字符串，直到操作符栈顶为 '#' 且当前字符也为 '#'
    while (!(S.top() == '#' && ch == '#'))
    {
        if (!IN(ch, OP)) // 如果当前字符不是操作符
        {
            CrtNode(T, ch, PTR); // 创建一个节点，并将其压入操作数栈
        }
        else // 如果当前字符是操作符
        {
            switch (ch)
            {
            case '(':
                S.push(ch); // 左括号直接入栈
                break;
            case ')':
                // 处理右括号：弹出操作符栈中的操作符，并构造相应的子树，直到遇到左括号
                while (S.top() != '(')
                {
                    char c = S.top();
                    S.pop();
                    BiTree t;
                    CrtSubtree(t, c, PTR); // 根据操作符构造子树
                    PTR.push(t);           // 将子树压入操作数栈
                }
                S.pop(); // 弹出左括号
                break;
            default:
                // 处理其他操作符：根据操作符的优先级构造子树，并将其压入操作数栈
                while (precede(S.top(), ch))
                {
                    char c = S.top();
                    S.pop();
                    BiTree t;
                    CrtSubtree(t, c, PTR); // 根据操作符构造子树
                    PTR.push(t);           // 将子树压入操作数栈
                }
                S.push(ch); // 当前操作符入栈
                break;
            }
        }
        ch = *(++exp); // 处理下一个字符
    }
    T = PTR.top(); // 最终操作数栈中剩下的树就是整个表达式树，将树的根节点赋给 T
}
