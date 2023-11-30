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
    // std::cout << "input a char:" << std::endl;  // ����һ���ַ�һ���ַ������룬Ҳ����ֱ������һ���ַ���
    char ch;
    std::cin >> ch;
    if (ch == '#')  // ��û��ǲ�Ҫѡ���Կո���Ϊ�սڵ㣬���ô���
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
    std::cout << "�����������������������У��սڵ���#��ʾ����" << std::endl;
    CreateBiTree(tree);

    std::cout << "������������";
    PreOrderTraversal(tree);
    std::cout << std::endl;

    return 0;
}
