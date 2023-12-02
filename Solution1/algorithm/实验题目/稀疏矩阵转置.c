

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
#define MAX_COL 100

typedef struct
{
    int row; // ��¼��ֵ
    int col; // ��¼��ֵ
    int value;
} Term;

void transpose(Term a[], Term b[])
{
    int numRows = a[0].row;    // ԭ���������
    int numCols = a[0].col;    // ԭ���������
    int numTerms = a[0].value; // ԭ����ķ���Ԫ�ظ���

    int colSize[MAX_COL]; // ԭ����ÿ�еķ���Ԫ�ظ���

    // ��ʼ��ת�þ������Ԫ��ͷ
    b[0].row = numCols;
    b[0].col = numRows;
    b[0].value = numTerms;

    // ͳ��ԭ����ÿ�еķ���Ԫ�ظ���
    for (int i = 1; i <= numCols; i++)
    {
        colSize[i] = 0;
    }
    for (int i = 1; i <= numTerms; i++)
    {
        colSize[a[i].col]++;
    }

    // ����ת�þ���ÿ�е���ʼλ��
    int startPosition[MAX_COL];
    startPosition[1] = 1;
    for (int i = 2; i <= numCols; i++)
    {
        startPosition[i] = startPosition[i - 1] + colSize[i - 1];
    }

    // ת��ԭ����ķ���Ԫ��
    for (int i = 1; i <= numTerms; i++)
    {
        int j = startPosition[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

void printMatrix(Term matrix[], int numTerms)
{
    for (int i = 0; i <= numTerms; i++)
    {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int compare(const void *a, const void *b)
{
    int rowA = ((Term *)a)->row;
    int rowB = ((Term *)b)->row;
    return rowA - rowB;
}

int main()
{
    int numRows, numCols, numTerms;
    Term matrix[MAX_TERMS], transposeMatrix[MAX_TERMS];

    scanf("%d%d%d", &numRows, &numCols, &numTerms);

    matrix[0].row = numRows;
    matrix[0].col = numCols;
    matrix[0].value = numTerms;

    for (int i = 1; i <= numTerms; i++)
    {
        scanf("%d%d%d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }

    transpose(matrix, transposeMatrix);

    qsort(transposeMatrix + 1, numTerms, sizeof(Term), compare);

    printMatrix(transposeMatrix, numTerms);

    return 0;
}