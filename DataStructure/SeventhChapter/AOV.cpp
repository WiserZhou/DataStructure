#include "ALGraph.h"
#include <stack>
// 设AOV网有n个顶点，e条边。
// 初始建立入度为0 的顶点栈，要检查所有顶点一次，执行时间为O(n)；
// 排序中，若AOV网无回路，则每个顶点入、出栈各一次，每个边表结点被检查一次，执行时间为O(n+e)；
// 拓扑排序算法的时间复杂度为O(n+e)。
// 如果采用邻接矩阵存储结构，则时间复杂行为O(n^2)。
void FindInDegree(ALGraph G, int inDegree[])
{
    for (int i = 1; i <= G.vexNum; i++)
    {
        ArcNode *p = G.vertices[i].firstArc;

        while (p)
        {
            inDegree[p->adjVex]++; // 遍历所有出边表，在每一个结点的inDegree上+1
            p = p->nextArc;
        }
    }
}

Status TopologicalSort(ALGraph G)
{
    int inDegree[MAX_VERTEX_NUM];
    // 对各顶点求入度
    FindInDegree(G, inDegree);
    // 初始化栈
    stack<int> S;

    for (int i = 1; i <= G.vexNum; ++i)
    {
        // 入度为0者进栈
        if (!inDegree[i])
        {
            S.push(i);
        }
    }

    int count = 0; // 计数器，对输出顶点计数
    // 用来存储入度为零的顶点

    while (!S.empty())
    {
        // 出栈、输出、计数
        int i = S.top();
        S.pop();
        Visit(i, G);
        ++count;

        // 扫描顶点i的边链表
        for (ArcNode *p = G.vertices[i].firstArc; p; p = p->nextArc) // 删去此结点后，遍历他的出边，让他们的度数均-1
        {
            int k = p->adjVex;
            if (!(--inDegree[k]))
            {
                // 更新入度，0度入栈
                S.push(k);
            }
        }
    }

    if (count < G.vexNum)
    {
        return ERROR; // 存在环路，拓扑排序失败
    }
    else
    {
        return OK; // 拓扑排序成功
    }
}
