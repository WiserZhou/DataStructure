

typedef int KeyType;

typedef struct
{
    KeyType key; // 关键字
    //...... 其他信息
} ElemType;

#define EQ(a, b) ((a) == (b)) // equal
#define LT(a, b) ((a) < (b))  // less than
#define LQ(a, b) ((a) <= (b)) // less than or equal

typedef struct
{
    ElemType *elem; // 数据元素存储空间基址，建表时按实际长度分配
    int length;     // 表的长度
} SSTable;

