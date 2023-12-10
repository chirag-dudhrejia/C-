#include <iostream>
using namespace std;

int fib(int num)
{
    if (num==1 || num==2)
    {
        return 1;
    }
    return fib(num-1) + fib(num-2);
}

int main()
{
    int number;

    cout<<"How many fibonacci numbers you want? ";
    cin>>number;

    int fib_number = fib(number);

    cout<<"Fibinacci number at position "<<number<<" is : "<<fib_number;
    return 0;
}