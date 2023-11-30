
// 题目:
// 已知带头结点的单链表L,至少有两个元素，逆置
// 该单链表，不许生成新结点

//  原始代码
void reverse(LIST L)
{
    position p, q;
    p = L->next->next;
    L->next->next = NULL;

    while (p != NULL)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}
//  这段代码没有对头结点进行判空处理，因此在调用函数前，确保传入的链表L至少有两个元素，并且头结点L不为空

// 改进后的代码
void reverse(LIST L)
{
    if (L->next == NULL || L->next->next == NULL)
    {
        // 链表为空或只有一个结点，不需要逆置
        return;
    }

    position p, q, r;
    p = L->next;
    q = p->next;
    p->next = NULL; // 将第一个结点作为逆置后的最后一个结点

    while (q != NULL)
    {
        r = q->next; // 保存下一个结点的地址
        q->next = p; // 反转指针指向
        p = q;       // 移动p和q指针
        q = r;
    }

    L->next = p; // 修改头结点的指向，指向逆置后的第一个结点
}
