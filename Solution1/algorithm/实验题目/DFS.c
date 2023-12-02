#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 100 // ��󶥵���
typedef struct
{
    char vertex[MAX_VERTEX_NUM];              // ����ֵ
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // �ڽӾ���
    int vertex_num;                           // ������
    int arc_num;                              // ����
} Graph;
bool visited[MAX_VERTEX_NUM]; // ��¼�����Ƿ��Ѿ�������
// ����ͼ
void createGraph(Graph *G, int type)
{
    scanf("%d%d", &(G->vertex_num), &(G->arc_num));
    for (int i = 0; i < G->vertex_num; i++)
        scanf(" %c", &(G->vertex[i]));
    // ��ʼ���ڽӾ���
    for (int i = 0; i < G->vertex_num; i++)
        for (int j = 0; j < G->vertex_num; j++)
            G->arcs[i][j] = 0;
    char start, end;
    int weight;
    for (int k = 0; k < G->arc_num; k++)
    {
        scanf(" %c %c", &start, &end);
        if (type == 1 || type == 3) // ��������������
            scanf("%d", &weight);
        int i, j;
        for (i = 0; i < G->vertex_num; i++)
            if (G->vertex[i] == start) // ����Ҫ�ҵ�start�ڱ������иߵ�λ��
                break;
        for (j = 0; j < G->vertex_num; j++)
            if (G->vertex[j] == end)
                break;
        G->arcs[i][j] = 1; // �������������������ϱ�
        if (type == 1 || type == 3)
            G->arcs[i][j] = weight; // ��¼Ȩֵ
        if (type == 2 || type == 3) // ����ͼ����������Ҫ���öԳƱ�
            G->arcs[j][i] = G->arcs[i][j];
    }
}
// �����������
void DFS(Graph G, int v)
{
    printf("%c", G.vertex[v]);
    visited[v] = true;
    for (int i = 0; i < G.vertex_num; i++)
        if (G.arcs[v][i] != 0 && !visited[i])
            DFS(G, i);
}
// ͼ�����������������
void DFSTraverse(Graph G)
{
    for (int i = 0; i < G.vertex_num; i++)
        visited[i] = false; // ��ʼ�����������ΪFalse
    char start;
    scanf(" %c", &start); // ��ʾ�Ӹõ㿪ʼ������ȱ���
    int v;
    for (v = 0; v < G.vertex_num; v++)
        if (G.vertex[v] == start) // �����ҵ�����ĵ��������еľ����λ��
            break;
    DFS(G, v);                             // �Ϳ�ʼ��ȱ���
    for (int i = 0; i < G.vertex_num; i++) // ��仰������Ǹ�ͼ������ͨͼ�����
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