// 数组在内存中主要采用两种存储方式：
// (1)以行序为主的存储方式;
// (2)以列序为主的存储方式。

// 分别以行序为主和以列序为主求二维数组a[3][4]
// 中元素a[1][2]地址，首地址用loc(a[0][0])表示，每个
// 元素占用L个内存单位。

// a00 a01 a02 a03
// a10 a11 a12 a13
// a20 a21 a22 a23

// 以行序为主：
// loc(a[1][2])=loc(a[0][0])+[(1×4)+2]×L

// 以列序为主：
// loc(a[1][2])=loc(a[0][0])+[(2×3)+1]×L
#include "../header/unity.h"
typedef int ElemType;

#define MAXSIZE 12500
typedef struct
{
    int i, j;   // 该非零元的行下标和列下标
    ElemType e; // 该非零元的值
} Triple;       // 三元组类型
//  三元组顺序表的实现

//! 稀疏矩阵类型也是三元组表
typedef struct
{
    Triple data[MAXSIZE + 1]; // data[0]未用
    int mu, nu, tu;           // 矩阵的行数、列数和非零元素的个数
} TSMatrix;                   // 稀疏矩阵类型

// 时间复杂度为: O(M.nu*M.tu)
Status TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    // 矩阵转置，三元组行列互换，重新排序
    int p, q, col;
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu) // 如果没有元素则没必要进行计算
    {
        q = 1;
        for (col = 1; col <= M.nu; ++col) // 用col代替T矩阵的行数 ，从M的列值上寻找到第col个
            for (p = 1; p <= M.tu; ++p)   // 遍历每一个元素值
                if (M.data[p].j == col)   // 如果M矩阵的第p个元素的列标为行数，从头开始遍历，然后寻找列值为1的元素放到最前面
                {
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q; // 将匹配的元素放到T里，使用单独的计数器q
                }
        // 将列值从小到大进行排序，然后放置到T里
    }
    return OK;
}
typedef int AtomType;

typedef enum
{
    ATOM,
    LIST
} ElemTag;

// 广义表的头尾链表存储表示

/**
 * 对于每一个结点，若tag=0表示这是一个原子结点，atom域存放该原子的值。
 * 若tag=1表示这是一个表结点，hp指向子表头，tp指向广义表的下一个
 */
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;
        struct
        {
            struct GLNode *hp, *tp;
        } ptr;
    };
} *GList;

// 扩展头尾指针的广义表结构
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;
        struct GLNode *hp;
    };
    struct GLNode *tp;
} *GList_Extra;