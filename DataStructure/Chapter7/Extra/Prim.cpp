#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 0x7fffffff // 表示无穷大

typedef char vertexType;
typedef int adjType;

// 图的邻接矩阵表示
struct MGraph
{
    vector<vertexType> vex;       // 顶点集合
    vector<vector<adjType>> arcs; // 邻接矩阵
    int vexNum, arNum;            // 顶点数和边数
};

int LocateVex(MGraph G, vertexType u)
{
    for (int i = 0; i < G.vexNum; i++)
    {
        if (G.vex[i] == u)
        {
            return i;
        }
    }
    return -1;
}

// 找到未加入最小生成树的顶点中权值最小的顶点
int minimum(vector<adjType> &lowCost, vector<bool> &inTree)
{
    int mincost = MAX_INT;
    int minIndex = -1;

    for (int i = 0; i < lowCost.size(); i++)
    {
        if (!inTree[i] && lowCost[i] < mincost)
        {
            mincost = lowCost[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void MiniSpanTree_P(MGraph G, vertexType u)
{
    int k;
    int i, j;
    vector<int> closeEdge(G.vexNum);      // 辅助数组，记录顶点到最小生成树的最小权值
    vector<bool> inTree(G.vexNum, false); // 记录顶点是否已加入最小生成树

    k = LocateVex(G, u); // k是节点u的编号

    for (j = 0; j < G.vexNum; ++j)
    {
        if (j != k)
            closeEdge[j] = G.arcs[k][j]; // 将k顶点到其他顶点的距离全部输入closeEdge数组
    }

    closeEdge[k] = 0; // 初始，U = {u}
    inTree[k] = true;

    for (i = 1; i < G.vexNum; ++i)
    {
        k = minimum(closeEdge, inTree); // 求出加入生成树的下一个顶点(k)

        adjType minWeight = MAX_INT;
        int minIndex = -1;

        // 在已加入最小生成树的顶点中找到与正在加入的顶点相邻接且权值最小的顶点
        for (j = 0; j < G.vexNum; ++j)
        {
            if (inTree[j] && G.arcs[k][j] < minWeight)
            {
                minWeight = G.arcs[k][j];
                minIndex = j;
            }
        }

        if (minIndex != -1)
        {
            cout << G.vex[minIndex] << "->" << G.vex[k] << endl; // 输出生成树上一条边
        }

        inTree[k] = true; // 第k顶点并入U集

        for (j = 0; j < G.vexNum; ++j)
        {
            if (!inTree[j] && G.arcs[k][j] < closeEdge[j])
            {
                closeEdge[j] = G.arcs[k][j];
            }
        }
    }
}

int main()
{
    MGraph graph;
    graph.vexNum = 6;
    graph.arNum = 10;

    // 初始化顶点和邻接矩阵
    for (int i = 0; i < graph.vexNum; i++)
    {
        vector<adjType> row(graph.vexNum);
        graph.arcs.push_back(row);
    }

    graph.vex = {'0', '1', '2', '3', '4', '5'};

    // 初始化邻接矩阵
    // 这里使用了无向图，矩阵对称xcx
    graph.arcs = {
        {0, 6, 1, 5, MAX_INT, MAX_INT},
        {6, 0, 5, MAX_INT, 3, MAX_INT},
        {1, 5, 0, 5, 6, 4},
        {5, MAX_INT, 5, 0, MAX_INT, 2},
        {MAX_INT, 3, 6, MAX_INT, 0, 6},
        {MAX_INT, MAX_INT, 4, 2, 6, 0}};

    MiniSpanTree_P(graph, '0');

    return 0;
}
