
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct
{                      // 项的表示
    float coefficient; // 系数
    int exponent;      // 指数
} term, ElemType;      // term用于本ADT，ElemType为LinkList的数据元素
typedef LinkList polynomial;
// 用带表头结点的有序链表表示多项式