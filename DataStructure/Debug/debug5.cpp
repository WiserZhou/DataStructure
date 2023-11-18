#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Student
{

public:
    string ID;
    string name;
    int score;
};
bool cmpByName(Student student1, Student student2)
{
    return student1.name <= student2.name;
}
bool cmpByID(Student student1, Student student2)
{
    return student1.ID < student2.ID;
}
bool cmpByScore(Student student1, Student student2)
{
    return student1.score <= student2.score;
}
int main()
{
    int N, C;
    cin >> N >> C;
    Student student[N];
    for (int i = 0; i < N; i++)
    {
        cin >> student[i].ID;
        cin >> student[i].name;
        cin >> student[i].score;
    }
    bool (*f)(Student student1, Student student2);
    if (C == 1)
        f = cmpByID;
    else if (C == 2)
        f = cmpByName;
    else if (C == 3)
        f = cmpByScore;

    sort(student, student + N, f);
    for (int i = 0; i < N; i++)
    {
        cout << student[i].ID << " " << student[i].name << " " << student[i].score << endl;
    }
    return 0;
}
