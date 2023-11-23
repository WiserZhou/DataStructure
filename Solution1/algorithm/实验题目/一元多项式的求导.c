

#include <stdio.h>

void differentiate(int coefficients[], int exponents[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        coefficients[i] *= exponents[i]; // �������ϵ��
        exponents[i]--;                  // �������ָ��

        if (coefficients[0] == 0)
        {
            printf("0 0");
        }
        // �����������ʽ�������ϵ����ָ��
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

    // ��ȡ�������ʽ��ϵ����ָ�������浽������
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

// // ��������㶨��
// typedef struct Node {
//     char data;
//     struct Node* left;
//     struct Node* right;
// } Node;

// // �������������
// Node* createNode(char data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// // ����������
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

// // �������������
// void inOrderTraversal(Node* root) {
//     if (root == NULL) return;

//     inOrderTraversal(root->left);
//     printf("%c", root->data);
//     inOrderTraversal(root->right);
// }

// // ����һ�Ƚ������
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