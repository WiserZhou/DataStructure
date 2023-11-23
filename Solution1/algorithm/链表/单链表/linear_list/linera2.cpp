// 线性表的链式实现

#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int elem;
    struct Link *next;
} link;
link *initLink(int n);
// 链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link *insertElem(link *p, int elem, int add);
// 删除结点的函数，p代表操作链表，add代表删除节点的位置
link *delElem(link *p, int add);
// 查找结点的函数，elem为目标结点的数据域的值
int selectElem(link *p, int elem);
// 更新结点的函数，newElem为新的数据域的值
link *amendElem(link *p, int add, int newElem);
void display(link *p);

int main()
{
    
    // 初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    int n;
    printf("请输入链表中元素的个数：");
    scanf("%d",&n);
    link *p = initLink(n);
    display(p);

    int a,b;
    printf("请输入要插入的位置以及元素值:");
    scanf("%d %d",&a,&b);
    printf("在第%d的位置插入元素%d:\n",a,b);
    p = insertElem(p, b, a);
    display(p);

    printf("删除元素3:\n");
    p = delElem(p, 3);
    display(p);

    printf("查找元素2的位置为:\n");
    int address = selectElem(p, 2);
    if (address == -1)
    {
        printf("没有该元素");
    }
    else
    {
        printf("元素2的位置为:%d\n", address);
    }
    printf("更改第3的位置上的数据为7:\n");
    p = amendElem(p, 3, 7);
    display(p);

    return 0;
}

// 初始化链表
link *initLink(int n)
{
    link *p = (link *)malloc(sizeof(link)); // 创建一个头结点
    link *temp = p;                         // 声明一个指针指向头结点，用于遍历链表
    // 生成链表
    for (int i = 0; i < n; i++)
    {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i+1;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
link *insertElem(link *p, int elem, int add)
{
    link *temp = p; // 创建临时结点temp
    // 首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p;
        }
    }
    // 创建插入结点c
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    // 向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return p;
}

link *delElem(link *p, int add)
{
    link *temp = p;
    // 遍历到被删除结点的上一个结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("没有该结点\n");
            return p;
        }
    }
    link *del = temp->next;        // 单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; // 删除某个结点的方法就是更改前一个结点的指针域
    free(del);                     // 手动释放该结点，防止内存泄漏
    return p;
}
int selectElem(link *p, int elem)
{
    link *t = p;
    int i = 1;
    while (t->next)
    {
        t = t->next;
        if (t->elem == elem)
        {
            return i;
        }
        i++;
    }
    return -1;
}
link *amendElem(link *p, int add, int newElem)
{
    link *temp = p;
    temp = temp->next; // tamp指向首元结点
    // temp指向被删除结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
void display(link *p)
{
    link *temp = p; // 将temp指针重新指向头结点
    // 只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}




// #include<stdio.h>
// #include<stdlib.h>
// #include<malloc.h>
// #include<Windows.h>

// #define TRUE    1
// #define FALSE   0
// #define OK      1
// #define ERROR   0

// typedef int ElemType;
// typedef int Status;

// typedef struct LNode
// {
//     ElemType data;
//     struct LNode*next;
// }LNode,*LinkList;

// // 构造一个空的带头节点的线性表L
// void InitList(LinkList &L){
//     // LinkList L;
//     L=(LNode *)malloc(sizeof(LNode));
//     L->next=NULL;
// }

// // 构造一个空的不带头节点的线性表L
// void InitList2(LinkList &L){
//     L=NULL;
// }

// // 判断线性表L是否为空
// Status ListEmpty(LinkList &L){
//     if(L->next==NULL)
//     return TRUE;
//     else
//     return FALSE;
// }

// // 取到i位置的值
// Status GetElem_L(LinkList L ,int i,ElemType &e){
//     LinkList p;
//     int j;
//     p=L->next;j=1;// 顺指针向后查找，直到p指向第i个元素或p为空
//     while(p&&j<i){
//         p=p->next;++j;
//     }
//     if(!p||j>i)   //  i>=1,j的初始值是1，j>i表示i<1是不合理的
//     return ERROR; //  说明第i个元素不存在
//     e=p->data;    //  存在的话就是取得第i个元素
//     return OK;
// }

// // 在i位置插入e
// Status ListInsert_L(LinkList L,int i,ElemType e){
//     // L为带头结点的单链表的头指针
//     // 本函数在链表中第i个结点之前插入新的元素e
//     LinkList p,s;
//     int j;
//     p=L;j=0;
//     while(p&&j<i-1)
//     {p=p->next;++j;} // 寻找第i-1个结点
//     if(!p||j>i) return ERROR; // i大于表长或者小于1
//     s=(LinkList )malloc(sizeof(LNode));s->data=e;
//     s->next=p->next;p->next=s; // 插入
// }

// // 删除i位置的元素
// Status ListDelete_L(LinkList L,int i,ElemType &e){
//     LinkList p,q;
//     int j=0;
//     while(p->next&&j<i-1){p=p->next;++j;}
//     // p的后继代表要删除的元素，因此p->next不能为空
//     if(!(p->next)||j>i-1)// i不在1和表长之间
//     return ERROR;// 删除的位置不合理

//     q=p->next,p->next=q->next;e=q->data;
//     free(q);
//     return OK;
// }

// // 将单链表重新置为一个空表
// void ClearList(LinkList L){
//     LinkList p;
//     while(L->next){
//         p=L->next;L->next=p->next;
//         free(p);
//     }
// }

// int main(){
//     //SetConsoleTitle("单链表的链式实现");
//     LinkList L;
//     //L->next=(LNode *)malloc(sizeof(LNode));
// 	int choose=0;
// 	while(1){
// 		printf("*****************************************\n");
// 		printf("*                                       *\n");
// 		printf("*  线性表的顺序表示和实现：             *\n");
// 		printf("*                                       *\n");
// 		printf("*    1.  构造一个空的线性表             *\n");
// 		printf("*    2.  对线性表进行赋值               *\n");
// 		printf("*    3.  对线性表进行销毁               *\n");
// 		printf("*    4.  对线性表进行重置               *\n");
// 		printf("*    5.  判断线性表是否为空             *\n");
// 		printf("*    6.  获取线性表的长度               *\n");
// 		printf("*    7.  获取线性表某一位置对应的元素   *\n");
// 		printf("*    8.  在线性表某一位置插入元素       *\n");
// 		printf("*    9.  删除线性表某一位置的元素       *\n");
// 		printf("*    10. 求线性表某一元素的前驱         *\n");
// 		printf("*    11. 求线性表某一元素的后继         *\n");
// 		printf("*    12. 打印线性表                     *\n");
// 		printf("*    13. 退出                           *\n");
// 		printf("*                                       *\n");
// 		printf("*****************************************\n");
// 		printf("请做出您的选择：");
// 		scanf("%d",&choose);
// 		switch(choose){
// 			case 1:InitList(L);break;
// 			case 2:ListEmpty(L);break;
// 			case 3:ClearList(L);break;
// 			case 4:ClearList(L);break;
// 			case 5:ListEmpty(L);break;
// 		}
// 	}
// 	return 0;
// }
