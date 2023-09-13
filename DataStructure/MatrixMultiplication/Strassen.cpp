#include <iostream>
using namespace std;
int * Strassen(int *a,int *b)
{
    
}


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
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}