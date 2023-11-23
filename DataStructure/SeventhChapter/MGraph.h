#include "..\header\unity.h"
#include <iostream>

typedef char VertexType;
typedef int VRType; // vex Relationship type
typedef char InfoType;
#define INFINITY INT32_MAX
#define MAX_VERTEX_NUM 100 // vex 顶点

typedef enum
{
    DG,  // 有向图 directed graph
    DN,  // 有向网 directed network
    UDG, // 无向图 undirected graph
    UDN  // 无向网 undirected network
} GraphKind;

typedef struct ArcCell // 弧形单元格
{
    VRType adj;                                       // 顶点关系类型，对于无权图，用1或者0表示相邻否，对带权图，则为权值类型,adjoin邻接，adj名词
    InfoType *info;                                   // 该弧相关信息的指针
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // adjoin 邻接

typedef struct
{
    VertexType vex[MAX_VERTEX_NUM]; // 顶点数组，包含所有的顶点
    AdjMatrix arc;                  // 弧的邻接矩阵
    int vexNum, arcNum;             // 图的当前顶点数和弧数     arc 弧
    GraphKind kind;                 // 图的种类标志
} MGraph;

// 空间开销O(n^2)
// 顶点的插入删除操作不容易。
// 边、弧的删除和插入操作容易。
void CreatGraph(MGraph &G)
{
    int kind;
    std::cin >> G.vexNum >> G.arcNum >> kind;
    G.kind = static_cast<GraphKind>(kind);

    for (int i = 1; i <= G.vexNum; i++) // 建立各个顶点,设顶点为char类型
        std::cin >> G.vex[i];

    for (int i = 1; i <= G.vexNum; i++) // 初始化边矩阵
        for (int j = 1; j <= G.vexNum; j++)
        {
            G.arc[i][j].adj = INFINITY; // 初始化的值都是INFINITY
            G.arc[i][j].info = NULL;
        }

    for (int k = 1; k <= G.arcNum; k++) // 录入各条边
    {
        int i, j, w;
        std::cin >> i >> j >> w;
        G.arc[i][j].adj = w;
        if (G.kind == UDG || G.kind == UDN)
            G.arc[j][i].adj = w;
    } // 注意对称赋值
}

int FirstAdjVex(MGraph G, int v)
{

    for (int j = 0; j < G.vexNum; j++)
        if (G.arc[v][j].adj != INFINITY)
            return j;
    return 0;
}

int NextAdjVex(MGraph G, int v, int w)
{
    for (int j = w + 1; j < G.vexNum; j++)
        if (G.arc[v][j].adj != INFINITY)
            return j;
    return 0;
}
