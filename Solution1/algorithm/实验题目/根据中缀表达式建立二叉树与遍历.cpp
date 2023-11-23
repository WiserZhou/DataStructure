

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};
int findLowestPriorityOperator(string expr, int start, int end)
{
    int priority = 0;
    int lowestPriority = INT_MAX;
    int lowestPriorityPos = -1;
    for (int i = start; i <= end; i++)
    {
        if (expr[i] == '(')
        {
            priority += 2;
        }
        else if (expr[i] == ')')
        {
            priority -= 2;
        }
        else if (expr[i] == '+' || expr[i] == '-')
        {
            int currPriority = priority + 1;
            if (currPriority <= lowestPriority)
            {
                lowestPriority = currPriority;
                lowestPriorityPos = i;
            }
        }
        else if (expr[i] == '*' || expr[i] == '/')
        {
            int currPriority = priority + 2;
            if (currPriority <= lowestPriority)
            {
                lowestPriority = currPriority;
                lowestPriorityPos = i;
            }
        }
    }
    return lowestPriorityPos;
}
TreeNode *buildTree(string expr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int pos = findLowestPriorityOperator(expr, start, end);
    if (pos == -1)
    {
        for (int i = 0; i <= end - start; i++)
        {
            if (expr[start + i] != '(' && expr[start + i] != ')')
            {
                return new TreeNode(expr[start + i]);
            }
        }
    }
    TreeNode *root = new TreeNode(expr[pos]);
    root->left = buildTree(expr, start, pos - 1);
    root->right = buildTree(expr, pos + 1, end);
    return root;
}
void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val;
}
void InorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    InorderTraversal(root->left);
    cout << root->val;
    InorderTraversal(root->right);
}
int main()
{
    string expr;
    getline(cin, expr);
    TreeNode *root = buildTree(expr, 0, expr.length() - 1);
    preorderTraversal(root);
    cout << endl;
    InorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
}