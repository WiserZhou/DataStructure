

// ѭ���������ز���
// https://blog.csdn.net/qq_34991245/article/details/82533392
#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
    int data;          // ������
    struct List *next; // ָ����

} list, *p_list;

// ֻҪ��Ҫ�޸�headָ����봫��head�ĵ�ַ����**p�������򴫵�headֵ����(*p)��
// ������ͨ�������ƣ�����Ҫ�޸���ͨ������ֵ���贫�����ַ�����򴫵���ͨ������ֵ���ɣ����ã�
// ��������
void creat_list(list **p) // �������Ϊ�գ��򴴽�һ������ָ����ָ���Լ�������Ѱ��β�ڵ㣬��
{                         // ��β�ڵ��ָ����ָ������½ڵ㣬�½ڵ��ָ����ָ��ͷ���
    int item;
    list *temp;
    list *target;
    printf("����ڵ��ֵ,����0����\n");
    while (1)
    {
        scanf("%d", &item);
        if (item == 0)
            break;

        if (*p == NULL) // �������������ǿա��򴴽�һ���µĽڵ㣬ʹ��nextָ��ָ���Լ�  (*head)->next=*head;
        {

            *p = (list *)malloc(sizeof(list)); // ���������½ڵ㿪�ٿռ�
            if (!*p)                           // �����ٿռ�ʧ�ܣ��������˳�
                exit(0);
            (*p)->data = item; // ����ǰָ����ָ���λ�ø�ֵ
            (*p)->next = *p;   // �������еĵ�ǰ�ڵ�� next ָ��ָ�������γ�һ��ѭ���������ѭ������ֻ��һ�����
        }
        else // ����������ǿյģ�Ѱ�������β�ڵ㣬ʹβ�ڵ��next=�½ڵ㡣�½ڵ��nextָ��ͷ�ڵ�
        {
            for (target = *p; target->next != *p; target = target->next) // ��ѭ�������У�β�ڵ��nextָ�����ͷ�ڵ�
                ;                                                        // ����ֺŲ�д�����򲻻ᱨ�����ǻ���ִ�й������쳣�˳�
            // Ѱ��β�ڵ�
            temp = (list *)malloc(sizeof(list)); // Ϊ������½ڵ�����ռ�
            if (!temp)                           // ���ٿռ�ʧ��
                exit(0);
            temp->data = item;   // ���½ڵ��������ֵ
            temp->next = *p;     // �½ڵ�ָ��ͷ�ڵ�
            target->next = temp; // ԭ����β�ڵ�ָ���½ڵ�
        }
    }
}

// ��������ָ��λ�ò�����
void insert(list **pNode, int place, int num)
{
    list *temp, *target;
    int i;
    if (place == 1) // ��������������1����ʾҪ����ͷ�ڵ㡣Ӧ�����⴦��
    {               // �����ҵ�β�ڵ㣬�ú����½ڵ��nextָ��ͷ�ڵ㣬β�ڵ�ָ���µ�ͷ�ڵ㣬����ͷָ��ָ��temp����Ҫ�ر�ע��
        temp = (list *)malloc(sizeof(list));
        if (!temp)
            exit(0);
        temp->data = num;                                                    // �½ڵ��Ѿ������ú͸�ֵ��
        for (target = *pNode; target->next != *pNode; target = target->next) // ��targetָ��β���
            ;

        temp->next = *pNode;
        target->next = temp;
        *pNode = temp; // �ر�ע�⣬��ʱͷ������temp��
    }

    else // �������ĵط�����ڵ㡣  ͬ�����ҵ�Ҫ�����λ�ã����λ�ó�������ĳ��ȣ��Զ������β��						tar  new  ԭ����2
    {    // �ҵ�Ҫ����λ�õ�ǰһ���ڵ�target����target->next=temp������ڵ��ǰ��ָ���½ڵ㣬�½ڵ�ָ��target->next�ĵ�ַ  1    2   3
        for (i = 1, target = *pNode; target->next != *pNode && i != place - 1; target = target->next, i++)
            ;
        temp = (list *)malloc(sizeof(list));
        temp->data = num;

        temp->next = target->next; // ��ͼ���
        target->next = temp;
    }
}

// ɾ��ָ��λ�õĽ��
void Delete(list **pNode, int place) // ɾ������
{
    list *temp, *target;
    int i;
    temp = *pNode;
    if (temp == NULL) // �����ж������Ƿ�Ϊ��
    {
        printf("����һ����ָ�� �޷�ɾ��\n");
        return;
    }
    if (place == 1)                                                          // ���ɾ������ͷ�ڵ�
    {                                                                        // Ӧ�����⴦���ҵ�β�ڵ㣬ʹβ�ڵ��nextָ��ͷ�ڵ����һ���ڵ� rear->next=(*head)->next;
                                                                             // Ȼ�����½ڵ���Ϊͷ�ڵ㣬�ͷ�ԭ����ͷ�ڵ�
        for (target = *pNode; target->next != *pNode; target = target->next) // ʹtargetָ��β���
            ;
        temp = *pNode; // tempָ��ѭ������ͷ�ڵ�ĵ�ַ

        *pNode = (*pNode)->next; // ʹͷ�ڵ����һ�����Ϊͷ�ڵ�
        target->next = *pNode;   // β���ָ���µ�ͷ�ڵ�
        free(temp);              // �ͷŵ�ɾ���Ľ��ռ�
    }
    else
    { // ɾ�������ڵ�
        for (i = 1, target = *pNode; target->next != *pNode && i != place - 1; target = target->next, i++)
            ;                       // �����ҵ�Ҫɾ���Ľ���ǰһ��λ��
        if (target->next == *pNode) // �ж�Ҫɾ����λ���Ƿ���������ȣ������������ȣ����⴦��:ֱ��ɾ��β�ڵ�
        {
            for (target = *pNode; target->next->next != *pNode; target = target->next)
                ;                // �ҳ�β�ڵ��ǰһ���ڵ�
            temp = target->next; //	β�ڵ��ǰһ���ڵ�ֱ��ָ��ͷ�ڵ�  �ͷ�ԭ����β�ڵ�
            target->next = *pNode;
            printf("����̫��ɾ��β��\n");
            free(temp);
        }
        else
        {
            temp = target->next;       //  ɾ����ͨ�ڵ�  �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�target��ʹtargetָ��Ҫɾ���ڵ����һ���ڵ�  ת��ɾ���ڵ��ַ
            target->next = temp->next; //  Ȼ���ͷ�����ڵ�
            free(temp);                //  ͨ��ָ��������Ҫɾ���ڵ��λ�ã�����ɾ�����ýڵ�
        }
    }
}

int findval(list *pNode, int val) // Ѱ��ֵ
{
    int i = 1;
    list *node;
    node = pNode;
    while (node->data != val && node->next != pNode)  // �˳�ѭ�����������ҵ���ָ��ֵ���ߵ�����β�ڵ㴦
    {
        i++;
        node = node->next;
    }
    if (node->next == pNode && node->data != val) // β�ڵ�ָ��ͷ�ڵ����������˻�Ҫ���һ��Ϊ�ڵ��data
    {
        return -1;
    }
    return i;
}

void show(list *p) // ������ѭ������ı��������do while��� ����Ϊͷ�ڵ����ֵ
{
    list *temp;
    temp = p;
    do
    {
        printf("%5d", temp->data);
        temp = temp->next;
    } while (temp != p);

    printf("\n");
}

int main()
{
    list *head = NULL;
    // list *val;
    int place, num;
    creat_list(&head);
    printf("ԭʼ������");
    show(head);

    printf("����Ҫɾ����λ�ã�");
    scanf("%d", &place);
    Delete(&head, place);
    show(head);

    printf("����Ҫ�����λ�ú������ÿո������");
    scanf("%d %d", &place, &num);
    insert(&head, place, num);
    show(head);

    printf("����������ҵ�ֵ:");
    scanf("%d", &num);
    place = findval(head, num);
    if (place != -1)
        printf("�ҵ���ֵ��λ����place=%d\n", place);
    else
        printf("û�ҵ�ֵ\n");

    return 0;
}