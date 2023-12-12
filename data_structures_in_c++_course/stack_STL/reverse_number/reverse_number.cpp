#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> stck;
    unsigned int number;

    cout<<"Enter number to reverse it : ";
    cin>>number;

    int remainder;
    while (number != 0)
    {
        remainder = number%10;
        stck.push(remainder);
        number /= 10;
    }

    unsigned int multiplyer = 1;
    while (!stck.empty())
    {
        number  = number + (stck.top()* multiplyer);
        stck.pop();
        multiplyer *= 10;
    }

    cout<<"Reversed Number.\n";
    cout<<number<<"\n\n";
    return 0;
}