#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// ���Ķ���
struct Node
{
    char ch;            // �ַ�
    int freq;           // Ƶ��
    Node *left, *right; // �����ӽ��
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
    { // Ҷ��㣬�������
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

    // ͳ��Ƶ��
    map<char, int> charFreq;
    for (char c : str)
    {
        if (isalpha(c))
        { // ֻ������ĸ�ַ�
            // c = tolower(c); // ͳһת��ΪСд��ĸ
            ++charFreq[c];
        }
    }

    // �����ַ�����б�
    vector<Node *> nodes;
    for (const auto &p : charFreq)
    {
        Node *node = new Node(p.first, p.second);
        nodes.push_back(node);
    }
    sort(nodes.begin(), nodes.end(), cmp); // ����Ƶ����������

    // �������Ŷ�����
    while (nodes.size() > 1)
    { // ֻҪ���н��ͺϲ�
        Node *left = nodes.front();
        nodes.erase(nodes.begin());
        Node *right = nodes.front();
        nodes.erase(nodes.begin());

        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes.push_back(parent);
        sort(nodes.begin(), nodes.end(), cmp); // ��������
    }

    // ������ѱ���
    vector<pair<char, string>> huffmanCode;
    getHuffmanCode(nodes.front(), "", huffmanCode);

    // ������
    int minCodeLength = 0;
    for (auto p : charFreq)
    {
        char ch = p.first;
        int freq = p.second;
        cout << ch << "(" << freq << ")";
        for (auto hc : huffmanCode)
        {
            if (hc.first == ch)
            {
                cout << hc.second;
                minCodeLength += freq * hc.second.size();
            }
        }
        cout << endl;
    }
    cout << minCodeLength << endl;
    // ���������볤

    // �ͷ��ڴ�
    for (Node *node : nodes)
    {
        delete node;
    }

    return 0;
}