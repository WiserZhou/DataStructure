#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1 // 重复

typedef int KeyType;
#define NULL_KEY -1
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
    ElemType *elem;
    int count; // 当前数据元素个数
    int size;  // hashsize[size]为当前容量
} HashTable;
#define MAX_SIZE 13
int Hash(KeyType K)
{
    return K;
}
void collision(int &p)
{
    p = (p + 1) % MAX_SIZE;
}

/**
 * c 为用于记录冲突次数的计数器
 */
Status SearchHash(HashTable H, KeyType K, int &p, int &c)
{
    p = Hash(K); // 求得哈希地址

    while (H.elem[p].key != NULL_KEY && !EQ(K, H.elem[p].key))
    {
        // 求得下一探查地址 p
        collision(p);
        ++c;
    }

    if (EQ(K, H.elem[p].key))
    {
        return SUCCESS; // 查找成功
    }
    else
    {
        return UNSUCCESS; // 查找不成功
    }
}
