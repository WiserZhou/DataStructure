#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> G[100]; // 每一个G数组的元素都是一个vector数组
int in_degree[100]; // 对应着每一个点的入度

void TopologicalSort(int n)
{
    stack<int> S;
    vector<int> result; // 用于存储拓扑排序的结果

    // 将所有入度为0的节点压入栈中
    for (int i = 0; i < n; ++i)
    {
        if (in_degree[i] == 0)
            S.push(i);
    }

    while (!S.empty())
    {
        int u = S.top();
        S.pop();
        result.push_back(u); // 将节点u加入结果中

        // 遍历节点u的所有出边(u, v)
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i]; // 获取u点出点的所有点
            in_degree[v]--;  // 将节点v的入度减1
            if (in_degree[v] == 0)
                S.push(v); // 如果节点v的入度变为0，则将其压入栈中
        }
    }

    // 输出拓扑排序的结果
    for (int i = 0; i < result.size() - 1; ++i)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int n = 10;                                                                                                               // 总节点数
    vector<pair<int, int>> edges = {{9, 6}, {6, 7}, {9, 8}, {8, 1}, {1, 10}, {6, 5}, {4, 5}, {4, 2}, {4, 3}, {5, 2}, {5, 3}}; // 边集合

    // 初始化邻接表和入度数组
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i].first, v = edges[i].second; // u为入点，v为出点
        G[u].push_back(v);                           // 给u点增加出点
        in_degree[v]++;                              // 增加v的入度
    }

    TopologicalSort(n);

    return 0;
}
