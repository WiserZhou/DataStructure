#include <iostream>
#include <stack>
using namespace std;

// 树结点定义
struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

// 根据先缀表达式和栈逆序建立树的函数
//*先缀表达式建树从后往前使用栈，后缀表达式建树从前往后使用栈
TreeNode *buildTreeFromPrefixReverse(string s)
{
    stack<TreeNode *> nodes;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            nodes.push(new TreeNode(s[i]));
        }
        else
        {
            TreeNode *node = new TreeNode(s[i]);

            TreeNode *left = nodes.top(); // 保存左子树
            nodes.pop();

            TreeNode *right = nodes.top(); // 保存右子树
            nodes.pop();

            node->left = left;
            node->right = right;

            nodes.push(node);
        }
    }
    return nodes.top();
}
// 根据后缀表达式建树
TreeNode *buildExpressionTree(const std::string &expression)
{
    std::stack<TreeNode *> nodeStack;

    for (char currentChar : expression)
    {
        if (isdigit(currentChar) || isalpha(currentChar))
        {
            nodeStack.push(new TreeNode(currentChar));
        }
        else
        {
            TreeNode *newNode = new TreeNode(currentChar);
            newNode->right = nodeStack.top();
            nodeStack.pop();
            newNode->left = nodeStack.top();
            nodeStack.pop();
            nodeStack.push(newNode);
        }
    }

    if (!nodeStack.empty())
    {
        TreeNode *root = nodeStack.top();
        nodeStack.pop();
        return root;
    }

    return nullptr;
}
// 根据先缀表达式正序建立二叉树
bool isInAlphabetSet(char ch)
{
    if (isdigit(ch))
        return true;
    else
        return false;
    // 假设这里是字母集检查的函数实现
    // 返回值为字符是否属于字母集
}

TreeNode *buildTreeFromPrefixRecursive(string s, int &index)
{
    if (index >= s.length())
        return nullptr; // Invalid index, return null

    char currentChar = s[index++];

    if (isInAlphabetSet(currentChar))
    {
        // If it is a character in the alphabet set, create a leaf node
        TreeNode *leaf = new TreeNode(currentChar);
        return leaf;
    }
    else
    {
        // If it is an operator, create a root node and recursively build left and right subtrees
        TreeNode *node = new TreeNode(currentChar);
        node->left = buildTreeFromPrefixRecursive(s, index);  // Recursively build the left subtree
        node->right = buildTreeFromPrefixRecursive(s, index); // Recursively build the right subtree
        return node;
    }
}

TreeNode *buildTreeFromPrefix(string s)
{
    int index = 0; // Start from the beginning of the string
    return buildTreeFromPrefixRecursive(s, index);
}

TreeNode *buildTreeFromPostfixRecursive(string s, int &index)
{
    if (index < 0)
        return nullptr; // Invalid index, return null

    char currentChar = s[index--];

    if (isInAlphabetSet(currentChar))
    {
        // If it is a character in the alphabet set, create a leaf node
        TreeNode *leaf = new TreeNode(currentChar);
        return leaf;
    }
    else
    {
        // If it is an operator, create a root node and recursively build left and right subtrees
        TreeNode *node = new TreeNode(currentChar);
        node->right = buildTreeFromPostfixRecursive(s, index); // Recursively build the right subtree
        node->left = buildTreeFromPostfixRecursive(s, index);  // Recursively build the left subtree
        return node;
    }
}

TreeNode *buildTreeFromPostfix(string s)
{
    int index = s.length() - 1; // Start from the beginning of the string
    return buildTreeFromPostfixRecursive(s, index);
}

TreeNode *buildTreeFromInfixRecursive(string s, int &index)
{
    if (index < 0 || index >= s.size())
    {
        return nullptr; // Invalid index, return null
    }

    char currentChar = s[index];
    index--;

    if (isInAlphabetSet(currentChar))
    {
        // If it is a character in the alphabet set, create a leaf node
        TreeNode *leaf = new TreeNode(currentChar);
        return leaf;
    }
    else if (currentChar == ')')
    {
        // Skip ')' and recursively build the subtree within parentheses
        TreeNode *subtree = buildTreeFromInfixRecursive(s, index);
        // Skip '('
        index--;
        return subtree;
    }
    else
    {
        // If it is an operator, create a root node and recursively build right and left subtrees
        TreeNode *node = new TreeNode(currentChar);
        node->right = buildTreeFromInfixRecursive(s, index); // Recursively build the right subtree
        node->left = buildTreeFromInfixRecursive(s, index);  // Recursively build the left subtree
        return node;
    }
}

TreeNode *buildTreeFromInfix(string s)
{
    int index = s.size() - 1; // Start from the end of the string
    return buildTreeFromInfixRecursive(s, index);
}

// 根据中缀表达式建立树的函数
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void processOperator(stack<char> &ops, stack<TreeNode *> &nodes)
{
    char op = ops.top();
    ops.pop();
    TreeNode *right = nodes.top();
    nodes.pop();
    TreeNode *left = nodes.top();
    nodes.pop();

    TreeNode *node = new TreeNode(op);
    node->left = left;
    node->right = right;
    nodes.push(node);
}
TreeNode *buildTreeFromInfixByUser(string s)
{
    stack<char> ops;
    stack<TreeNode *> nodes;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;

        if (isalpha(s[i]))
            nodes.push(new TreeNode(s[i]));
        else if (s[i] == '(')
            ops.push(s[i]);
        else if (s[i] == ')')
        {
            while (ops.top() != '(')
                processOperator(ops, nodes);
            ops.pop(); // 弹出左括号
        }
        else
        { // 运算符号
            while (!ops.empty() && priority(s[i]) <= priority(ops.top()))
                processOperator(ops, nodes);
            ops.push(s[i]); // 当前运算符号入栈
        }
    }

    while (!ops.empty())
        processOperator(ops, nodes);

    return nodes.top();
}

// 递归创建二叉树的函数，不包含括号
TreeNode *buildTree(string s, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(s[mid]);

    root->left = buildTree(s, start, mid - 1);
    root->right = buildTree(s, mid + 1, end);

    return root;
}
/**
 * 根据先缀表达式和中缀表达式建树
 */
typedef TreeNode *BiTree;

int Search(char arr[], char key, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1; // Key not found
}

// ps表示当前先序遍历序列的起始索引
// is表示当前中序遍历序列的起始索引
// n表示当前子树的节点数量
void CrtBT(BiTree &T, char pre[], char ino[], int ps, int is, int n)
{
    // 已知pre[ps..ps+n-1]为二叉树的先序序列，
    // ino[is..is+n-1]为二叉树的中序序列，本算
    // 法由此两个序列构造二叉链表
    if (n == 0)
        T = nullptr;
    else
    {
        int k = Search(ino, pre[ps], is, is + n - 1); // k是在中缀表达式中寻找当前位置的先缀表达式字符的位置
        if (k == -1)
            T = nullptr;
        else
        {
            T = new TreeNode(pre[ps]);
            if (k == is) // 如果k的位置就是中缀表达式开始的位置，那么说明他的左边也就是左子树是空的
                T->left = nullptr;
            else
                CrtBT(T->left, pre, ino, ps + 1, is, k - is); // 现在左边的结点的个数是中缀表达式左边的个数，也就是先缀表达式直接往后数，中缀表达式左边的
            if (k == is + n - 1)                              // 如果k的位置就是中缀表达式的最后一个位置，说明他的右边没有结点，也就是右子树是空的
                T->right = nullptr;
            else
                CrtBT(T->right, pre, ino, ps + 1 + (k - is), k + 1, n - (k - is) - 1); // k-is是左子树的结点的个数，先缀表达式从ps+k-is+1开始，
                                                                                       // 中缀表达式从k+1开始，个数就是总个数减去左边的个数，再减去中间的节点
        }
    }
}
