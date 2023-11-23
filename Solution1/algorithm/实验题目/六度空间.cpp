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
    result = result / N * 100; // �������
    cout.setf(ios::fixed);
    cout << node << ": " << fixed << setprecision(2) << result << "%" << endl; // ������,���þ���ΪС�������λ
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
                    Print(node, result); // ������
                    return;
                }
                result++;
            }
        }
    }
    Print(node, result); // ������
    return;
}
void Default()
{
    result = 1;
    for (int i = 0; i < max; i++)
    {
        dist[i] == -1;      // ��ʼ����������
        visited[i] = false; // ��ʼ�����ʱ������
    }
    while (!q.empty())
        q.pop(); // ��ն���
}
void creat()
{
    cin >> N >> M; // ����ڵ����ͱ���
    for (int i = 0; i < max; i++)
    {
        dist[i] == -1;      // ��ʼ����������
        visited[i] = false; // ��ʼ�����ʱ������
        for (int j = 0; j < max; j++)
        {
            a[i][j] = 0; // ��ʼ���ڽӾ���
        }
    }
    int x, y;
    for (int k = 0; k < M; k++)
    {
        cin >> x >> y;
        a[x][y] = 1; // ������ӹ�ϵ
        a[y][x] = 1; // ������ӹ�ϵ
    }
    return;
}
int main()
{
    Default(); // ��ʼ��

    creat(); // ����ͼ��Ϣ
    for (int i = 1; i < N + 1; i++)
    {
        bfs(i);    // ��ÿ���ڵ���й����������
        Default(); // ���÷���״̬
    }
    return 0;
}