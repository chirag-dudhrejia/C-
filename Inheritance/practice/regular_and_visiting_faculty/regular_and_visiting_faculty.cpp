#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Faculty
{
protected:
    string name;
    string qualif;
    // int no_subs;
    vector <string> sub_can;

public:
    virtual void input_data();
    virtual void output_data();
    virtual ~Faculty(){}
};
void Faculty::input_data()
{
    cout << "Enter Name : ";
    getline(cin >> ws, name);
    cout << "Enter Qualification : ";
    getline(cin >> ws, qualif);
    int no_subs;
    cout << "Number of subjects : ";
    cin >> no_subs;

    for (int i = 0; i < no_subs; i++)
    {
        cout<<"Subject name : ";
        string sub_name;
        getline(cin >> ws, sub_name);
        sub_can.push_back(sub_name);
    }
}
void Faculty::output_data()
{
    cout<<left;
    cout<<"\n+-------------------------+-------------------------+-------------------------+\n"
        <<"|"<<setw(25)<<"Name"<<"|"<<setw(25)<<"Qualification"<<"|"<<setw(25)<<"Subjects"<<"|\n"
        <<"+-------------------------+-------------------------+-------------------------+\n"
        <<"|"<<setw(25)<<name<<"|"<<setw(25)<<qualif<<"|"<<setw(25)<<sub_can[0]<<"|\n";

    vector<string>::iterator i;
    for (i = sub_can.begin()+1; i < sub_can.end(); i++)
    {
       cout<<"|"<<setw(25)<<" "<<"|"<<setw(25)<<" "<<"|"<<setw(25)<<*i<<"|\n"; 
    }
    cout<<"+-------------------------+-------------------------+-------------------------+\n";
 
}

class Regular_faculty: public Faculty
{
protected:
    string available;
    vector <string> sub_teach;
    string institute;
public:
    void input_data();
    void output_data();
};
void Regular_faculty::input_data()
{
    cout << "Enter Name : ";
    getline(cin >> ws, name);
    cout << "Enter Qualification : ";
    getline(cin >> ws, qualif);
    int no_subs;
    cout << "Number of subjects : ";
    cin >> no_subs;

    for (int i = 0; i < no_subs; i++)
    {
        cout<<"Subject "<<i+1<<" : ";
        string sub_name;
        getline(cin >> ws, sub_name);
        sub_can.push_back(sub_name);
    }
    available = "FullTime";

    cout << "Number of subjects teach : ";
    cin >> no_subs;

    for (int i = 0; i < no_subs; i++)
    {
        cout<<"Subject "<<i+1<<" : ";
        string sub_name;
        getline(cin >> ws, sub_name);
        sub_teach.push_back(sub_name);
    }
    institute = "Chirag Tech University";
}
void Regular_faculty::output_data()
{
    cout<<left;
    cout<<"\n+-------------------------+-------------------------+-------------------------+--------------+-------------------------+\n"
        <<"|"<<setw(25)<<"Name"<<"|"<<setw(25)<<"Qualification"<<"|"<<setw(25)<<"Subjects"<<"|"<<setw(14)<<"Available"<<"|"<<setw(25)<<"Institute"<<"|\n"
        <<"+-------------------------+-------------------------+-------------------------+--------------+-------------------------+\n"
        <<"|"<<setw(25)<<name<<"|"<<setw(25)<<qualif<<"|"<<setw(25)<<sub_can[0]<<"|"<<setw(14)<<available<<"|"<<setw(25)<<institute<<"|\n";

    vector<string>::iterator i;
    for (i = sub_teach.begin()+1; i < sub_teach.end(); i++)
    {
       cout<<"|"<<setw(25)<<" "<<"|"<<setw(25)<<" "<<"|"<<setw(25)<<*i<<"|"<<setw(14)<<" "<<"|"<<setw(25)<<" "<<"|\n"; 
    }
    cout<<"+-------------------------+-------------------------+-------------------------+--------------+-------------------------+\n";
 
}
class Visiting_faculty: public Faculty
{
protected:
    vector <string> available;
    string sub_teach;
    string institute;
public:
    void input_data();
    void output_data();
};
void Visiting_faculty::input_data()
{
    cout << "Enter Name : ";
    getline(cin >> ws, name);
    cout << "Enter Qualification : ";
    getline(cin >> ws, qualif);
    int no_subs;
    cout << "Number of subjects : ";
    cin >> no_subs;

    for (int i = 0; i < no_subs; i++)
    {
        cout<<"Subject "<<i+1<<" : ";
        string sub_name;
        getline(cin >> ws, sub_name);
        sub_can.push_back(sub_name);
    }
    
    int days;
    cout<<"How many days available in week? : ";
    cin>>days;

    while (days)
    {
        cout<<"Available when? Enter Day(Mon) then Time(11 A.M. - 1 P.M.) : ";
        string timing;
        getline(cin>>ws, timing);
        available.push_back(timing);
        days--;
    }

    cout<<"Subject teach : ";
    getline(cin >> ws, sub_teach);

    cout<<"Institute Name : ";
    getline(cin>>ws, institute);
}
void Visiting_faculty::output_data()
{
    cout<<left;
    cout<<"\n+-------------------------+-------------------------+-------------------------+--------------------+-------------------------+\n"
        <<"|"<<setw(25)<<"Name"<<"|"<<setw(25)<<"Qualification"<<"|"<<setw(25)<<"Subjects"<<"|"<<setw(20)<<"Available"<<"|"<<setw(25)<<"Institute"<<"|\n"
        <<"+-------------------------+-------------------------+-------------------------+--------------------+-------------------------+\n"
        <<"|"<<setw(25)<<name<<"|"<<setw(25)<<qualif<<"|"<<setw(25)<<sub_teach<<"|"<<setw(20)<<available[0]<<"|"<<setw(25)<<institute<<"|\n";

    vector<string>::iterator i;
    for (i = available.begin()+1; i < available.end(); i++)
    {
       cout<<"|"<<setw(25)<<" "<<"|"<<setw(25)<<" "<<"|"<<setw(25)<<" "<<"|"<<setw(20)<<*i<<"|"<<setw(25)<<" "<<"|\n"; 
    }
    cout<<"+-------------------------+-------------------------+-------------------------+--------------------+-------------------------+\n";
 
}

int main()
{
    Faculty* f;
    Regular_faculty r;
    Visiting_faculty v;


    f = &r;
    f->input_data();
    f->output_data();
    
    f = &v;
    f->input_data();
    f->output_data();

    delete f;
    return 0;
}