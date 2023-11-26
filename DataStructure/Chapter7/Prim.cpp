
#include "MGraph.h"
// 伪代码：
//  *Prim(G, start):
//  *    初始化一个空的最小生成树 MST
//  *    将start顶点标记为已访问
//   *   初始化一个最小堆 minHeap，用于存储所有从已访问的顶点出发到未访问顶点的边

//   *  while (MST 中的顶点数量 < G 的总顶点数量):
//    *     将所有从已访问顶点到未访问顶点的边加入 minHeap

//     *    if (minHeap 为空):
//      *       break  // 所有顶点都被访问过，退出循环

//       *  从 minHeap 中取出权重最小的边 (u, v)

//        * if (v 未访问):
//         *    将顶点 v 加入 MST
//          *   将边 (u, v) 加入 MST
//           *  标记顶点 v 为已访问

//     返回 MST
struct close
{
    VertexType adjVex;
    VRType lowCost; // closeEdge[i].lowCost记录了顶点adjVex与i号顶点之间的临时最小权
} closeEdge[MAX_VERTEX_NUM];

// *说明： 如果 closeEdge[i].lowCost=0，则表示i号顶点已经纳入生成树中，即属于U，
// *否则，i号顶点属于V-U，还没有纳入生成树中。

int LocateVex(MGraph G, VertexType u)
{
    for (int i = 1; i <= G.vexNum; i++)
    {
        if (u == G.vex[i])
        {
            return i;
        }
    }
    return 0;
}
int Minimum(MGraph G)
{
    VRType min = INFINITY;
    int k = 0;
    for (int i = 1; i <= G.vexNum; i++)
    {
        if (min > closeEdge[i].lowCost && closeEdge[i].lowCost != 0)
        {
            min = closeEdge[i].lowCost;
            k = i;
        }
    }
    return k;
}
// 时间复杂性主要体现在两层循环上，复杂性是O（n^2）
// 空间复杂性主要体现在一个辅助数组，复杂性是O（n）
// *closeEdge数组存放着每一个结点距离已经遍历过的结点的最短路径和相应的结点
void MiniSpanTree_Prim(MGraph G, VertexType u)
{
    int k = LocateVex(G, u); // 获取顶点u在图G中的编号
    // 辅助数组closeEdge的初始化
    for (int j = 1; j <= G.vexNum; ++j)
    {
        if (j != k)
            closeEdge[j] = {u, G.arc[k][j].adj};
    }
    closeEdge[k].lowCost = 0; // 初始，U = {u}

    for (int i = 1; i < G.vexNum; ++i) // 剩余G.vexNum-1个结点
    {
        k = Minimum(G); // 求出加入生成树的下一个顶点(k)

        std::cout << closeEdge[k].adjVex << "----" << G.vex[k] << std::endl; // 输出生成树上一条边
        closeEdge[k].lowCost = 0;                                            // 第k顶点并入U集

        // 修改临时最小权
        for (int j = 1; j <= G.vexNum; ++j)
        {
            // 修改closeEdge数组中的权值
            if (G.arc[k][j].adj < closeEdge[j].lowCost)
                closeEdge[j] = {G.vex[k], G.arc[k][j].adj};
        }
    }
}
