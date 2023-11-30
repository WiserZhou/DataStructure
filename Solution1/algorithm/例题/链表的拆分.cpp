

// ��Ŀ:
// ��дһ���㷨,��һ��ͷ���ָ��ΪA�ĵ�����A
// �ֽ������������A��B��
//  ��ͷ���ָ��ֱ�ΪA��B��
//  ʹ��A�����к���ԭ����A�����Ϊ������Ԫ�ء�
//  B�����к���ԭ����A�����Ϊż����Ԫ�ء�
//  ����ԭ�������˳��

void disa(LIST &A, LIST &B)
{
    B->next = NULL;
    position r = B, p = A->next, q;

    while (p != NULL && p->next != NULL)
    {
        q = p->next; // qָ��ż�����

        p->next = q->next; // ��q������A��ɾ��
        r->next = q;       // ��q���뵽����B��
        r = q;

        p = p->next; // pָ����һ���������
    }

    r->next = NULL; // ������B��β���ָ��NULL
}

void splitList(LIST A, LIST B)
{
    if (A == NULL || A->next == NULL)
    {
        // A����Ϊ�ջ�ֻ��һ����㣬����Ҫ�ֽ�
        return;
    }

    position p = A->next;
    position q = B;

    while (p != NULL)
    {
        // ȡ����ǰ���
        position tmp = p;
        p = p->next;

        // ���뵽��Ӧ������
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

    // ������A��B��β���ָ��NULL
    A->next->prev = NULL;
    q->next->prev = NULL;
    A->next->prev = q;
    q->next = NULL;
}
