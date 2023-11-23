

// 循环链表的相关操作
// https://blog.csdn.net/qq_34991245/article/details/82533392
#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
    int data;          // 数据域
    struct List *next; // 指针域

} list, *p_list;

// 只要是要修改head指针必须传递head的地址（用**p），否则传递head值即可(*p)。
// 这与普通变量类似，当需要修改普通变量的值，需传递其地址，否则传递普通变量的值即可（引用）
// 创建链表
void creat_list(list **p) // 如果链表为空，则创建一个链表，指针域指向自己，否则寻找尾节点，将
{                         // 将尾节点的指针域指向这个新节点，新节点的指针域指向头结点
    int item;
    list *temp;
    list *target;
    printf("输入节点的值,输入0结束\n");
    while (1)
    {
        scanf("%d", &item);
        if (item == 0)
            break;

        if (*p == NULL) // 如果输入的链表是空。则创建一个新的节点，使其next指针指向自己  (*head)->next=*head;
        {

            *p = (list *)malloc(sizeof(list)); // 给创建的新节点开辟空间
            if (!*p)                           // 若开辟空间失败，则正常退出
                exit(0);
            (*p)->data = item; // 给当前指针所指向的位置赋值
            (*p)->next = *p;   // 将链表中的当前节点的 next 指针指向自身，形成一个循环链表。这个循环链表只有一个结点
        }
        else // 输入的链表不是空的，寻找链表的尾节点，使尾节点的next=新节点。新节点的next指向头节点
        {
            for (target = *p; target->next != *p; target = target->next) // 在循环链表中，尾节点的next指向的是头节点
                ;                                                        // 这个分号不写，程序不会报错，但是会在执行过程中异常退出
            // 寻找尾节点
            temp = (list *)malloc(sizeof(list)); // 为插入的新节点申请空间
            if (!temp)                           // 开辟空间失败
                exit(0);
            temp->data = item;   // 给新节点的数据域赋值
            temp->next = *p;     // 新节点指向头节点
            target->next = temp; // 原来的尾节点指向新节点
        }
    }
}

// 向链表中指定位置插入结点
void insert(list **pNode, int place, int num)
{
    list *temp, *target;
    int i;
    if (place == 1) // 如果输入的数字是1，表示要插入头节点。应该特殊处理
    {               // 首先找到尾节点，让后让新节点的next指向头节点，尾节点指向新的头节点，在让头指针指向temp。这要特别注意
        temp = (list *)malloc(sizeof(list));
        if (!temp)
            exit(0);
        temp->data = num;                                                    // 新节点已经创建好和赋值了
        for (target = *pNode; target->next != *pNode; target = target->next) // 让target指向尾结点
            ;

        temp->next = *pNode;
        target->next = temp;
        *pNode = temp; // 特别注意，此时头结点就是temp了
    }

    else // 在其他的地方插入节点。  同样先找到要插入的位置，如果位置超出链表的长度，自动插入队尾。						tar  new  原来是2
    {    // 找到要插入位置的前一个节点target，让target->next=temp，插入节点的前驱指向新节点，新节点指向target->next的地址  1    2   3
        for (i = 1, target = *pNode; target->next != *pNode && i != place - 1; target = target->next, i++)
            ;
        temp = (list *)malloc(sizeof(list));
        temp->data = num;

        temp->next = target->next; // 画图理解
        target->next = temp;
    }
}

// 删除指定位置的结点
void Delete(list **pNode, int place) // 删除操作
{
    list *temp, *target;
    int i;
    temp = *pNode;
    if (temp == NULL) // 首先判断链表是否为空
    {
        printf("这是一个空指针 无法删除\n");
        return;
    }
    if (place == 1)                                                          // 如果删除的是头节点
    {                                                                        // 应当特殊处理，找到尾节点，使尾节点的next指向头节点的下一个节点 rear->next=(*head)->next;
                                                                             // 然后让新节点作为头节点，释放原来的头节点
        for (target = *pNode; target->next != *pNode; target = target->next) // 使target指向尾结点
            ;
        temp = *pNode; // temp指向循环链表头节点的地址

        *pNode = (*pNode)->next; // 使头节点的下一个结点为头节点
        target->next = *pNode;   // 尾结点指向新的头节点
        free(temp);              // 释放掉删除的结点空间
    }
    else
    { // 删除其他节点
        for (i = 1, target = *pNode; target->next != *pNode && i != place - 1; target = target->next, i++)
            ;                       // 首先找到要删除的结点的前一个位置
        if (target->next == *pNode) // 判断要删除的位置是否大于链表长度，若大于链表长度，特殊处理:直接删除尾节点
        {
            for (target = *pNode; target->next->next != *pNode; target = target->next)
                ;                // 找出尾节点的前一个节点
            temp = target->next; //	尾节点的前一个节点直接指向头节点  释放原来的尾节点
            target->next = *pNode;
            printf("数字太大删除尾巴\n");
            free(temp);
        }
        else
        {
            temp = target->next;       //  删除普通节点  找到要删除节点的前一个节点target，使target指向要删除节点的下一个节点  转存删除节点地址
            target->next = temp->next; //  然后释放这个节点
            free(temp);                //  通过指针来访问要删除节点的位置，进而删除掉该节点
        }
    }
}

int findval(list *pNode, int val) // 寻找值
{
    int i = 1;
    list *node;
    node = pNode;
    while (node->data != val && node->next != pNode)  // 退出循环的条件：找到了指定值或者到达了尾节点处
    {
        i++;
        node = node->next;
    }
    if (node->next == pNode && node->data != val) // 尾节点指向头节点就跳出，因此还要检测一次为节点的data
    {
        return -1;
    }
    return i;
}

void show(list *p) // 遍历，循环链表的遍历最好用do while语句 ，因为头节点就有值
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
    printf("原始的链表：");
    show(head);

    printf("输入要删除的位置：");
    scanf("%d", &place);
    Delete(&head, place);
    show(head);

    printf("输入要插入的位置和数据用空格隔开：");
    scanf("%d %d", &place, &num);
    insert(&head, place, num);
    show(head);

    printf("输入你想查找的值:");
    scanf("%d", &num);
    place = findval(head, num);
    if (place != -1)
        printf("找到的值的位置是place=%d\n", place);
    else
        printf("没找到值\n");

    return 0;
}