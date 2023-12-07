#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

    public:
    void set_data(int, int);
    Point operator + ();
    void print();
};

void Point::set_data(int a, int b)
{
    x = a;
    y = b;
}

Point Point::operator + ()
{
    Point p1;
    p1.x = x + 1;
    p1.y = y + 1;
    return p1;
}

void Point::print()
{
    cout <<"X : "<<x<<endl;
    cout <<"Y : "<<y<<endl;
}


int main()
{
    Point p1, p2;

    p1.set_data(2, 5);

    p2 = +p1;

    p2.print();

    return 0;
}