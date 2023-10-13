// #include "..\header\unity.h"
// typedef int VRType;
// typedef char VertexType;
// typedef char InfoType;
// #define INFINITY INT32_MAX
// #define MAX_VERTEX_NUM 20 // vertex 顶点
// typedef enum
// {
//     DG,  // 有向图 directed graph
//     DN,  // 有向网 directed network
//     UDG, // 无向图 undirected graph
//     UDN  // 无向网 undirected network
// } GraphKind;
// typedef struct ArcCell
// {
//     VRType adj;                                       // 顶点关系类型，对于无权图，用1或者0表示相邻否，对带权图，则为权值类型
//     InfoType *info;                                   // 该弧相关信息的指针
// } ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // adjoin 邻接

// typedef struct
// {
//     VertexType vexs[MAX_VERTEX_NUM]; // 顶点数组，包含所有的顶点
//     AdjMatrix arcs;                  // 弧的邻接矩阵
//     int vexNum, arcNum;              // 图的当前顶点数和弧数     arc 弧
//     GraphKind kind;                  // 图的种类标志
// } MGraph;

// Status CreateGraph(MGraph &G)
// {
//     cin >> G.kind;
//     switch (G.kind)
//     {
//     case DG:
//         return CreateDG(G);
//     case DN:
//         return CreateDN(G);
//     case UDG:
//         return CreateUDG(G);
//     case UDN:
//         return CreateUDN(G);
//     default:
//         return ERROR;
//     }
// }

// Status CreateUDN(MGraph &G)
// {
//     cin >> G.vexNum >> G.arcNum >> IncInfo;
//     for (int i = 0; i < G.vexNum; i++)
//         cin >> G.vexs[i];
//     for (int i = 0; i < G.vexNum; i++)
//         for (int j = 0; j < G.vexNum; j++)
//             G.arcs[i][j] = {INFINITY, NULL};
//     for (int k = 0; k < G.arcNum; k++)
//     {
//         cin >> v1 >> v2 >> w;
//         i = LocateVex(G, v1);
//         j = locateVex(G, v2);
//         G.arcs[i][j].adj = w;
//         if (IncInfo)
//             Input(*G.arcs[i][j].info);
//         G.arcs[j][i] = G.arcs[i][j];
//     }
//     return OK;
// }

// typedef struct vnode{
//     vertextype data;
//     Arcnode *firstarc;
// }vnode,adjlist[MAX_VERTEX_NUM];

// typedef struct ArcNode{
//     int adjvex;
//     VRType adj;
//     struct
// }

