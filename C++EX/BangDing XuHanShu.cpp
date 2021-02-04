#include <iostream>
using namespace std;
class Basel
{
public:
    virtual void display() const; //虚函数
};
void Basel::display() const
{
    cout << "Basel ::display()" << endl;
}
class Basel2 :public Basel//公有继承派生类
{
public:
    void display() const;//覆盖基类的虚函数
};
void Basel2::display() const
{
    cout << "Basel2::display()" << endl;
}
class Derived : public Basel2
{
public:
    void display() const;//覆盖基类虚函数
};
void Derived::display() const
{
    cout << "Derived :: display()"<<endl;
}
void fun(Basel* ptr)
{
    ptr->display();//对象指针->成员名
}
int main()
{
    Basel base1;
    Basel2 base2;
    Derived derived;
    fun(&base1);
    fun(&base2);
    fun(&derived);
}

