// ���Ա����ʽʵ��

#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int elem;
    struct Link *next;
} link;
link *initLink(int n);
// �������ĺ�����p������elem�ǲ���Ľ���������add�ǲ����λ��
link *insertElem(link *p, int elem, int add);
// ɾ�����ĺ�����p�����������add����ɾ���ڵ��λ��
link *delElem(link *p, int add);
// ���ҽ��ĺ�����elemΪĿ������������ֵ
int selectElem(link *p, int elem);
// ���½��ĺ�����newElemΪ�µ��������ֵ
link *amendElem(link *p, int add, int newElem);
void display(link *p);

int main()
{
    
    // ��ʼ������1��2��3��4��
    printf("��ʼ������Ϊ��\n");
    int n;
    printf("������������Ԫ�صĸ�����");
    scanf("%d",&n);
    link *p = initLink(n);
    display(p);

    int a,b;
    printf("������Ҫ�����λ���Լ�Ԫ��ֵ:");
    scanf("%d %d",&a,&b);
    printf("�ڵ�%d��λ�ò���Ԫ��%d:\n",a,b);
    p = insertElem(p, b, a);
    display(p);

    printf("ɾ��Ԫ��3:\n");
    p = delElem(p, 3);
    display(p);

    printf("����Ԫ��2��λ��Ϊ:\n");
    int address = selectElem(p, 2);
    if (address == -1)
    {
        printf("û�и�Ԫ��");
    }
    else
    {
        printf("Ԫ��2��λ��Ϊ:%d\n", address);
    }
    printf("���ĵ�3��λ���ϵ�����Ϊ7:\n");
    p = amendElem(p, 3, 7);
    display(p);

    return 0;
}

// ��ʼ������
link *initLink(int n)
{
    link *p = (link *)malloc(sizeof(link)); // ����һ��ͷ���
    link *temp = p;                         // ����һ��ָ��ָ��ͷ��㣬���ڱ�������
    // ��������
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
    link *temp = p; // ������ʱ���temp
    // �����ҵ�Ҫ����λ�õ���һ�����
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("����λ����Ч\n");
            return p;
        }
    }
    // ����������c
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    // �������в�����
    c->next = temp->next;
    temp->next = c;
    return p;
}

link *delElem(link *p, int add)
{
    link *temp = p;
    // ��������ɾ��������һ�����
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("û�иý��\n");
            return p;
        }
    }
    link *del = temp->next;        // ��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
    temp->next = temp->next->next; // ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
    free(del);                     // �ֶ��ͷŸý�㣬��ֹ�ڴ�й©
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
    temp = temp->next; // tampָ����Ԫ���
    // tempָ��ɾ�����
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
void display(link *p)
{
    link *temp = p; // ��tempָ������ָ��ͷ���
    // ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
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

// // ����һ���յĴ�ͷ�ڵ�����Ա�L
// void InitList(LinkList &L){
//     // LinkList L;
//     L=(LNode *)malloc(sizeof(LNode));
//     L->next=NULL;
// }

// // ����һ���յĲ���ͷ�ڵ�����Ա�L
// void InitList2(LinkList &L){
//     L=NULL;
// }

// // �ж����Ա�L�Ƿ�Ϊ��
// Status ListEmpty(LinkList &L){
//     if(L->next==NULL)
//     return TRUE;
//     else
//     return FALSE;
// }

// // ȡ��iλ�õ�ֵ
// Status GetElem_L(LinkList L ,int i,ElemType &e){
//     LinkList p;
//     int j;
//     p=L->next;j=1;// ˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
//     while(p&&j<i){
//         p=p->next;++j;
//     }
//     if(!p||j>i)   //  i>=1,j�ĳ�ʼֵ��1��j>i��ʾi<1�ǲ������
//     return ERROR; //  ˵����i��Ԫ�ز�����
//     e=p->data;    //  ���ڵĻ�����ȡ�õ�i��Ԫ��
//     return OK;
// }

// // ��iλ�ò���e
// Status ListInsert_L(LinkList L,int i,ElemType e){
//     // LΪ��ͷ���ĵ������ͷָ��
//     // �������������е�i�����֮ǰ�����µ�Ԫ��e
//     LinkList p,s;
//     int j;
//     p=L;j=0;
//     while(p&&j<i-1)
//     {p=p->next;++j;} // Ѱ�ҵ�i-1�����
//     if(!p||j>i) return ERROR; // i���ڱ�����С��1
//     s=(LinkList )malloc(sizeof(LNode));s->data=e;
//     s->next=p->next;p->next=s; // ����
// }

// // ɾ��iλ�õ�Ԫ��
// Status ListDelete_L(LinkList L,int i,ElemType &e){
//     LinkList p,q;
//     int j=0;
//     while(p->next&&j<i-1){p=p->next;++j;}
//     // p�ĺ�̴���Ҫɾ����Ԫ�أ����p->next����Ϊ��
//     if(!(p->next)||j>i-1)// i����1�ͱ�֮��
//     return ERROR;// ɾ����λ�ò�����

//     q=p->next,p->next=q->next;e=q->data;
//     free(q);
//     return OK;
// }

// // ��������������Ϊһ���ձ�
// void ClearList(LinkList L){
//     LinkList p;
//     while(L->next){
//         p=L->next;L->next=p->next;
//         free(p);
//     }
// }

// int main(){
//     //SetConsoleTitle("���������ʽʵ��");
//     LinkList L;
//     //L->next=(LNode *)malloc(sizeof(LNode));
// 	int choose=0;
// 	while(1){
// 		printf("*****************************************\n");
// 		printf("*                                       *\n");
// 		printf("*  ���Ա��˳���ʾ��ʵ�֣�             *\n");
// 		printf("*                                       *\n");
// 		printf("*    1.  ����һ���յ����Ա�             *\n");
// 		printf("*    2.  �����Ա���и�ֵ               *\n");
// 		printf("*    3.  �����Ա��������               *\n");
// 		printf("*    4.  �����Ա��������               *\n");
// 		printf("*    5.  �ж����Ա��Ƿ�Ϊ��             *\n");
// 		printf("*    6.  ��ȡ���Ա�ĳ���               *\n");
// 		printf("*    7.  ��ȡ���Ա�ĳһλ�ö�Ӧ��Ԫ��   *\n");
// 		printf("*    8.  �����Ա�ĳһλ�ò���Ԫ��       *\n");
// 		printf("*    9.  ɾ�����Ա�ĳһλ�õ�Ԫ��       *\n");
// 		printf("*    10. �����Ա�ĳһԪ�ص�ǰ��         *\n");
// 		printf("*    11. �����Ա�ĳһԪ�صĺ��         *\n");
// 		printf("*    12. ��ӡ���Ա�                     *\n");
// 		printf("*    13. �˳�                           *\n");
// 		printf("*                                       *\n");
// 		printf("*****************************************\n");
// 		printf("����������ѡ��");
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
