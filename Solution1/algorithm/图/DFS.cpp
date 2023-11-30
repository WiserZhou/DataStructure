#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100 // 最大顶点数
typedef char VertexType;   // 定义顶点数据类型

// 定义邻接表存储结构
typedef struct ArcNode
{
    int adjvex;           // 邻接顶点编号
    struct ArcNode *next; // 下一个边节点指针
} ArcNode;

typedef struct VNode
{
    VertexType data;   // 顶点数据
    ArcNode *firstarc; // 第一个边节点指针
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;   // 顶点数组
    int vexnum, arcnum; // 顶点数和边数
} Graph;

int visited[MAX_VERTEX_NUM]; // 记录顶点是否被访问过的数组

// 初始化图结构
void InitGraph(Graph *G)
{
    G->vexnum = G->arcnum = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; i++)
    {
        G->vertices[i].data = '\0';
        G->vertices[i].firstarc = NULL;
    }
}

// 添加边到邻接表中
void AddArcNode(ArcNode **p, int adjvex)
{
    ArcNode *newnode = (ArcNode *)malloc(sizeof(ArcNode));
    newnode->adjvex = adjvex;
    newnode->next = NULL;
    *p = newnode;
}

// 增加边
void AddArc(Graph *G, int v1, int v2)
{
    AddArcNode(&G->vertices[v1].firstarc, v2);
    G->arcnum++;
}

// 获取第一个邻接顶点
int FirstAdjVex(Graph G, int v)
{
    if (G.vertices[v].firstarc != NULL)
        return G.vertices[v].firstarc->adjvex;
    else
        return 0;
}

// 获取下一个邻接顶点
int NextAdjVex(Graph G, int v, int w)
{
    ArcNode *p = G.vertices[v].firstarc;
    while (p != NULL && p->adjvex != w) // 通过一个循环找到邻接顶点w
        p = p->next;
    if (p != NULL && p->next != NULL) // 如果找到了邻接顶点w，并且w后面还有下一个邻接顶点，则返回这个下一个邻接顶点的编号
        return p->next->adjvex;
    else
        return 0;
}

// 访问顶点
void VisitFunc(int v)
{
    printf("%d ", v);
}

// 深度优先搜索遍历连通图
void DFS(Graph G, int v)
{
    visited[v] = 1; // 标记该顶点已经被访问过
    VisitFunc(v);   // 访问该顶点
    for (int w = FirstAdjVex(G, v); w != 0; w = NextAdjVex(G, v, w))
    {
        if (!visited[w])
        {              // 对v的尚未访问的邻接顶点w
            DFS(G, w); // 递归调用DFS
        }
    }
}

int main()
{
    Graph G;
    InitGraph(&G);

    // 添加顶点和边
    G.vexnum = 5;
    AddArc(&G, 0, 1);
    AddArc(&G, 0, 2);
    AddArc(&G, 1, 2);
    AddArc(&G, 1, 3);
    AddArc(&G, 2, 4);

    // 初始化visited数组
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    // 深度优先搜索遍历图
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            DFS(G, i);
    }

    return 0;
}
