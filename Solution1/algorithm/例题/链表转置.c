
// ��Ŀ:
// ��֪��ͷ���ĵ�����L,����������Ԫ�أ�����
// �õ��������������½��

//  ԭʼ����
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
//  ��δ���û�ж�ͷ�������пմ�������ڵ��ú���ǰ��ȷ�����������L����������Ԫ�أ�����ͷ���L��Ϊ��

// �Ľ���Ĵ���
void reverse(LIST L)
{
    if (L->next == NULL || L->next->next == NULL)
    {
        // ����Ϊ�ջ�ֻ��һ����㣬����Ҫ����
        return;
    }

    position p, q, r;
    p = L->next;
    q = p->next;
    p->next = NULL; // ����һ�������Ϊ���ú�����һ�����

    while (q != NULL)
    {
        r = q->next; // ������һ�����ĵ�ַ
        q->next = p; // ��תָ��ָ��
        p = q;       // �ƶ�p��qָ��
        q = r;
    }

    L->next = p; // �޸�ͷ����ָ��ָ�����ú�ĵ�һ�����
}
