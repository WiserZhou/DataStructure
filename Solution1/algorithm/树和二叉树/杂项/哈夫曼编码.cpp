// https://c.biancheng.net/view/3398.html
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_N 256

typedef struct TreeNode
{
    int weight;
    int parent, leftchild, rightchild;
} TreeNode, *HuffmanTree;

// 选择权值最小的两个结点，返回它们在数组中的下标
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
    s1 = s2 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            if (s1 == -1 || HT[i].weight < HT[s1].weight)
            {
                s2 = s1;
                s1 = i;
            }
            else if (s2 == -1 || HT[i].weight < HT[s2].weight)
            {
                s2 = i;
            }
        }
    }
}

// 建立哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT, int *w, int n)
{
    if (n <= 1)
    {
        return;
    }

    int m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(TreeNode));
    for (int i = 1; i <= m; i++)
    {
        HT[i].weight = HT[i].parent = HT[i].leftchild = HT[i].rightchild = 0;
    }

    // 初始化叶子结点
    for (int i = 1; i <= n; i++)
    {
        HT[i].weight = w[i - 1];
    }

    // 构建哈夫曼树
    for (int i = n + 1; i <= m; i++)
    {
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = HT[s2].parent = i;
        HT[i].leftchild = s1;
        HT[i].rightchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// 哈夫曼编码(递归实现)
void HuffmanCoding(HuffmanTree &HT, char **HC, int n)
{
    *HC = (char *)malloc(n * sizeof(char));
    (*HC)[n - 1] = '\0';

    for (int i = 1; i <= n; i++)
    {
        int p = HT[i].parent;
        int c = i;
        int k = n - 1;

        while (p != 0)
        {
            if (HT[p].leftchild == c)
            {
                (*HC)[k--] = '0';
            }
            else
            {
                (*HC)[k--] = '1';
            }

            c = p;
            p = HT[c].parent;
        }

        // 将编码写入数组
        strcpy(HC[i - 1], &(*HC)[k + 1]);
    }
}

int main()
{
    int n, w[MAX_N];
    HuffmanTree HT;
    char *HC[MAX_N];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    CreateHuffmanTree(HT, w, n);
    HuffmanCoding(HT, HC, n);

    printf("Huffman codes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d: %s\n", w[i], HC[i]);
    }

    return 0;
}
