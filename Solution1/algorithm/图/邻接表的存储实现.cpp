

#include <stdio.h>
#include <stdlib.h>

// 定义顶点和边的数据类型
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef int VRType;

// 边表结点的定义
typedef struct ArcNode
{
    int adjvex;              // 该弧所指向的顶点的位置
    VRType adj;              // 弧<v1,v2>的权值，描述带权图时候需要
    struct ArcNode *nextarc; // 指向下一条弧的指针
} ArcNode;

// 顶点表结点的定义
typedef struct vnode
{
    VertexType data;   // 顶点信息
    ArcNode *firstarc; // 指向第一条依附该顶点的弧
} VNode, AdjList[MAX_VERTEX_NUM];

// 图的定义（邻接表存储方式）
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind; // 图的种类标志
} ALGraph;

// 创建无向带权图的邻接表存储结构
void createALGraph(ALGraph &G)
{
    int i, j, w;
    ArcNode *s;

    // 输入顶点数、边数、图的种类
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &G.kind);
    getchar(); // 处理scanf输入后换行符的影响

    // 输入每个顶点的数据，并初始化每个顶点的邻接表头指针
    for (i = 1; i <= G.vexnum; i++)
    {
        G.vertices[i].data = getchar();
        G.vertices[i].firstarc = NULL;
    }
    getchar(); // 处理scanf输入后换行符的影响

    // 读入每条边的信息，建立邻接表
    for (i = 0; i < G.arcnum; i++)
    {
        scanf("%d%d%d", &i, &j, &w);

        // 在i的邻接表中插入一条指向j的边
        s = (ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex = j;                       // 表示该弧指向的顶点是j
        s->adj = w;                          // 表示该弧的权值
        s->nextarc = G.vertices[i].firstarc; // 用的是前插法
        G.vertices[i].firstarc = s;

        // 在j的邻接表中插入一条指向i的边
        s = (ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex = i;
        s->adj = w;
        s->nextarc = G.vertices[j].firstarc; // 依旧还是前插法
        G.vertices[j].firstarc = s;
    }
}

int main()
{
    ALGraph G;
    createALGraph(G);
    return 0;
}
