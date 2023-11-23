

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     char data;
//     int ltag, rtag;
//     struct Node *left;
//     struct Node *right;
// };

// struct Node *createBinaryTree(char *str, int *index)
// {
//     if (str[*index] == '#')
//     {
//         (*index)++;
//         return NULL;
//     }
//     struct Node *root = (struct Node *)malloc(sizeof(struct Node));
//     root->data = str[*index];
//     root->rtag = 0;
//     root->ltag = 0;
//     (*index)++;
//     root->left = createBinaryTree(str, index);
//     root->right = createBinaryTree(str, index);
//     return root;
// }
// void inorderTraversal1(struct Node *root)
// {
//     if (root)
//     {
//         struct Node *current = root;
//         while (current->ltag == 0)
//         {
//             current = current->left;
//         }
//         while (current)
//         {
//             printf("%c", current->data);
//             if (current->rtag == 1)
//             {
//                 current = current->right;
//             }
//             else
//             {
//                 current = current->right;
//                 while (current && current->ltag == 0)
//                 {
//                     current = current->left;
//                 }
//             }
//         }
//     }
// }

// void createThreaded(struct Node *root)
// {
//     if (root)
//     {
//         static struct Node *prev = NULL;
//         createThreaded(root->left);

//         if (root->left == NULL)
//         {
//             root->left = prev;
//             root->ltag = 1;
//         }

//         if (prev != NULL && prev->right == NULL)
//         {
//             prev->right = root;
//             prev->rtag = 1;
//         }

//         prev = root;
//         createThreaded(root->right);
//     }
// }

// void inorderTraversal(struct Node *root)
// {
//     if (root)
//     {
//         inorderTraversal(root->left);
//         printf("%c", root->data);
//         inorderTraversal(root->right);
//     }
// }

// int countSingleDegreeNodes(struct Node *root)
// {
//     if (!root || (!root->ltag && !root->rtag))
//     {
//         return 0;
//     }
//     int count = 0;
//     if (((root->ltag) && (!root->rtag)) || ((!root->ltag) && (root->rtag)))
//     {
//         count = 1;
//     }
//     return count + countSingleDegreeNodes(root->ltag) + countSingleDegreeNodes(root->rtag);
// }

// int main()
// {
//     char input[100];
//     scanf("%s", input);
//     int index = 0;
//     struct Node *root = createBinaryTree(input, &index);
//     inorderTraversal1(root);
//     inorderTraversal(root);
//     printf("\n");
//     int singleDegreeNodes = countSingleDegreeNodes(root);
//     printf("%d\n", singleDegreeNodes);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    int ltag,rtag;
    struct Node *left;
    struct Node *right;
};

struct Node *createBinaryTree(char *str, int *index)
{
    if (str[*index] == '#')
    {
        (*index)++;
        return NULL;
    }
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = str[*index];
    (*index)++;
    root->left = createBinaryTree(str, index);
    root->right = createBinaryTree(str, index);
    return root;
}

void inorderTraversal(struct Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("%c", root->data);
        inorderTraversal(root->right);
    }
}

int countSingleDegreeNodes(struct Node *root)
{
    if (!root || (!root->ltag && !root->rtag))
    {
        return 0;
    }
    int count = 0;
    if (((root->ltag) && (!root->rtag)) || ((!root->ltag) && (root->rtag)))
    {
        count = 1;
    }
    return count + countSingleDegreeNodes(root->ltag) + countSingleDegreeNodes(root->rtag);
}
void createThreaded(struct Node *root){
    static struct Node *pre=NULL;
    if(root==NULL)return ;
    createThreaded(root->left);
    if(root->left==NULL){
        root->left=pre;
        root->ltag=1;
    }
    if (pre!=NULL&&pre->right==NULL)
    {
        pre->right=root;
        pre->right=1;
    }
    pre=root;
    createThreaded(root->right);
}
int main()
{
    char input[100];
    scanf("%s", input);
    int index = 0;
    struct Node *root = createBinaryTree(input, &index);
    inorderTraversal(root);
    printf("\n");
    createThreaded(root);
    int singleDegreeNodes = countSingleDegreeNodes(root);
    printf("%d\n", singleDegreeNodes);
    return 0;
}