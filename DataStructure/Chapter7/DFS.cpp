#include "MGraph.h"
#include "ALGraph.h"
#include <stack>
// 邻接表图的DFS
// 如果用邻接表表示图，沿每个链可以找到某个
// 顶点 v 的所有邻接顶点 w。由于总共有 2e 个边结点，
// 所以扫描边的时间为O(e)。而且对所有顶点递归访问
// 1次，所以遍历图的时间复杂性为O(n+e)。

void DFS(ALGraph G, int v, bool *visited)
{ // 从顶点v出发，深度优先搜索遍历连通图 G
    visited[v] = true;
    Visit(v, G); // 访问v
    for (int w = FirstAdjVex(G, v); w != 0; w = NextAdjVex(G, v, w))
        if (!visited[w])        // 对v的尚未访问的邻接顶点w
            DFS(G, w, visited); // 递归调用DFS
} // DFS

// 邻接矩阵的情况
// 如果用邻接矩阵表示图，则查找每一个顶点的
// 所有的边，所需时间为O(n)，则遍历图中所有的顶
// 点所需的时间为O(n2)。

void DFS(MGraph G, int v, bool *visited)
{ // 从顶点v出发，深度优先搜索遍历连通图 G
    visited[v] = true;
    Visit(v, G);
    for (int w = 1; w <= G.vexNum; w++)
        if (G.arc[v][w].adj != INFINITY && !visited[w]) // 对v的尚未访问的邻接顶点w
            DFS(G, w, visited);                         // 递归调用DFS
} // DFS

// 覆盖非连通图情况的DFS
void DFSTraverse(MGraph G)
{
    int i = 1; // 连通分量计数器
    bool visited[G.vexNum + 1];
    for (int v = 1; v <= G.vexNum; ++v)
        visited[v] = false; // 访问标志数组初始化
    for (int v = 1; v <= G.vexNum; ++v)
        if (!visited[v])
        {
            std::cout << "第" << i++ << "个连通分量" << endl;
            DFS(G, v, visited); // 从v开始深度优先搜索
        }
}
// !非递归方式DFS，将其中的stack换成queue就是BFS
void DFS(MGraph G, int v, bool *visited)
{
    std::stack<int> S;

    S.push(v);
    visited[v] = true;

    while (!S.empty())
    {
        int currentVertex = S.top();
        S.pop();

        Visit(currentVertex, G);

        for (int w = G.vexNum; w >= 1; --w)
        {
            if (G.arc[currentVertex][w].adj != INFINITY && !visited[w])
            {
                S.push(w);
                visited[w] = true;
            }
        }
    }
}

//* 以下是基于深度优先搜索查看是否G中有start到end的长度为k的路径
bool DFS(ALGraph &G, int v, int k, int target)
{
    visited[v] = true;

    if (k == 0 && v == target)
        return true; // 找到一条长度为k的路径

    for (ArcNode *arc = G.vertices[v].firstArc; arc; arc = arc->nextArc)
    {
        int adjVex = arc->adjVex;
        if (!visited[adjVex])
            if (DFS(G, adjVex, k - 1, target)) // 通过使用k-1的递归来完成长度为k的路径的证明
                return true;
    }

    visited[v] = false; // 回溯，标记为未访问
    return false;
}

// 判断是否存在长度为k的路径
bool hasSimplePathK(ALGraph &G, int start, int end, int k)
{
    if (k <= 0)
        return false; // k必须是正整数
    // 初始化visited数组
    for (int i = 0; i < G.vexNum; ++i)
        visited[i] = false;

    return DFS(G, start, k, end);
}

// *DFS判断图是否有回路
bool hasCycle()
{
    // 创建用于标记节点是否被访问过的数组
    vector<bool> visited(num_vertices, false);

    // 创建递归栈，用于标记当前递归调用路径上的节点
    vector<bool> rec_stack(num_vertices, false);

    // 遍历图中的每个节点
    for (int i = 0; i < num_vertices; ++i)
        // 如果当前节点未被访问过且存在环路，则返回 true
        if (!visited[i] && dfs(i, visited, rec_stack))
            return true;

    // 图中不存在环路，返回 false
    return false;
}

bool dfs(int node, vector<bool> &visited, vector<bool> &rec_stack)
{
    // 标记当前节点为已访问，并加入递归栈
    visited[node] = true;
    rec_stack[node] = true;

    // 遍历当前节点的邻居节点
    for (int neighbor : adj_list[node])
    {
        // 如果邻居节点未被访问过，则递归调用DFS
        if (!visited[neighbor])
        {
            if (dfs(neighbor, visited, rec_stack))
            {
                return true; // 如果递归调用返回 true，说明存在环路，直接返回 true
            }
        }
        // 如果邻居节点已经在递归栈中，说明存在环路，返回 true
        else if (rec_stack[neighbor])
        {
            return true;
        }
    }

    // 回溯时，取消当前节点在递归栈中的标记
    rec_stack[node] = false;

    // 当前路径上不存在环路，返回 false
    return false;
}
