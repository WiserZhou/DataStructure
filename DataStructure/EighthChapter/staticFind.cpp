typedef int KeyType;
// 表示这个ElemType有一个key作为查找的关键字，其余还有很多的附加属性
typedef struct
{
    KeyType key; // 关键字
    // …
} ElemType;

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))

// #define EQ(a, b) (!strcmp((a), (b)))
// #define LT(a, b) (strcmp((a), (b)) < 0)
// #define LQ(a, b) (strcmp((a), (b) <= 0))

// 顺序查找表的结构
typedef struct
{
    ElemType *elem;
    // 数据元素存储空间基址，建表时
    // 按实际长度分配
    int length; // 表的长度
} SSTable;

// SSTable ST;
// ST.elem[i].key
// 顺序查找
int Search_Seq(SSTable ST, KeyType key)
{
    // 在顺序表ST中顺序查找其关键字等于
    // key的数据元素。若找到，则函数值
    // 为该元素在表中的位置，否则为0。
    ST.elem[0].key = key; // 监视哨，当后面的所有都没有查到的时候，返回0，这样的话，在后面的查找就不用每次都要比较范围。
    int i;
    for (i = ST.length; ST.elem[i].key != key; --i)
        ;
    // 从后往前找
    return i;
    // 找不到时，i为0
} // Search_Seq

// 折半查找
int Search_Bin(SSTable ST, KeyType key)
{
    KeyType low = 0;
    KeyType high = ST.length - 1; // 置区间初值

    while (low <= high)
    {
        KeyType mid = (low + high) / 2; // 获得中间的键值

        if (EQ(key, ST.elem[mid].key))
            return mid; // 找到待查元素
        else if (LT(key, ST.elem[mid].key))
            high = mid - 1; // 继续在前半区间进行查找
        else
            low = mid + 1; // 继续在后半区间进行查找
    }
    return 0; // 顺序表中不存在待查元素
} // Search_Bin

// 索引表的元素结构
typedef struct
{
    KeyType key; // 本块最大值
    int addr;    // 本块开始地址
} indexType;
#define maxBlock 100

// 索引表的结构
typedef struct
{
    indexType index[maxBlock];
    int block; // 表示索引表含有的元素个数
} INtable;
// INtable IX;

int SEARCH(SSTable ST, INtable IX, KeyType key)
{
    // 根据索引表进行查找，先比较和索引表里最大元素的大小，然后确定块的位置，在这个块里进行查找
    int i = 0, s, e; // s和e分别记录在查找表中的开始位置和结束位置

    while ((key > IX.index[i].key) && (i < IX.block))
        i++; // 在索引表中查找,确定块号i

    if (i < IX.block)
    {
        s = IX.index[i].addr;                                                 // 根据块号确定s
        i == IX.block - 1 ? e = ST.length - 1 : e = IX.index[i + 1].addr - 1; // 确定e，如果i是最后一块，那么e的值就是ST的最后
        // 一个，反之，e就是i的下一块的开始位置减1，因为最后一块没有下一块，所以要区分对待
        while (key != ST.elem[s].key && (s <= e)) // 在查找表中从s到e查找
            s = s + 1;
        if (s <= e)
            return s;
    }
    return -1;
}