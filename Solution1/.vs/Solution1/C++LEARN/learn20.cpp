#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
#define N 5
#define random(x) rand() % (x)
class student
{
private:
    int id;
    int score;

public:
    student();
    student(int, int);
    friend void input(student *);
    friend void output(student *p);
};
student::student(){};
student::student(int id_, int score_)
{
    id = id_;
    score = score_;
}
void input(student *p)
{
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].id >> p[i].score;
    }
}
void output(student *p)
{
    int i;
    srand((int)time(NULL));
    while (1)
    {
        i = random(N);
        if (p[i].score > 80)
        {
            cout << p[i].id << "  " << p[i].score << endl;
            cout << i;
            break;
        }
    }
}
int main()
{
    student stu[N];
    input(stu);
    output(stu);
    system("pause");
    return 0;
}