
#include "..\header\unity.h"

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 此时用LinkList定义的变量是指针，可以用来遍历访问链表
Status initList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

Status ListEmpty(LinkList L)
{
    if (L == NULL || (L->next == NULL && L->data == NULL))
        return TRUE;
    else
        return FALSE;
}
Status getElem(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j++ < i)
        p = p->next;
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}
Status insertElem(LinkList &L, int i, ElemType e)
{
    LinkList p = L;
    int j = 0;
    while (p && j++ < i - 1)
        p = p->next;
    if (!p || j > i - 1)
        return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status clearList(LinkList &L)
{
    while (L->next)
    {
        LinkList p = L->next;
        L->next = p->next;
        free(p);
    } // 神奇方法，一直利用->next来释放对象
}
Status deleteElem(LinkList &L, int i, ElemType &e)
{
    LinkList p = L;
    int j = 0;
    while (p->next && j++ < i - 1)
        p = p->next;
    if (!(p->next) || (j > i - 1))
        return ERROR;
    LinkList q = p->next; // 使用要删除的结点的前一个结点，方便对后面的进行操作，因为结点只有后继的指针。
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

Status insertHead(LinkList &L, int n)
{
    for (int i = n; i > 0; i++)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data); // scanf将数据写进地址所在的位置
        p->next = L->next;     // 将新的结点插在开头
        L->next = p;
    }
    return OK;
}
Status insertEnd(LinkList &L, int n)
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if (!p)
        exit(OVERFLOW);
    LinkList q = L;
    for (int i = 0; i < n; i++)
    {
        q = q->next;
    }
    scanf("%d", &p->data);
    q->next = p;
    q = p;
    q->next = NULL;
    return OK;
}
Status mergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    // 头结点都是空的，只保存着下一个结点的指针
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc = Lc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb; // 这里pc之后会接上pa或者pb的部分结点，所以不可以进行释放。
    
    return OK;
}
