#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
struct Node
{
    char ch;            // 字符
    int freq;           // 频率
    Node *left, *right; // 左右子结点
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};
int main()
{
    string str;
    unordered_map<char, int> alphaSet;
    getline(cin, str);
    for (char c : str)
    {
        if (isalpha(c))
        {
            ++alphaSet[c];
        }
    }
    
}