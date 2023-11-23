#include <iostream>
#include <string.h>
using namespace std;
class A
{
    char name[20];

public:
    void put_name(char *s) { strcpy(name, s); }
    void show_name() { cout << name << "\n"; }
};
class B : public A
{
    char phone_num[20];

public:
    void put_phone(char *num) { strcpy(phone_num, num); }
    void show_phone() { cout << phone_num << endl; }
};
int main()
{
    A *A_p;
    A A_obj;
    B B_obj;
    A_p = &A_obj;
    A_p->put_name("Wang xiao hua");
    A_p->show_name();
    A_p = &B_obj;
    A_p->put_name("Chen ming");
    A_p->show_name();
    B_obj.put_phone("5461654545132489");
    ((B *)A_p)->show_phone();

    system("pause");
    return 0;
}