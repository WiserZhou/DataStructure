// �ٶ���һ��ѭ���������ʾ���У��ö�
// ��ֻ��һ����βָ��rear������ͷָ�룬����
// ͷ��㣺
//  д����
//  (1)����㷨(���Ԫ��Ϊx)��
//  (2)�����㷨

void ENQUEUE(elementtype x, node *rear)
{
    node *p;
    p = (node *)malloc(sizeof(node)); // �����½��
    p->element = x;                   // x�����½��

    if (rear == NULL)
    { // �������Ϊ�գ���rearΪNULL������rearָ���½��p������p��nextָ������Ȼ�󷵻�
        rear = p;
        rear->next = rear;
    }
    else
    { // ��p��nextָ��rear->next����rear->nextָ���½��p�����rearָ���½��p
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}

void DEQUEUE(node *rear)
{
    node *p;
    if (rear == NULL)
        error("���п�");
    else
    {
        p = rear->next;
        if (rear == rear->next) // ��ʾ��������ֻ��һ�����
        {                       // only one node
            rear = NULL;
        }
        else
        {
            rear->next = p->next; // ��rear����һ�����ָ��p�ĺ�̽��
        }
        free(p); // �ͷ�p��ָ�Ľ��
    }
}
