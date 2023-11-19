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

// 比较运算符优先级
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 根据先缀表达式和栈逆序建立树的函数
TreeNode *buildTreeFromPrefix(string s)
{
    stack<TreeNode *> nodes;
    for (int i = s.size() - 1; i >= 0; i--) // 将先缀表达式逆序扫描，压入栈后的顺序就是正序
    {
        if (isdigit(s[i]))
        {
            nodes.push(new TreeNode(s[i])); // 如果是数字，就将其压入栈
        }
        else
        {
            TreeNode *node = new TreeNode(s[i]);
            node->left = nodes.top(); // 压入的时候是倒序，所以左子树在上面
            nodes.pop();
            node->right = nodes.top();
            nodes.pop();
            nodes.push(node); // 如果是运算符，就弹出栈顶的两个结点，并且将其连接在运算符结点的两侧
        }
    }
    return nodes.top();
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

TreeNode *buildTreeFromPrefix()
{
    char ch;
    cin >> ch; // 从输入中读取一个字符

    if (isInAlphabetSet(ch))
    {
        // 如果是字母集中的字符，建立叶子结点
        TreeNode *leaf = new TreeNode(ch);
        return leaf;
    }
    else
    {
        // 如果是运算符，则建立根结点，并递归建立左右子树
        TreeNode *root = new TreeNode(ch);
        root->left = buildTreeFromPrefix();  // 递归建立左子树
        root->right = buildTreeFromPrefix(); // 递归建立右子树
        return root;
    }
}

// 根据中缀表达式建立树的函数
TreeNode *buildTreeFromInfix(string s)
{
    stack<char> ops;
    stack<TreeNode *> nodes;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue; // 忽略空格字符

        if (isalpha(s[i]))
        { // 字母，直接入栈
            nodes.push(new TreeNode(s[i]));
        }
        else if (s[i] == '(')
        { // 左括号，直接入栈
            ops.push(s[i]);
        }
        else if (s[i] == ')')
        { // 右括号，弹出运算符号和结点建立子树
            while (ops.top() != '(')
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
            ops.pop(); // 弹出左括号
        }
        else
        { // 运算符号
            while (!ops.empty() && priority(s[i]) <= priority(ops.top()))
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
            ops.push(s[i]); // 当前运算符号入栈
        }
    }

    // 处理栈中剩余的运算符号和结点
    while (!ops.empty())
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

    return nodes.top();
}

// 根据后缀表达式建立树的函数
TreeNode *buildTreeFromPostfix(string s)
{
    stack<TreeNode *> nodes;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            nodes.push(new TreeNode(s[i]));
        }
        else
        {
            TreeNode *node = new TreeNode(s[i]);
            node->right = nodes.top();
            nodes.pop();
            node->left = nodes.top();
            nodes.pop();
            nodes.push(node);
        }
    }
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