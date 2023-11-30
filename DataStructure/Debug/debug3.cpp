#include <iostream>
#include <cctype>

class TreeNode
{
public:
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

class ExpressionTreeBuilder
{
public:
    TreeNode *buildExpressionTree(const std::string &expression, int &index)
    {
        if (index < 0)
            return nullptr;

        char currentChar = expression[index--];

        if (currentChar == '(')
        {
            TreeNode *subExpressionRoot = buildExpressionTree(expression, index);
            index--; // Skip the ')'
            return subExpressionRoot;
        }
        else if (isdigit(currentChar) || isalpha(currentChar))
        {
            return new TreeNode(currentChar);
        }
        else
        {
            TreeNode *newNode = new TreeNode(currentChar);
            newNode->right = buildExpressionTree(expression, index);
            newNode->left = buildExpressionTree(expression, index);
            return newNode;
        }
    }
    void inorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            inorderTraversal(root->left);
            std::cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void postorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            std::cout << root->data << " ";
        }
    }

    ~ExpressionTreeBuilder()
    {
        // Implement destruction of the tree nodes
    }
};

int main()
{
    std::string expression = "A+(B*C)-(D/E)";
    int index = expression.length() - 1;

    ExpressionTreeBuilder treeBuilder;
    TreeNode *root = treeBuilder.buildExpressionTree(expression, index);

    std::cout << "Inorder traversal: ";
    treeBuilder.inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    treeBuilder.postorderTraversal(root);
    std::cout << std::endl;

    // Implement deletion of tree nodes

    return 0;
}
