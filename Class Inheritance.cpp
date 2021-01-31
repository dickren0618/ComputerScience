#include <iostream>
#include<cmath>
using namespace std;
class Point {//基类成员函数
public:
    void initPoint(float x = 0, float y = 0) { this->x = x; this->y = y;
    }
    void move(float offX, float offY) {
        x += offX; y += offY;
    }
    float getX() const {return x;}
    float getY() const { return y; }
private:
    float x, y;
};
class Rectangke :public Point {//派生类 这次是公有继承其父类
public:
    void initRectangle(float x, float y, float w, float h) {
        initPoint(x, y);
        this->w = w;
        this->h = h;
    }
    float getH() const { return h; }
    float getW() const { return w; }
private:
    float w, h;
};
void main()
{
    Rectangke rect;
    rect.initRectangle(2, 3, 20, 10);
    rect.move(3, 2);
    cout << "The data of rect(x,y,w,h):" << endl;
    cout << rect.getX() << "," << rect.getY() << "," << rect.getW() << "," << rect.getH() << endl;
}