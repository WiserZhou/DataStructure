// #include <stdio.h>
// #include <stdlib.h>

// // 二叉树节点的定义
// typedef struct TreeNode
// {
//     char data;              // 数据域
//     struct TreeNode *left;  // 左子树指针
//     struct TreeNode *right; // 右子树指针
// } TreeNode;

// // 创建节点
// TreeNode *createNode(char data)
// {
//     TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// // 判断运算符的优先级
// int priority(char op)
// {
//     if (op == '+' || op == '-')
//         return 1;
//     else if (op == '*' || op == '/')
//         return 2;
//     return 0;
// }

// // 根据中缀表达式建立二叉树
// TreeNode *buildExpressionTree(char expression[])
// {
//     TreeNode *stack[100];
//     int top = -1;
//     int i = 0;

//     while (expression[i] != '\0')
//     {
//         if (expression[i] == '(')
//         { // 左括号，将运算符入栈
//             stack[++top] = createNode(expression[i]);
//         }
//         else if (expression[i] == ')' && top >= 0)
//         { // 右括号，弹出运算符并建立子树
//             while (top >= 1 && stack[top]->data != '(')
//             {
//                 TreeNode *right = stack[top--];
//                 TreeNode *op = stack[top--];
//                 TreeNode *left = stack[top--];

//                 op->left = left;
//                 op->right = right;

//                 stack[++top] = op;
//             }
//             if (stack[top]->data == '(')
//             { // 弹出左括号
//                 top--;
//             }
//         }
//         // else if (expression[i] >= 'a' && expression[i] <= 'z')
//         // { // 操作数，直接入栈
//         //     stack[++top] = createNode(expression[i]);
//         // }
//         else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
//         { // 运算符
//             while (top >= 0 && priority(expression[i]) <= priority(stack[top]->data))
//             {
//                 TreeNode *right = stack[top--];
//                 TreeNode *op = stack[top--];
//                 TreeNode *left = stack[top--];

//                 op->left = left;
//                 op->right = right;

//                 stack[++top] = op;
//             }
//             stack[++top] = createNode(expression[i]);
//         }
//         else
//         {
//             stack[++top] = createNode(expression[i]);
//         }
//         i++;
//     }

//     // 构建树的根节点
//     while (top >= 1)
//     {
//         TreeNode *right = stack[top--];
//         TreeNode *op = stack[top--];
//         TreeNode *left = stack[top--];

//         op->left = left;
//         op->right = right;

//         stack[++top] = op;
//     }

//     return stack[top];
// }

// // 先序遍历
// void preorderTraversal(TreeNode *root)
// {
//     if (root != NULL)
//     {
//         printf("%c", root->data);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//     }
// }

// // 中序遍历
// void inorderTraversal(TreeNode *root)
// {
//     if (root != NULL)
//     {
//         inorderTraversal(root->left);
//         printf("%c", root->data);
//         inorderTraversal(root->right);
//     }
// }

// // 后序遍历
// void postorderTraversal(TreeNode *root)
// {
//     if (root != NULL)
//     {
//         postorderTraversal(root->left);
//         postorderTraversal(root->right);
//         printf("%c", root->data);
//     }
// }

// int main()
// {
//     char expression[100];
//     scanf("%s", expression);

//     TreeNode *root = buildExpressionTree(expression);

//     preorderTraversal(root);
//     printf("\n");

//     inorderTraversal(root);
//     printf("\n");

//     postorderTraversal(root);
//     printf("\n");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct Node
// {
//     char letter;
//     int freq;
//     struct Node *left;
//     struct Node *right;
// } Node;

// // 统计频率
// void countFrequency(char *str, int *frequency)
// {
//     int len = strlen(str);
//     for (int i = 0; i < len; i++)
//     {
//         if (str[i] != ' ')
//         {
//             frequency[str[i] - 'a']++;
//         }
//     }
// }

// // 构造最优二叉树
// Node *buildOptimalTree(int *frequency)
// {
//     Node *forest[256] = {NULL};
//     int forestSize = 0;

//     // 创建单节点树并插入森林
//     for (int i = 0; i < 26; i++)
//     {
//         if (frequency[i] > 0)
//         {
//             Node *node = (Node *)malloc(sizeof(Node));
//             node->letter = 'a' + i;
//             node->freq = frequency[i];
//             node->left = NULL;
//             node->right = NULL;
//             forest[forestSize++] = node;
//         }
//     }

//     while (forestSize > 1)
//     {
//         // 找到频率最小的两棵树
//         int minIndex1 = 0;
//         int minIndex2 = 1;
//         if (forest[minIndex2]->freq < forest[minIndex1]->freq)
//         {
//             int temp = minIndex1;
//             minIndex1 = minIndex2;
//             minIndex2 = temp;
//         }
//         for (int i = 2; i < forestSize; i++)
//         {
//             if (forest[i]->freq < forest[minIndex1]->freq)
//             {
//                 minIndex2 = minIndex1;
//                 minIndex1 = i;
//             }
//             else if (forest[i]->freq < forest[minIndex2]->freq)
//             {
//                 minIndex2 = i;
//             }
//         }

//         // 构造一棵新树
//         Node *newTree = (Node *)malloc(sizeof(Node));
//         newTree->letter = '$';
//         newTree->freq = forest[minIndex1]->freq + forest[minIndex2]->freq;
//         newTree->left = forest[minIndex1];
//         newTree->right = forest[minIndex2];

//         // 插入森林
//         forest[minIndex1] = newTree;
//         forest[minIndex2] = forest[forestSize - 1];
//         forestSize--;
//     }

//     return forest[0];
// }

// // 计算编码
// void calculateCodes(Node *root, int *frequency, char **codes, char *currentCode)
// {
//     if (root->left == NULL && root->right == NULL)
//     {
//         int index = root->letter - 'a';
//         codes[index] = (char *)malloc(sizeof(char) * (strlen(currentCode) + 1));
//         strcpy(codes[index], currentCode);
//         frequency[index] = root->freq;
//     }
//     else
//     {
//         int len = strlen(currentCode);
//         char *leftCode = (char *)malloc(sizeof(char) * (len + 2));
//         char *rightCode = (char *)malloc(sizeof(char) * (len + 2));
//         strcpy(leftCode, currentCode);
//         strcpy(rightCode, currentCode);
//         leftCode[len] = '0';
//         leftCode[len + 1] = '\0';
//         rightCode[len] = '1';
//         rightCode[len + 1] = '\0';
//         calculateCodes(root->left, frequency, codes, leftCode);
//         calculateCodes(root->right, frequency, codes, rightCode);
//         free(leftCode);
//         free(rightCode);
//     }
// }

// // 计算最优码长
// int calculateOptimalCodeLength(char *str, char **codes)
// {
//     int len = strlen(str);
//     int codeLength = 0;

//     for (int i = 0; i < len; i++)
//     {
//         if (str[i] != ' ')
//         {
//             int index = str[i] - 'a';
//             codeLength += strlen(codes[index]) * codes[index][0];
//         }
//     }

//     return codeLength;
// }

// int main()
// {
//     char str[257];
//     fgets(str, sizeof(str), stdin);
//     int frequency[26] = {0};
//     countFrequency(str, frequency);
//     Node *root = buildOptimalTree(frequency);
//     char *codes[26];
//     calculateCodes(root, frequency, codes, "");
//     int optimalCodeLength = calculateOptimalCodeLength(str, codes);

//     // 输出字母频率和编码
//     for (int i = 0; i < 26; i++)
//     {
//         if (frequency[i] > 0)
//         {
//             printf("%c(%d)%s\n", 'a' + i, frequency[i], codes[i]);
//         }
//     }

//     printf("%d\n", optimalCodeLength);

//     // 释放内存
//     for (int i = 0; i < 26; i++)
//     {
//         if (frequency[i] > 0)
//         {
//             free(codes[i]);
//         }
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <string.h>

// #define MAX_NODES 100

// typedef struct TreeNode
// {
//     char val;
//     struct TreeNode *first_child;
//     struct TreeNode *next_sibling;
// } TreeNode;

// TreeNode *createNode(char val)
// {
//     TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
//     node->val = val;
//     node->first_child = NULL;
//     node->next_sibling = NULL;
//     return node;
// }

// TreeNode *buildTree()
// {
//     TreeNode *root = NULL;
//     TreeNode *nodes[MAX_NODES];
//     char fa, ch;
//     int count = 0;
//     scanf("%c,%c", &fa, &ch);
//     while (fa != '#' || ch != '#')
//     {
//         TreeNode *new_node = createNode(ch);
//         nodes[count] = new_node;
//         count++;
//         if (fa == ch)
//         {
//             root = new_node;
//         }
//         else
//         {
//             int i;
//             for (i = 0; i < count - 1; i++)
//             {
//                 if (nodes[i]->val == fa)
//                 {
//                     if (nodes[i]->first_child == NULL)
//                     {
//                         nodes[i]->first_child = new_node;
//                     }
//                     else
//                     {
//                         TreeNode *sibling = nodes[i]->first_child;
//                         while (sibling->next_sibling != NULL)
//                         {
//                             sibling = sibling->next_sibling;
//                         }
//                         sibling->next_sibling = new_node;
//                     }
//                 }
//             }
//         }
//         scanf("%c,%c", &fa, &ch);
//     }
//     return root;
// }

// void preorderTraversal(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     printf("%c", root->val);
//     preorderTraversal(root->first_child);
//     preorderTraversal(root->next_sibling);
// }

// void postorderTraversal(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     postorderTraversal(root->first_child);
//     printf("%c", root->val);
//     postorderTraversal(root->next_sibling);
// }

// int depth(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int max_depth = depth(root->first_child);
//     TreeNode *sibling = root->first_child;
//     while (sibling != NULL)
//     {
//         int sibling_depth = depth(sibling);
//         if (sibling_depth > max_depth)
//         {
//             max_depth = sibling_depth;
//         }
//         sibling = sibling->next_sibling;
//     }

//     return max_depth + 1;
// }

// int leafCount(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     if (root->first_child == NULL)
//     {
//         return 1 + leafCount(root->next_sibling);
//     }

//     return leafCount(root->first_child) + leafCount(root->next_sibling);
// }

// void printPathUtil(TreeNode *root, char *path, int path_len)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     path[path_len++] = root->val;

//     if (root->first_child == NULL)
//     {
//         int i;
//         for (i = 0; i < path_len; i++)
//         {
//             printf("%c", path[i]);
//         }
//         printf("\n");
//     }

//     printPathUtil(root->first_child, path, path_len);
//     printPathUtil(root->next_sibling, path, path_len);
// }

// void printPath(TreeNode *root)
// {
//     char path[MAX_NODES];
//     printPathUtil(root, path, 0);
// }

// int main()
// {
//     TreeNode *root = buildTree();
//     preorderTraversal(root);
//     printf("\n");
//     postorderTraversal(root);
//     printf("\n");
//     printf("%d\n", depth(root));
//     printf("%d\n", leafCount(root));
//     printPath(root);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Huffman树结点
// typedef struct Node {
//     int freq;
//     char data;
//     struct Node* left;
//     struct Node* right;
// } Node;

// // 最小堆结构
// typedef struct MinHeap {
//     int size;
//     int capacity;
//     Node** array;
// } MinHeap;

// // 创建一个新的Huffman树结点
// Node* newNode(int freq, char data) {
//     Node* node = (Node*)malloc(sizeof(Node));
//     node->freq = freq;
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }

// // 创建一个新的最小堆
// MinHeap* createMinHeap(int capacity) {
//     MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
//     minHeap->size = 0;
//     minHeap->capacity = capacity;
//     minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
//     return minHeap;
// }

// // 交换两个结点
// void swapNode(Node** a, Node** b) {
//     Node* t = *a;
//     *a = *b;
//     *b = t;
// }

// // 调整最小堆
// void minHeapify(MinHeap* minHeap, int idx) {
//     int smallest = idx;
//     int left = 2 * idx + 1;
//     int right = 2 * idx + 2;

//     if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
//         smallest = left;

//     if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
//         smallest = right;

//     if (smallest != idx) {
//         swapNode(&minHeap->array[idx], &minHeap->array[smallest]);
//         minHeapify(minHeap, smallest);
//     }
// }

// // 检查最小堆是否只有一个结点
// int isSizeOne(MinHeap* minHeap) {
//     return (minHeap->size == 1);
// }

// // 获取并删除最小堆的最小结点
// Node* extractMin(MinHeap* minHeap) {
//     Node* node = minHeap->array[0];
//     minHeap->array[0] = minHeap->array[minHeap->size - 1];
//     --minHeap->size;
//     minHeapify(minHeap, 0);
//     return node;
// }

// // 插入一个结点到最小堆中
// void insertMinHeap(MinHeap* minHeap, Node* node) {
//     ++minHeap->size;
//     int i = minHeap->size - 1;

//     while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
//         minHeap->array[i] = minHeap->array[(i - 1) / 2];
//         i = (i - 1) / 2;
//     }

//     minHeap->array[i] = node;
// }

// // 构建Huffman树
// Node* buildHuffmanTree(char data[], int freq[], int size) {
//     MinHeap* minHeap = createMinHeap(size);

//     for (int i = 0; i < size; ++i) {
//         minHeap->array[i] = newNode(freq[i], data[i]);
//     }

//     minHeap->size = size;

//     while (!isSizeOne(minHeap)) {
//         Node* left = extractMin(minHeap);
//         Node* right = extractMin(minHeap);

//         Node* top = newNode(left->freq + right->freq, '$');
//         top->left = left;
//         top->right = right;

//         insertMinHeap(minHeap, top);
//     }

//     return extractMin(minHeap);
// }

// // 打印Huffman编码
// void printCodes(Node* root, int arr[], int top) {
//     if (root->left) {
//         arr[top] = 0;
//         printCodes(root->left, arr, top + 1);
//     }

//     if (root->right) {
//         arr[top] = 1;
//         printCodes(root->right, arr, top + 1);
//     }

//     if (!root->left && !root->right) {
//         printf("%c(%d): ", root->data, root->freq);
//         for (int i = 0; i < top; ++i) {
//             printf("%d", arr[i]);
//         }
//         printf("\n");
//     }
// }

// // 计算Huffman树的带权路径长度
// int calculateOptimalCodeLength(Node* root, int depth) {
//     if (!root)
//         return 0;

//     if (!root->left && !root->right)
//         return root->freq * depth;

//     return calculateOptimalCodeLength(root->left, depth + 1) + calculateOptimalCodeLength(root->right, depth + 1);
// }

// // 统计字母频率
// void countLetterFrequency(char str[], int freq[]) {
//     int len = strlen(str);

//     for (int i = 0; i < len; ++i) {
//         if (str[i] != ' ') {
//             freq[str[i] - 'a']++;
//         }
//     }
// }

// // 按字母频率进行升序排序
// void sortByFrequency(char data[], int freq[], int size) {
//     for (int i = 0; i < size - 1; ++i) {
//         for (int j = 0; j < size - i - 1; ++j) {
//             if (freq[j] > freq[j + 1]) {
//                 int tempFreq = freq[j];
//                 freq[j] = freq[j + 1];
//                 freq[j + 1] = tempFreq;

//                 char tempData = data[j];
//                 data[j] = data[j + 1];
//                 data[j + 1] = tempData;
//             }
//         }
//     }
// }

// int main() {
//     char str[256];
//     scanf("%s",str);
//     int len = strlen(str);
//     int freq[26] = { 0 };

//     countLetterFrequency(str, freq);

//     int size = 0;
//     for (int i = 0; i < 26; ++i) {
//         if (freq[i] > 0) {
//             size++;
//         }
//     }

//     char data[size];
//     int validFreq[size];
//     int index = 0;
//     for (int i = 0; i < 26; ++i) {
//         if (freq[i] > 0) {
//             data[index] = i + 'a';
//             validFreq[index] = freq[i];
//             index++;
//         }
//     }

//     sortByFrequency(data, validFreq, size);

//     Node* root = buildHuffmanTree(data, validFreq, size);
//     int arr[100], top = 0;
//     printCodes(root, arr, top);

//     int optimalCodeLength = calculateOptimalCodeLength(root, 0);
//     printf("%d\n", optimalCodeLength);

//     return 0;
// }

#include <stdio.h>

#define MAXSIZE 100 // 定义栈的最大容量

typedef struct
{
    int data[MAXSIZE]; // 存放栈中元素
    int top;           // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack *S)
{
    S->top = -1; // 初始化栈顶指针为-1
}

// 判断栈是否为空
int StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return 1; // 栈空
    }
    else
    {
        return 0; // 栈非空
    }
}

// 入栈
int Push(SqStack *S, int x)
{
    if (S->top == MAXSIZE - 1)
    {
        return 0; // 栈满
    }
    S->top++;
    S->data[S->top] = x;
    return 1; // 入栈成功
}

// 出栈
// 函数的返回值只能传递一个整数值（0或1），而无法直接传递出栈的元素值。
int Pop(SqStack *S, int *x)
{
    if (S->top == -1)
    {
        return 0; // 栈空
    }
    *x = S->data[S->top];
    S->top--;
    return 1; // 出栈成功
}

// 十进制转八进制并输出
void conversion()
{
    SqStack S;
    int N, e;
    InitStack(&S); // 初始化栈
    printf("请输入一个十进制数：");
    scanf("%d", &N); // 输入一个十进制数
    while (N)
    {
        Push(&S, N % 8); // 将 N 除以 8 的余数入栈
        N = N / 8;       // 更新 N 的值为 N 除以 8 的商
    }
    printf("转换为八进制数为：");
    while (!StackEmpty(S))
    {
        Pop(&S, &e); // 出栈并输出
        printf("%d", e);
    }
}
int main()
{
    conversion(); // 调用转换函数
    return 0;
}
