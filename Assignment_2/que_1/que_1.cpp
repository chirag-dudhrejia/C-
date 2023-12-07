#include <iostream>
using namespace std;

class Number
{
    int num;

    public:
    Number(){num = 0;}
    Number(int n);
    Number operator + (Number another);
    void display();
};

Number::Number(int n)
{
    num = n;
}

Number Number::operator + (Number another)
{
    return Number(this->num + another.num);
}

void Number::display()
{
    cout<<num<<endl;
}

int main()
{
    Number num1, num2, total;
    int number;
    cout<<"Enter 1st Number here : ";cin>>number;
    num1 = Number(number);
    cout<<"Enter 2nd Number here : ";cin>>number;
    num2 = Number(number);

    total = num1 + num2;

    cout<<endl<<"Sum Is : ";
    total.display();

    return 0;
}