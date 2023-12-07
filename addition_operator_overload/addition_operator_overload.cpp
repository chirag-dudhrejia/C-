#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

    public:
    void set_data(int , int );
    Point operator + (const Point &rhs); 
    void print();
};

void Point::set_data(int a, int b)
{
    x = a;
    y = b;
}

Point Point::operator +(const Point &rhs)
{
    Point p;
    p.x = x + rhs.x;
    p.y = y + rhs.y;

    return p;
}

void Point::print()
{
    cout <<"X : "<<x<<endl;
    cout <<"Y : "<<y<<endl;
}

int main()
{
    Point p1, p2, p3;

    p1.set_data(2, 5);
    p2.set_data(1, 3);

    p3 = p1 + p2;

    p3.print();

}