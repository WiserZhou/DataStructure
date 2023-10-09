#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
// 先序遍历的递归算法
void PreOrderTraversalRecursion(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";               // 访问根节点
    PreOrderTraversalRecursion(root->left);  // 遍历左子树
    PreOrderTraversalRecursion(root->right); // 遍历右子树
}

// 中序遍历的递归算法
void InOrderTraversalRecursion(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    InOrderTraversalRecursion(root->left);  // 遍历左子树
    cout << root->data << " ";              // 访问根节点
    InOrderTraversalRecursion(root->right); // 遍历右子树
}

// 后序遍历的递归算法
void PostOrderTraversalRecursion(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    PostOrderTraversalRecursion(root->left);  // 遍历左子树
    PostOrderTraversalRecursion(root->right); // 遍历右子树
    cout << root->data << " ";                // 访问根节点
}
// 先序遍历的非递归算法
void PreOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st; // 创建一个栈
    TreeNode *node = root;

    while (node != nullptr || !st.empty()) // 当前指针指向非空表示此段直接遍历未结束，栈非空表示遍历未终止
    {
        while (node != nullptr)
        {
            cout << node->data << " "; // 访问根节点
            st.push(node);             // 将根节点压入栈
            node = node->left;         // 移动到左子树
        }

        if (!st.empty())
        {
            node = st.top(); // 弹出栈顶节点并访问其右子树
            st.pop();
            node = node->right; // 移动到右子树
        }
    }
}

// 中序遍历的非递归算法
void InOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st; // 创建一个栈
    TreeNode *node = root;

    while (node != nullptr || !st.empty())
    {
        while (node != nullptr)
        {
            st.push(node);     // 将节点压入栈
            node = node->left; // 移动到左子树
        }

        if (!st.empty())
        {
            node = st.top(); // 弹出栈顶节点并访问
            st.pop();
            cout << node->data << " "; // 访问根节点
            node = node->right;        // 移动到右子树
        }
    }
}

// 后序遍历的非递归算法
void PostOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st; // 创建一个栈
    TreeNode *node = root;
    TreeNode *lastVisited = nullptr; // 上次访问的节点

    while (node != nullptr || !st.empty()) // 为了全部将所有的左子树全部遍历，防止出现遗漏
    {
        while (node != nullptr)
        {
            st.push(node);     // 将节点压入栈
            node = node->left; // 移动到左子树
        }

        node = st.top(); // 查看栈顶节点

        if (node->right == nullptr || node->right == lastVisited) // 只有右边没有或者右边已经遍历完成后，再进行遍历中结点
        {
            st.pop();                  // 弹出栈顶节点并访问
            cout << node->data << " "; // 访问根节点
            lastVisited = node;
            node = nullptr; // 回退到上一级节点
        }
        else
        {
            node = node->right; // 移动到右子树
        }
    }
}

int main()
{
    // 创建一个二叉树
    TreeNode *root = new TreeNode();
    root->data = 1;

    TreeNode *node2 = new TreeNode();
    node2->data = 2;

    TreeNode *node3 = new TreeNode();
    node3->data = 3;

    TreeNode *node4 = new TreeNode();
    node4->data = 4;

    TreeNode *node5 = new TreeNode();
    node5->data = 5;

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;

    // 先序遍历
    cout << "PreOrder traversal: ";
    PreOrderTraversal(root);
    cout << endl;

    // 中序遍历
    cout << "InOrder traversal: ";
    InOrderTraversal(root);
    cout << endl;

    // 后序遍历
    cout << "PostOrder traversal: ";
    PostOrderTraversal(root);
    cout << endl;

    return 0;
}
