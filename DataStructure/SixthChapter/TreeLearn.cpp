/**
 * 先序遍历（PreOrderTraverse）：从树的根节点开始，先访问根节点，然后递归地先序遍历左子树，最后递归地先序遍历右子树。
 * 中序遍历（InOrderTraverse）：从树的根节点开始，递归地中序遍历左子树，然后访问根节点，最后递归地中序遍历右子树。
 * 后序遍历（PostOrderTraverse）：从树的根节点开始，递归地后序遍历左子树，然后递归地后序遍历右子树，最后访问根节点。
 * 层序遍历（LevelOrderTraverse）：从树的根节点开始，按照层级顺序逐层访问树的节点，通常使用队列来实现。
 */
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
    // 左右孩子指针
} BiTNode, *BiTree;

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

void Preorder(BiTree T, void (*visit)(TElemType &e))
{
    if (T)
    {
        // 访问结点
        visit(T->data);
        Preorder(T->lchild, visit); // 遍历左子树
        Preorder(T->rchild, visit); // 遍历右子树
    }
}

