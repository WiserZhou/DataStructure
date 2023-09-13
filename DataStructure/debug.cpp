#include <stdio.h>
#include <stdlib.h>

// 定义迷宫的大小
#define ROW 8
#define COL 8

// 迷宫结构体定义
typedef struct
{
    int row, col; // 行和列
} PosType;

typedef struct
{
    int data[ROW][COL];    // 迷宫矩阵
    int visited[ROW][COL]; // 标记是否已经访问过
} MazeType;

// 队列结构体定义
typedef struct
{
    PosType data[ROW * COL];
    int front;
    int rear;
} SqQueue;

// 初始化队列
void initQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
}

// 判断队列是否为空
int isEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}

// 入队
void enQueue(SqQueue *Q, PosType e)
{
    if ((Q->rear + 1) % (ROW * COL) == Q->front)
    {
        printf("Queue is full!\n");
        exit(0);
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % (ROW * COL);
}

// 出队
PosType deQueue(SqQueue *Q)
{
    if (isEmpty(*Q))
    {
        printf("Queue is empty!\n");
        exit(0);
    }
    PosType e = Q->data[Q->front];
    Q->front = (Q->front + 1) % (ROW * COL);
    return e;
}

// 初始化迷宫
void initMaze(MazeType *maze)
{
    int data[ROW][COL] = {
        {0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0}};
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            maze->data[i][j] = data[i][j];
            maze->visited[i][j] = 0;
        }
    }
}

// 打印迷宫
void printMaze(MazeType maze)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%3d", maze.data[i][j]);
        }
        printf("\n");
    }
}

// 判断是否可以通过
int canPass(MazeType maze, int row, int col)
{
    if (maze.data[row][col] == 0 && maze.visited[row][col] == 0)
    {
        // 没有墙壁并且没有被访问过
        return 1;
    }
    return 0;
}

// 迷宫求解函数
void solveMaze(MazeType maze, PosType start, PosType end)
{
    SqQueue Q;
    PosType curr, next;

    initQueue(&Q);
    initMaze(&maze);

    // 将起点加入队列并标记为已访问
    enQueue(&Q, start);
    maze.visited[start.row][start.col] = 1;

    while (!isEmpty(Q))
    {
        // 取出队头位置作为当前位置
        curr = deQueue(&Q);

        // 判断是否到达终点
        if (curr.row == end.row && curr.col == end.col)
        {
            printf("Find the path!\n");
            return;
        }

        // 对当前位置的上下左右四个相邻位置进行遍历
        // 并将可以通过的位置加入队列后标记为已访问
        if (curr.row - 1 >= 0 && canPass(maze, curr.row - 1, curr.col))
        {
            next.row = curr.row - 1;
            next.col = curr.col;
            enQueue(&Q, next);
            maze.visited[next.row][next.col] = 1;
        }
        if (curr.row + 1 < ROW && canPass(maze, curr.row + 1, curr.col))
        {
            next.row = curr.row + 1;
            next.col = curr.col;
            enQueue(&Q, next);
            maze.visited[next.row][next.col] = 1;
        }
        if (curr.col - 1 >= 0 && canPass(maze, curr.row, curr.col - 1))
        {
            next.row = curr.row;
            next.col = curr.col - 1;
            enQueue(&Q, next);
            maze.visited[next.row][next.col] = 1;
        }
        if (curr.col + 1 < COL && canPass(maze, curr.row, curr.col + 1))
        {
            next.row = curr.row;
            next.col = curr.col + 1;
            enQueue(&Q, next);
            maze.visited[next.row][next.col] = 1;
        }
    }

    // 队列为空，未找到路径
    printf("No path found!\n");
}

int main()
{
    MazeType maze;
    PosType start = {0, 0};
    PosType end = {ROW - 1, COL - 1};

    printf("Original maze:\n");
    printMaze(maze);

    solveMaze(maze, start, end);

    return 0;
}
