#include <iostream>
#include <cstdlib>

#define OK 1
#define OVERFLOW -1

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef int Status;

Status CreateBiTree(BiTree &T)
{
    // std::cout << "input a char:" << std::endl;  // 可以一个字符一个字符的输入，也可以直接输入一个字符串
    char ch;
    std::cin >> ch;
    if (ch == '#')  // 最好还是不要选择以空格作为空节点，不好处理
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

void PreOrderTraversal(BiTree T)
{
    if (T)
    {
        std::cout << T->data << " ";
        PreOrderTraversal(T->lchild);
        PreOrderTraversal(T->rchild);
    }
}

int main()
{
    BiTree tree;
    std::cout << "请输入二叉树的先序遍历序列（空节点用#表示）：" << std::endl;
    CreateBiTree(tree);

    std::cout << "先序遍历结果：";
    PreOrderTraversal(tree);
    std::cout << std::endl;

    return 0;
}
