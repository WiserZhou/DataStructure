#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
int adjMatrix[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
void BFS(int n, int start, int *circleSizes)
{
    int queue[MAX_SIZE];
    int front = -1;
    int rear = -1;
    visited[start] = true;
    queue[++rear] = start;
    while (front != rear)
    {
        int vertex = queue[++front];
        circleSizes[start]++;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && adjMatrix[vertex][i]) // 表示的是，要是该顶点没有被访问并且图的邻接矩阵不为0的话，执行下面的语句
            {
                visited[i] = true; // 标记该节点为已访问
                queue[++rear] = i; // 该节点入栈
            }
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int circleSizes[MAX_SIZE] = {0};
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adjMatrix[a][b] = adjMatrix[b][a] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            BFS(n, i, circleSizes);
    int numOfCircles = 0;
    for (int i = 1; i <= n; i++)
        if (circleSizes[i] >= 2)
            numOfCircles++;
    printf("%d\n", numOfCircles);
    int sortedCircleSizes[MAX_SIZE]; // 这是排序好的朋友圈的个数
    int sortedCount = 0;             // 表示要进行冒泡排序的次数
    for (int i = 1; i <= n; i++)
        if (circleSizes[i] >= 2)
            sortedCircleSizes[sortedCount++] = circleSizes[i];
    for (int i = 0; i < sortedCount; i++)
        for (int j = i + 1; j < sortedCount; j++)
            if (sortedCircleSizes[i] > sortedCircleSizes[j])
            {
                int tmp = sortedCircleSizes[i];
                sortedCircleSizes[i] = sortedCircleSizes[j];
                sortedCircleSizes[j] = tmp;
            }
    for (int i = 0; i < sortedCount; i++)
        printf("%d ", sortedCircleSizes[i]);
    printf("\n");
    return 0;
}