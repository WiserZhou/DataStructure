

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int VRType;     // 顶点关系类型
typedef char InfoType;  // 弧或边额外信息类型
typedef int VertexType; // 顶点类型

typedef struct
{
    VRType adj;
    InfoType *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
} MGraph;

typedef struct
{
    int data[MAX_VERTEX_NUM];
    int front, rear;
} Queue;

Status Visit(int v)
{
    printf("%d ", v);
    return TRUE;
}

void InitQueue(Queue *Q)
{
    Q->front = Q->rear = 0;
}

Status QueueEmpty(Queue Q)
{
    return Q.front == Q.rear;
}

Status EnQueue(Queue *Q, int v)
{
    if ((Q->rear + 1) % MAX_VERTEX_NUM == Q->front)// 说明此时栈满了
        return FALSE;
    Q->data[Q->rear] = v;
    Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;
    return TRUE;
}

Status DeQueue(Queue *Q, int *v)
{
    if (Q->front == Q->rear)
        return FALSE;
    *v = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
    return TRUE;
}

int FirstAdjvex(MGraph G, int v)
{
    int i;
    for (i = 0; i < G.vexnum; ++i)
    {
        if (G.arcs[v][i].adj != 0)
            return i;
    }
    return -1;
}

int NextAdjvex(MGraph G, int v, int w)
{
    int i;
    for (i = w + 1; i < G.vexnum; ++i)
    {
        if (G.arcs[v][i].adj != 0)
            return i;
    }
    return -1;
}

void BFSTraverse(MGraph G, Status (*Visit)(int v))
{
    int v, u, w;
    int visited[MAX_VERTEX_NUM];
    Queue Q;

    for (v = 0; v < G.vexnum; ++v)
        visited[v] = FALSE;

    InitQueue(&Q);

    for (v = 0; v < G.vexnum; ++v)
    {
        if (!visited[v])
        {
            visited[v] = TRUE;
            Visit(v);
            EnQueue(&Q, v);

            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &u);

                for (w = FirstAdjvex(G, u); w != -1; w = NextAdjvex(G, u, w))
                {
                    if (!visited[w])
                    {
                        visited[w] = TRUE;
                        Visit(w);
                        EnQueue(&Q, w);
                    }
                }
            }
        }
    }
}

int main()
{
    MGraph graph;
    graph.vexnum = 6;
    graph.arcnum = 7;

    // 初始化顶点信息
    for (int i = 0; i < graph.vexnum; i++)
    {
        graph.vexs[i] = i;
    }

    // 初始化邻接矩阵
    for (int i = 0; i < graph.vexnum; i++)
    {
        for (int j = 0; j < graph.vexnum; j++)
        {
            graph.arcs[i][j].adj = 0; // 初始时顶点之间没有关系
            graph.arcs[i][j].info = NULL;
        }
    }

    // 添加边的关系
    graph.arcs[0][1].adj = 1;
    graph.arcs[0][2].adj = 1;
    graph.arcs[1][3].adj = 1;
    graph.arcs[1][4].adj = 1;
    graph.arcs[2][4].adj = 1;
    graph.arcs[3][5].adj = 1;
    graph.arcs[4][5].adj = 1;

    BFSTraverse(graph, Visit);

    return 0;
}
