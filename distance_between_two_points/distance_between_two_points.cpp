#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    float x, y;

    public:
    Point(float, float);
    friend float calc_distance(Point, Point);

};

Point::Point(float a, float b)
{
    x = a;
    y = b;
}

float calc_distance(Point p1, Point p2)
{
    float distance;

    distance  = sqrt(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2));

    return distance;
}

int main()
{
    float distance;
    Point pt1(3, 4), pt2(5, 8);

    distance = calc_distance(pt1, pt2);

    printf("\n\nDistance : %f\n\n", distance);


}