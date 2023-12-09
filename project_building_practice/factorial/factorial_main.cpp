#include <iostream>
#include "fact.h"
using namespace std;

int main()
{
    int number;

    cout<<"Enter number to calculate factorial : ";
    cin>>number;

    int factorial = fact(number);

    cout<<"Factorial of "<<number<<" is : "<<factorial;
}