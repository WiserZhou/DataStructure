#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char, int> inMap;
string preOrderStr, inOrderStr;
struct TNode
{
    char data;
    struct TNode *left;
    struct TNode *right;
    TNode(char c) : data(c), left(nullptr), right(nullptr) {}
};
TNode *CreateTree(int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

    TNode *root = new TNode(preOrderStr[preStart]);

    int inPosition = inMap[preOrderStr[preStart]];
    // cout << inPosition << "\n"
    int leftSize = inPosition - inStart;
    int rightSize = inEnd - inPosition;

    root->left = CreateTree(preStart + 1, preStart + leftSize, inStart, inPosition - 1);
    root->right = CreateTree(preStart + leftSize + 1, preEnd, inPosition + 1, inEnd);
    return root;
}
int calculate(TNode *T, int &count)
{
    if (T)
    {
        if (T->left == nullptr && T->right == nullptr)
            ++count;
        int depthLeft = calculate(T->left, count) + 1;
        int depthRight = calculate(T->right, count) + 1;
        return max(depthLeft, depthRight);
    }
    else
        return 0;
}
int main()
{

    cin >> preOrderStr >> inOrderStr;

    for (int i = 0; i < inOrderStr.size(); i++)
    {
        inMap[inOrderStr[i]] = i;
    }
    TNode *T = CreateTree(0, preOrderStr.size() - 1, 0, inOrderStr.size() - 1);
    int depth, count = 0;
    depth = calculate(T, count);
    cout << depth << "\n"
         << count << "\n";
    return 0;
}