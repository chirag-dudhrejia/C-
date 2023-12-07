#include <iostream>
using namespace std;
template <class T>
T largest(T a, T b)
{
    return (a>b?a:b);
}

int main()
{
    int a, b;
    float c, d;
    char e, f;

    cout<<"Enter two integer : ";
    cin>>a>>b;
    cout<<largest(a, b)<<" is largest."<<"\n"<<"\n";

    cout<<"Enter two floating number : ";
    cin>>c>>d;
    cout<<largest(c, d)<<" is largest."<<"\n"<<"\n";

    cout<<"Enter two character : ";
    cin>>e>>f;
    cout<<largest(e, f)<<" is largest."<<"\n"<<"\n";

    return 0;
}