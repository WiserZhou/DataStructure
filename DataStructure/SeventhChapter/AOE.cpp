#include "ALGraph.h"
#include <stack>

Status TopologicalOrder(ALGraph G, std::stack<int> &T, int ve[]) // 注意ve的大小也是MAX_VERTEX_NUM
{

    int inDegree[MAX_VERTEX_NUM];

    std::stack<int> S;         // 建立入度为零的顶点栈S
    FindInDegree(G, inDegree); // 计算各个顶点的入度

    for (int j = 1; j <= G.vexNum; ++j)
        if (inDegree[j] == 0)
            S.push(j); // 入度为0者进栈

    int count = 0;

    while (!S.empty())
    {
        int j = S.top();
        S.pop();
        T.push(j);

        ++count;

        for (ArcNode *p = G.vertices[j].firstArc; p; p = p->nextArc)
        {
            int k = p->adjVex;
            if (--inDegree[k] == 0)
                S.push(k); // 若入度减为0，则入栈

            if (ve[j] + p->adj > ve[k])
                ve[k] = ve[j] + p->adj; // 更新事件k的最早发生时间
        }
    }

    if (count < G.vexNum)
        return ERROR;
    else
        return OK;
}

Status CriticalPath(ALGraph G)
{ // 输出有向网G的各项关键活动
    stack<int> T;
    int a, j, k, el, ee, dut;
    char tag;
    ArcNode *p;
    if (!TopologicalOrder(G, T))
        return ERROR;
    for (int i = 1; i <= G.vexNum; i++)
        vl[i] = ve[G.vexNum - 1]; // 初始化顶点事件的最迟发生时间
    while (!T.empty())            // 按拓扑逆序求各顶点的vl值
        for (Pop(T, j), p = G.vertices[j].firstArc; p; p = p->nextArc)
        {
            k = p->adjVex;
            dut = *(p->info); // dut<j,k>
            if (vl[k] - dut < vl[j])
                vl[j] = vl[k] - dut; // 更新事件k的最迟发生时间
        }

    for (j = 0; j < G.vexNum; ++j) // 求ee,el和关键活动
        for (p = G.vertices[j].firstArc; p; p = p->nextArc)
        {
            k = p->adjVex;
            dut = *(p->info);
            ee = ve[j];
            el = vl[k] - dut;
            tag = (ee == el) ? '*' : ' ';
            printf(j, k, dut, ee, el, tag); // 输出关键活动
        }
    return OK;
} // CriticalPath

// 在拓扑排序求Ve[i]和逆拓扑有序求Vl[i]时,
// 所需时间为O(n+e)；
//  求各个活动的e[k]和l[k]时所需时间为O(e)；
//  总共花费时间仍然是O(n+e)。
// 如果采用邻接矩阵存储结构，时间复杂性
// 是O(n2
// )。