#pragma once
#include "..\header\unity.h"
#include <iostream>
typedef char VertexType;
typedef int VRType; // vex Relationship type
typedef char InfoType;
#define INFINITY INT32_MAX
#define MAX_VERTEX_NUM 100 // vex 顶点

// 边表的存储类型：
typedef struct ArcNode
{
    int adjVex;              // !该弧所指向的顶点的位置，而不是顶点本身
    VRType adj;              // 弧<v1,v2>的权值，描述带权图时候需要
    struct ArcNode *nextArc; // 指向下一条弧的指针
    InfoType *info;          // 该弧相关信息的指针
} ArcNode;

// 顶点表的存储类型：
typedef struct VNode
{
    VertexType vex;    // 顶点信息
    ArcNode *firstArc; // 指向第一条依附该顶点的弧
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices; // 顶点列表
    int vexNum, arcNum;
    GraphKind kind; // 图的种类标志
} ALGraph;

void CreatAdjList(ALGraph &G)
{

    int kind;
    std::cin >> G.vexNum >> G.arcNum >> kind;
    G.kind = static_cast<GraphKind>(kind);

    for (int i = 1; i <= G.vexNum; i++) // 从1开始，0是空着的，建立顶点列表
    {
        std::cin >> G.vertices[i].vex;
        G.vertices[i].firstArc = nullptr;
    }

    for (int k = 1; k <= G.arcNum; k++)
    {
        int i, j, w;
        std::cin >> i >> j >> w;

        ArcNode *s = (ArcNode *)malloc(sizeof(ArcNode)); // 使用前插法插入结点
        s->adjVex = j;
        s->adj = w;
        s->info = nullptr;
        s->nextArc = G.vertices[i].firstArc;
        G.vertices[i].firstArc = s;

        if (G.kind == UDG || G.kind == UDN)
        {
            ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode));
            q->adjVex = i;
            q->adj = w;
            q->nextArc = G.vertices[j].firstArc;
            G.vertices[j].firstArc = q;
        }
    }
    // 建立无向网络(边带权图) G的邻接表算法详解(1) 对于顶点多边少的图采用邻接表存储节省空
    // 间；空间复杂度O(n + e)。 (2)容易找到任一顶点的第一个邻接点。
}

int FirstAdjVex(ALGraph G, int v)
{
    return G.vertices[v].firstArc->adjVex;
}

int NextAdjVex(ALGraph G, int v, int w)
{
    ArcNode *i = G.vertices[v].firstArc->nextArc;
    while (i->adjVex != w && i != nullptr)
        i = i->nextArc;
    if (i->adjVex == w)
        return i->nextArc->adjVex;
    else
        return 0;
}

void Visit(int v, ALGraph G)
{
    cout << G.vertices[v].vex << endl;
}

void FindInDegree(ALGraph G, int inDegree[])
{
    for (int i = 1; i <= G.vexNum; i++)
    {
        ArcNode *p = G.vertices[i].firstArc;

        while (p)
        {
            ++inDegree[p->adjVex]; // 遍历所有出边表，在每一个结点的inDegree上+1
            p = p->nextArc;
        }
    }
}