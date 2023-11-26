#include "MGraph.h"
/**
 * D[]表示当前所找到的原点到每个终点i的最短路径的长度，最短路径的初值都是源点到各点的路径长度，后来进行赋值的时候就是当前迭代点与各点的距离与之前已经填上的最短路径之间的比较
 * final[]表示顶点i的最短路径是否求出，1则求出，0则没有求出，求出的就没必要再进行比较了
 * P[]表示从源点到点i的当前最短路径上离i最近的那个点的编号，如果是-1，那么表示没有最短路，通过它可以标记最短路径的源头
 * v0表示源点
 */
void ShortestPath_DIJ(MGraph G, int v0, int *P, int *D)
{

    bool final[MAX_VERTEX_NUM];

    for (int v = 1; v <= G.vexNum; ++v)
    {
        final[v] = false;        // 都没有求出最短路
        D[v] = G.arc[v0][v].adj; // 赋值为源点到各点的距离
        P[v] = -1;               // 设没有最近点
        if (D[v] < INFINITY)     // 如果直接相连，那么就设置最近点为源点
            P[v] = v0;
    }

    final[v0] = true; // 设置源点已经访问过
    P[v0] = -1;       // 源点置空

    for (int i = 1; i < G.vexNum; ++i) // 剩下的G.vexNum-1个结点
    {
        int min = INFINITY; // 当前所知离v0顶点的最近距离
        int v = 0;
        for (int w = 1; w <= G.vexNum; ++w) // 寻找最近的，没有访问过的，这里的最近是指存储的D[]中最小的
            if (!final[w])                  // w顶点在V-S中，即w的最短路径还没有求出
                if (D[w] < min)
                {
                    v = w;
                    min = D[w];
                }
        
        final[v] = true; // 离v0顶点最近的v加入S集

        for (int w = 1; w <= G.vexNum; ++w)
            if (!final[w] && (min + G.arc[v][w].adj < D[w])) // 如果没有求出最短路的而且此时最短路径加上v-w之间的距离比之前的标记更短
            {
                D[w] = min + G.arc[v][w].adj;
                P[w] = v; // 重新标记
            }
    } // for

    for (int i = 1; i <= G.vexNum; i++)
    {
        std::cout << "distance: " << D[i] << "  path: " << i;
        int pre = P[i];
        while (pre != -1)
        {
            std::cout << " <- " << pre;
            pre = P[pre]; // 通过迭代P[]获得从源点到当前结点的路径
        }                 // end of while
        std::cout << std::endl;
    } // end of for
} // ShortestPath_DIJ

// Dijkstra算法的时间复杂性主要体现在求每个顶点的最短路径时，需要修改距离值和求最小值，时间复杂性O(n^2)
// Dijkstra算法的空间复杂性主要体现在两个辅助数组，空间复杂性是O(n)。


伪代码：
ShortestPath_DIJ(G, v0, P, D)
    // 初始化
    for v in vertices(G)
        final[v] = false
        D[v] = G.arc[v0][v].adj
        P[v] = -1
        if D[v] < INFINITY
            P[v] = v0

    final[v0] = true
    P[v0] = -1

    // 迭代 G.vexNum - 1 次
    for i in 1 to G.vexNum - 1
        min = INFINITY
        v = 0

        // 寻找未访问过的最近顶点
        for w in vertices(G)
            if not final[w] and D[w] < min
                v = w
                min = D[w]

        final[v] = true

        // 更新最短路径和最近点标记
        for w in vertices(G)
            if not final[w] and (min + G.arc[v][w].adj < D[w])
                D[w] = min + G.arc[v][w].adj
                P[w] = v

    // 输出最短路径信息
    for i in vertices(G)
        output "distance: " + D[i] + "  path: " + i
        pre = P[i]
        while pre != -1
            output " <- " + pre
            pre = P[pre]
        output newline
