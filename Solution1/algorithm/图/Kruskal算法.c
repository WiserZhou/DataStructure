// https://blog.csdn.net/Attract1206/article/details/106728651
// https://c.biancheng.net/algorithm/kruskal.html
#include <stdio.h>
#include <stdlib.h>
#define VertexMax 20 // 最大顶点数为20

typedef char VertexType;

typedef struct
{
    VertexType begin;
    VertexType end;
    int weight;
} Edge; // 边集数组edge[]的单元

typedef struct
{
    VertexType Vertex[VertexMax]; // 顶点数组
    Edge edge[VertexMax];         // 边集数组
    int vexnum;                   // 顶点数
    int edgenum;                  // 边数
} EdgeGraph;

void CreateEdgeGraph(EdgeGraph *E)
{
    int i;

    printf("请输入顶点数和边数:\n");
    printf("顶点数 n=");
    scanf("%d", &E->vexnum);
    printf("边  数 e=");
    scanf("%d", &E->edgenum);
    printf("\n");
    // printf("\n");

    printf("输入顶点(无需空格隔开):");
    scanf("%s", E->Vertex);
    printf("\n\n");

    printf("输入边信息和权值(如:AB,15):\n");
    for (i = 0; i < E->edgenum; i++)
    {
        printf("请输入第%d边的信息:", i + 1);
        scanf(" %c%c,%d", &E->edge[i].begin, &E->edge[i].end, &E->edge[i].weight);
    }
}

void print(EdgeGraph *E)
{
    int i;

    printf("\n-----------------------------------\n");
    printf(" 顶点数组Vertex:");
    for (i = 0; i < E->vexnum; i++)
    {
        printf("%c ", E->Vertex[i]);
    }
    printf("\n\n");

    printf(" 边集数组edge:\n\n");
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

int LocateVex(EdgeGraph *E, VertexType v) // 查找元素v在一维数组 Vertex[] 中的下标，并返回下标
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

int FindRoot(int t, int parent[]) // t接收到是结点在Vertex数组中的下标
{
    while (parent[t] > -1) // parent=-1表示没有双亲，即没有根节点
    {
        t = parent[t]; // 逐代查找根节点
    }

    return t; // 将找到的根节点返回，若没有根节点返回自身
}

void MiniSpanTree_Kruskal(EdgeGraph *E)
{
    int i;
    int num; // 生成边计数器，当num=顶点数-1 就代表最小生成树生成完毕
    int root1, root2;
    int LocVex1, LocVex2;
    int parent[VertexMax]; // 用于查找顶点的双亲，判断两个顶点间是否有共同的双亲，来判断生成树是否会成环

    // 1.按权值从小到大排序
    sort(E);
    print(E);
    // 2.初始化parent数组
    for (i = 0; i < E->vexnum; i++)
    {
        parent[i] = -1;
    }

    printf("\n 最小生成树(Kruskal):\n\n");
    // 3.
    for (num = 0, i = 0; i < E->edgenum; i++)
    {
        LocVex1 = LocateVex(E, E->edge[i].begin);
        LocVex2 = LocateVex(E, E->edge[i].end);
        root1 = FindRoot(LocVex1, parent);
        root2 = FindRoot(LocVex2, parent);

        if (root1 != root2) // 若不会成环，则在最小生成树中构建此边
        {
            printf("\t\t%c-%c w=%d\n", E->edge[i].begin, E->edge[i].end, E->edge[i].weight); // 输出此边
            parent[root2] = root1;                                                           // 合并生成树
            num++;

            if (num == E->vexnum - 1) // 若num=顶点数-1，代表树生成完毕，提前返回
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
