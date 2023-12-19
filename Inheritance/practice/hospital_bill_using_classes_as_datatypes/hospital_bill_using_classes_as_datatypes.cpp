#include <iostream>
#include <stdlib.h>
using namespace std;

class Doctor
{
    string name;
    string degree;
public:
    void set_doc();
    void get_doc();
};
void Doctor::set_doc()
{
    cout<<"\nEnter doctor name : ";
    getline(cin>>ws, name);
    cout<<"Enter Doctorate degree : ";
    getline(cin>>ws, degree);
}
void Doctor::get_doc()
{
    cout<<"\nDoctor Name : "<<name;
    cout<<"\nDoctorate Degree : "<<degree;
}

class Patient
{
    string name;
    string number;
public:
    void set_patient();
    void get_patient();
};
void Patient::set_patient()
{
    cout<<"Enter Patient name : ";
    getline(cin>>ws, name);
    cout<<"Enter contact number : ";
    cin>>number;
}
void Patient::get_patient()
{
    cout<<"\nPatient Name : "<<name;
    cout<<"\nContact Number : "<<number;
}

class Ward
{
    string ward_name;
public:
    void set_ward();
    void get_ward();
};
void Ward::set_ward()
{
    cout<<"\nEnter Ward name : ";
    getline(cin>>ws, ward_name);
}
void Ward::get_ward()
{
    cout<<"\nWard name : "<<ward_name;
}

class Bill
{
    int dues;
    Doctor doc;
    Patient pat;
    Ward wrd;
public:
    void set_bill();
    void get_bill();
};
void Bill::set_bill()
{
    pat.set_patient();
    doc.set_doc();
    wrd.set_ward();
    cout<<"Enter Dues of patient : ";
    cin>>dues;
}
void Bill::get_bill()
{
    system("cls");
    pat.get_patient();
    doc.get_doc();
    wrd.get_ward();
    cout<<"\nTotal Dues of patient : "<<dues;
}


int main()
{
    Bill b1;
    b1.set_bill();
    b1.get_bill();
    return 0;
}