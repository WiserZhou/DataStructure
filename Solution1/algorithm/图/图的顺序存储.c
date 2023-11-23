

// ͼ��˳��洢
#include <stdio.h>
#define INFINITY INT_MAX  // ���ֵ����ʾ�����
#define MAX_VERtEX_NUM 20 // �����������
#define VRType int        // ��ʾ����֮��Ĺ�ϵ�ı�������
#define InfoType char     // �洢�����߱߶�����Ϣ��ָ���������
#define VertexType int    // ͼ�ж������������
typedef enum
{
    DG,       // ����ͼ
    DN,       // ����ͼ
    UDG,      // ������
    UDN       // ������
} GraphKind; // ö��ͼ�� 4 ������ 
typedef struct
{
    VRType adj;     // ������Ȩͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ����ڴ�Ȩͼ��ֱ��ΪȨֵ��
    InfoType *info; // ����߶��⺬�е���Ϣָ��
} ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
typedef struct
{
    VertexType vexs[MAX_VERtEX_NUM]; // �洢ͼ�ж�����Ϣ
    AdjMatrix arcs;                  // ��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum, arcnum;              // ��¼ͼ�Ķ������ͻ����ߣ���
    GraphKind kind;                  // ��¼ͼ������
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
void CreateDG(MGraph *G)
{
    // ����ͼ���еĶ������ͻ��ĸ���
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));
    // �������붥�㱾�������
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%d", &(G->vexs[i]));
    }
    // ��ʼ����ά����ȫ����0��ָ��ָ��NULL
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    // �ڶ�ά��������ӻ�������
    for (int i = 0; i < G->arcnum; i++)
    {
        int v1, v2;
        // ���뻡ͷ�ͻ�β
        scanf("%d,%d", &v1, &v2);
        // ȷ������λ��
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        // �ų���������
        if (m == -1 || n == -1)
        {
            printf("no this vertex\n");
            return;
        }
        // ����ȷ�Ļ������ݼ����ά����
        G->arcs[n][m].adj = 1;
    }
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
// ������������������ͼ��ͬ���Ƕ��׾����д洢����Ȩֵ�����Ǵ�Ȩͼ
void CreateUDG(MGraph *G)
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
        int v1, v2, w;
        scanf("%d,%d,%d", &v1, &v2, &w);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1)
        {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = w;
    }
}
// ������������������ͼΨһ��������Ƕ��׾����д洢����Ȩֵ
void CreateUDN(MGraph *G)
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
        int v1, v2, w;
        scanf("%d,%d,%d", &v1, &v2, &w);
        int m = LocateVex(G, v1);
        int n = LocateVex(G, v2);
        if (m == -1 || n == -1)
        {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = w;
        G->arcs[m][n].adj = w; // ����Գ�
    }
}
void CreateGraph(MGraph *G)
{
    // ѡ��ͼ������
    scanf("%d", &(G->kind));
    // ������ѡ���ͣ����ò�ͬ�ĺ���ʵ�ֹ���ͼ�Ĺ���
    switch (G->kind)
    {
    case DG:
        return CreateDG(G);
        break;
    case DN:
        return CreateDN(G);
        break;
    case UDG:
        return CreateUDG(G);
        break;
    case UDN:
        return CreateUDN(G);
        break;
    default:
        break;
    }
}
// �������
void PrintGrapth(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            printf("%d ", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}
int main()
{
    MGraph G;        // ����һ��ͼ�ı���
    CreateGraph(&G); // ���ô��������������ַ����
    PrintGrapth(G);  // ���ͼ�Ķ��׾���
    return 0;
}