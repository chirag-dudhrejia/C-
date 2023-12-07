#include <iostream>

using namespace std;

class Student
{
    int rollno;
    string name;
    float maths;
    float science;
    float english;
    float total;
    float percentage;

    public:
    void set_data();
    void calc();
    void get_data();

};

void Student::set_data()
{
    cout <<"Roll No. : ";
    cin >>rollno;
    cout <<"Name : ";
    cin >>name;
    cout <<"Maths : ";
    cin >>maths;
    cout <<"Science : ";
    cin >>science;
    cout <<"English : ";
    cin >>english;
}

void Student::calc()
{
    total = maths + science + english;

    percentage = total/3;
}

void Student::get_data()
{
    cout <<"Name : "<<name<<endl;
    cout <<"Maths : "<<maths<<endl; 
    cout <<"Science : "<<science<<endl; 
    cout <<"English : "<<english<<endl;
    cout <<"Total : "<<total<<endl;
    cout <<"Percentage : "<<percentage<<endl; 
}

int main()
{
    int i, n;
    Student stud[3];

    for ( i = 0; i < 3; i++)
    {
        cout <<"Enter details for student : "<<i+1<<endl;
        stud[i].set_data();
        stud[i].calc();
    }

    cout<<endl<<endl;

    for ( i = 0; i < 3; i++)
    {
        cout <<"Details of student : "<<i+1<<endl;
        stud[i].get_data();
        cout<<endl;
    }
    
    
    return 0;
}