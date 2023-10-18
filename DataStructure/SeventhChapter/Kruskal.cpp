#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 边的结构体，包括边的两个顶点和边权重
struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

// 并查集数据结构，用于判定两个顶点是否在同一个连通分量中
class UnionFind
{
public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int Find(int x)
    { // 查找x的祖先节点
        if (parent[x] != x)
            parent[x] = Find(parent[x]); // 路径压缩
        return parent[x];
    }

    void Union(int x, int y)
    { // 将x和y所在的连通分量合并
        int rootX = Find(x), rootY = Find(y);
        if (rootX == rootY)
            return;
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
        { // 如果两个节点的秩相同，则任意选择一个作为父节点，并将父节点的秩加1
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

private:
    vector<int> parent; // 私有成员变量，存储每个节点的祖先节点
    vector<int> rank;   // 私有成员变量，存储每个节点的秩
};

// 定义比较函数，用于对边按照权重从小到大进行排序
bool cmp(Edge &e1, Edge &e2)
{
    return e1.w < e2.w;
}

void Kruskal(vector<Edge> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp); // 先按照边权重从小到大排序

    UnionFind uf(n); // 初始化并查集
    int cnt = 0;     // 记录生成树上边的数量
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (uf.Find(u) == uf.Find(v))
            continue;                                           // 如果u和v已经在同一个连通分量中，说明加入这条边会形成环，直接跳过
        cout << char(u + 'A') << "->" << char(v + 'A') << endl; // 输出生成树的一条边
        uf.Union(u, v);                                         // 合并u和v所在的连通分量
        cnt++;
        if (cnt == n - 1)
            break; // 当生成树上的边数达到n-1时停止算法，此时生成树已构建完成
    }
}

int main()
{
    int n = 5; // 图的顶点数量
    vector<Edge> edges;
    edges.push_back(Edge(0, 2, 1));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(0, 1, 6));
    edges.push_back(Edge(1, 4, 3));
    edges.push_back(Edge(1, 2, 5));
    edges.push_back(Edge(2, 4, 6));
    edges.push_back(Edge(2, 3, 5));
    edges.push_back(Edge(3, 4, 4));

    Kruskal(edges, n); // 执行算法，生成最小生成树

    return 0;
}
