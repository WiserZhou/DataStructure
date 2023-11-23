
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结点结构体
typedef struct Node
{
    char data;          // 字符
    int frequency;      // 频率
    struct Node *left;  // 左子树
    struct Node *right; // 右子树
} Node;

// 统计字母频率
void countFrequency(char *str, int *frequency)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            frequency[str[i] - 'a']++;
        }
    }
}

// 创建叶子结点
Node *createLeaf(char data, int frequency)
{
    Node *leaf = (Node *)malloc(sizeof(Node));
    leaf->data = data;
    leaf->frequency = frequency;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

// 构造最优二叉树
Node *constructOptimalTree(int *frequency)
{
    Node **nodes = (Node **)malloc(26 * sizeof(Node *));
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
        {
            nodes[i] = createLeaf('a' + i, frequency[i]);
        }
        else
        {
            nodes[i] = NULL;
        }
    }
    int min1, min2;
    while (1)
    {
        min1 = -1;
        min2 = -1;
        for (int i = 0; i < 26; i++)
        {
            if (nodes[i] != NULL)
            {
                if (min1 == -1 || nodes[i]->frequency < nodes[min1]->frequency)
                {
                    min2 = min1;
                    min1 = i;
                }
                else if (min2 == -1 || nodes[i]->frequency < nodes[min2]->frequency)
                {
                    min2 = i;
                }
            }
        }

        if (min2 == -1)
        {
            break;
        }

        Node *parent = (Node *)malloc(sizeof(Node));
        parent->data = '\0';
        parent->frequency = nodes[min1]->frequency + nodes[min2]->frequency;
        parent->left = nodes[min1];
        parent->right = nodes[min2];

        nodes[min1] = parent;
        nodes[min2] = NULL;
    }

    Node *root = nodes[min1];
    free(nodes);
    return root;
}

// 递归计算编码
void calculateCode(Node *node, char *code, int depth)
{
    if (node->left == NULL && node->right == NULL)
    {
        printf("%c: %s\n", node->data, code);
    }
    else
    {
        code[depth] = '0';
        calculateCode(node->left, code, depth + 1);
        code[depth] = '1';
        calculateCode(node->right, code, depth + 1);
    }
}

// 计算最优码长（带权路径长度）
int calculateOptimalCodeLength(Node *node, int depth)
{
    if (node->left == NULL && node->right == NULL)
    {
        return node->frequency * depth;
    }
    else
    {
        return calculateOptimalCodeLength(node->left, depth + 1) +
               calculateOptimalCodeLength(node->right, depth + 1);
    }
}

int main()
{
    char str[257];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }

    int frequency[26] = {0};
    countFrequency(str, frequency);

    Node *root = constructOptimalTree(frequency);

    char code[30];
    calculateCode(root, code, 0);

    int optimalCodeLength = calculateOptimalCodeLength(root, 0);
    printf("%d\n", optimalCodeLength);

    free(root);

    return 0;
}