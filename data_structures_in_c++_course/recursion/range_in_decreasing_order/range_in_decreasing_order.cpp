#include <iostream>
using namespace std;

// Prints range in reverse from end to start + 1
void range(int s, int e)
{
    if (s == e)
    {
        return;
    }
    cout<<e<<" ";
    return range(s, e-1);
}

int main()
{
    int start_point, end_point;

    cout<<"Enter starting point of range : ";
    cin>>start_point;
    cout<<"Enter end point of range : ";
    cin>>end_point;

    range(start_point, end_point);
    return 0;
}