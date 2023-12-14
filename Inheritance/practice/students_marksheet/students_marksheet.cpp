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
    cout<<"\nPercent : "<<calculate()<<"\n";
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
    int count = 0;
    int option = 1;
    int key;
    Marksheet ms[20];

    cout<<"\nInput details of student "<<count+1<<"\n";
    ms[count++].input();

    while (option != 0)
    {
        cout<<"\nChoose task to perform.\n"
            <<"1. Insert data for more than one student.\n"
            <<"2. Insert data for 1 student.\n"
            <<"3. Get data of student using roll no.\n"
            <<"0. Exit.\n";
        cin>>option;

        if (option == 1)
        {
            int n;
            cout<<"How many student's data you want to enter? : ";
            cin>>n;
            while (n--)
            {
                cout<<"\nInput details of student "<<count+1<<"\n";
                ms[count++].input();
            }
            
        }
        else if (option == 2)
        {
            cout<<"\nInput details of student "<<count+1<<"\n";
            ms[count++].input();
        }
        else if (option == 3)
        {
            cout<<"Enter roll no to see details : ";
            cin>>key;
            cout<<"Details.\n";
            ms[search(ms, key, count)].output();
        }
        else if (option != 0)
        {
            cout<<"Invelid Input.\nEnter Again.\n";
        }
        
    }

    return 0;
}