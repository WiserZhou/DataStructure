#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // 存储边的权值和目标节点的pair类型

int primMST(vector<vector<pii>> &graph)
{
    int numNodes = graph.size(); // 图的节点数

    // 创建用于记录是否访问过的数组
    vector<bool> visited(numNodes, false);

    // 创建最小堆，用于存储边及其权值，按权值从小到大排序
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int startNode = 0; // 设置初始节点为0号节点
    int minCost = 0;   // 用于保存最小生成树的总权值

    // 将初始节点加入最小堆
    pq.push(make_pair(0, startNode));

    while (!pq.empty())
    {
        // 取出权值最小的边
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        // 如果该节点已访问过，则跳过
        if (visited[curNode])
        {
            continue;
        }

        // 将该节点标记为已访问
        visited[curNode] = true;

        // 更新最小生成树的权值
        minCost += curWeight;

        // 遍历与当前节点相邻的节点
        for (auto neighbor : graph[curNode])
        {
            int neighborNode = neighbor.second;
            int neighborWeight = neighbor.first;

            // 如果邻居节点未被访问过，则将边加入最小堆
            if (!visited[neighborNode])
            {
                pq.push(make_pair(neighborWeight, neighborNode));
            }
        }
    }

    return minCost;
}

int main()
{
    int numNodes = 5;

    // 创建图的邻接表表示
    vector<vector<pii>> graph(numNodes);

    // 添加边信息
    graph[0].push_back(make_pair(2, 1));
    graph[1].push_back(make_pair(2, 0));
    graph[1].push_back(make_pair(3, 2));
    graph[1].push_back(make_pair(4, 3));
    graph[1].push_back(make_pair(1, 4));
    graph[2].push_back(make_pair(3, 1));
    graph[3].push_back(make_pair(4, 1));
    graph[4].push_back(make_pair(1, 1));

    int minCost = primMST(graph);

    cout << "Minimum cost of the spanning tree: " << minCost << endl;

    return 0;
}
