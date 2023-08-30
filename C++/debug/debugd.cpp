#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int n;
class Student
{
    string ID;
    double Score;

public:
    string getID() const
    {
        return ID;
    }
    void setID(string ID)
    {
        this->ID = ID;
    }
    void setScore(double Score)
    {
        this->Score = Score;
    }
    double getScore() const
    {
        return Score;
    }
    Student() {}
    vector<Student> stu;
    Student(int N)
    {
        string x;
        double y;

        for (int i = 0; i < N; i++)
        {
            Student k;
        back:
            cin >> x;
            k.setID(x);
            cin >> y;
            if (y <= 80)
            {
                n--;
                N--;
                goto back;
            }
            k.setScore(y);
            stu.push_back(k);
        }
    }
    ~Student()
    {
        stu.clear();
    }
};
int main()
{
    srand(time(0));
    cin >> n;
    Student student(n);
    int x = rand() % n;
    cout << "ID:" << student.stu[x].getID() << " ?score:" << student.stu[x].getScore() << "\n";
    return 0;
}