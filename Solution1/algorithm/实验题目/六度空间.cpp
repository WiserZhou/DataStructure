#include <iomanip>
#include <queue>
#include <iostream>
using namespace std;
#define max 1001 // N<=1000
int a[max][max];
int N, M;
queue<int> q;
double result = 1;
int dist[max];
bool visited[max];
void Print(int node, double result)
{
    result = result / N * 100; // 计算比例
    cout.setf(ios::fixed);
    cout << node << ": " << fixed << setprecision(2) << result << "%" << endl; // 输出结果,设置精度为小数点后两位
}
void bfs(int node)
{
    int front;
    dist[node] = 0;
    visited[node] = true;
    q.push(node);
    while (!q.empty())
    {
        front = q.front();
        q.pop();
        for (int i = 1; i < N + 1; i++)
        {
            if (a[front][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[front] + 1;
                if (dist[i] > 6)
                {
                    Print(node, result); // 输出结果
                    return;
                }
                result++;
            }
        }
    }
    Print(node, result); // 输出结果
    return;
}
void Default()
{
    result = 1;
    for (int i = 0; i < max; i++)
    {
        dist[i] == -1;      // 初始化距离数组
        visited[i] = false; // 初始化访问标记数组
    }
    while (!q.empty())
        q.pop(); // 清空队列
}
void creat()
{
    cin >> N >> M; // 读入节点数和边数
    for (int i = 0; i < max; i++)
    {
        dist[i] == -1;      // 初始化距离数组
        visited[i] = false; // 初始化访问标记数组
        for (int j = 0; j < max; j++)
        {
            a[i][j] = 0; // 初始化邻接矩阵
        }
    }
    int x, y;
    for (int k = 0; k < M; k++)
    {
        cin >> x >> y;
        a[x][y] = 1; // 标记连接关系
        a[y][x] = 1; // 标记连接关系
    }
    return;
}
int main()
{
    Default(); // 初始化

    creat(); // 读入图信息
    for (int i = 1; i < N + 1; i++)
    {
        bfs(i);    // 对每个节点进行广度优先搜索
        Default(); // 重置访问状态
    }
    return 0;
}