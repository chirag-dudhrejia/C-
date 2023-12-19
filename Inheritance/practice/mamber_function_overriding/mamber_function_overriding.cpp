#include <iostream>
using namespace std;

class Employee
{
protected:
    int emp_id;
    string f_name;
    string l_name;
    float salary;
    int age;
public:
    void enter_data();
    void display_data();
};
void Employee::enter_data()
{
    cout<<"Enter Employee ID : ";
    cin>>emp_id;
    cout<<"Enter First name : ";
    cin>>f_name;
    cout<<"Enter Last name : ";
    cin>>l_name;
    cout<<"Enter Salary : ";
    cin>>salary;
    cout<<"Enter age : ";
    cin>>age;
}
void Employee::display_data()
{
    cout<<"\nEmp ID : "<<emp_id;
    cout<<"\nName : "+f_name+" "+l_name;
    cout<<"\nSalary : "<<salary;
    cout<<"\nAge : "<<age;
}

class Engineer: public Employee
{
    string designation;
public:
    void enter_data();
    void display_data();
};
void Engineer::enter_data()
{
    Employee::enter_data();    //Overriding member finction
    cout<<"Enter Designation : ";
    getline(cin>>ws, designation);
}
void Engineer::display_data()
{
    cout<<"Details.\n";
    Employee::display_data();   //Overriding member function
    cout<<"\nDesignation : "<<designation;
}

int main()
{
    Engineer e1;

    e1.enter_data();

    e1.display_data();
    return 0;
}