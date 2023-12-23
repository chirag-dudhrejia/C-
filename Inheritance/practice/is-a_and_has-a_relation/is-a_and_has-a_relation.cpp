#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person(){}
    Person(string name, int age): name(name), age(age){}
};

class Department
{
protected:
    int dept_no;
    string dept_name;
public:
    Department(){}
    Department(int d_no, string d_name): dept_no(d_no), dept_name(d_name){}
    void show_data();
};
void Department::show_data()
{
    cout<<setw(15)<<"\nDepartment No."<<" : "<<dept_no;
    cout<<setw(15)<<"\nDepartment"<<" : "<<dept_name;
}

class Employee: public Person
{
    int empid;
    string designation;
    Department dept;
public:
    Employee(){}
    Employee(int age, string name, int d_no, string d_name, string desig, int e_id): Person(name, age), dept(d_no, d_name), empid(e_id), designation(desig){}
    void show_data();
};
void Employee::show_data()
{
    cout<<left;
    cout<<setw(15)<<"\nEmployee ID"<<" : "<<empid;
    cout<<setw(15)<<"\nName"<<" : "<<name;
    cout<<setw(15)<<"\nAge"<<" : "<<age;
    cout<<setw(15)<<"\nDesignation"<<" : "<<designation;
    dept.show_data();
}

int main()
{
    Employee e;
    e = Employee(22, "Chirag", 101, "Machine Learning", "Data Analyst", 12);

    e.show_data();
    return 0;
}