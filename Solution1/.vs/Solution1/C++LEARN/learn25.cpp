#include <iostream>
#include <ostream>
using namespace std;
class Person
{
private:  int n1;
public:
    Person(int n1){this->n1 = n1;}
    int getN1() const{return n1;}
};
class Money : public Person
{  private:  int n2;
public:
    Money(int n1, int n2) : Person(n1), n2(n2) {}
    int getN2() const{return n2;}
    friend bool operator>(const Money &m1, const Money &m2);
    friend ostream &operator<<(ostream &os, const Money &m);
};

bool operator>(const Money &m1, const Money &m2)
{
    return m1.getN1() * m1.getN2() > m2.getN1() * m2.getN2();
}

ostream &operator<<(ostream &os, const Money &m)
{
    cout << "Person:" << m.getN1() << ", Average money:" << m.getN2();
    return os;
}

int main()
{
    Money m1(7, 4), m2(9, 3);
    if (m1 > m2)cout << m1;
    else cout << m2;
    return 0;
}
