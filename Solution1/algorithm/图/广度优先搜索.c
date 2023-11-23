#include <stdio.h>
#include <stdlib.h>
#define MAX_VERtEX_NUM 20 // �����������
#define VRType int        // ��ʾ����֮��Ĺ�ϵ�ı�������
#define InfoType char     // �洢�����߱߶�����Ϣ��ָ���������
#define VertexType int    // ͼ�ж������������
typedef enum
{
    false,
    true
} bool;                       // ����bool�ͳ���
bool visited[MAX_VERtEX_NUM]; // ����ȫ�����飬��¼��Ƕ����Ƿ񱻷��ʹ�
typedef struct Queue
{
    VertexType data;
    struct Queue *next;
} Queue;
typedef struct
{
    VRType adj;     // ������Ȩͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ����ڴ�Ȩͼ��ֱ��ΪȨֵ��
    InfoType *info; // ����߶��⺬�е���Ϣָ��
} ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct
{
    VertexType vexs[MAX_VERtEX_NUM]; // �洢ͼ�ж�������
    AdjMatrix arcs;                  // ��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum, arcnum;              // ��¼ͼ�Ķ������ͻ����ߣ���
} MGraph;
// ���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph *G, VertexType v)
{
    int i = 0;
    // ����һά���飬�ҵ�����v
    for (; i < G->vexnum; i++)
    {
        if (G->vexs[i] == v)
        {
            break;
        }
    }
    // ����Ҳ����������ʾ��䣬����-1
    if (i > G->vexnum)
    {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
// ��������ͼ
void CreateDN(MGraph *G)
{
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%d", &(G->vexs[i]));
    }
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    for (int i = 0; i < G->arcnum; i++)
    {
        int v1, v2;
        scanf("%d,%d", &v1, &v2);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1)
        {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = 1;
        G->arcs[m][n].adj = 1; // ����ͼ�Ķ��׾��������Խ��߶Գ�
    }
}

int FirstAdjVex(MGraph G, int v)
{
    // �����������±�Ϊv�Ķ���֮���бߵĶ��㣬�������������е��±�
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.arcs[v][i].adj)
        {
            return i;
        }
    }
    return -1;
}
int NextAdjVex(MGraph G, int v, int w)
{
    // ��ǰһ������λ��w����һ��λ�ÿ�ʼ������֮���бߵĶ���
    for (int i = w + 1; i < G.vexnum; i++)
    {
        if (G.arcs[v][i].adj)
        {
            return i;
        }
    }
    return -1;
}
// ��������ĺ���
void visitVex(MGraph G, int v)
{
    printf("%d ", G.vexs[v]);
}
// ��ʼ������
void InitQueue(Queue **Q)
{
    (*Q) = (Queue *)malloc(sizeof(Queue));
    (*Q)->next = NULL;
}
// ����Ԫ��v������
void EnQueue(Queue **Q, VertexType v)
{
    Queue *element = (Queue *)malloc(sizeof(Queue));
    element->data = v;
    element->next = NULL;
    Queue *temp = (*Q);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = element;
}
// ��ͷԪ�س�����
void DeQueue(Queue **Q, int *u)
{
    (*u) = (*Q)->next->data;
    (*Q)->next = (*Q)->next->next;
}
// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue *Q)
{
    if (Q->next == NULL)
    {
        return true;
    }
    return false;
}
// �����������
void BFSTraverse(MGraph G)
{ //
    int v;
    // ��������ǵ�visit�����ʼ��Ϊfalse
    for (v = 0; v < G.vexnum; ++v)
    {
        visited[v] = false;
    }
    // ����ÿ�����Ϊfalse�Ķ���������������������
    Queue *Q;
    InitQueue(&Q);
    for (v = 0; v < G.vexnum; v++)
    {
        if (!visited[v])
        {
            visited[v] = true;
            visitVex(G, v);
            EnQueue(&Q, G.vexs[v]);
            while (!QueueEmpty(Q))
            {
                int u;
                DeQueue(&Q, &u);
                u = LocateVex(&G, u);
                for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
                {
                    if (!visited[w])
                    {
                        visited[w] = true;
                        visitVex(G, w);
                        EnQueue(&Q, G.vexs[w]);
                    }
                }
            }
        }
    }
}
int main()
{
    MGraph G;       // ����һ��ͼ�ı���
    CreateDN(&G);   // ��ʼ��ͼ
    BFSTraverse(G); // �����������ͼ
    return 0;
}