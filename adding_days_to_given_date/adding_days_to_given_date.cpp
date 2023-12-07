#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date() {}
    Date(int d, int m, int y);
    Date operator+(int days);
    void display();
};

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

Date Date::operator+(int days)
{
    Date new_date;
    int total_days;

    new_date.day = day;
    new_date.month = month;
    new_date.year = year;

    new_date.day = day + days;

    if (new_date.day > 365)
    {
        new_date.year = new_date.year + (new_date.day / 365);
        new_date.day = new_date.day % 365;
    }

    if (new_date.day > 30)
    {
        new_date.month = new_date.month + (new_date.day / 30);
        new_date.day = new_date.day % 30;
    }

    return new_date;
}

void Date::display()
{
    cout<<day<<"/"<<month<<"/"<<year<<endl;
}

int main()
{
    int day, month, year;

    cout << "Enter Date, Month and Year Respectively : ";
    cin >> day >> month >> year;

    int days;

    cout << "Enter Number Of Days To Add : ";
    cin >> days;

    Date dt, new_dt;

    dt = Date(day, month, year);

    new_dt = dt + days;

    cout<<"Old Date : ";
    dt.display();
    cout<<"New Date : ";
    new_dt.display();

    return 0;
}