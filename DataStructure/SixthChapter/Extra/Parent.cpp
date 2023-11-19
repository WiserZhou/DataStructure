#include <iostream>
#define MAX_TREE_SIZE 100 // 树的最大节点数量

typedef struct
{
    char data;  // 节点数据
    int parent; // 双亲节点的索引
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE]; // 节点数组
    int n;                       // 当前节点数目
} PTree;

// 初始化树对象
void InitTree(PTree *tree)
{
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {
        tree->nodes[i].data = 0;    // 将节点数据初始化为0
        tree->nodes[i].parent = -1; // 将节点的双亲索引初始化为-1
    }
    tree->n = 0; // 初始化节点数量为0
}

// 添加节点到树中
void addNode(PTree *tree, char data, int parentIndex)
{
    if (tree->n >= MAX_TREE_SIZE)
    { // 如果树已满，不能再添加数据
        std::cout << "错误：树已满，不能再添加数据。\n";
        return;
    }

    PTNode newNode;
    newNode.data = data; // 设置新节点的数据

    if (parentIndex < 0)
    {
        newNode.parent = -1; // 如果双亲索引小于0，则表示没有双亲节点
    }
    else
    {
        newNode.parent = parentIndex; // 否则，将双亲索引设置为给定的索引值
    }

    tree->nodes[tree->n] = newNode; // 将新节点添加到节点数组中
    tree->n++;                      // 更新节点数量
}

// 按值查找节点
void LocateElem(const PTree *tree, char data)
{
    int i, j;
    int childCount = 0;
    int firstChildPos = -1;

    for (i = 0, j = -1; i < tree->n; i++)
    {
        if (tree->nodes[i].data == data)
        { // 如果找到匹配的节点
            std::cout << "找到结点 " << data << std::endl;
            std::cout << "当前结点信息："
                      << "位置: " << i << ", 数据: " << tree->nodes[i].data << ", 双亲位置: " << tree->nodes[i].parent << std::endl;

            j = tree->nodes[i].parent;
            if (j != -1)
            {
                std::cout << "父节点信息："
                          << "位置: " << j << ", 数据: " << tree->nodes[j].data << ", 双亲位置: " << tree->nodes[j].parent << std::endl;
            }

            for (int k = 0; k < tree->n; k++)
            {
                if (tree->nodes[k].parent == i)
                {
                    if (childCount == 0)
                    {
                        firstChildPos = k;
                    }
                    std::cout << "子节点信息："
                              << "位置: " << k << ", 数据: " << tree->nodes[k].data << ", 双亲位置: " << tree->nodes[k].parent << std::endl;
                    childCount++;
                }
            }

            if (childCount == 0)
            {
                std::cout << "该结点没有子节点" << std::endl;
            }
            else
            {
                std::cout << "子节点数量: " << childCount << std::endl;
                // std::cout << "第一个子节点信息：" << "位置: " << firstChildPos << ", 数据: " << tree->nodes[firstChildPos].data << ", 双亲位置: " << tree->nodes[firstChildPos].parent << std::endl;
            }

            return;
        }
    }

    std::cout << "未找到结点 " << data << std::endl;
}

// 获取节点的子孙节点
void GetOffspring(const PTree &tree, int index)
{
    if (index < 0 || index >= tree.n)
    { // 检查索引是否越界
        std::cout << "错误：索引越界。\n";
        return;
    }

    const PTNode &currentNode = tree.nodes[index];

    std::cout << "结点位置: " << index << ", 数据: " << currentNode.data << ", 父节点位置: " << currentNode.parent << std::endl;

    int childCount = 0;

    for (int i = 0; i < tree.n; i++)
    {
        if (tree.nodes[i].parent == index)
        { // 如果节点的双亲索引与给定索引相等，则表示是其子节点
            childCount++;
            GetOffspring(tree, i); // 递归调用以获取孩子节点的子节点
        }
    }

    if (childCount == 0)
    {
        std::cout << "该结点没有孩子结点。\n";
    }
}

// 获取节点的祖先节点
void GetAncestors(const PTree &tree, int index)
{
    if (index < 0 || index >= tree.n)
    { // 检查索引是否越界
        std::cout << "错误：索引越界。\n";
        return;
    }

    const PTNode &currentNode = tree.nodes[index];

    std::cout << "结点位置: " << index << ", 数据: " << currentNode.data << ", 父节点位置: " << currentNode.parent << std::endl;

    int parentIndex = currentNode.parent;
    if (parentIndex >= 0)
    {
        GetAncestors(tree, parentIndex); // 递归调用以获取祖先节点的祖先节点
    }
}

int main()
{
    PTree newtree;
    // 初始化树对象
    InitTree(&newtree);

    // 增加节点
    char data;
    int parentIndex;
    while (std::cout << "输入结点: " && std::cin >> data && data != '\\')
    {
        std::cout << "输入结点的双亲位置: ";
        std::cin >> parentIndex;
        addNode(&newtree, data, parentIndex);
    }

    std::cout << std::endl;

    // 输出结点
    for (int i = 0; i < newtree.n; i++)
    {
        std::cout << "结点位置: " << i << ", 数据: " << newtree.nodes[i].data << ", 父节点位置: " << newtree.nodes[i].parent << std::endl;
    }

    std::cout << std::endl;

    // 输出按值查找结点信息
    char target1;
    std::cout << "请输入要按值查找的结点: ";
    std::cin >> target1;
    LocateElem(&newtree, target1);

    std::cout << std::endl;

    // 输出子孙结点
    int targetIndex1;
    std::cout << "寻找该位序的子孙结点: ";
    std::cin >> targetIndex1;
    GetOffspring(newtree, targetIndex1);

    std::cout << std::endl;

    // 输出祖先结点
    int targetIndex2;
    std::cout << "寻找该位序的祖先结点: ";
    std::cin >> targetIndex2;
    GetAncestors(newtree, targetIndex2);

    return 0;
}