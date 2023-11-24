// #include "TreeStructure.h"
// #include <stack>
// #include <iostream>
// #include <vector>

// void AllPath(TreeNode *T, std::stack<int> &S)
// {
//     if (T)
//     {
//         // 将当前节点的数据压入栈
//         S.push(T->data);

//         // 如果是叶子结点，打印栈的内容
//         if (!T->lchild && !T->rchild)
//         {
//             // 将栈中的元素放入临时容器（vector）中
//             std::vector<int> tempVector;
//             while (!S.empty())
//             {
//                 tempVector.push_back(S.top());
//                 S.pop();
//             }

//             // 逆序输出元素，以恢复栈的原始顺序
//             for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it)
//             {
//                 std::cout << *it << " ";
//                 S.push(*it); // 恢复栈的原始顺序
//             }
//             std::cout << std::endl;
//         }
//         else
//         {
//             // 递归处理左子树和右子树
//             AllPath(T->lchild, S);
//             AllPath(T->rchild, S);
//         }

//         // 无论是叶子结点还是非叶子结点，结束后都要弹出栈顶元素
//         S.pop();
//     }
// }

// int main()
// {

//     BiTree t6 = new BiTNode(6);
//     BiTree t5 = new BiTNode(5, nullptr, t6);
//     BiTree t4 = new BiTNode(4);
//     BiTree t3 = new BiTNode(3, t5, nullptr);
//     BiTree t2 = new BiTNode(2, t4, nullptr);
//     BiTree t1 = new BiTNode(1, t2, t3);

//     std::stack<int> S;
//     AllPath(t1, S);
// }

#include <iostream>
#include <stack>
#include <vector>
typedef struct BiTreeNode
{
    int data;
    struct BiTreeNode *firstchild, *nextsibling;
} BiTreeNode, *Bitree;
void PrintPath(std::stack<int> S)
{
    // 将栈中的元素放入临时容器（vector）中
    std::vector<int> tempVector;
    while (!S.empty())
    {
        tempVector.push_back(S.top());
        S.pop();
    }

    // 逆序输出元素，以恢复栈的原始顺序
    for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void OutPath(Bitree T, std::stack<int> &S)
{
    // 输出森林中所有从根到叶的路径
    while (T)
    {
        S.push(T->data);

        if (!T->firstchild)
            PrintPath(S);
        else
            OutPath(T->firstchild, S);

        S.pop();
        T = T->nextsibling; // 往右走前要出栈，因为右链域是兄弟
    }
}

Bitree createNode(int data)
{
    Bitree newNode = new BiTreeNode;
    newNode->data = data;
    newNode->firstchild = nullptr;
    newNode->nextsibling = nullptr;
    return newNode;
}

Bitree initializeTree()
{
    // Creating nodes for the tree
    Bitree root = createNode(1);
    Bitree child1 = createNode(2);
    Bitree child2 = createNode(3);
    Bitree child3 = createNode(4);
    Bitree child4 = createNode(5);

    // Building the tree structure
    root->firstchild = child1;
    child1->nextsibling = child2;
    child2->nextsibling = child3;
    child3->nextsibling = child4;

    return root;
}

int main()
{
    // Example usage:
    std::stack<int> myStack;
    Bitree myTree = initializeTree();

    OutPath(myTree, myStack);

    return 0;
}
