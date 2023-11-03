typedef int InfoType;

#define MAXSIZE 1000 // 待排顺序表最大长度
typedef int KeyType; // 关键字类型为整数类型
typedef struct
{
    KeyType key;        // 关键字项
    InfoType otherInfo; // 其它数据项
} RcdType;              // 记录类型

typedef struct
{
    RcdType r[MAXSIZE + 1]; // r[0]闲置
    int length;             // 顺序表长度
} SqList;                   // 顺序表类型

void InsertionSort(SqList &L)
{
    // 对顺序表 L 作直接插入排序。
    int i, j;
    for (i = 2; i <= L.length; ++i) // 从2号位置开始
        if (L.r[i].key < L.r[i - 1].key)
        {
            L.r[0] = L.r[i]; // 复制为监视哨
            for (j = i - 1; L.r[0].key < L.r[j].key; --j)
                L.r[j + 1] = L.r[j]; // 记录后移
            L.r[j + 1] = L.r[0];     // 插入到正确位置
        }
} // InsertSort