#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct
{
    int factor;
    int index;
} ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;
void InitList(LinkList &L)
{
    L = (Node *)malloc(sizeof(Node));
    if (!L)
    {
        printf("error!");
        exit(0);
    }
    L->next = NULL;
}
void ListInput(LinkList &L)
{
    LinkList p = L;
    char ch;
    do
    {
        LinkList s = (Node *)malloc(sizeof(Node));
        scanf("%d%d", &s->data.factor, &s->data.index);
        s->next = NULL;
        p->next = s;
        p = s;
    } while (ch = getchar() != EOF);
}
void ListOutput(LinkList &L)
{
    LinkList p;
    for (p = L->next; p != NULL; p = p->next)
    {
        if (p->data.index != 0)
            printf("%d %d", (p->data.factor) * (p->data.index), p->data.index - 1);
        else
        {
            if (L->next->next == NULL)
            {
                printf("%d 0", (p->data.factor) * (p->data.index));
            }
            else
            {
                continue;
            }
        }
        if (p->next != NULL)
            printf(" ");
    }
}
void DestroyList(LinkList &L)
{
    LinkList p = L, q = L->next;
    for (; q; q = q->next)
    {
        free(p);
        p = q;
    }
}
int main()
{
    LinkList L;
    InitList(L);
    ListInput(L);
    ListOutput(L);
    DestroyList(L);
    system("pause");
}