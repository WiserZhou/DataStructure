

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

// 索引查找表
#define MAX_BLOCK 100

typedef struct
{
    KeyType key; // 本块最大值
    int addr;    // 本块开始地址
} IndexType;
typedef struct
{
    IndexType index[MAX_BLOCK]; // 表示索引表的块表
    int block;                  // 表示索引表的块数
} INtable;


int SearchIndex()