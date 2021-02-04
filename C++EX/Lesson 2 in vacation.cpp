#include<iostream>
using namespace std;
const float PI = 3.1415926;
const int ZhalanP = 35;
const int GuodaoP = 20;
class Circle
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }
    float Long()
    {
        return 2 * radius * PI;
    }
    float Square()
    {
        return radius * radius * PI;
    }
};
void main()
{
    float radius;
    cout << "Input the radius" << endl;
    cin >> radius;
    Circle pool(radius);
    Circle ZhaLan(radius+3);
    cout << "The price of Zhalan is " << ZhaLan.Long()* ZhalanP << endl;
    cout << "The price of Guodao is " <<(ZhaLan.Square() - pool.Square()) * GuodaoP << endl;
    printf("%-4f", radius);
}

