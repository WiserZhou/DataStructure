
typedef int KeyType;

typedef struct
{
    KeyType key; // 关键字
    // 其他属性
} TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 二叉排序树中序有序排列
void inOrder(BiTree T)
{
    if (T)
    {
        inOrder(T->lchild);
        printf("%d ", T->data.key);
        inOrder(T->rchild);
    }
}

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
    {
        p = T;
        return TRUE;
    } // 找到结点,p=T,返回真值
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
