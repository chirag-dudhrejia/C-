#include <iostream>

using namespace std;

class Employee
{
    int empid;
    string name;
    float basic_salary;
    float hra;
    float da;
    float oa;
    float gross_salary;

    public:
    void set_data();
    void calc();
    void get_data();
};

void Employee::set_data()
{
    cout <<"Employee ID : ";
    cin >>empid;
    cout <<"Name : ";
    cin >>name;
    cout <<"Basic Salary : ";
    cin >>basic_salary;
}

void Employee::calc()
{
    hra = basic_salary*25/100;
    da = basic_salary*20/100;
    oa = basic_salary*15/100;

    gross_salary = basic_salary + hra + da + oa;
}

void Employee::get_data()
{
    cout <<"Employee ID : "<<empid<<endl;
    cout <<"Name : "<<name<<endl;
    cout <<"Basic Salary : "<<basic_salary<<endl;
    cout <<"Gross Salary : "<<gross_salary<<endl;
}

int main()
{
    int i, n;

    Employee emp[3];

    for ( i = 0; i < 3; i++)
    {
        cout <<"Details of employee : "<<i+1<<endl;
        emp[i].set_data();
        emp[i].calc();
    }

    cout<<endl<<endl;

    for ( i = 0; i < 3; i++)
    {
        cout <<"Details Of Employee : "<<i+1<<endl;
        emp[i].get_data();
        cout <<endl;
    }
    
    
    return 0;
}