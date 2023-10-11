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
int prece(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 根据先缀表达式建立树的函数
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
            node->left = nodes.top();
            nodes.pop();
            node->right = nodes.top();
            nodes.pop();
            nodes.push(node); // 如果是运算符，就弹出栈顶的两个结点，并且将其连接在运算符结点的两侧
        }
    }
    return nodes.top();
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

        if (isdigit(s[i]))
        { // 数字，直接入栈
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
            while (!ops.empty() && prece(s[i]) <= prece(ops.top()))
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
        if (isdigit(s[i]))
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

// 中序遍历函数
void inorder(TreeNode *root)
{
    if (!root)
        return;
    if (root->left)
    {
        cout << "(";
        inorder(root->left);
    }
    cout << root->val;
    if (root->right)
    {
        inorder(root->right);
        cout << ")";
    }
}

int main()
{
    string prefix = "*+123";
    TreeNode *root1 = buildTreeFromPrefix(prefix);
    inorder(root1);
    cout << endl;

    string infix = "(1+2)*3";
    TreeNode *root2 = buildTreeFromInfix(infix);
    inorder(root2);
    cout << endl;

    string postfix = "12+3*";
    TreeNode *root3 = buildTreeFromPostfix(postfix);
    inorder(root3);
    cout << endl;

    return 0;
}
