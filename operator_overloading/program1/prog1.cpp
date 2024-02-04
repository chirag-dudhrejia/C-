#include <iostream>
using namespace std;

class Numbers
{
    int a;
    int b;
    public:
    Numbers(){}
    Numbers(int a, int b): a(a), b(b){}
    Numbers(Numbers const& obj);
    Numbers operator + (Numbers const& obj);
    Numbers operator - (Numbers const& obj);
    Numbers operator * (Numbers const& obj);
    Numbers operator / (Numbers const& obj);
    void operator = (Numbers const& obj);
    friend ostream & operator << (ostream &output, Numbers const& obj);
    friend istream & operator >> (istream &input, Numbers & obj);
};

Numbers::Numbers(Numbers const& obj)
{
    a = obj.a;
    b = obj.b;
}

Numbers Numbers::operator + (Numbers const& obj)
{
    return Numbers(a+obj.a, b+obj.b);
}

Numbers Numbers::operator - (Numbers const& obj)
{
    return Numbers(a-obj.a, b-obj.b);
}

Numbers Numbers::operator * (Numbers const& obj)
{
    return Numbers(a*obj.a, b*obj.b);
}

Numbers Numbers::operator / (Numbers const& obj)
{
    return Numbers(a/obj.a, b/obj.b);
}

void Numbers::operator = (Numbers const& obj)
{
    a = obj.a;
    b = obj.b;
}

istream & operator >> (istream &input, Numbers & obj)
{
    input>>obj.a;
    input>>obj.b;
}

ostream & operator << (ostream &output, Numbers const& obj)
{
    output<<obj.a<<"\n";
    output<<obj.b<<"\n";
}

int main()
{
    Numbers num1(5,5), num2(5,10);
    Numbers num3 = num1 + num2;
    cout<<num3;
    return 0;
}