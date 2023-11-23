#include <iostream>
#include <string>
using namespace std;
class Student
{

public:
    int Getage() const { return nAge; }
    void Setage(int n) { nAge = n; }
    Student LargerAge(const Student &);

private:
    string strName;
    int nAge;
};
Student Student::LargerAge(const Student &s)
{
    if (this->Getage() >= s.Getage())
        return *this;
    else
        return s;
}
int main()
{
    Student s1,s2;
    s1.Setage(19);
    s2.Setage(20);
    Student s3=s1.LargerAge(s2);
    cout <<s3.Getage()<<endl;
    system("pause");
    return 0;
}