#include <iostream>
using namespace std;
class Complex {//这里是构造复数类，学习了一下加法和减法的运算符重载
public:
    Complex(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }
    Complex OK(double real, double imag) 
    {
        this->real = real;
        this->imag = imag;
        return Complex(real, imag);

    }
    void display() const { cout << "real is " << real << " imag is " << imag<<endl; }

    Complex operator + (const Complex &c2) const 
    {
        return Complex(real + c2.real,imag + c2.imag);
    }

    Complex operator - (const Complex& c2) const 
    {
        return Complex(real - c2.real, imag - c2.imag);
    }
private:
    double real, imag;
};
class Clock {//这里我要开始构造钟类，来学习前置++和后置++的区别了
public:
    Clock(int hour = 0, int minute = 0, int second = 0) 
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    void showtime() const {
        cout << "Hour is " << hour << " Minute is " << minute << " Second is " << second << endl;
    }
    Clock& operator ++ () 
    {//前置单目运算符重载，无参数
        second++;
        if (second >= 60) 
        {
            second -= 60;
            minute++;
            if (minute >= 60) 
            {
                minute -= 60;
                hour = (hour + 1) % 24;
            }
        }
        return *this;
    }
    Clock operator ++ (int) //后置单目运算符，有参数
    {
        Clock old=*this;
        ++(*this);
        return old;
    }
private:
    int hour, minute, second;
};
int main()
{
    Complex c1(1, 1);
    Complex c2(10, 2);
    c2 = c2 - c1;
    c2.display();
    cout << "-------------------------------------------------" << endl;
    Clock myclock(23, 59, 59);
    cout << "First time output: ";
    myclock.showtime();
    cout << "Show myclock++: ";
    (myclock++).showtime();
    cout << "Show ++myclock: ";
    (++myclock).showtime();

}




