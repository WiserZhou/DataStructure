
#include "..\header\unity.h"

typedef enum
{
    ATOM, // 原子
    LIST  // 子表
} ELemTag;
typedef int AtomType;

typedef struct GLNode
{
    ELemTag tag; // 标志位，用以区分原子结点和表结点
    union
    {
        AtomType atom;
        struct
        {
            struct GLNode *hp, *tp; // hp指向表头，tp指向表尾
        } ptr;
    };
} *GList;

// 扩展头尾指针的广义表的存储结构
typedef struct GLNode
{
    ELemTag tag;
    union
    {
        AtomType atom;
        struct GLNode *hp;
    };
    struct GLNode *tp;
} *GList2;

// 递归求解广义表的深度
int GListDepth(GList L)
{
    if (!L)
        return 1; // 空表的深度为1
    if (L->tag == ATOM)
        return 0; // 原子的深度为0

    GList pp = L;
    int max;
    for (max = 0; pp; pp = pp->ptr.tp)
    {
        int dep = GListDepth(pp->ptr.hp);
        if (dep > max)
            max = dep;
    }

    return max + 1;
}

// 递归进行广义表的复制
Status CopyGList(GList &T, GList L)
{
    if (!L)
        T = NULL;
    else
    {
        if (!(T = (GList)malloc(sizeof(GLNode))))
            exit(OVERFLOW);

        T->tag = L->tag;

        if (L->tag == ATOM)
            T->atom = L->atom; // 递归的典型套路，先设定特殊临界条件

        else
        {
            CopyGList(T->ptr.hp, L->ptr.hp);
            CopyGList(T->ptr.tp, L->ptr.tp); // 表头和表尾可以唯一确定一个广义表
        }
    }
    return OK;
}
