#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100 // ��󶥵���
typedef char VertexType;   // ���嶥����������

// �����ڽӱ�洢�ṹ
typedef struct ArcNode
{
    int adjvex;           // �ڽӶ�����
    struct ArcNode *next; // ��һ���߽ڵ�ָ��
} ArcNode;

typedef struct VNode
{
    VertexType data;   // ��������
    ArcNode *firstarc; // ��һ���߽ڵ�ָ��
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;   // ��������
    int vexnum, arcnum; // �������ͱ���
} Graph;

int visited[MAX_VERTEX_NUM]; // ��¼�����Ƿ񱻷��ʹ�������

// ��ʼ��ͼ�ṹ
void InitGraph(Graph *G)
{
    G->vexnum = G->arcnum = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; i++)
    {
        G->vertices[i].data = '\0';
        G->vertices[i].firstarc = NULL;
    }
}

// ��ӱߵ��ڽӱ���
void AddArcNode(ArcNode **p, int adjvex)
{
    ArcNode *newnode = (ArcNode *)malloc(sizeof(ArcNode));
    newnode->adjvex = adjvex;
    newnode->next = NULL;
    *p = newnode;
}

// ���ӱ�
void AddArc(Graph *G, int v1, int v2)
{
    AddArcNode(&G->vertices[v1].firstarc, v2);
    G->arcnum++;
}

// ��ȡ��һ���ڽӶ���
int FirstAdjVex(Graph G, int v)
{
    if (G.vertices[v].firstarc != NULL)
        return G.vertices[v].firstarc->adjvex;
    else
        return 0;
}

// ��ȡ��һ���ڽӶ���
int NextAdjVex(Graph G, int v, int w)
{
    ArcNode *p = G.vertices[v].firstarc;
    while (p != NULL && p->adjvex != w) // ͨ��һ��ѭ���ҵ��ڽӶ���w
        p = p->next;
    if (p != NULL && p->next != NULL) // ����ҵ����ڽӶ���w������w���滹����һ���ڽӶ��㣬�򷵻������һ���ڽӶ���ı��
        return p->next->adjvex;
    else
        return 0;
}

// ���ʶ���
void VisitFunc(int v)
{
    printf("%d ", v);
}

// �����������������ͨͼ
void DFS(Graph G, int v)
{
    visited[v] = 1; // ��Ǹö����Ѿ������ʹ�
    VisitFunc(v);   // ���ʸö���
    for (int w = FirstAdjVex(G, v); w != 0; w = NextAdjVex(G, v, w))
    {
        if (!visited[w])
        {              // ��v����δ���ʵ��ڽӶ���w
            DFS(G, w); // �ݹ����DFS
        }
    }
}

int main()
{
    Graph G;
    InitGraph(&G);

    // ��Ӷ���ͱ�
    G.vexnum = 5;
    AddArc(&G, 0, 1);
    AddArc(&G, 0, 2);
    AddArc(&G, 1, 2);
    AddArc(&G, 1, 3);
    AddArc(&G, 2, 4);

    // ��ʼ��visited����
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    // ���������������ͼ
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            DFS(G, i);
    }

    return 0;
}
