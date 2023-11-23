#include "MGraph.h"
#include "ALGraph.h"
// 伪代码
//  procedure DFS(node):
//      if node is not visited:
//          mark node as visited
//          process(node)
//          for each neighbor in neighbors(node):
//              DFS(neighbor)



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
    bool visited[G.vexNum];
    for (int v = 1; v <=G.vexNum; ++v)
        visited[v] = false; // 访问标志数组初始化
    for (int v = 1; v <= G.vexNum; ++v)
        if (!visited[v])
            DFS(G, v, visited); // 对尚未访问的顶点调用DFS
}