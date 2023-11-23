

// function Kruskal(graph):
//     initialize an empty set to store the minimum spanning tree (MST)
//     initialize a disjoint set data structure to track connected components

//     sort all edges of the graph in non-decreasing order by weight

//     for each vertex v in graph.vertices:
//         makeSet(v)  // create a disjoint set for each vertex

//     for each edge (u, v) in graph.edges:
//         if findSet(u) ≠ findSet(v):  // check if adding the edge forms a cycle
//             add (u, v) to the MST
//             unionSets(u, v)  // merge the sets of u and v

//     return the MST
// 解释：

// makeSet(v): 创建一个包含单个顶点v的新集合。
// findSet(v): 返回包含顶点v的集合的代表元素。
// unionSets(u, v): 将包含顶点u和顶点v的两个集合合并为一个集合。
#include <vector>
// 定义边的数据结构
struct Edge
{
    int u, v, weight;
};

// 定义并查集的数据结构
struct DisjointSet
{
    int *parent, *rank;
    int n;

    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

        // 初始化每个顶点为一个独立的集合
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // 查找集合的代表元素
    int findSet(int u)
    {
        if (u != parent[u])
            parent[u] = findSet(parent[u]);
        return parent[u];
    }

    // 合并两个集合
    void unionSets(int u, int v)
    {
        int rootU = findSet(u);
        int rootV = findSet(v);

        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

// Kruskal算法函数
void kruskal(vector<Edge> &edges, int n)
{
    vector<Edge> minimumSpanningTree;
    DisjointSet disjointSet(n);

    // 对边按权值升序排序
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    int nComp = n; // 初始连通分量数等于顶点数

    // 遍历排序后的边
    for (const Edge &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        // 检查边的两个端点是否属于不同的连通分量
        if (disjointSet.findSet(u) != disjointSet.findSet(v))
        {
            // 将边加入最小生成树
            minimumSpanningTree.push_back(edge);

            // 合并两个连通分量
            disjointSet.unionSets(u, v);

            // 连通分量数减一
            nComp--;

            // 如果连通分量数已经为1，说明所有顶点都在同一个集合中，算法结束
            if (nComp == 1)
                break;
        }
    }

    // 在这里可以根据需要对最小生成树进行进一步处理或输出
}
