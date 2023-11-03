#include <bits/stdc++.h>
using namespace std;

// 定义平衡二叉树的结构
struct node
{
    int data;    // 结点数据
    int height;  // 结点高度
    node *left;  // 左子树结点指针
    node *right; // 右子树结点指针
};

// 计算结点高度
int height(node *n)
{
    if (n == NULL)
        return 0; // 空节点高度为0
    return n->height;
}

// 计算平衡因子
int balanceFactor(node *n)
{
    if (n == NULL)
        return 0;                              // 空节点平衡因子为0
    return height(n->left) - height(n->right); // 计算左右子树高度差
}

// 创建新结点
node *createNode(int data)
{
    node *newNode = new node(); // 新建一个节点
    newNode->data = data;       // 设定节点数据
    newNode->height = 1;        // 高度初始化为1
    newNode->left = NULL;       // 左右子树指针初始化为空
    newNode->right = NULL;
    return newNode; // 返回新节点
}

// 右旋操作
node *rightRotate(node *y)
{
    node *x = y->left;   // 记录左子树
    node *T2 = x->right; // 记录左子树的右子树

    // 进行旋转，将x作为新的根节点，y作为其右子树
    x->right = y;
    y->left = T2;

    // 更新高度，先更新y的高度再更新x的高度
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // 返回新的根节点
    return x;
}

// 左旋操作
node *leftRotate(node *x)
{
    node *y = x->right; // 记录右子树
    node *T2 = y->left; // 记录右子树的左子树

    // 进行旋转，将y作为新的根节点，x作为其左子树
    y->left = x;
    x->right = T2;

    // 更新高度，先更新x的高度再更新y的高度
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // 返回新的根节点
    return y;
}

// 插入结点操作
node *insertNode(node *root, int data)
{
    // 执行二叉搜索树的插入操作
    if (root == NULL)
        return createNode(data); // 如果根节点为空，返回一个新节点
    if (data < root->data)
        root->left = insertNode(root->left, data); // 插入左子树
    else if (data > root->data)
        root->right = insertNode(root->right, data); // 插入右子树
    else
        return root; // 如果数据已经存在于树中，则返回根节点

    // 更新结点高度
    root->height = max(height(root->left), height(root->right)) + 1;

    // 计算平衡因子
    int balance = balanceFactor(root);

    // 左左情况，需要进行右旋操作
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // 右右情况，需要进行左旋操作
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // 左右情况，需要先进行左旋再进行右旋
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 右左情况，需要先进行右旋再进行左旋
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // 返回平衡后的根节点
    return root;
}

// 找到最小结点
node *findMin(node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// 删除结点操作
node *deleteNode(node *root, int data)
{
    // 执行二叉搜索树的删除操作
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data); // 在左子树中删除
    else if (data > root->data)
        root->right = deleteNode(root->right, data); // 在右子树中删除
    else
    {
        // 结点只有一个子树或者没有子树
        if ((root->left == NULL) || (root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            // 结点有两个子树，找到右子树中的最小结点
            node *temp = findMin(root->right);

            // 将该结点的值赋给当前结点
            root->data = temp->data;

            // 删除右子树中的最小结点
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // 更新结点高度
    root->height = max(height(root->left), height(root->right)) + 1;

    // 计算平衡因子
    int balance = balanceFactor(root);

    // 左左情况，需要进行右旋操作
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // 右右情况，需要进行左旋操作
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // 左右情况，需要先进行左旋再进行右旋
    if (balance > 1 && balanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 右左情况，需要先进行右旋再进行左旋
    if (balance < -1 && balanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // 返回平衡后的根节点
    return root;
}

// 中序遍历平衡二叉树
void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);  // 遍历左子树
    cout << root->data << " ";     // 输出当前节点
    inOrderTraversal(root->right); // 遍历右子树
}

int main()
{
    node *root = NULL; // 根节点初始化为空
    int n, x;
    cin >> n;

    // 插入结点
    for (int i = 0; i < n; i++)
    {
        cin >> x;                   // 输入数据
        root = insertNode(root, x); // 插入到平衡二叉树中
    }

    // 删除结点
    cout << "Enter the element to be deleted: ";
    cin >> x;
    root = deleteNode(root, x); // 从平衡二叉树中删除

    // 中序遍历平衡二叉树
    cout << "InOrder traversal of the AVL tree is: ";
    inOrderTraversal(root);

    return 0;
}
