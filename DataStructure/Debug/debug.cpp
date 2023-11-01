#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_DISTANCE = 0;
vector<char> VexVector;
int getIndex(char a)
{
    auto it = find(VexVector.begin(), VexVector.end(), a);
    return distance(VexVector.begin(), it);
}
char getAlpha(int x)
{
    return VexVector[x];
}
void setValue(vector<vector<int>> &matrix, char a, char b)
{
    int x = getIndex(a);
    int y = getIndex(b);
    matrix[x][y] = 1;
}
void DFS(vector<vector<int>> matrix, char start)
{
    stack<int> vexGraph;
    vector<bool> visited(VexVector.size(), false);
    int startIndex = getIndex(start);

    // cout << start;
    // visited[startIndex] = true;

    vexGraph.push(startIndex);

    while (!vexGraph.empty())
    {
        int index = vexGraph.top();
        vexGraph.pop();
        if (visited[index])
            break;
        cout << getAlpha(index);
        visited[index] = true;

        for (int pointer = VexVector.size() - 1; pointer >= 0; pointer--)
        {

            if (!visited[pointer] && matrix[index][pointer] == 1)
            {
                // cout << getAlpha(pointer);
                vexGraph.push(pointer);
            }
            // cout << "}}}}";
        }
    }
}
void DFS_A(vector<vector<int>> matrix, char start)
{
    stack<int> vexGraph;
    vector<bool> visited(VexVector.size(), false);
    int startIndex = getIndex(start);

    // cout << start;
    // visited[startIndex] = true;

    vexGraph.push(startIndex);

    while (!vexGraph.empty())
    {
        int index = vexGraph.top();
        vexGraph.pop();
        if (visited[index])
            break;
        cout << getAlpha(index);
        visited[index] = true;

        for (int pointer = VexVector.size() - 1; pointer >= 0; pointer--)
        {
            bool flag = false;
            if (!visited[pointer] && matrix[index][pointer] == 1)
            {
                // cout << getAlpha(pointer);
                flag = true;
                vexGraph.push(pointer);
            }
            // cout << "}}}}";
            if (flag == false)
            {
                if (!visited[pointer] && ((matrix[index][pointer] == 1) || (matrix[pointer][index] == 1)))
                {
                    // cout << getAlpha(pointer);
                    flag = true;
                    vexGraph.push(pointer);
                }
            }
        }
    }
}
int main()
{
    int attribute, vex, arc;
    cin >> attribute >> vex >> arc;

    for (int i = 0; i < vex; i++)
    {
        char ch;
        cin >> ch;
        VexVector.push_back(ch);
    }
    vector<vector<int>> matrix(vex, vector<int>(vex, MAX_DISTANCE));

    for (int i = 0; i < arc; i++)
    {
        char a, b;
        cin >> a >> b;
        if (attribute == 1 || attribute == 3)
        {
            int x;
            cin >> x;
        }
        setValue(matrix, a, b);
        if (attribute >= 2)
            setValue(matrix, b, a);
    }

    char start;
    cin >> start;
    if (attribute >= 2)
        DFS(matrix, start);
    else
        DFS_A(matrix, start);
    // cout << matrix[getIndex('C')][getIndex('D')];
    return 0;
}