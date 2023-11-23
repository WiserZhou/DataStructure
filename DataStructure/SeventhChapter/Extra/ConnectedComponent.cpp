#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> num;
int NUM = 0;
void dfsRecursive(vector<vector<int>> &graph, vector<bool> &visited, int curNode)
{
    visited[curNode] = true;

    // 遍历与当前节点相邻的节点
    for (int neighbor = graph[curNode].size() - 1; neighbor >= 0; neighbor--)
    {
        if (!visited[neighbor] && graph[curNode][neighbor] == 1)
        {
            NUM++;
            dfsRecursive(graph, visited, neighbor);
        }
    }
}

int getConnectedComponentCount(vector<vector<int>> &graph)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); // 用于记录节点是否被访问过的数组

    int count = 0;
    for (int i = 0; i < numNodes; i++)
    { // 从每个未被访问的节点开始进行深度优先搜索
        if (!visited[i])
        {
            NUM = 0;
            dfsRecursive(graph, visited, i);

            if (NUM + 1 >= 2)
            {
                count++;
                num.push_back(NUM + 1);
            }
        }
    }

    return count;
}

int main()
{

    int n, m;
    int u, v;
    cin >> n >> m;
    vector<vector<int>> graph;
    graph.resize(n, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    //   matrix.resize(m, std::vector<int>(m)); // 分配空间并初始化为默认值0
    int count = getConnectedComponentCount(graph);
    cout << count << endl;
    sort(num.begin(), num.end());
    for (auto i : num)
    {
        cout << i << " ";
    }
    return 0;
}
