#include <iostream>
#include <vector>

using namespace std;

void dfsRecursive(vector<vector<int>> &graph, vector<bool> &visited, int curNode)
{
    visited[curNode] = true;

    // 遍历与当前节点相邻的节点
    for (int neighbor : graph[curNode])
    {
        if (!visited[neighbor])
        {
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
            dfsRecursive(graph, visited, i);
            count++;
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> graph{
        {1},    // 0号节点的邻居节点有1
        {0, 2}, // 1号节点的邻居节点有0和2
        {1, 3}, // 2号节点的邻居节点有1和3
        {2},    // 3号节点的邻居节点有2
        {5},    // 4号节点的邻居节点有5
        {4}     // 5号节点的邻居节点有4
    };

    int count = getConnectedComponentCount(graph);
    cout << "The number of connected components is: " << count << endl;

    return 0;
}
