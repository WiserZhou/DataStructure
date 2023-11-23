

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
    ElemType data;
    struct LNode*next;
}LNode,*LinkList;


Status InitList(LNode &L){
    LinkList L;

}