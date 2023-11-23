#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *lchild; // ָ������
    struct Node *rbro;   // ָ�����ֵ�
} Node;

// ����һ���ڵ�
Node *createNode(char data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rbro = NULL;
    return node;
}

// �������뽨�����ĺ���-�ֵ�����
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

// �������
void preOrder(Node *node)
{
    if (node != NULL)
    {
        printf("%c", node->data);
        preOrder(node->lchild);
        preOrder(node->rbro);
    }
}

// �������
void postOrder(Node *node)
{
    if (node != NULL)
    {
        postOrder(node->lchild);
        postOrder(node->rbro);
        printf("%c", node->data);
    }
}

// �����������
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

// ��������Ҷ�ӽڵ�����
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

// ������дӸ���Ҷ�ӵ�·��
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

    printf("������������");
    preOrder(root);
    printf("\n");

    printf("������������");
    postOrder(root);
    printf("\n");

    int depth = treeDepth(root);
    printf("������ȣ�%d\n", depth);

    int leafNum = leafCount(root);
    printf("Ҷ�ӽڵ�������%d\n", leafNum);

    printf("�Ӹ���Ҷ�ӵ�·����\n");
    char path[100];
    printPath(root, path, 0);

    return 0;
}