
// 代码有点问题
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row, col;
    int value;
    struct Node *nextRow;
    struct Node *nextCol;
} Node;

typedef struct
{
    int numRows;
    int numCols;
    int numNonZero;
    Node *headRow;
    Node *headCol;
} SparseMatrix;

SparseMatrix fastTranspose(SparseMatrix M)
{
    SparseMatrix T;
    T.numRows = M.numCols;
    T.numCols = M.numRows;
    T.numNonZero = M.numNonZero;

    T.headRow = (Node *)malloc((T.numRows + 1) * sizeof(Node));
    T.headCol = (Node *)malloc((T.numCols + 1) * sizeof(Node));

    for (int i = 0; i <= T.numRows; i++)
    {
        T.headRow[i].nextRow = NULL;
    }
    for (int j = 0; j <= T.numCols; j++)
    {
        T.headCol[j].nextCol = NULL;
    }

    for (int i = 1; i <= M.numCols; i++)
    {
        Node *p = M.headCol[i].nextCol;
        while (p != NULL)
        {
            int j = p->row;
            int value = p->value;

            Node *q = (Node *)malloc(sizeof(Node));
            q->row = j;
            q->col = i;
            q->value = value;
            q->nextRow = T.headRow[j].nextRow;
            T.headRow[j].nextRow = q;

            q->nextCol = T.headCol[i].nextCol;
            T.headCol[i].nextCol = q;

            p = p->nextCol;
        }
    }

    return T;
}

int main()
{
    SparseMatrix M;
    M.numRows = 3;
    M.numCols = 4;
    M.numNonZero = 4;

    M.headRow = (Node *)malloc((M.numRows + 1) * sizeof(Node));
    M.headCol = (Node *)malloc((M.numCols + 1) * sizeof(Node));

    for (int i = 0; i <= M.numRows; i++)
    {
        M.headRow[i].nextRow = NULL;
    }
    for (int j = 0; j <= M.numCols; j++)
    {
        M.headCol[j].nextCol = NULL;
    }

    printf("Enter the non-zero elements of the matrix:\n");
    for (int k = 0; k < M.numNonZero; k++)
    {
        int row, col, value;
        printf("Enter row, column, and value of non-zero element %d:\n", k + 1);
        scanf("%d %d %d", &row, &col, &value);

        Node *node = (Node *)malloc(sizeof(Node));
        node->row = row;
        node->col = col;
        node->value = value;
        node->nextRow = M.headRow[row].nextRow;
        M.headRow[row].nextRow = node;
        node->nextCol = M.headCol[col].nextCol;
        M.headCol[col].nextCol = node;
    }

    SparseMatrix T = fastTranspose(M);

    printf("\nOriginal Matrix:\n");
    for (int i = 1; i <= M.numRows; i++)
    {
        Node *p = M.headRow[i].nextRow;
        while (p != NULL)
        {
            printf("%d %d %d\n", p->row, p->col, p->value);
            p = p->nextRow;
        }
    }

    printf("\nTransposed Matrix:\n");
    for (int i = 1; i <= T.numRows; i++)
    {
        Node *p = T.headRow[i].nextRow;
        while (p != NULL)
        {
            printf("%d %d %d\n", p->row, p->col, p->value);
            p = p->nextRow;
        }
    }

    return 0;
}