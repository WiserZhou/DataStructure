#include "MGraph.h"
#include "ALGraph.h"

// 伪代码
// procedure BFS(graph, start_vertex):
//     initialize an empty queue
//     create a boolean array 'visited' and set all elements to false

//     enqueue(start_vertex)
//     visited[start_vertex] = true

//     while the queue is not empty:
//         current_vertex = dequeue()

//         // Process the current vertex (e.g., print it)
//         process(current_vertex)

//         for each neighbor in graph.adjacent_vertices(current_vertex):
//             if neighbor is not visited:
//                 enqueue(neighbor)
//                 visited[neighbor] = true
// 如果使用邻接表表示图，则循环的总时间
// 代价为 d0 + d1 + … + dn-1 = O(n+e)，其中的 di
// 是顶点 i 的度。
//  如果使用邻接矩阵，则对于每一个被访问
// 过的顶点，循环要检测矩阵中的 n 个元素，总
// 的时间代价为O(n^2)。
#include <queue>

void BFSTraverse(MGraph G)
{
    vector<bool> visited(G.vexNum + 2, false); // 初始化访问标志
    queue<int> Q;

    for (int v = 1; v <= G.vexNum; ++v)
    {
        if (!visited[v])
        { // v 尚未访问
            visited[v] = true;
            Visit(v, G); // 访问 v
            Q.push(v);   // v 入队列

            while (!Q.empty())
            {
                int u = Q.front(); // 队头元素出队并置为 u
                Q.pop();

                for (int w = FirstAdjVex(G, u); w != 0; w = NextAdjVex(G, u, w))
                {
                    if (!visited[w])
                    {
                        visited[w] = true;
                        Visit(w, G);
                        Q.push(w);
                    }
                }
            }
        }
    }
}

// 基于邻接表的写法
void BFSTraverse(ALGraph G, Status (*Visit)(int v))
{

    queue<int> Q;
    vector<bool> visited(G.vexNum, false); // 初始化访问标志

    for (int v = 1; v <= G.vexNum; ++v)
    {
        if (!visited[v])
        {
            visited[v] = true;
            Visit(v);  // 访问u
            Q.push(v); // v入队列
            while (!Q.empty())
            {
                int u = Q.front(); // 队头元素出队并置为u
                Q.pop();
                for (ArcNode *p = G.vertices[u].firstArc; p != NULL; p = p->nextArc)
                {
                    int w = p->adjVex;
                    if (!visited[w])
                    {
                        visited[w] = true;
                        Visit(w);
                        Q.push(w);
                    }
                }
            }
        }
    }
}

int main()
{
    MGraph G;
    G.vexNum = 6;
    G.arcNum = 9;
    G.kind = UDG;
    for (int i = 1; i <= G.vexNum; i++)
    {
        G.vex[i] = 'A' + i - 1;
    }
    for (int i = 1; i <= G.vexNum; i++)
    {
        for (int j = 1; j <= G.vexNum; j++)
        {
            G.arc[i][j].adj = INFINITY;
        }
    }
    G.arc[1][2].adj = 1;
    G.arc[1][3].adj = 1;
    G.arc[1][5].adj = 1;
    G.arc[2][1].adj = 1;
    G.arc[2][3].adj = 1;
    G.arc[2][5].adj = 1;
    G.arc[2][6].adj = 1;
    G.arc[3][1].adj = 1;
    G.arc[3][2].adj = 1;
    G.arc[3][4].adj = 1;
    G.arc[4][3].adj = 1;
    G.arc[4][5].adj = 1;
    G.arc[5][1].adj = 1;
    G.arc[5][2].adj = 1;
    G.arc[6][2].adj = 1;
    G.arc[6][4].adj = 1;
    G.arc[6][5].adj = 1;

    BFSTraverse(G);
}