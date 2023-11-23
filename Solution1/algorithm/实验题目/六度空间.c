#include <stdio.h>
#include <stdlib.h>

#define SIX 6
#define MaxVertexNum 1000 /* 最大顶点数 */

typedef unsigned long VertexType; /* 顶点用无符号长整数表示 */
typedef struct node
{                      /* 边表结点 */
    VertexType AdjV;   /* 邻接点域 */
    struct node *Next; /* 指向下一个邻接点的指针域 */
                       /* 若要表示边上的权值信息，则应增加一个数据域Weight */
} EdgeNode;

typedef unsigned long VertexType; /* 顶点用无符号长整数表示 */
typedef struct Vnode
{                        /* 顶点表结点 */
    char Visited;        /* 顶点域，这里用于标记该结点是否已经访问 */
    double Percent;      /* 用于记录距离不超过SIX的结点百分比 */
    EdgeNode *FirstEdge; /* 边表头指针 */
} VertexNode;

typedef VertexNode AdjList[MaxVertexNum];
/* AdjList是邻接表类型 */
typedef struct
{
    AdjList adjlist;        /* 邻接表 */
    unsigned long int n, e; /* 顶点数和边数 */
} ALGraph;                  /* ALGraph是以邻接表方式存储的图类型 */

typedef struct Element
{
    VertexType v; /* 结点编号 */
    int Layer;    /* BFS的层次 */
} QElementType;
typedef struct Node
{
    QElementType Data;
    struct Node *Next;
} QNode;
typedef struct
{                 /* 链队列结构  */
    QNode *rear;  /* 指向队尾结点 */
    QNode *front; /* 指向队头结点 */
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
    QNode *cell = (QNode *)malloc(sizeof(QNode)); /* 申请一个结点空间  */

    cell->Data = item;
    cell->Next = NULL;
    if (IsEmptyQ(PtrQ)) /* 若队列空，头尾是同一个元素 */
        PtrQ->front = PtrQ->rear = cell;
    else
    { /* 否则新元素添加到尾部 */
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
        printf("队列空");
        exit(0);
    }
    FrontCell = PtrQ->front;
    if (PtrQ->front == PtrQ->rear)       /* 若队列只有一个元素 */
        PtrQ->front = PtrQ->rear = NULL; /* 删除后队列置为空 */
    else
        PtrQ->front = PtrQ->front->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell); /* 释放被删除结点空间  */
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

    scanf("%ld %ld", &(G->n), &(G->e)); /* 读入顶点数和边数 */
    for (i = 0; i < G->n; i++)
    {                                   /* 建立有n个顶点的顶点表 */
        G->adjlist[i].Visited = 0;      /* 记录该结点是否已经访问 */
        G->adjlist[i].Percent = 0.0;    /* 距离不超过SIX的结点百分比 */
        G->adjlist[i].FirstEdge = NULL; /* 顶点的边表头指针设为空 */
    }
    for (k = 0; k < G->e; k++)
    {                             /* 建立边表 */
        scanf("%ld %ld", &i, &j); /* 读入边<vi,vj>的顶点对应序号*/
        edge = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* 生成新边表结点edge，用来表示边（vi, vj） */
        edge->AdjV = j - 1; /* 邻接点序号为j */
        /* 将新边表结点edge插入到顶点vi的边表头部 */
        edge->Next = G->adjlist[i - 1].FirstEdge;
        G->adjlist[i - 1].FirstEdge = edge;
        /* 因为是无向图，还要生成一个结点，用来表示边（vj, vi）  */
        edge = (EdgeNode *)malloc(sizeof(EdgeNode));
        edge->AdjV = i - 1; /* 邻接点序号为i */
        /* 将新边表结点edge插入到顶点vj的边表头部 */
        edge->Next = G->adjlist[j - 1].FirstEdge;
        G->adjlist[j - 1].FirstEdge = edge;
    }
}

void SixDegree_BFS(ALGraph *G, VertexType Start)
{ /* 计算离节点Start的距离不超过SIX的节点百分比 */
    QElementType qe;
    LinkQueue Q;
    VertexType v;
    EdgeNode *edge;
    unsigned long int VisitCount = 1; /* 记录路径长度<=SIX的顶点数 */

    Initialize(&Q); /* 置空的队列Q */
    G->adjlist[Start].Visited = 1;
    qe.v = Start;
    qe.Layer = 0; /* 起点算0层 */
    AddQ(&Q, qe); /* qe入队列 */
    while (!IsEmptyQ(&Q))
    { /* 队列非空循环 */
        qe = DeleteQ(&Q);
        v = qe.v;
        for (edge = G->adjlist[v].FirstEdge; edge; edge = edge->Next)
            if (!G->adjlist[edge->AdjV].Visited)
            /* 若edge->AdjV是v的尚未访问的邻接顶点 */
            {
                G->adjlist[edge->AdjV].Visited = 1;
                /* 将其记为六度以内的顶点 */
                VisitCount++;         /* 增加路径长度<=SIX的顶点数 */
                if (++qe.Layer < SIX) /* 仅将六度以内的顶点再进队 */
                {
                    qe.v = edge->AdjV;
                    AddQ(&Q, qe);
                }
                qe.Layer--; /* 恢复qe的层数 */
            }               /* 结束if，for */
    }                       /* 结束while循环 */
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
        SixDegree_BFS(G, i); /*计算离节点i的距离不超过SIX的节点百分比 */
        printf("%ld: %.2f%%\n", i + 1, G->adjlist[i].Percent);
        for (j = 0; j < G->n; j++)     /* 工作空间初始化 */
            G->adjlist[j].Visited = 0; /* 重置标记所有结点未经访问 */
    }
    return 0;
}