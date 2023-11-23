

#include <stdio.h>

void differentiate(int coefficients[], int exponents[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        coefficients[i] *= exponents[i]; // 求导数后的系数
        exponents[i]--;                  // 求导数后的指数

        if (coefficients[0] == 0)
        {
            printf("0 0");
        }
        // 输出导数多项式非零项的系数和指数
        else if (coefficients[i] != 0 && i != size - 1)
        {
            printf("%d %d ", coefficients[i], exponents[i]);
        }
        else if (i == size - 1 && coefficients[i] != 0)
        {
            printf("%d %d", coefficients[i], exponents[i]);
        }
    }
}

int main()
{
    int coefficients[1000], exponents[1000], inputSize = 0;
    int i = 0;

    // 读取输入多项式的系数和指数，保存到数组中
    while (1)
    {
        if (scanf("%d %d", &coefficients[i], &exponents[i]) == EOF)
            break;
        inputSize++;
        i++;
        char c;
        scanf("%c", &c);
        if (c == '\n')
            break;
    }
    differentiate(coefficients, exponents, inputSize);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// // 二叉树结点定义
// typedef struct Node {
//     char data;
//     struct Node* left;
//     struct Node* right;
// } Node;

// // 创建二叉树结点
// Node* createNode(char data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// // 创建二叉树
// Node* createBinaryTree(char** input) {
//     if (**input == '\0') return NULL;
//     if (**input == '#') {
//         (*input)++;
//         return NULL;
//     }

//     Node* root = createNode(**input);
//     (*input)++;

//     root->left = createBinaryTree(input);
//     root->right = createBinaryTree(input);

//     return root;
// }

// // 中序遍历二叉树
// void inOrderTraversal(Node* root) {
//     if (root == NULL) return;

//     inOrderTraversal(root->left);
//     printf("%c", root->data);
//     inOrderTraversal(root->right);
// }

// // 计算一度结点数量
// int countDegreeOneNodes(Node* root) {
//     if (root == NULL) return 0;

//     int count = 0;

//     if ((root->left != NULL && root->right == NULL) ||
//         (root->left == NULL && root->right != NULL)) {
//         count++;
//     }

//     count += countDegreeOneNodes(root->left);
//     count += countDegreeOneNodes(root->right);

//     return count;
// }

// int main() {
//     char input[100];
//     scanf("%s", input);

//     char* pointer = input;
//     Node* root = createBinaryTree(&pointer);

//     inOrderTraversal(root);
//     printf("\n");

//     int degreeOneCount = countDegreeOneNodes(root);
//     printf("%d\n", degreeOneCount);

//     return 0;
// }