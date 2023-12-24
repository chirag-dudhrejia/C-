#include <iostream>
#include <iomanip>
using namespace std;

class Staff
{
protected:
    int code;
    string name;
public:
    Staff(){}
    Staff(int code, string name): code(code), name(name){}
};

class Teacher: public Staff
{
protected:
    string subject;
    string publication;
public:
    Teacher(){}
    Teacher(int code,  string name, string sub, string publi): Staff(code, name), subject(sub), publication(publi){}
    void show_details();
};
void Teacher::show_details()
{
    cout<<left;
    cout<<"\n+--------+-------------------------+-------------------------+--------------------+"
        <<"\n|"<<setw(8)<<"Staff ID"<<"|"<<setw(25)<<"Name"<<"|"<<setw(25)<<"Subject"<<"|"<<setw(20)<<"Publication"<<"|"
        <<"\n+--------+-------------------------+-------------------------+--------------------+"
        <<"\n|"<<setw(8)<<code<<"|"<<setw(25)<<name<<"|"<<setw(25)<<subject<<"|"<<setw(20)<<publication<<"|"
        <<"\n+--------+-------------------------+-------------------------+--------------------+\n";
}

class Typist:public Staff
{
protected:
    int speed;
public:
    Typist(){}
    Typist(int speed, int code, string name): Staff(code, name), speed(speed){}
};

class Regular_typist:public Typist
{
protected:
    float salary;
public:
    Regular_typist(){}
    Regular_typist(float sal, int speed, int code, string name): Typist(speed, code, name), salary(sal){}
    void show_details();
};
void Regular_typist::show_details()
{
    cout<<left;
    cout<<"\n+--------+-------------------------+------------+"
        <<"\n|"<<setw(8)<<"Staff ID"<<"|"<<setw(25)<<"Name"<<"|"<<setw(12)<<"Salary"<<"|"
        <<"\n+--------+-------------------------+------------+"
        <<"\n|"<<setw(8)<<code<<"|"<<setw(25)<<name<<"|"<<setw(12)<<salary<<"|"
        <<"\n+--------+-------------------------+------------+\n";
}
class Casual_typist:public Typist
{
protected:
    float d_wages;
public:
    Casual_typist(){}
    Casual_typist(float wage, int speed, int code, string name): Typist(speed, code, name), d_wages(wage){}
    void show_details();
};
void Casual_typist::show_details()
{
    cout<<left;
    cout<<"\n+--------+-------------------------+------------+"
        <<"\n|"<<setw(8)<<"Staff ID"<<"|"<<setw(25)<<"Name"<<"|"<<setw(12)<<"Wages"<<"|"
        <<"\n+--------+-------------------------+------------+"
        <<"\n|"<<setw(8)<<code<<"|"<<setw(25)<<name<<"|"<<setw(12)<<d_wages<<"|"
        <<"\n+--------+-------------------------+------------+\n";
}

class Officer:public Staff
{
protected:
    int grade;
public:
    Officer(){}
    Officer(int grade, int code, string name): Staff(code, name), grade(grade){}
    void show_details();
};
void Officer::show_details()
{
    cout<<left;
    cout<<"\n+--------+-------------------------+------------+"
        <<"\n|"<<setw(8)<<"Staff ID"<<"|"<<setw(25)<<"Name"<<"|"<<setw(12)<<"Grade"<<"|"
        <<"\n+--------+-------------------------+------------+"
        <<"\n|"<<setw(8)<<code<<"|"<<setw(25)<<name<<"|"<<setw(12)<<grade<<"|"
        <<"\n+--------+-------------------------+------------+\n";
}

int main()
{
    Teacher t;
    Officer o;
    Regular_typist r;
    Casual_typist c;

    t = Teacher(101, "Chirag", "Maths", "ABCDEFGH");
    o = Officer(1, 201, "Rohan");
    r = Regular_typist(1000, 50, 301, "Jigar");
    c = Casual_typist(50000, 70, 401, "Yash");

    t.show_details();
    cout<<"\n";
    o.show_details();
    cout<<"\n";
    r.show_details();
    cout<<"\n";
    c.show_details();
    return 0;
}