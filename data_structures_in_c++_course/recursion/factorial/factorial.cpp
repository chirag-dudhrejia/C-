#include <iostream>
using namespace std;

long long fact(int num)
{
    if (num < 0)
    {
        return 0;
    }
    
    if (num == 0)
    {
        return 1;
    }
    return num * fact(num-1);
}

int main()
{
    int number;

    cout<<"Enter number to find factorial : ";
    cin>>number;
    long long factorial = fact(number);

    cout<<"Factorial of "<<number<<" is : "<<factorial;
    return 0;
}