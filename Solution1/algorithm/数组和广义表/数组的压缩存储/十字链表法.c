

// 该代码使用了三元组的方式表示稀疏矩阵。结构体 OLNode 表示矩阵中的非零元素，
// 包含行号、列号和元素的值，以及两个指针域 right 和 down 用于链接右侧和下方的元素。
// 结构体 CrossList 表示整个稀疏矩阵，包含行链表头指针数组 rhead、列链表头指针数组 chead，
// 分别用于存储每一行和每一列的链表头指针。同时还记录了矩阵的行数、列数和非零元素个数。
// CreateMatrix_OL 函数用于创建稀疏矩阵，先根据用户输入的行数、列数和非零元素个数初始化稀疏矩阵的属性，
// 然后通过遍历用户输入的非零元素，创建对应的结点，并按照行链表和列链表的方式连接起来。
// display 函数用于输出稀疏矩阵，遍历列链表，并输出每个结点的行号、列号和元素的值。
// 在 main 函数中，初始化矩阵并调用 CreateMatrix_OL 函数创建稀疏矩阵，最后调用 display 函数输出稀疏矩阵。
#include <stdio.h>
#include <stdlib.h>

// 稀疏矩阵的三元组表示
typedef struct OLNode
{
    int i, j, e;                 // 矩阵三元组 i代表行 j代表列 e代表当前位置的数据
    struct OLNode *right, *down; // 指针域 右指针 下指针
} OLNode, *OLink;

typedef struct
{
    OLink *rhead, *chead; // 行和列链表头指针
    int mu, nu, tu;       // 矩阵的行数,列数和非零元的个数
} CrossList;

// 创建稀疏矩阵
CrossList CreateMatrix_OL(CrossList M);
// 输出稀疏矩阵
void display(CrossList M);

int main()
{
    CrossList M;
    M.rhead = NULL;
    M.chead = NULL;
    M = CreateMatrix_OL(M);
    printf("输出矩阵M:\n");
    display(M);
    return 0;
}

CrossList CreateMatrix_OL(CrossList M)
{
    int m, n, t;
    int i, j, e;
    OLNode *p, *q;

    printf("输入矩阵的行数、列数和非零元素个数：");
    scanf("%d%d%d", &m, &n, &t);

    M.mu = m;
    M.nu = n;
    M.tu = t;

    // 分配行和列链表头指针数组的内存空间
    if (!(M.rhead = (OLink *)malloc((m + 1) * sizeof(OLink))) || !(M.chead = (OLink *)malloc((n + 1) * sizeof(OLink))))
    {
        printf("初始化矩阵失败");
        exit(0);
    }

    // 初始化行链表头指针数组和列链表头指针数组
    for (i = 1; i <= m; i++)
    {
        M.rhead[i] = NULL;
    }
    for (j = 1; j <= n; j++)
    {
        M.chead[j] = NULL;
    }

    // 输入非零元素的行号、列号和值
    for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e))
    {
        // 创建新结点并赋值
        if (!(p = (OLNode *)malloc(sizeof(OLNode))))
        {
            printf("初始化三元组失败");
            exit(0);
        }
        p->i = i;
        p->j = j;
        p->e = e;

        // 链接到行的指定位置
        if (NULL == M.rhead[i] || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            for (q = M.rhead[i]; (q->right) && q->right->j < j; q = q->right)
                ;
            p->right = q->right;
            q->right = p;
        }

        // 链接到列的指定位置
        if (NULL == M.chead[j] || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            for (q = M.chead[j]; (q->down) && q->down->i < i; q = q->down)
                ;
            p->down = q->down;
            q->down = p;
        }
    }

    return M;
}

void display(CrossList M)
{
    for (int i = 1; i <= M.nu; i++)
    {
        if (NULL != M.chead[i])
        {
            OLink p = M.chead[i];
            while (NULL != p)
            {
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p = p->down;
            }
        }
    }
}
