#include<iostream>
#include<string>
using namespace std;
class Student
{
    public:
     Student(const string& ="",const string& ="" );
     virtual void Test()=0;
     protected:
        string strNum,strName;
};
Student::Student(const string& number,const string &name)
{
    strNum=number;
    strName=name;
}
class Doctor:public Student
{
    public:
     Doctor(const string&,const string &,const string&);
     void Test()
     {
        cout <<"this is the herb"<<endl;
     }
     private:
       string strMajor;
};
Doctor::Doctor(const string& number,const string &name,const string& major):Student(number,name)
{strMajor=major;}
class MidschoolStu:public Student{
    protected:
        int nGrade;
} ;
class HighschoolStu:public MidschoolStu
{
    public :
    void Test(){cout<<"the number you have "<<endl;}
};
int main()
{
    Student* pStu=nullptr;
    Doctor ds("494668465456","Hjnid","jdfhfkgksfj hjbfsdb jjjh");
    HighschoolStu hs;
    pStu=&ds;
    pStu->Test();
    pStu=&hs;
    pStu->Test();
    system("pause");
    return 0;
}