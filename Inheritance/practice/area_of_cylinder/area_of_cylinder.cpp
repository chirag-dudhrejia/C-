#include <iostream>
using namespace std;

class Circle
{
protected:
    float radius;
public:
    Circle(){}
    Circle(float r): radius(r){}
    void area();
};
void Circle::area()
{
    cout<<"\nArea of circle : "<<22/7*radius*radius<<"\n";
}
class Rectangle
{
protected:
    float length, breadth;
public:
    Rectangle(){}
    Rectangle(float l, float b): length(l), breadth(b){}
    void area();
};
void Rectangle::area()
{
    cout<<"\nArea of Rectangle : "<<length*breadth<<"\n";
}

class Cylinder:public Circle, public Rectangle
{
public:
    Cylinder(){}
    Cylinder(float r, float l, float b): Circle(r), Rectangle(l, b){}
    void volume();
};
void Cylinder::volume()
{
    cout<<"\nVolume of cylinder : "<<22/7* radius*radius *length<<"\n";
}

int main()
{
    Cylinder c;
    c = Cylinder(4, 10, 5);
    c.volume();
    return 0;
}