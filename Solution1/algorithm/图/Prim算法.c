
// https://blog.csdn.net/Attract1206/article/details/106649013
#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 // ��󶥵���Ϊ100
#define MaxInt 32767 // ��ʾ�����������ʾ ��

typedef char VertexType; // ÿ��������������Ϊ�ַ���

typedef struct // �ڽӾ���ṹ��
{
    VertexType Vertex[VertexMax];        // ��Ŷ���Ԫ�ص�һά����
    int AdjMatrix[VertexMax][VertexMax]; // �ڽӾ����ά����
    int vexnum, arcnum;                  // ͼ�Ķ������ͱ���
} MGraph;

typedef struct // ��������ṹ��(��ѡ��̱�)
{
    VertexType adjvex; // ��ѡ��̱ߵ��ڽӵ�
    int lowcost;       // ��ѡ��̱ߵ�Ȩֵ
} ShortEdge;

int LocateVex(MGraph *G, VertexType v) // ����Ԫ��v��һά���� Vertex[] �е��±꣬�������±�
{
    int i;

    for (i = 0; i < G->vexnum; i++)
    {
        if (v == G->Vertex[i])
        {
            return i;
        }
    }

    printf("No Such Vertex!\n");
    return -1;
}

void CreateUDN(MGraph *G) // ������������Undirected Network��
{
    int i, j;
    // 1.���붥�����ͱ���
    printf("���붥������ͱ�����\n");
    printf("������ n=");
    scanf("%d", &G->vexnum);
    printf("��  �� e=");
    scanf("%d", &G->arcnum);
    printf("\n");

    printf("\n");

    // 2.���붥��Ԫ��
    printf("���붥��Ԫ��(����ո����):");
    scanf("%s", G->Vertex);
    printf("\n");
    // 3.�����ʼ��
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
        {
            G->AdjMatrix[i][j] = MaxInt;
        }

    // 4.�����ڽӾ���
    int n, m;
    VertexType v1, v2;
    int w; // v1->v2��Ȩֵ

    printf("������ߵ���Ϣ��Ȩֵ(��:AB,15):\n");
    for (i = 0; i < G->arcnum; i++)
    {
        printf("�����%d������Ϣ��Ȩֵ:", i + 1);
        scanf(" %c%c,%d", &v1, &v2, &w);
        n = LocateVex(G, v1); // ��ȡv1����Ӧ����Vertex�����е�����
        m = LocateVex(G, v2); // ��ȡv2����Ӧ����Vertex�����е�����

        if (n == -1 || m == -1)
        {
            printf("NO This Vertex!\n");
            return;
        }

        G->AdjMatrix[n][m] = w;
        G->AdjMatrix[m][n] = w; // ���������˴���ͬ
    }
}

void print(MGraph G)
{
    int i, j;
    printf("\n-------------------------------");
    printf("\n �ڽӾ���\n\n");

    printf("\t ");
    for (i = 0; i < G.vexnum; i++)
        printf("\t%c", G.Vertex[i]);
    printf("\n");

    for (i = 0; i < G.vexnum; i++)
    {
        printf("\t%c", G.Vertex[i]);

        for (j = 0; j < G.vexnum; j++)
        {

            if (G.AdjMatrix[i][j] == MaxInt)
                printf("\t��");
            else
                printf("\t%d", G.AdjMatrix[i][j]);
        }
        printf("\n");
    }
}

int minimal(MGraph *G, ShortEdge *shortedge)
{
    int i;
    int min, loc;

    min = MaxInt;
    for (i = 1; i < G->vexnum; i++)
    {
        if (min > shortedge[i].lowcost && shortedge[i].lowcost != 0)
        {
            min = shortedge[i].lowcost;
            loc = i;
        }
    }
    return loc;
}

void MiniSpanTree_Prim(MGraph *G, VertexType start)
{
    int i, j, k;
    ShortEdge shortedge[VertexMax];

    // 1.������ʼ��start
    k = LocateVex(G, start);
    for (i = 0; i < G->vexnum; i++)
    {
        shortedge[i].adjvex = start;
        shortedge[i].lowcost = G->AdjMatrix[k][i];
    }
    shortedge[k].lowcost = 0; // lowcostΪ0��ʾ�ö�������U����

    // 2.����������
    for (i = 0; i < G->vexnum - 1; i++) // �Լ���U��ȥ�����·���Ķ���
    {
        k = minimal(G, shortedge); // �����·���Ķ���

        printf("%c->%c,%d\n", shortedge[k].adjvex, G->Vertex[k], shortedge[k].lowcost); // ����ҵ������·��������·��Ȩֵ
        shortedge[k].lowcost = 0;                                                       // ���ҵ������·��������뼯��U��

        for (j = 0; j < G->vexnum; j++) // U�м������½ڵ㣬���ܳ����µ����·�����ʸ���shortedge����
        {
            if (G->AdjMatrix[k][j] < shortedge[j].lowcost) // �и���·������ʱ�������滻��shortedge����
            {
                shortedge[j].lowcost = G->AdjMatrix[k][j];
                shortedge[j].adjvex = G->Vertex[k];
            }
        }
    }
}

int main()
{
    VertexType start;

    MGraph G;
    CreateUDN(&G);
    print(G);

    printf("��������ʼ�㣺");
    scanf(" %c", &start); //%cǰ���пո�
    MiniSpanTree_Prim(&G, start);

    return 0;
}
