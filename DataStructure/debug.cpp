#include <iostream>
using namespace std;
#define MAX_SIZE 1000
// #define MAX_INIT 100
typedef struct Matrix
{
    int i, j;
    int elem;
} Matrix;

int main()
{
    Matrix matrix[MAX_SIZE];
    // Matrix matrix2[MAX_SIZE];
    int col, row, num;
    cin >> col >> row >> num;
    for (int i = 1; i <= num; ++i)
    {
        // int c_col, r_row, e_elem;
        cin >> matrix[i].i >> matrix[i].j >> matrix[i].elem;
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j < num; j++)
        {
            if (matrix[j].j > matrix[j + 1].j)
            {
                Matrix matrix3 = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = matrix3;
            }
            // else if (matrix[i].j == matrix[j].j)
            // {
            //     if (matrix[i].i < matrix[j].i)
            //     {
            //         Matrix matrix3 = matrix[i];
            //         matrix[i] = matrix[j];
            //         matrix[j] = matrix3;
            //     }
            // }
        }
    }
    cout << row << " " << col << " " << num << "\n";
    for (int i = 1; i <= num; i++)
    {
        cout << matrix[i].j << " " << matrix[i].i << " " << matrix[i].elem << "\n";
    }
    return 0;
}