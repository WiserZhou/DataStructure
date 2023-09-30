#include <iostream>
#include <queue>
using namespace std;

struct Position
{
    int x, y;       // 坐标位置
    int steps;      // 到达该位置的步数
    Position *prev; // 前驱位置指针
};

int maze[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}};

bool isValidPosition(int x, int y)
{
    // 检查坐标是否合法
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] == 0);
}

void solveMaze()
{
    bool visited[5][5] = {false}; // 标记数组，记录位置是否已经访问过
    int dx[4] = {-1, 1, 0, 0};    // 上下左右四个方向的x偏移量
    int dy[4] = {0, 0, -1, 1};    // 上下左右四个方向的y偏移量

    queue<Position *> q;                 // 将队列中存储的类型修改为Position*，即指向Position结构体的指针
    Position start = {0, 0, 0, nullptr}; // 起始位置
    visited[0][0] = true;
    q.push(&start);

    while (!q.empty())
    {
        Position *current = q.front();
        q.pop();

        if (current->x == 4 && current->y == 4)
        {
            // 找到出口位置，输出解并结束算法
            cout << "The number of steps is: " << current->steps << endl;

            // 还原最短路径的顺序并输出
            cout << "The shortest path: ";
            Position *p = current;
            while (p != nullptr)
            {
                cout << "(" << p->x << ", " << p->y << ") ";
                p = p->prev;
            }
            cout << endl;

            return; // 立即终止程序
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (isValidPosition(nx, ny) && !visited[nx][ny])
            {
                // 如果下一个位置合法且未访问过，则标记为已访问并放入队列
                Position *next = new Position; // 使用new关键字动态创建新的Position结构体
                next->x = nx;
                next->y = ny;
                next->steps = current->steps + 1;
                next->prev = current;
                visited[nx][ny] = true;
                q.push(next);
            }
        }
    }

    // 队列为空，无法找到出口位置
    cout << "The maze has no solution." << endl;
}

int main()
{
    solveMaze();
    return 0;
}
