// https://blog.csdn.net/Attract1206/article/details/106728651
// https://c.biancheng.net/algorithm/kruskal.html
#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 // ��󶥵���Ϊ20

typedef char VertexType;

typedef struct
{
    VertexType begin;
    VertexType end;
    int weight;
} Edge; // �߼�����edge[]�ĵ�Ԫ

typedef struct
{
    VertexType Vertex[VertexMax]; // ��������
    Edge edge[VertexMax];         // �߼�����
    int vexnum;                   // ������
    int edgenum;                  // ����
} EdgeGraph;

void CreateEdgeGraph(EdgeGraph *E)
{
    int i;

    printf("�����붥�����ͱ���:\n");
    printf("������ n=");
    scanf("%d", &E->vexnum);
    printf("��  �� e=");
    scanf("%d", &E->edgenum);
    printf("\n");
    // printf("\n");

    printf("���붥��(����ո����):");
    scanf("%s", E->Vertex);
    printf("\n\n");

    printf("�������Ϣ��Ȩֵ(��:AB,15):\n");
    for (i = 0; i < E->edgenum; i++)
    {
        printf("�������%d�ߵ���Ϣ:", i + 1);
        scanf(" %c%c,%d", &E->edge[i].begin, &E->edge[i].end, &E->edge[i].weight);
    }
}

void print(EdgeGraph *E)
{
    int i;

    printf("\n-----------------------------------\n");
    printf(" ��������Vertex:");
    for (i = 0; i < E->vexnum; i++)
    {
        printf("%c ", E->Vertex[i]);
    }
    printf("\n\n");

    printf(" �߼�����edge:\n\n");
    printf("\t\tBegin	End	Weight\n");
    for (i = 0; i < E->edgenum; i++)
    {
        printf("\tedge[%d]	%c	%c	%d\n", i, E->edge[i].begin, E->edge[i].end, E->edge[i].weight);
    }
    printf("\n-----------------------------------\n");
}

void sort(EdgeGraph *E)
{
    int i, j;
    Edge temp;

    for (i = 0; i < E->edgenum - 1; i++)
    {
        for (j = i + 1; j < E->edgenum; j++)
        {
            if (E->edge[i].weight > E->edge[j].weight)
            {
                temp = E->edge[i];
                E->edge[i] = E->edge[j];
                E->edge[j] = temp;
            }
        }
    }
}

int LocateVex(EdgeGraph *E, VertexType v) // ����Ԫ��v��һά���� Vertex[] �е��±꣬�������±�
{
    int i;

    for (i = 0; i < E->vexnum; i++)
    {
        if (v == E->Vertex[i])
        {
            return i;
        }
    }

    printf("No Such Vertex!\n");
    return -1;
}

int FindRoot(int t, int parent[]) // t���յ��ǽ����Vertex�����е��±�
{
    while (parent[t] > -1) // parent=-1��ʾû��˫�ף���û�и��ڵ�
    {
        t = parent[t]; // ������Ҹ��ڵ�
    }

    return t; // ���ҵ��ĸ��ڵ㷵�أ���û�и��ڵ㷵������
}

void MiniSpanTree_Kruskal(EdgeGraph *E)
{
    int i;
    int num; // ���ɱ߼���������num=������-1 �ʹ�����С�������������
    int root1, root2;
    int LocVex1, LocVex2;
    int parent[VertexMax]; // ���ڲ��Ҷ����˫�ף��ж�����������Ƿ��й�ͬ��˫�ף����ж��������Ƿ��ɻ�

    // 1.��Ȩֵ��С��������
    sort(E);
    print(E);
    // 2.��ʼ��parent����
    for (i = 0; i < E->vexnum; i++)
    {
        parent[i] = -1;
    }

    printf("\n ��С������(Kruskal):\n\n");
    // 3.
    for (num = 0, i = 0; i < E->edgenum; i++)
    {
        LocVex1 = LocateVex(E, E->edge[i].begin);
        LocVex2 = LocateVex(E, E->edge[i].end);
        root1 = FindRoot(LocVex1, parent);
        root2 = FindRoot(LocVex2, parent);

        if (root1 != root2) // ������ɻ���������С�������й����˱�
        {
            printf("\t\t%c-%c w=%d\n", E->edge[i].begin, E->edge[i].end, E->edge[i].weight); // ����˱�
            parent[root2] = root1;                                                           // �ϲ�������
            num++;

            if (num == E->vexnum - 1) // ��num=������-1��������������ϣ���ǰ����
            {
                return;
            }
        }
    }
}

int main()
{
    EdgeGraph E;

    CreateEdgeGraph(&E);
    MiniSpanTree_Kruskal(&E);

    return 0;
}
