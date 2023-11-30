
typedef int KeyType;

typedef struct
{
    KeyType key; // 关键字
    // 其他属性
} TElemType;

// 二叉排序树(Binary Sort Tree)或者是一棵空树；
//  或者是具有下列性质的二叉树：
//  若根节点有左子树，则左子树上所有结点关键字的值均小于根结点关键字的值；
//  若根节点有右子树，则右子树上所有结点关键字的值均大于根结点的关键字的值；
//  根节点的左、右子树也分别为二叉排序树。

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 在二叉排序树中的查找算法
BiTree SearchBST(BiTree T, KeyType k)
{
    BiTree p = T;
    while (p != nullptr)
    {
        if (k == p->data.key)
            return p;
        if (k < p->data.key)
            p = p->lchild;
        if (k > p->data.key)
            p = p->rchild;
    }
    return nullptr;
}

// (1) 二叉排序树的平均查找长度最差情况与顺序表相同(关键字有序时),为O(n);
// (2) 最好情况与折半查找相同,是O（log2n）数量级的;
// (3) 二叉排序树的平均查找长度仍然是O(log2n)。

// 若按照中序遍历，那么将从小到大排序
void InOrder(BiTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        printf("%d ", T->data.key);
        InOrder(T->rchild);
    }
}

#include "../header/unity.h"

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree &p)
{ // 在二叉排序树T上找key，f是T的双亲，p用于记录查找路径上的最后一个结点，特殊情况是此结点的值为空，那么最后一
    // 个结点就是上一个，此结点的值就是我想要找的值，那么最后一个结点就是本结点。

    // 初始时候T的双亲为空，故f为空
    if (!T)
    {
        p = f;
        return FALSE;
    } // 树为空时，p的值就是他的父结点的值，也是最后一个结点的值，p=f ，返回假值
    else if (EQ(key, T->data.key))
        return TRUE; // 找到结点,p=T,返回真值
    else if (LT(key, T->data.key))
        return SearchBST(T->lchild, key, T, p); // 去左子树找
    else
        return SearchBST(T->rchild, key, T, p); // 去右子树找
}

Status InsertBST(BiTree &T, TElemType e)
{
    BiTree p, s; // p用来记录搜索的最后一个非空结点,s用来创建新的结点
    if (!SearchBST(T, e.key, nullptr, p))
    {
        // 确定插入位置
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->rchild = nullptr;

        if (!p)
            T = s; // p为空，则 s 为新的根结点
        else if (LT(e.key, p->data.key))
            p->lchild = s; // 插入s为p的左孩子
        else
            p->rchild = s; // 插入 s 为p的右孩子
        return TRUE;
    }
    else
        return FALSE; // T中已有e，不需要插入
} // Insert BST

// (1)二叉排序树的插入算法的时间复杂性与查找算法的相同;
// (2)最好情况是O(log2n);
//  最坏情况是O(n);
//  平均情况是O(log2n)。
// 问题：如何生成二叉排序树?
// 答案：从空树开始循环调用插入算法。

Status Delete(BiTree &p)
{
    BiTree q, s;

    if (!p->rchild) // p无右子树,则p为叶子或只有左子树
    {
        q = p;
        p = p->lchild;
        free(q);
    }

    else if (!p->lchild) // p只有右子树
    {
        q = p;
        p = p->rchild;
        free(q);
    }

    else // p的左右子树都不为空的情况
    {
        q = p;         // q是s的父亲
        s = p->lchild; // s指向p的左子树,
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }                  // 找最大
        p->data = s->data; // 把结点s的数据赋给p的数据
        if (q != p)
            q->rchild = s->lchild; // 执行了while，此时q指向最大元素的父亲，他的右边重新指向最大元素的左子树
        else
            q->lchild = s->lchild; // while未被执行，此时q就是要删除的结点，他的左孩子没有右结点，直接将孩子的左孩子接到他的左边即可
        free(s);
    }
    return TRUE;
} // Delete

Status DeleteBST(BiTree &T, KeyType key)
{
    if (!T)
        return FALSE; // 空树，无法删除
    else
    {
        if (EQ(key, T->data.key))      // 找到
            return Delete(T);          // 删除T
        else if (LT(key, T->data.key)) // 去左子树删
            return DeleteBST(T->lchild, key);
        else // 去右子树删
            return DeleteBST(T->rchild, key);
    }
} // DeleteBST

// (1)二叉排序树的删除算法的时间复杂性与查找算法的时间复杂性相同;
// (2)最好情况是O（log2n）;最坏情况是O(n);平均情况是O(log2n)。
