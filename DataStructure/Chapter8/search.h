

typedef int Keytype;

typedef struct
{
    Keytype key; // 关键字
    //...... 其他信息
} ElemType;

#define EQ(a, b) ((a) == (b)) // equal
#define LT(a, b) ((a) < (b))  // less than
#define LQ(a, b) ((a) <= (b)) // less than or equal

