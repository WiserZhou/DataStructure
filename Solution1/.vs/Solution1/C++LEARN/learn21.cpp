#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template <typename T>
class Complex
{
    //friend Complex<T> Complex<T>::operator+(Complex<T> &c);
public:
    Complex(T real, T imag){tReal=real;tImag=imag;};
    Complex operator+(Complex &);
    Complex operator-(Complex &);
    Complex operator*(Complex &);
    void ShowInfo();
private:
    T tReal;
    T tImag;
};
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c)
{
    Complex<T> temp = *this;
    temp.tReal = this->tReal + c.tReal;
    temp.tImag = this->tImag + c.tImag;
    return temp;
}
template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c)
{
    Complex<T> temp = *this;
    temp.tImag = this->tImag - c.tImag;
    temp.tReal = this->tReal - c.tReal;
    return temp;
}
template <typename T>
Complex<T> Complex<T>::operator*(Complex<T> &c)
{
    Complex<T> temp = *this;
    temp.tImag = this->tImag * c.tImag;
    temp.tReal = this->tReal * c.tReal;
    return temp;
}
template <typename T>
void Complex<T>::ShowInfo()
{
    cout << "(" << tReal << "," << tImag << ")" << endl;
}
int main()
{
    Complex<double> c1(1.9, 2.8), c2(-3.7, 4.66), c3(0.99, 0.59);
    cout << "c1:";
    c1.ShowInfo();
    cout << "c2:";
    c2.ShowInfo();
    c3 = c1 + c2;
    cout << "c1+c2:";
    c3.ShowInfo();
    c3 = c1 - c2;
    cout << "c1-c2:";
    c3.ShowInfo();
    c3 = c1 * c2;
    cout << "c1*c2:";
    c3.ShowInfo();
    system("pause");
    return 0;
}