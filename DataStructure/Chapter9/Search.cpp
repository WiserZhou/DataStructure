

typedef int KeyType;

typedef struct
{
    KeyType key; // 关键字
    //...... 其他信息
} ElemType;

#define EQ(a, b) ((a) == (b)) // equal
#define LT(a, b) ((a) < (b))  // less than
#define LQ(a, b) ((a) <= (b)) // less than or equal
#define NE(a, b) ((a) != (b)) // not equal

typedef struct
{
    ElemType *elem; // 数据元素存储空间基址，建表时按实际长度分配
    int length;     // 表的长度
} SSTable;

// 倒序，从后往前找，在0的位置存要查找的数据，不必讨论越界问题
int Search_Seq(SSTable ST, KeyType key)
{
    // 在顺序表ST中顺序查找其关键字等于key的数据元素。
    // 若找到，则函数值为该元素在表中的位置，否则为0。
    ST.elem[0].key = key; // 设置哨兵
    int i;
    for (i = ST.length; NE(ST.elem[i].key, key); --i)
        ;
    // 从后往前找
    return i; // 找不到时，i为0
} // Search_Seq

// 折半查找
int Search_Bin(SSTable ST, KeyType key)
{
    int low = 1;
    int high = ST.length ; // 置区间初值

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (EQ(key, ST.elem[mid].key))
            return mid; // 找到待查元素
        else if (LT(key, ST.elem[mid].key))
            high = mid - 1; // 继续在前半区间进行查找
        else
            low = mid + 1; // 继续在后半区间进行查找
    }

    return 0; // 顺序表中不存在待查元素
} // Search_Bin

// 折半查找的时间复杂度为 \(O(\log_2 n)\) 可以通过以下步骤来证明：

// 假设数组的长度为 \(n\)，折半查找的过程是将数组分成两半，每次通过比较中间元素来确定目标元素在哪一半中。这样，每一轮查找都将搜索范围减半。

// 1. **第一轮：** 查找时，考虑整个数组，数组长度为 \(n\)。
// 2. **第二轮：** 如果目标元素不在第一半，就在第二半查找，此时搜索范围缩小为 \(n/2\)。
// 3. **第三轮：** 如果目标元素不在第二半，就在第四半查找，此时搜索范围缩小为 \(n/4\)。
// 4. **以此类推：** 第 \(k\) 轮查找后，搜索范围缩小为 \(n/2^k\)。

// 在最坏情况下，当找到目标元素时，假设共查找 \(k\) 轮，即 \(n/2^k = 1\)。解上述等式，得到 \(k = \log_2 n\)。

// 因此，折半查找的时间复杂度为 \(O(\log_2 n)\)。

// 查找的平均查找长度的计算
// https: // blog.csdn.net/zhupengqq/article/details/51837908

int Search_Bin_Recursion(int low, int high, LIST F, int K)
{

    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (K == F[mid].key)
            return mid; // 找到关键字 K，返回索引 mid
        else if (K < F[mid].key)
            return Search_Bin_Recursion(low, mid - 1, F, K); // 在左半边继续查找
        else
            return Search_Bin_Recursion(mid + 1, high, F, K); // 在右半边继续查找
    }

    return -1; // 没有找到关键字 K，返回 -1
}

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

// 索引表查找法，首先确定他所在的区块，然后在区块内顺序查找，相当于在索引表和部分原表内进行顺序查找
int Search_Index(SSTable ST, INtable IX, KeyType key)
{
    int i = 0, s, e; // s and e record the start and end positions in the search table

    // Binary search in the index table to determine the block number (i)
    while ((key > IX.index[i].key) && (i < IX.block))
        i++;

    if (i < IX.block)
    {
        s = IX.index[i].addr; // Determine the start position (s)

        // Determine the end position (e)
        i == IX.block - 1 ? e = ST.length - 1 : e = IX.index[i + 1].addr - 1;

        // Linear search in the search table from s to e
        while (key != ST.elem[s].key && (s <= e))
            s = s + 1;

        if (s <= e)
            return s; // Return the position if the key is found
    }

    return -1; // Return -1 if the key is not found
}

// 问题：长度为n的线性表,平均分成多少块平均查找次数最少?   sqrt(n)

// 问题：如果索引表长度为b，每块平均长度为L平均查找长度是多少？  (b+1)/2+(L+1)/2。