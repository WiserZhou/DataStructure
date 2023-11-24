#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20
#define INFINITY 999999

typedef struct ArcNode
{
    int adjVex;
    struct ArcNode *nextArc;
    int info;
} ArcNode;

typedef struct vnode
{
    int data;
    ArcNode *firstArc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexNum, arcNum;
    int kind;
} ALGraph;

void ShortestPath_DIJ(ALGraph G, int v0, int P[], float D[])
{
    int i, v, w, min;
    int final[MAX_VERTEX_NUM];
    ArcNode *p;

    for (v = 0; v < G.vexNum; ++v)
    {
        final[v] = 0;
        D[v] = INFINITY;
        P[v] = -1;
        if (v == v0)
            D[v] = 0;
    }

    for (i = 0; i < G.vexNum; ++i)
    {
        min = INFINITY;
        for (w = 0; w < G.vexNum; ++w)
            if (!final[w] && D[w] < min)
            {
                v = w;
                min = D[w];
            }
        final[v] = 1;

        for (p = G.vertices[v].firstArc; p; p = p->nextArc)
        {
            w = p->adjVex;
            if (!final[w] && D[v] + p->info < D[w])
            {
                D[w] = D[v] + p->info;
                P[w] = v;
            }
        }
    }
}

int main()
{
    // 初始化图G
    ALGraph G;
    // ...（省略）

    int P[MAX_VERTEX_NUM];
    float D[MAX_VERTEX_NUM];
    ShortestPath_DIJ(G, 0, P, D); // 假设从第0个顶点开始寻找最短路径

    int i, pre;
    for (i = 0; i < G.vexNum; i++)
    {
        printf("%f\n%d", D[i], i);
        pre = P[i];
        while (pre != -1)
        {
            printf("->%d", pre);
            pre = P[pre];
        }
        printf("\n");
    }

    return 0;
}
