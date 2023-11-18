#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void search(vector<vector<int>> matrix, int depth, int &num, vector<int> &visit, int index)
{
    if (depth >= 6)
        return;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (visit[i] == 0 && matrix[index][i] == 1)
        {
            num++;
            visit[i] = 1;
            search(matrix, depth + 1, num, visit, i);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        matrix[x - 1][y - 1] = 1;
        matrix[y - 1][x - 1] = 1;
    }
    // cout << "OK";
    for (int i = 0; i < N; i++)
    {
        vector<int> visit(N, 0);

        visit[i] = 1;
        int num = 1;
        search(matrix, 0, num, visit, i);
        // cout << num << endl;
        cout << fixed << setprecision(2) << i + 1 << ": " << num / (double)N * 100 << "%" << endl;
    }
    return 0;
}