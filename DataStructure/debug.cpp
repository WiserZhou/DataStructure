#include <iostream>
#include <vector>
using namespace std;
const int MAX_DISTANCE = 1000;

int main()
{
    int attribute, vex, arc;
    cin >> attribute >> vex >> arc;
    vector<char> VexVector;
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
        
    }
}