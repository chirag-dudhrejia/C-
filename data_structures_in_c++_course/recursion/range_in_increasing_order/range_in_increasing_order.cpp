#include <iostream>
using namespace std;

// Prints numbers from start to end - 1
void range(int s, int e)
{
    if (s == e)
    {
        return;
    }
    cout<<s<<" ";
    return range(s+1, e);
}

int main()
{
    int start_number, end_number;

    cout<<"Enter starting point of ranage : ";
    cin>>start_number;
    cout<<"Enter last number of range : ";
    cin>>end_number;

    cout<<"\nRange.\n";
    range(start_number, end_number);
    return 0;
}