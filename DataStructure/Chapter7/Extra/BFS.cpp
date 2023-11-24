#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); // 用于记录节点是否被访问过的数组

    queue<int> q; // 创建队列用于存储待遍历的节点
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        // 处理当前节点
        cout << curNode << " ";

        // 遍历与当前节点相邻的节点
        for (int neighbor : graph[curNode])
        {
            if (!visited[neighbor])
            { // 如果邻居节点未被访问过，则加入队列并标记为已访问
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph{
        {1, 5},    // 0号节点的邻居节点有1和2
        {0, 2, 6}, // 1号节点的邻居节点有0、2和3
        {1, 3, 7}, // 2号节点的邻居节点有0、1和3
        {2, 4, 7}, // 3号节点的邻居节点有1和2
        {3, 5},
        {0, 4},
        {1, 7, 8},
        {2, 3, 6, 8},
        {6, 7}};

    bfs(graph, 0); // 从0号节点开始进行广度优先遍历
    cout << endl;

    return 0;
}
