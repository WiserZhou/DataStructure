#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 100 // 最大顶点数
typedef struct
{
    char vertex[MAX_VERTEX_NUM];              // 顶点值
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vertex_num;                           // 顶点数
    int arc_num;                              // 边数
} Graph;
bool visited[MAX_VERTEX_NUM]; // 记录顶点是否已经被访问
// 创建图
void createGraph(Graph *G, int type)
{
    scanf("%d%d", &(G->vertex_num), &(G->arc_num));
    for (int i = 0; i < G->vertex_num; i++)
        scanf(" %c", &(G->vertex[i]));
    // 初始化邻接矩阵
    for (int i = 0; i < G->vertex_num; i++)
        for (int j = 0; j < G->vertex_num; j++)
            G->arcs[i][j] = 0;
    char start, end;
    int weight;
    for (int k = 0; k < G->arc_num; k++)
    {
        scanf(" %c %c", &start, &end);
        if (type == 1 || type == 3) // 有向网或无向网
            scanf("%d", &weight);
        int i, j;
        for (i = 0; i < G->vertex_num; i++)
            if (G->vertex[i] == start) // 就是要找到start在边数组中高的位置
                break;
        for (j = 0; j < G->vertex_num; j++)
            if (G->vertex[j] == end)
                break;
        G->arcs[i][j] = 1; // 给刚输入的两个顶点加上边
        if (type == 1 || type == 3)
            G->arcs[i][j] = weight; // 记录权值
        if (type == 2 || type == 3) // 无向图或无向网需要设置对称边
            G->arcs[j][i] = G->arcs[i][j];
    }
}
// 深度优先搜索
void DFS(Graph G, int v)
{
    printf("%c", G.vertex[v]);
    visited[v] = true;
    for (int i = 0; i < G.vertex_num; i++)
        if (G.arcs[v][i] != 0 && !visited[i])
            DFS(G, i);
}
// 图的深度优先搜索序列
void DFSTraverse(Graph G)
{
    for (int i = 0; i < G.vertex_num; i++)
        visited[i] = false; // 初始化访问数组均为False
    char start;
    scanf(" %c", &start); // 表示从该点开始进行深度遍历
    int v;
    for (v = 0; v < G.vertex_num; v++)
        if (G.vertex[v] == start) // 就是找到输入的点在数组中的具体的位置
            break;
    DFS(G, v);                             // 就开始深度遍历
    for (int i = 0; i < G.vertex_num; i++) // 这句话处理的是该图不是连通图的情况
        if (!visited[i])
            DFS(G, i);
}
int main()
{
    int type;
    scanf("%d", &type);
    Graph G;
    createGraph(&G, type);
    DFSTraverse(G);
    printf("\n");
    return 0;
}