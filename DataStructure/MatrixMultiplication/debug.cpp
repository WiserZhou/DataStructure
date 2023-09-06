#include <iostream>
using namespace std;

int main()
{
    int n = 2;
    int A[n][n] = {{1, 2}, {3, 4}};
    int B[n][n] = {{1, 2}, {3, 4}};
    int C[n][n] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}