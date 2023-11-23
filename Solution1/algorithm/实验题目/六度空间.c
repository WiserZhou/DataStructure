#include <stdio.h>
#include <stdlib.h>

#define SIX 6
#define MaxVertexNum 1000 /* ��󶥵��� */

typedef unsigned long VertexType; /* �������޷��ų�������ʾ */
typedef struct node
{                      /* �߱��� */
    VertexType AdjV;   /* �ڽӵ��� */
    struct node *Next; /* ָ����һ���ڽӵ��ָ���� */
                       /* ��Ҫ��ʾ���ϵ�Ȩֵ��Ϣ����Ӧ����һ��������Weight */
} EdgeNode;

typedef unsigned long VertexType; /* �������޷��ų�������ʾ */
typedef struct Vnode
{                        /* ������� */
    char Visited;        /* �������������ڱ�Ǹý���Ƿ��Ѿ����� */
    double Percent;      /* ���ڼ�¼���벻����SIX�Ľ��ٷֱ� */
    EdgeNode *FirstEdge; /* �߱�ͷָ�� */
} VertexNode;

typedef VertexNode AdjList[MaxVertexNum];
/* AdjList���ڽӱ����� */
typedef struct
{
    AdjList adjlist;        /* �ڽӱ� */
    unsigned long int n, e; /* �������ͱ��� */
} ALGraph;                  /* ALGraph�����ڽӱ�ʽ�洢��ͼ���� */

typedef struct Element
{
    VertexType v; /* ����� */
    int Layer;    /* BFS�Ĳ�� */
} QElementType;
typedef struct Node
{
    QElementType Data;
    struct Node *Next;
} QNode;
typedef struct
{                 /* �����нṹ  */
    QNode *rear;  /* ָ���β��� */
    QNode *front; /* ָ���ͷ��� */
} LinkQueue;

void Initialize(LinkQueue *PtrQ)
{
    PtrQ->rear = PtrQ->front = NULL;
}

int IsEmptyQ(LinkQueue *PtrQ)
{
    return PtrQ->front == NULL;
}

void AddQ(LinkQueue *PtrQ, QElementType item)
{
    QNode *cell = (QNode *)malloc(sizeof(QNode)); /* ����һ�����ռ�  */

    cell->Data = item;
    cell->Next = NULL;
    if (IsEmptyQ(PtrQ)) /* �����пգ�ͷβ��ͬһ��Ԫ�� */
        PtrQ->front = PtrQ->rear = cell;
    else
    { /* ������Ԫ����ӵ�β�� */
        PtrQ->rear->Next = cell;
        PtrQ->rear = cell;
    }
}

QElementType DeleteQ(LinkQueue *PtrQ)
{
    QNode *FrontCell;
    QElementType FrontElem;

    if (PtrQ->front == NULL)
    {
        printf("���п�");
        exit(0);
    }
    FrontCell = PtrQ->front;
    if (PtrQ->front == PtrQ->rear)       /* ������ֻ��һ��Ԫ�� */
        PtrQ->front = PtrQ->rear = NULL; /* ɾ���������Ϊ�� */
    else
        PtrQ->front = PtrQ->front->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell); /* �ͷű�ɾ�����ռ�  */
    return FrontElem;
}

void DestroyQueue(LinkQueue Q)
{
    QNode *cell;
    while ((cell = Q.front))
    {
        Q.front = Q.front->Next;
        free(cell);
    }
}

void CreateALGraph(ALGraph *G)
{
    unsigned long int i, j, k;
    EdgeNode *edge;

    scanf("%ld %ld", &(G->n), &(G->e)); /* ���붥�����ͱ��� */
    for (i = 0; i < G->n; i++)
    {                                   /* ������n������Ķ���� */
        G->adjlist[i].Visited = 0;      /* ��¼�ý���Ƿ��Ѿ����� */
        G->adjlist[i].Percent = 0.0;    /* ���벻����SIX�Ľ��ٷֱ� */
        G->adjlist[i].FirstEdge = NULL; /* ����ı߱�ͷָ����Ϊ�� */
    }
    for (k = 0; k < G->e; k++)
    {                             /* �����߱� */
        scanf("%ld %ld", &i, &j); /* �����<vi,vj>�Ķ����Ӧ���*/
        edge = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* �����±߱���edge��������ʾ�ߣ�vi, vj�� */
        edge->AdjV = j - 1; /* �ڽӵ����Ϊj */
        /* ���±߱���edge���뵽����vi�ı߱�ͷ�� */
        edge->Next = G->adjlist[i - 1].FirstEdge;
        G->adjlist[i - 1].FirstEdge = edge;
        /* ��Ϊ������ͼ����Ҫ����һ����㣬������ʾ�ߣ�vj, vi��  */
        edge = (EdgeNode *)malloc(sizeof(EdgeNode));
        edge->AdjV = i - 1; /* �ڽӵ����Ϊi */
        /* ���±߱���edge���뵽����vj�ı߱�ͷ�� */
        edge->Next = G->adjlist[j - 1].FirstEdge;
        G->adjlist[j - 1].FirstEdge = edge;
    }
}

void SixDegree_BFS(ALGraph *G, VertexType Start)
{ /* ������ڵ�Start�ľ��벻����SIX�Ľڵ�ٷֱ� */
    QElementType qe;
    LinkQueue Q;
    VertexType v;
    EdgeNode *edge;
    unsigned long int VisitCount = 1; /* ��¼·������<=SIX�Ķ����� */

    Initialize(&Q); /* �ÿյĶ���Q */
    G->adjlist[Start].Visited = 1;
    qe.v = Start;
    qe.Layer = 0; /* �����0�� */
    AddQ(&Q, qe); /* qe����� */
    while (!IsEmptyQ(&Q))
    { /* ���зǿ�ѭ�� */
        qe = DeleteQ(&Q);
        v = qe.v;
        for (edge = G->adjlist[v].FirstEdge; edge; edge = edge->Next)
            if (!G->adjlist[edge->AdjV].Visited)
            /* ��edge->AdjV��v����δ���ʵ��ڽӶ��� */
            {
                G->adjlist[edge->AdjV].Visited = 1;
                /* �����Ϊ�������ڵĶ��� */
                VisitCount++;         /* ����·������<=SIX�Ķ����� */
                if (++qe.Layer < SIX) /* �����������ڵĶ����ٽ��� */
                {
                    qe.v = edge->AdjV;
                    AddQ(&Q, qe);
                }
                qe.Layer--; /* �ָ�qe�Ĳ��� */
            }               /* ����if��for */
    }                       /* ����whileѭ�� */
    DestroyQueue(Q);
    G->adjlist[Start].Percent = 100.0 * (double)VisitCount / (double)G->n;
}

int main()
{
    VertexType i, j;
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph));
    CreateALGraph(G);
    for (i = 0L; i < G->n; i++)
    {
        SixDegree_BFS(G, i); /*������ڵ�i�ľ��벻����SIX�Ľڵ�ٷֱ� */
        printf("%ld: %.2f%%\n", i + 1, G->adjlist[i].Percent);
        for (j = 0; j < G->n; j++)     /* �����ռ��ʼ�� */
            G->adjlist[j].Visited = 0; /* ���ñ�����н��δ������ */
    }
    return 0;
}