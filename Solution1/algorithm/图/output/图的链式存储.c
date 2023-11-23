#include<stdio.h>

#define MAX_VERTEX_NUM  20

typedef struct ArcNode
{
    int adjvex;
    int adj;
    struct ArcNode *nextarc;
    char *info;
}ArcNode;

typedef struct vnode
{
    int data;
    ArcNode *firstarc;
}vnode,adjlist[MAX_VERTEX_NUM];



