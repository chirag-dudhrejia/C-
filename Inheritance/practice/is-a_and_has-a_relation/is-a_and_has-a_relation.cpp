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
    cout<<"|"<<setw(10)<<dept_no
        <<"|"<<setw(25)<<dept_name<<"|\n";
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
    cout<<"|"<<setw(6)<<empid
        <<"|"<<setw(25)<<name
        <<"|"<<setw(6)<<age
        <<"|"<<setw(25)<<designation;
    dept.show_data();
}

int main()
{
    string saperator = "+------+-------------------------+------+-------------------------+----------+-------------------------+\n";
    Employee e[3];
    e[0] = Employee(22, "Chirag", 101, "Machine Learning", "Data Analyst", 12);
    e[1] = Employee(21, "Jigar", 102, "Artificial Intelligence", "Data Scientist", 14);
    e[2] = Employee(22, "Rohan", 105, "Developement", "Software Developer", 25);

    cout<<left<<saperator;
    cout<<"|"<<setw(6)<<"Emp ID"<<"|"<<setw(25)<<"Name"<<"|"<<setw(6)<<"Age"<<"|"<<setw(25)<<"Designation"<<"|"<<setw(10)<<"Dept. No."<<"|"<<setw(25)<<"Dept. Name"<<"|\n";
    cout<<saperator;

    for (int i = 0; i < 3; i++)
    {
        e[i].show_data();
        cout<<saperator;

    }
    
    return 0;
}