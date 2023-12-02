#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// 结点的定义
struct Node
{
    char ch;            // 字符
    int freq;           // 频率
    Node *left, *right; // 左右子结点
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};
bool cmp(const Node *a, const Node *b)
{
    return a->freq < b->freq;
}
void getHuffmanCode(Node *root, string code, vector<pair<char, string>> &huffmanCode)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    { // 叶结点，保存编码
        huffmanCode.push_back({root->ch, code});
        return;
    }
    getHuffmanCode(root->left, code + "0", huffmanCode);
    getHuffmanCode(root->right, code + "1", huffmanCode);
}
int main()
{
    string str;
    getline(cin, str);

    // 统计频率
    map<char, int> charFreq;
    for (char c : str)
    {
        if (isalpha(c))
        {                   // 只考虑字母字符
            c = tolower(c); // 统一转换为小写字母
            ++charFreq[c];
        }
    }

    // 构造字符结点列表
    vector<Node *> nodes;
    for (const auto &p : charFreq)
    {
        Node *node = new Node(p.first, p.second);
        nodes.push_back(node);
    }
    sort(nodes.begin(), nodes.end(), cmp); // 按照频率升序排序

    // 构造最优二叉树
    while (nodes.size() > 1)
    { // 只要还有结点就合并
        Node *left = nodes.front();
        nodes.erase(nodes.begin());
        Node *right = nodes.front();
        nodes.erase(nodes.begin());

        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes.push_back(parent);
        sort(nodes.begin(), nodes.end(), cmp); // 重新排序
    }

    // 计算最佳编码
    vector<pair<char, string>> huffmanCode;
    getHuffmanCode(nodes.front(), "", huffmanCode);

    // 输出结果
    for (auto p : charFreq)
    {
        char ch = p.first;
        int freq = p.second;
        cout << ch << "(" << freq << ")";
        for (auto hc : huffmanCode)
        {
            if (hc.first == ch)
                cout << hc.second;
        }
        cout << endl;
    }

    // 计算最优码长
    int minCodeLength = 0;
    for (auto p : charFreq)
    {
        char ch = p.first;
        int freq = p.second;
        for (auto hc : huffmanCode)
        {
            if (hc.first == ch)
                minCodeLength += freq * hc.second.size();
        }
    }
    cout << minCodeLength << endl;

    // 释放内存
    for (Node *node : nodes)
    {
        delete node;
    }

    return 0;
}
