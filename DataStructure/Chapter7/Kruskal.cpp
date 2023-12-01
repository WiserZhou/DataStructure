#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
public:
    int V, E;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int v, int e) : V(v), E(e)
    {
        edges.resize(E);
    }

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, {dest, weight}});
    }

    vector<pair<int, pair<int, int>>> kruskalMST();
    bool isCyclic(int parent, vector<bool> &visited, vector<vector<int>> &graph);
};

vector<pair<int, pair<int, int>>> Graph::kruskalMST()
{
    vector<pair<int, pair<int, int>>> result;
    int e = 0; // 用于计数已选择的边

    // 将边按权重进行排序
    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
         { return a.second.second < b.second.second; });

    // 分配每个顶点一个父节点
    vector<int> parent(V, -1);

    // 选择 V-1 条边
    while (result.size() < V - 1 && e < E)
    {
        pair<int, pair<int, int>> next_edge = edges[e++];

        // 加入这条边不形成环，则加入结果集中
        if (parent[next_edge.first] == -1 && parent[next_edge.second.first] == -1)
        {
            result.push_back(next_edge);

            // 将新边加入图矩阵
            vector<vector<int>> graph(V, vector<int>(V, 0));
            for (const auto &edge : result)
            {
                graph[edge.first][edge.second.first] = edge.second.second;
                graph[edge.second.first][edge.first] = edge.second.second;
            }

            // 检查是否形成环
            vector<bool> visited(V, false);
            if (isCyclic(next_edge.first, visited, graph))
            {
                result.pop_back(); // 如果形成环，则移除该边
            }
            else
            {
                // 更新父节点信息
                parent[next_edge.first] = next_edge.second.first;
                parent[next_edge.second.first] = next_edge.first;
            }
        }
    }

    return result;
}

bool Graph::isCyclic(int v, vector<bool> &visited, vector<vector<int>> &graph)
{
    if (!visited[v])
    {
        visited[v] = true;
        for (int i = 0; i < V; ++i)
        {
            if (graph[v][i] && !visited[i])
            {
                if (isCyclic(i, visited, graph))
                {
                    return true;
                }
            }
            else if (graph[v][i] && visited[i])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Graph g(4, 5);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    vector<pair<int, pair<int, int>>> mst = g.kruskalMST();

    cout << "Edges in MST:" << endl;
    for (const auto &edge : mst)
    {
        cout << edge.first << " - " << edge.second.first << " : " << edge.second.second << endl;
    }

    return 0;
}
