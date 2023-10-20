// float ve[n], vl[n];
// 记录事件的最早发生时间和最晚发生时间
// 邻接表的存储表示
#define MAX_VERTEX_NUM 20
// (1)
// 边表：
typedef struct ArcNode
{
    int adjVex; // 该弧所指向的顶点的位置
    struct ArcNode *nextArc;
    // 指向下一条弧的指针
    int info; // 存权值
} ArcNode;

// (2) 顶点表：
typedef struct vnode
{
    int data; // 顶点信息
    ArcNode *firstArc;
    // 指向第一条依附该顶点的弧
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexNum, arcNum;
    int kind; // 图的种类标志
} ALGraph;
ALGraph G;