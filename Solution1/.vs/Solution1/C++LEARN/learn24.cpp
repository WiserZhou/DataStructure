#include <iostream>
using namespace std;
class Person
{
protected:  int n1;// number of the people
public:  //Person() : n1(0) {}
};
class Money : public Person
{   int n2;// average money of each person
public:
   void set(int n1, int n2){this->n1 = n1;this->n2 = n2;}
   int get() const{return this->n1 * this->n2;}
   //Money() : n2(0) {}
   bool operator>(const Money &a)// 对>运算符进行重载
   {
      return get() > a.get();
   }
   friend void operator<<(ostream &os, const Money &m)//对<<运算符重载，
   {
      cout << "人数为: " << m.n1 << " , 奖金平均数为:" << m.n2 << endl;
   }
};
int main()
{
   Money a, b;
   int x, y;
   cin >> x >> y;
   a.set(x, y);
   cin >> x >> y;
   b.set(x, y);
   if (a > b)cout << a;
   else cout << b;
   system("pause");
   return 0;
}
