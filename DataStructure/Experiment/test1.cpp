#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Student
{
public:
    string ID;
    string name;
    int score;

    Student(string id, string n, int s) : ID(id), name(n), score(s) {}

    bool cmpByID(const Student &other) const
    {
        return ID < other.ID;
    }

    bool cmpByName(const Student &other) const
    {
        return name <= other.name;
    }

    bool cmpByScore(const Student &other) const
    {
        return score <= other.score;
    }

    static Student readStudentInfo()
    {
        string id, n;
        int s;
        cin >> id >> n >> s;
        return Student(id, n, s);
    }

    void printStudentInfo() const
    {
        cout << ID << " " << name << " " << score << endl;
    }
};

// Function to sort student information
void sortStudentInfo(vector<Student> &students, int C)
{
    auto cmpFunction = [&](const Student &a, const Student &b)
    {
        if (C == 1)
            return a.cmpByID(b);
        else if (C == 2)
            return a.cmpByName(b);
        else
            return a.cmpByScore(b);
    };

    sort(students.begin(), students.end(), cmpFunction);
}

// Function to print student information
void printStudentInfo(const vector<Student> &students)
{
    for (const auto &student : students)
    {
        student.printStudentInfo();
    }
}

int main()
{
    int N, C;
    cin >> N >> C;

    // Use vector to store student information
    vector<Student> students;

    // Use emplace_back to add elements directly to the vector
    for (int i = 0; i < N; i++)
    {
        students.emplace_back(Student::readStudentInfo());
    }

    // Call the sorting function
    sortStudentInfo(students, C);

    // Call the printing function
    printStudentInfo(students);

    return 0;
}
