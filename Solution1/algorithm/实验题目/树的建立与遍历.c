#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *lchild; // 指向左孩子
    struct Node *rbro;   // 指向右兄弟
} Node;

// 创建一个节点
Node *createNode(char data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rbro = NULL;
    return node;
}

// 根据输入建立树的孩子-兄弟链表
Node *buildTree()
{
    Node *root = NULL;
    char fa, ch;
    scanf("%c,%c", &fa, &ch);
    if (fa == '#')
    {
        return NULL;
    }
    else
    {
        root = createNode(fa);
        Node *child = createNode(ch);
        root->lchild = child;
        Node *prev = child;
        while (scanf("%c,%c", &fa, &ch) == 2)
        {
            if (fa == '#')
            {
                break;
            }
            else if (fa == root->data)
            {
                child = createNode(ch);
                prev->rbro = child;
                prev = child;
            }
        }
    }
    return root;
}

// 先序遍历
void preOrder(Node *node)
{
    if (node != NULL)
    {
        printf("%c", node->data);
        preOrder(node->lchild);
        preOrder(node->rbro);
    }
}

// 后序遍历
void postOrder(Node *node)
{
    if (node != NULL)
    {
        postOrder(node->lchild);
        postOrder(node->rbro);
        printf("%c", node->data);
    }
}

// 计算树的深度
int treeDepth(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int maxDepth = 0;
    Node *child = node->lchild;
    while (child != NULL)
    {
        int depth = treeDepth(child);
        if (depth > maxDepth)
        {
            maxDepth = depth;
        }
        child = child->rbro;
    }
    return maxDepth + 1;
}

// 计算树中叶子节点数量
int leafCount(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->lchild == NULL)
    {
        return 1 + leafCount(node->rbro);
    }
    return leafCount(node->lchild) + leafCount(node->rbro);
}

// 输出树中从根到叶子的路径
void printPath(Node *node, char *path, int pathLen)
{
    if (node == NULL)
    {
        return;
    }
    path[pathLen] = node->data;
    if (node->lchild == NULL)
    {
        for (int i = 0; i <= pathLen; i++)
        {
            printf("%c", path[i]);
        }
        printf("\n");
    }
    else
    {
        printPath(node->lchild, path, pathLen + 1);
    }
    printPath(node->rbro, path, pathLen);
}

int main()
{
    Node *root = buildTree();

    printf("先序遍历结果：");
    preOrder(root);
    printf("\n");

    printf("后序遍历结果：");
    postOrder(root);
    printf("\n");

    int depth = treeDepth(root);
    printf("树的深度：%d\n", depth);

    int leafNum = leafCount(root);
    printf("叶子节点数量：%d\n", leafNum);

    printf("从根到叶子的路径：\n");
    char path[100];
    printPath(root, path, 0);

    return 0;
}