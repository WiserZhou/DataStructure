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

    int count = 0; // 用来计数入度为零的所有点，判断是否是无环，全部遍历

    while (!S.empty())
    {
        int j = S.top();
        S.pop();
        T.push(j); // T为拓扑逆序栈即T从栈顶到栈底为拓扑逆序

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
    int ve[MAX_VERTEX_NUM] = {0}, vl[MAX_VERTEX_NUM];
    stack<int> T;

    if (!TopologicalOrder(G, T, ve)) // 获得ve的值和拓扑逆序，判断是否为无环
        return ERROR;

    for (int i = 1; i <= G.vexNum; i++)
        vl[i] = ve[G.vexNum]; // 初始化顶点事件的最迟发生时间

    while (!T.empty()) // 按拓扑逆序求各顶点的vl值
    {
        int j = T.top();
        T.pop();
        for (ArcNode *p = G.vertices[j].firstArc; p; p = p->nextArc)
        {
            int k = p->adjVex;
            int dut = p->adj; // dut<j,k>
            if (vl[k] - dut < vl[j])
                vl[j] = vl[k] - dut; // 更新事件k的最迟发生时间
        }
    }

    for (int j = 1; j <= G.vexNum; ++j) // 求ee,el和关键活动
    {
        for (ArcNode *p = G.vertices[j].firstArc; p; p = p->nextArc)
        {
            int k = p->adjVex;
            int dut = p->adj;
            int ee = ve[j];
            int el = vl[k] - dut;
            char tag = (ee == el) ? 'T' : 'F';
            // printf(j, k, dut, ee, el, tag); // 输出关键活动
            std::cout << "活动" << j << "--" << k << ": ee:" << ee << ",el:" << el << ",is critical activity? :" << tag << std::endl;
        }
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