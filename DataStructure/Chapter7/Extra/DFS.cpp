#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> &graph, int startNode)
{
    vector<bool> visited(graph.size(), false); // 记录节点是否被访问过
    stack<int> s;                              // 用栈模拟递归过程
    s.push(startNode);                         // 将起始节点放入栈中
    visited[startNode] = true;                 // 标记起始节点已访问

    while (!s.empty())
    {
        int curNode = s.top(); // 获取栈顶节点
        s.pop();

        // 处理当前节点
        cout << curNode << " ";

        // 遍历与当前节点相邻的节点，将未访问的节点入栈
        for (int neighbor : graph[curNode]) // 从尾部开始遍历
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void dfsRecursive(vector<vector<int>> &graph, vector<bool> &visited, int curNode)
{
    // 处理当前节点
    cout << curNode << " ";
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

void dfs(vector<vector<int>> &graph, int startNode)
{
    // 创建visited数组，用于记录节点是否被访问过
    vector<bool> visited(graph.size(), false);

    // 调用递归函数进行深度优先遍历
    dfsRecursive(graph, visited, startNode);
}

int main()
{
    vector<vector<int>> graph{
        {1, 5},    // 0号节点的邻居节点有1和2
        {0, 2},    // 1号节点的邻居节点有0、2和3
        {1, 3, 7}, // 2号节点的邻居节点有0、1和3
        {2, 4, 7}, // 3号节点的邻居节点有1和2
        {3, 5},
        {0, 4},
        {7, 8},
        {3, 4, 6, 8},
        {6, 7}};

    dfs(graph, 0); // 从0号节点开始进行深度优先遍历
    cout << endl;

    return 0;
}

