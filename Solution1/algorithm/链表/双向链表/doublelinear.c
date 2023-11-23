

// ˫�����ж����ݽ��� "��ɾ���" ����
#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    struct line *prior; // ����ǰָ�룬ָ��ǰ��
    int data;
    struct line *next; // �����ָ�룬ָ����
} line;

// ˫����Ĵ���
line *initLine(line *head);
// ˫�������Ԫ�أ�add��ʾ����λ��
line *insertLine(line *head, int data, int add);
// ˫����ɾ��ָ��Ԫ��
line *delLine(line *head, int data);

line *dellLine(line *head, int add);
// ˫�����в���ָ��Ԫ��
int selectElem(line *head, int elem);
// ˫�����и���ָ��λ�ýڵ��д洢�����ݣ�add��ʾ����λ��
line *amendElem(line *p, int add, int newElem);
// ���˫�����ʵ�ֺ���
void display(line *head);
int main()
{
    line *head = NULL;
    // ����˫����
    head = initLine(head);
    display(head);
    // �ڱ��е� 3 ��λ�ò���Ԫ�� 7
    head = insertLine(head, 7, 3);
    display(head);
    // ����ɾ��Ԫ�� 2
    head = delLine(head, 2);
    display(head);
    // ����ɾ��β�ڵ�λ�õ�Ԫ��
    head = dellLine(head, 5);
    display(head);

    printf("Ԫ�� 3 ��λ���ǣ�%d\n", selectElem(head, 3));
    // ���е� 3 ���ڵ��е����ݸ�Ϊ�洢 6
    head = amendElem(head, 3, 6);
    display(head);
    return 0;
}

// ��ʼ��˫������
line *initLine(line *head)
{
    head = (line *)malloc(sizeof(line)); // ��ͷ�ڵ㿪�ٿռ�
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    line *list = head; // ����ṹ��ָ��ָ��ͷ�ڵ㣬��һ�β���list���ǲ���head
    for (int i = 2; i <= 5; i++)
    {
        line *body = (line *)malloc(sizeof(line)); // ÿһ����㶼Ҫ���ٿռ�
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;  // list��ָ��ָ�򴴽���һ���½ڵ���
        body->prior = list; // �������½ڵ�ǰָ��ָ��list�������Ͱ������������������
        list = list->next;  // listָ����һ�����
    }
    return head; // ����ѭ��֮�����head�ʹ�����һ��˫��������
}

// ��˫��������ָ��λ�ò���ָ��Ԫ��
line *insertLine(line *head, int data, int add)
{
    // �½�������Ϊdata�Ľ��
    line *temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    // ���뵽����ͷ��Ҫ���⿼��
    if (add == 1)
    {
        temp->next = head;  // �������½ڵ�ĺ�ָ��ָ��ԭ˫�������ͷ�ڵ��λ��
        head->prior = temp; // ͷ�ڵ��ǰָ��ָ�򴴽��Ľڵ�
        head = temp;        // temp ��ʱ�����ͷ�ڵ�
    }
    else
    {
        line *body = head;
        // �ҵ�Ҫ����λ�õ�ǰһ����㣬ͨ���ƶ�ָ������
        for (int i = 1; i < add - 1; i++)
        {
            body = body->next; // body������ָ��Ҫɾ���ڵ�ĵ�ַ�ģ����ں����Ĳ���
        }
        // �ж�����Ϊ�棬˵������λ��Ϊ����β
        if (body->next == NULL)
        {
            body->next = temp;
            temp->prior = body;
        }
        else
        {
            body->next->prior = temp; // �����д��뻭ͼ�����
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;
        }
    }
    return head;
}

// ��˫��������ָ��λ�õĽ��ɾ��
line *dellLine(line *head, int add)
{
    line *temp = head;  // ����һ���ṹ��ָ�룬ָ��head��ͷ�ڵ�ĵ�ַ��ͨ��������ҵ�Ҫɾ���ڵ��λ��
    if (add == 1) // Ҫɾ����λ�øպ���ͷ�ڵ�
    {
        
        temp->next->prior = NULL; // ֱ����temp����һ���ڵ��ǰ��ָ���
        head=temp->next;
        temp->next=NULL;   // ͷ�ڵ��βָ��ָ���
        free(temp);       // �ͷ�ͷ�ڵ�Ŀռ�
        // return head;
    }
    else
    {
        for (int i = 1; i < add; i++)// ��tempָ���ƶ���ָ����λ��ȥ
        {
            temp = temp->next;
        }
        if (temp->next == NULL)  // Ҫɾ���Ľ����β�ڵ�
        {
            temp->prior->next = NULL;
            temp->prior=NULL;
            free(temp);
        }
        else
        {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
        }
    }
    return head;
}

// ժ�������е���ͬԪ��
line *delLine(line *head, int data)
{
    line *temp = head;
    // ��������
    while (temp)
    {
        // �жϵ�ǰ������������data�Ƿ���ȣ�����ȣ�ժ���ý��
        if (temp->data == data)
        {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp); // ��temp���ڽڵ�Ŀռ��ͷŵ�
            return head;
        }
        temp = temp->next; // �ȽϺ���ȵĻ���tempָ����һ���ڵ㣬������һ��ѭ��
    }
    printf("�������޸�����Ԫ��"); // ���Ǳ������������飬��û���ҵ�ָ��Ԫ�ص����
    return head;
}

// headΪԭ˫����elem��ʾ������Ԫ��
int selectElem(line *head, int elem)
{
    // �½�һ��ָ��t����ʼ��Ϊͷָ�� head
    line *t = head;
    int i = 1;
    while (t)
    {
        if (t->data == elem)
        {
            return i;
        }
        i++;
        t = t->next;
    }
    // ����ִ�����˴�����ʾ����ʧ��
    return -1;
}

// ���º��������У�add ��ʾ���Ľ����˫�����е�λ�ã�newElem Ϊ�����ݵ�ֵ
line *amendElem(line *head, int add, int newElem)
{
    line *temp = head; // ͨ��ָ������������
    // ��������ɾ�����
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->data = newElem; // ��ָ����㴦��Ԫ��ֵ�ĵ�����
    return head;
}

// �������Ĺ��ܺ���
void display(line *head)
{
    line *temp = head;  // ���һ�������ѭ��
    while (temp)
    {
        if (temp->next == NULL)
        {
            printf("%d\n", temp->data);
        }
        else
        {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }
}




// #include <stdio.h>
// #include <stdlib.h>
// // �ڵ�ṹ
// typedef struct line
// {
//     struct line *prior; // ǰ��㣬ָ��ǰ��
//     int data;
//     struct line *next; //  ���㣬ָ����
// } line;

// // ˫����Ĵ�������
// line *initLine(line *head);
// // ���˫����ĺ���
// void display(line *head);

// int main()
// {
//     // ����һ��ͷָ��
//     line *head = NULL;
//     // ��������������
//     head = initLine(head);
//     // ��������õ�����
//     display(head);
//     // ��ʾ˫������ŵ�
//     printf("�����е� 4 ���ڵ��ֱ��ǰ���ǣ�%d", head->next->next->next->prior->data);
//     return 0;
// }
// line *initLine(line *head)
// {
//     // ����һ����Ԫ�ڵ㣬�����ͷָ��Ϊhead
//     head = (line *)malloc(sizeof(line));
//     // �Խڵ���г�ʼ��
//     head->prior = NULL;
//     head->next = NULL;
//     head->data = 1;
//     // ����һ��ָ����Ԫ�ڵ��ָ�룬�������������������´����Ľڵ�
//     line *list = head;
//     for (int i = 2; i <= 5; i++)
//     {
//         // �����µĽڵ㲢��ʼ��
//         line *body = (line *)malloc(sizeof(line));// �����µĽڵ�ʱ����ǰһ���ڵ�ͺ�һ����㶼ָ��գ�
//         body->prior = NULL;
//         body->next = NULL;
//         body->data = i;

//         // �½ڵ����������һ���ڵ㽨����ϵ
//         list->next = body;
//         body->prior = list;
//         // list��Զָ�����������һ���ڵ�
//         list = list->next;
//     }
//     // �����´���������
//     return head;
// }
// void display(line *head)
// {
//     line *temp = head;
//     while (temp)
//     {
//         // ����ýڵ��޺�̽ڵ㣬˵���˽ڵ�����������һ���ڵ�
//         if (temp->next == NULL)
//         {
//             printf("%d\n", temp->data);
//         }
//         else
//         {
//             printf("%d <-> ", temp->data);
//         }
//         temp = temp->next;
//     }
// }