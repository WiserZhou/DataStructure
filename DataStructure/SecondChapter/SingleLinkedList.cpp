
#include "..\header\unity.h"
/**
 * 结构体，包含data数据和next指针
 */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 此时用LinkList定义的变量是指针，可以用来遍历访问链表
/**
 * 初始化链表，设置一个头结点
 */
Status initList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    L->data = 0;
    return OK;
}
/**
 * 判断链表是否为空
 */
Status ListEmpty(LinkList L)
{
    if (L == NULL || (L->next == NULL && L->data == 0))
        return TRUE;
    else
        return FALSE;
}
/**
 * 获取第i个元素的值
 */
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
/**
 * 在第i个位置插入元素e
 */
Status insertElem(LinkList &L, int i, ElemType e)
{
    LinkList p = L;
    int j = 0;
    while (p && j++ < i - 1) // 将指针移动到i-1的位置，方便后面的插入
        p = p->next;
    if (!p || j > i - 1)
        return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
/**
 * 清空整个链表的空间
 */
Status clearList(LinkList &L)
{
    while (L->next)
    {
        LinkList p = L->next;
        L->next = p->next;
        free(p);
        p = nullptr;
    } // 神奇方法，一直利用->next来释放对象，同时保持后面的结点仍然连接在头结点上
    return OK;
}
/**
 * 删除位置i的元素
 */
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
    q = nullptr;
    return OK;
}
/**
 * 头插法
 */
Status insertHead(LinkList &L)
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    scanf("%d", &p->data); // scanf将数据写进地址所在的位置
    p->next = L->next;     // 将新的结点插在开头
    L->next = p;
    return OK;
}
/**
 * 尾插法
 */
Status insertEnd(LinkList &L)
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if (!p)
        exit(OVERFLOW);
    LinkList q = L;
    while (!(q->next))
        q = q->next;
    scanf("%d", &p->data);
    q->next = p;
    p->next = nullptr;
    return OK;
}
/**
 * 按照顺序合并两个链表，要求两个链表之前就已经进行了排序
 */
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
/**
 * 通过值找到在链表中的位置
 */
int getIndexByElem(LinkList L, ElemType e)
{
    LinkList p = L;
    int i = 1;
    while (!(p->next))
    {
        p = p->next;
        if (p->data == e)
            return i;
        else
            i++;
    }
    return ERROR;
}
