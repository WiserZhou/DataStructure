#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class stclass
{
public:
    stclass()
    {
        cout << "stclass guozaohanshu " << endl;
    }
    ~stclass()
    {
        cout << "stclass xigouhanshu" << endl;
    }
};
class score
{
public:
    score()
    {
        cout << "score gouzaohanshu" << endl;
    }
    ~score()
    {
        cout << "score xigouhanshu" << endl;
    }
};
class student : public stclass, public score
{
public:
    student()
    {
        cout << "diaoyong student gouzaohanshu" << endl;
    }
    ~student()
    {
        cout << "diao yong student xigouhanshu " << endl;
    }
};
void call()
{
    student st1;
}
int main(){
    call();
    system("pause");
    return 0;
}
