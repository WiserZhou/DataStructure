#include "MGraph.h"
#include <iostream>
#include <cstring>

// Floyd算法的时间复杂性主要体现在三重循环，时间复杂性为O(n^3)
// Floyd算法的空间复杂性主要体现在利用了一个二维数组，空间复杂性为O(n2)
// 讨论：权值是否可以是负值？
// 答案：权值可以是负值，但不能有长度是负值的环路

// 在Floyd算法中，D和P分别表示距离矩阵（Distance Matrix）和路径矩阵（Path Matrix）：

// D矩阵（距离矩阵）： 存储了图中任意两个顶点之间的最短路径长度。D[i][j]表示顶点i到顶点j的最短路径长度。
// 在算法执行过程中，D矩阵会不断更新，最终包含了所有顶点对之间的最短路径长度信息。

// P矩阵（路径矩阵）： 存储了图中任意两个顶点之间的最短路径上的中间顶点信息。P[i][j][k]表示从顶点i到顶点j的最
// 短路径上是否经过了顶点k。如果P[i][j][k]为真（TRUE），则表示最短路径经过了顶点k，否则表示没有经过。在算法执行过程中，P矩阵也会不断更新。

// 通过这两个矩阵，我们可以获得从一个顶点到另一个顶点的最短路径长度以及路径上的所有中间顶点。
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int DistanceMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void ShortestPath_FLOYD(MGraph G, PathMatrix P, DistanceMatrix &D)
{
    // 初始化
    for (int v = 1; v <= G.vexNum; ++v)
    {
        for (int w = 1; w <= G.vexNum; ++w)
        {
            D[v][w] = G.arc[v][w].adj; // v和w之间的距离赋值给D[v][w]

            for (int u = 1; u <= G.vexNum; ++u)
            {
                P[v][w][u] = false; // 首先初始化为每一个点都不经过
            }

            if (D[v][w] < INFINITY) // 如果v和w之间是直接连通的，那么v-w肯定经过v和w本身
            {
                P[v][w][v] = P[v][w][w] = true;
            }
        }
    }

    // 更新最短路径和路径矩阵
    for (int u = 1; u <= G.vexNum; ++u) // 对于每一个顶点，都要判断是否有其他边经过这个点
    {
        for (int v = 1; v <= G.vexNum; ++v)
        {
            for (int w = 1; w <= G.vexNum; ++w)
            {
                if (D[v][u] + D[u][w] < D[v][w]) // 从v经u到w的一条路径更短
                {
                    D[v][w] = D[v][u] + D[u][w]; // 那么直接赋值为更短的长度

                    for (int i = 1; i <= G.vexNum; ++i)
                    {
                        P[v][w][i] = (P[v][u][i] || P[u][w][i]); // 此时v-w是否经过i取决于v-u或者u-w是否经过i
                    }
                }
            }
        }
    }

    // 输出最短路径长度和路径信息
    for (int v = 1; v <= G.vexNum; ++v)
    {
        for (int w = 1; w <= G.vexNum; ++w)
        {
            std::cout << "Shortest distance from " << v << " to " << w << ": " << D[v][w] << std::endl;
            std::cout << "Path: ";
            for (int i = 1; i <= G.vexNum; ++i)
            {
                if (P[v][w][i])
                {
                    std::cout << i << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}

int main()
{
    // 示例用法
    MGraph graph;
    graph.vexNum = 4;
    int arcs[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 6, 7, 3},
        {0, 4, 0, 1, 3},
        {0, 3, 9, 0, 2},
        {0, 6, 2, 3, 0}};
    // 将 arcs 数组的内容复制到 graph.arc 中
    for (int i = 1; i <= graph.vexNum; ++i)
    {
        for (int j = 1; j <= graph.vexNum; ++j)
        {
            graph.arc[i][j].adj = arcs[i][j];
        }
    }

    PathMatrix P;
    DistanceMatrix D;

    ShortestPath_FLOYD(graph, P, D);

    return 0;
}
