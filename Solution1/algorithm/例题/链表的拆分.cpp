

// 题目:
// 编写一个算法,将一个头结点指针为A的单链表A
// 分解成两个单链表A和B。
//  其头结点指针分别为A和B。
//  使得A链表中含有原链表A中序号为奇数的元素。
//  B链表中含有原链表A中序号为偶数的元素。
//  保持原来的相对顺序

void disa(LIST &A, LIST &B)
{
    B->next = NULL;
    position r = B, p = A->next, q;

    while (p != NULL && p->next != NULL)
    {
        q = p->next; // q指向偶数结点

        p->next = q->next; // 将q从链表A中删除
        r->next = q;       // 将q插入到链表B中
        r = q;

        p = p->next; // p指向下一个奇数结点
    }

    r->next = NULL; // 将链表B的尾结点指向NULL
}

void splitList(LIST A, LIST B)
{
    if (A == NULL || A->next == NULL)
    {
        // A链表为空或只有一个结点，不需要分解
        return;
    }

    position p = A->next;
    position q = B;

    while (p != NULL)
    {
        // 取出当前结点
        position tmp = p;
        p = p->next;

        // 插入到对应的链表
        if (tmp->index % 2 == 1)
        {
            tmp->next = A->next;
            A->next = tmp;
        }
        else
        {
            tmp->next = q->next;
            q->next = tmp;
            q = tmp;
        }
    }

    // 将链表A和B的尾结点指向NULL
    A->next->prev = NULL;
    q->next->prev = NULL;
    A->next->prev = q;
    q->next = NULL;
}
