#include <iostream>
using namespace std;

class Student
{
protected:
    int rollno;
    string Sname;
    int age;
    string address;
public:
    void getdata();
    void putdata();
};

void Student::getdata()
{
    cout<<"Roll no.\n";
    cin>>rollno;
    cout<<"Studetn Name.\n";
    getline(cin>>ws, Sname);
    cout<<"Age.\n";
    cin>>age;
    cout<<"Address.\n";
    getline(cin>>ws, address);
}

void Student::putdata()
{
    cout<<"\nRoll NO : "<<rollno;
    cout<<"\nName    : "<<Sname;
    cout<<"\nAge     : "<<age;
}

class Marksheet:public Student
{
    int oocp;
    int dsa;
    int dbms;
    float percentage;
public:
    void input();
    void output();
    float calculate();
    friend int search(Marksheet m[], int key, int n);
};

void Marksheet::input()
{
    getdata();
    cout<<"Marks in oocp.\n";
    cin>>oocp;
    cout<<"Marks in dsa.\n";
    cin>>dsa;
    cout<<"Marks in dbms.\n";
    cin>>dbms;
}

void Marksheet::output()
{
    putdata();
    cout<<"\nOOCP    : "<<oocp;
    cout<<"\nDSA     : "<<dsa;
    cout<<"\nDBMS    : "<<dbms;
    cout<<"\nPercent : "<<calculate();
}

float Marksheet::calculate()
{
    return (oocp+dsa+dbms)/3;
}

int search(Marksheet m[], int key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (m[i].rollno == key)
        {
            return i;
        }
        
    }
    return -1;
}

int main()
{
    int n = 3;
    int key;
    Marksheet m[3];

    for (int i = 0; i < n; i++)
    {
        cout<<"\nInput details of student "<<i+1<<"\n";
        m[i].input();
    }

    cout<<"\nEnter roll no of student to see details : ";
    cin>>key;
    m[search(m, key, n)].output();

    return 0;
}