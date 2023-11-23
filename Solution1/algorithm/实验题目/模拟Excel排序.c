#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 106
typedef struct
{
    char num[20];
    char name[20];
    int score;
} Student;

typedef struct
{
    Student r[MAX];
    int length;
} SQList;
int N, C; //  设置的是一个全局变量

//  用来初始化每一个学生的信息的函数
void scan(SQList *L)
{
    int i;
    scanf("%d %d", &N, &C);
    for (i = 1; i <= N; i++)
    {
        scanf("%s %s %d", &L->r[i].num, &L->r[i].name, &L->r[i].score);
        L->length++;
    }
}

int Partition(SQList *L, int low, int high)
{
    strcpy(L->r[0].num, L->r[low].num);
    strcpy(L->r[0].name, L->r[low].name);
    L->r[0].score = L->r[low].score; // 这三段代码是以L.r[low]为枢轴
    // int key3 = L->r[low].score;     // 要是没有这一具代码，在case3中就需要在文中写成L->r[0].score，而不是L->r[low].score
    switch (C)
    {
    case 1:
    {
        while (low < high)
        {
            while (low < high && strcmp(L->r[high].num, L->r[0].num) >= 0)
                --high;
            L->r[low] = L->r[high]; // 只有当不满足上面的条件的时候，才会将枢轴右边的数据赋值给左边
            while (low < high && strcmp(L->r[low].num, L->r[0].num) <= 0)
                ++low;
            L->r[high] = L->r[low];
        }
        break;
    }
    case 2:
    {
        while (low < high)
        {
            while (low < high && (strcmp(L->r[high].name, L->r[0].name) > 0 || (strcmp(L->r[high].name, L->r[0].name) == 0 && strcmp(L->r[high].num, L->r[0].num) >= 0)))
                // 这段代码就是说明在姓名相等的情况下就比较学好的
                --high;
            L->r[low] = L->r[high];
            while (low < high && (strcmp(L->r[low].name, L->r[0].name) < 0 || (strcmp(L->r[low].name, L->r[0].name) == 0 && strcmp(L->r[low].num, L->r[0].num) <= 0)))
                ++low;
            L->r[high] = L->r[low];
        }

        break;
    }
    case 3:
    {
        while (low < high)
        {
            while (low < high && (L->r[high].score > L->r[0].score || (L->r[high].score == L->r[0].score && strcmp(L->r[high].num, L->r[0].num) >= 0)))
                --high;
            L->r[low] = L->r[high];
            while (low < high && (L->r[low].score < L->r[0].score || (L->r[low].score == L->r[0].score && strcmp(L->r[high].num, L->r[0].num) <= 0)))
                ++low;
            L->r[high] = L->r[low];
        }
        break;
    }
    }
    L->r[low] = L->r[0];
    return low;
}

// 递归实现快速排序
void QSort(SQList *L, int low, int high)
{
    int pivotloc;
    if (low < high)
    {
        pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}

// 输出排序后的学生信息
void Output(SQList L)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        printf("%s %s %d\n", L.r[i].num, L.r[i].name, L.r[i].score);
    }
}

int main()
{
    SQList L;
    L.length = 0;
    scan(&L);
    QSort(&L, 1, N);
    Output(L);
    return 0;
}