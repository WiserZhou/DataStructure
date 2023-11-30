

#include <iostream>
#include <cstdlib>

struct BiTNode
{
    char data;
    BiTNode *Lchild;
    BiTNode *Rchild;
};

typedef BiTNode *BiTree;

int Search(char arr[], char target, int start, int end)
{
    for (int i = start; i <= end; i++)
        if (arr[i] == target)
            return i; // 找到目标元素的下标
    return -1;
}

void CrtBT(BiTree &T, char pre[], char ino[], int ps, int is, int n)
// ps代表pre的开始编号，is代表ino的开始下标
{
    if (n == 0) // 表示为空树
        T = NULL;
    else
    {
        int k = Search(ino, pre[ps], is, is + n - 1); // 找到树的根在中序遍历中的下标值，以此来进行建树
        if (k == -1)                                  // 表示没有找到
            T = NULL;
        else
        {
            T = (BiTNode *)malloc(sizeof(BiTNode)); // 为根节点申请空间
            T->data = pre[ps];                      // 把值传递给根节点
            if (k == is)                            // 要是k就是中序遍历的第一个元素，说明此树根结点没有左孩子
                T->Lchild = NULL;
            else
                CrtBT(T->Lchild, pre, ino, ps + 1, is, k - is); // 递归建立左子树
            if (k == is + n - 1)                                // 要是k就是中序遍历的最后个元素，说明此树根结点没有右孩子
                T->Rchild = NULL;
            else
                CrtBT(T->Rchild, pre, ino, ps + 1 + (k - is), k + 1, n - (k - is) - 1); // 递归建立左子树
        }
    }
}

void PostTraversal(BiTree T)
{
    if (T)
    {
        PostTraversal(T->Lchild);
        PostTraversal(T->Rchild);
        std::cout << T->data << " ";
    }
}

int main()
{
    char pre[100], ino[100];
    int n;

    std::cout << "请输入先序序列长度：";
    std::cin >> n;

    std::cout << "请输入先序序列：";
    for (int i = 0; i < n; i++)
        std::cin >> pre[i];

    std::cout << "请输入中序序列：";
    for (int i = 0; i < n; i++)
        std::cin >> ino[i];

    BiTree T = NULL;
    CrtBT(T, pre, ino, 0, 0, n); // 就是开始时都是从下标0开始的

    std::cout << "后序遍历结果：";
    PostTraversal(T);
    std::cout << std::endl;

    return 0;
}
