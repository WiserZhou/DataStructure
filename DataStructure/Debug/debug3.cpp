#include <iostream>
using namespace std;
typedef struct MGraph
{
    int arc[7][7];
    char vertex[7];
    int vexNum, arcNum;
} MGraph;
typedef struct closeEdge
{
    char vertex;
    int lowCost;
} Array;
void Prim(MGraph G, char c)
{
    Array array[7];

    int k;
    for (int i = 1; i <= G.vexNum; i++)
    {
        if (c == G.vertex[i])
        {
            k = i;
            break;
        }
    }
    for (int i = 1; i <= G.vexNum; i++)
    {
        array[i] = {c, G.arc[k][i]};
    }
    array[k].lowCost = 0;
    for (int i = 1; i < G.vexNum; i++)
    {
        int min = INT32_MAX;
        int l;
        for (int i = 1; i <= G.vexNum; i++)
        {
            if (min > array[i].lowCost && array[i].lowCost != 0)
            {
                min = array[i].lowCost;
                l = i;
            }
        }
        cout << array[l].vertex << "----" << G.vertex[l] << endl;
        array[l].lowCost = 0;
        for (int i = 1; i <= G.vexNum; i++)
        {
            if (array[i].lowCost > G.arc[l][i] && G.arc[l][i] != INT32_MAX)
            {
                array[i] = {G.vertex[l], G.arc[l][i]};
            }
        }
    }
}
