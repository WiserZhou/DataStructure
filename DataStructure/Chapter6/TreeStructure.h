typedef int TElemType;
#define MAX_TREE_SIZE 100
// 二叉树的最大结点数
/**
 * 二叉树的顺序存储
 */
typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 二叉树的顺序存储
// 0号单元存储根结点

// 使用满二叉树和当前的树进行一一对应

/**
 * 二叉链表
 */
typedef struct BiTNode
{ // 结点结构
    TElemType data;
    struct BiTNode *lchild, *rchild;
    BiTNode(TElemType data, struct BiTNode *lchild, struct BiTNode *rchild) : data(data), lchild(lchild), rchild(rchild) {}
    BiTNode(TElemType data) : data(data), lchild(nullptr), rchild(nullptr) {}
    // 左右孩子指针
} TreeNode, *BiTree;

/**
 * 三叉链表
 */
typedef struct TriTNode
{ // 结点结构
    TElemType data;
    struct TriTNode *lchild, *rchild;
    // 左右孩子指针
    struct TriTNode *parent; // 双亲指针
} TriTNode, *TriTree;

/**
 * 双亲链表的结点结构
 */
typedef struct BPTNode
{ // 结点结构
    TElemType data;
    int *parent; // 指向双亲的指针
    char LRTag;  // 左、右孩子标志域
} BPTNode;
/**
 * 双亲链表的树结构
 */
typedef struct BPTree
{ // 树结构
    BPTNode nodes[MAX_TREE_SIZE];
    int num_node; // 结点数目
    int root;     // 根结点的位置
} BPTree;