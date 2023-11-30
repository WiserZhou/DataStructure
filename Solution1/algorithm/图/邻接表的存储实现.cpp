

#include <stdio.h>
#include <stdlib.h>

// ���嶥��ͱߵ���������
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef int VRType;

// �߱���Ķ���
typedef struct ArcNode
{
    int adjvex;              // �û���ָ��Ķ����λ��
    VRType adj;              // ��<v1,v2>��Ȩֵ��������Ȩͼʱ����Ҫ
    struct ArcNode *nextarc; // ָ����һ������ָ��
} ArcNode;

// �������Ķ���
typedef struct vnode
{
    VertexType data;   // ������Ϣ
    ArcNode *firstarc; // ָ���һ�������ö���Ļ�
} VNode, AdjList[MAX_VERTEX_NUM];

// ͼ�Ķ��壨�ڽӱ�洢��ʽ��
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind; // ͼ�������־
} ALGraph;

// ���������Ȩͼ���ڽӱ�洢�ṹ
void createALGraph(ALGraph &G)
{
    int i, j, w;
    ArcNode *s;

    // ���붥������������ͼ������
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &G.kind);
    getchar(); // ����scanf������з���Ӱ��

    // ����ÿ����������ݣ�����ʼ��ÿ��������ڽӱ�ͷָ��
    for (i = 1; i <= G.vexnum; i++)
    {
        G.vertices[i].data = getchar();
        G.vertices[i].firstarc = NULL;
    }
    getchar(); // ����scanf������з���Ӱ��

    // ����ÿ���ߵ���Ϣ�������ڽӱ�
    for (i = 0; i < G.arcnum; i++)
    {
        scanf("%d%d%d", &i, &j, &w);

        // ��i���ڽӱ��в���һ��ָ��j�ı�
        s = (ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex = j;                       // ��ʾ�û�ָ��Ķ�����j
        s->adj = w;                          // ��ʾ�û���Ȩֵ
        s->nextarc = G.vertices[i].firstarc; // �õ���ǰ�巨
        G.vertices[i].firstarc = s;

        // ��j���ڽӱ��в���һ��ָ��i�ı�
        s = (ArcNode *)malloc(sizeof(ArcNode));
        s->adjvex = i;
        s->adj = w;
        s->nextarc = G.vertices[j].firstarc; // ���ɻ���ǰ�巨
        G.vertices[j].firstarc = s;
    }
}

int main()
{
    ALGraph G;
    createALGraph(G);
    return 0;
}
