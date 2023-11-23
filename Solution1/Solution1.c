// #include <stdio.h>
// #include <stdlib.h>

// typedef struct data
// {
//   char name[8];
//   int age;
//   char sex[2];
//   float score;
// } Elemtype;

// typedef struct
// {
//   Elemtype data[30];
//   int length;
//   int listsize;
// } SqList; // SqList现在是一个顺序表数据类型；

// int main()
// {

//   SqList L;
//   L.data = (Elemtype *)malloc(30 * sizeof(Elemtype));
// }

// #include <stdio.h>
// int main()
// {
//   int n, i,p[30];
//   float aver, sum = 0;
//   scanf("%d", &n);
//   if (n >= 3 && n <= 30)
//   {
//     for (i = 0; i < n; i++)
//     {
//       scanf("%d", &p[i]);
//       if (p[i] < 0 || p[i] > 100)
//       {
//         printf("ERROR\n");
//         return 0;
//       }
//       sum += p[i];
//     }
//     aver = sum / n;
//     printf("%5.2f", aver);
//   }
//   else
//     printf("ERROR");
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *lchild;
    struct Node *rbro;
};

typedef struct Node Node;

Node *createNode(char data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rbro = NULL;
    return node;
}

void xian(Node *node)
{
    if (node != NULL)
    {
        printf("%c", node->data);
        xian(node->lchild);
        xian(node->rbro);
    }
}

void hou(Node *node)
{
    if (node != NULL)
    {
        hou(node->lchild);
        printf("%c", node->data);
        hou(node->rbro);
    }
}

int maxDepth(Node *T)
{
    if (T == NULL)
        return 0;
    else
        return 1 + (maxDepth(T->lchild) > maxDepth(T->rbro) ? maxDepth(T->lchild) : maxDepth(T->rbro));
}

int countLeafNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild == NULL && root->rbro == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->lchild) + countLeafNodes(root->rbro);
}

char *removeLastChar(const char *s)
{
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }

    char *result = (char *)malloc(length * sizeof(char));
    for (int i = 0; i < length - 1; i++)
    {
        result[i] = s[i];
    }
    result[length - 1] = '\0';
    return result;
}

void zimu(char *s, Node *node)
{
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }

    char *temp = (char *)malloc((length + 2) * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        temp[i] = s[i];
    }
    temp[length] = node->data;
    temp[length + 1] = '\0';

    if (node->lchild != NULL)
    {
        zimu(temp, node->lchild);
    }
    else
    {
        printf("%s\n", temp);
    }
    if (node->rbro != NULL)
    {
        char *temp2 = removeLastChar(temp);
        zimu(temp2, node->rbro);
        free(temp2);
    }
    free(temp);
}

void levelOrde(Node *root)
{
    Node **queue = (Node **)malloc(100 * sizeof(Node *));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        root = queue[front++];
        printf("%c", root->data);
        Node *temp = root->lchild;
        while (temp != NULL)
        {
            queue[rear++] = temp;
            temp = temp->rbro;
        }
    }
    free(queue);
}

int main()
{
    Node *root, *temp;
    char pre, last;
    Node **dl = (Node **)malloc(100 * sizeof(Node *));
    int flag = 0;
    char s[100];
    int rear = 0; // 在这里定义rear变量
    fgets(s, sizeof(s), stdin);
    pre = s[0];
    last = s[2];
    root = createNode(last);
    dl[0] = root;
    while (1)
    {
        if (flag == 0)
        {
            char s[100];
            fgets(s, sizeof(s), stdin);
            pre = s[0];
            last = s[2];
        }
        if (pre == '#' && last == '#')
        {
            xian(root);
            printf("\n");
            hou(root);
            printf("\n");
            levelOrde(root);
            printf("\n");
            printf("%d\n", maxDepth(root));
            printf("%d\n", countLeafNodes(root));
            zimu("", root);
            free(dl);
            return 0;
        }
        Node *nw = createNode(last);
        temp = dl[0];
        char tpdt = temp->data;

        if (tpdt == pre)
        {
            dl[rear++] = nw;
            temp->lchild = nw;
            while (1)
            {
                char is[100];
                fgets(is, sizeof(is), stdin);
                char prein = is[0];
                char lastin = is[2];
                if (prein != tpdt)
                {
                    pre = prein;
                    last = lastin;
                    flag = 1;
                    break;
                }
                else
                {
                    temp = dl[rear - 1];
                    Node *nwin = createNode(lastin);
                    dl[rear++] = nwin;
                    temp->rbro = nwin;
                }
            }
        }
        rear--;
    }
}
