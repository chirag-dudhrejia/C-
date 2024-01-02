#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Student
{
protected:
	int rollno;
	string name;
	string contact;
public:
	Student(){}
	Student(int roll, string name, string contact): rollno(roll), name(name), contact(contact){}
	void output();
};
void Student::output()
{
	cout<<"\nRoll No : "<<rollno;
	cout<<"\nName : "<<name;
	cout<<"\nContact : "<<contact;
}

class Marksheet:public Student
{
	vector<int> marks;
	float percent;
	char grade;
	string result;
public:
	Marksheet(){}
	Marksheet(int roll, string name, string contact, int mark1, int mark2, int mark3);
	void output();
	float calc_percent();
    char calc_sub_grade(int mark);
	char calc_grade();
	string calc_result();
    friend int search(vector<Marksheet> m, int key);
};
Marksheet::Marksheet(int roll, string name, string contact, int mark1, int mark2, int mark3): Student(roll, name, contact){
		marks.push_back(mark1);
		marks.push_back(mark2);
		marks.push_back(mark3);
		
		percent = calc_percent();
		grade = calc_grade();
		result = calc_result();
}
float Marksheet::calc_percent()
{
	return (marks[0]+marks[1]+marks[2])/3;
}
char Marksheet::calc_sub_grade(int mark)
{
    if (mark>=90) return 'A';
	else if(mark>= 75) return 'B';
	else if(mark>= 60) return 'C';
	else if(mark>= 40) return 'D';
	else return 'F';
}
char Marksheet::calc_grade()
{
    if (calc_sub_grade(marks[0]) == 'F' || calc_sub_grade(marks[1]) == 'F' || calc_sub_grade(marks[2]) == 'F') return 'F';
	if (percent>=90) return 'A';
	else if(percent>= 75) return 'B';
	else if(percent>= 60) return 'C';
	else if(percent>= 40) return 'D';
	else return 'F';
}
string Marksheet::calc_result()
{
	return grade=='F'?"Fail":"Pass";
}
void Marksheet::output()
{
    cout<<left;
    cout<<"\n+------------------------------------------------------------------------------+"
        <<"\n|"<<setw(78)<<"Marksheet of Mr./Ms."<<"|"
        <<"\n|"<<setw(78)<<name<<"|"
        <<"\n+------------------------------------------------------------------------------+"
        <<"\n|"<<setw(78)<<"Institute name"<<"|"
        <<"\n|"<<setw(78)<<"Chirag Institute of Technology"<<"|"
        <<"\n+------------------------------------------------------------------------------+"
        <<"\n|"<<setw(11)<<"Roll No. : "<<setw(20)<<rollno<<"|"<<setw(11)<<"Course : "<<setw(35)<<"Master Of Computer Application"<<"|"
        <<"\n+------------------------------------------------------------------------------+"
        <<"\n|"<<setw(6)<<"Code"<<"|"<<setw(44)<<"Subject"<<"|"<<setw(8)<<"Max"<<"|"<<setw(8)<<"Obtained"<<"|"<<setw(8)<<"Grade"<<"|"
        <<"\n|"<<setw(6)<<"49930"<<"|"<<setw(44)<<"Object Oriented Conccepts & Programming"<<"|"<<setw(8)<<100<<"|"<<setw(8)<<marks[0]<<"|"<<setw(8)<<calc_sub_grade(this->marks[0])<<"|"
        <<"\n|"<<setw(6)<<"49931"<<"|"<<setw(44)<<"Data Structure & Algorithm"<<"|"<<setw(8)<<100<<"|"<<setw(8)<<marks[1]<<"|"<<setw(8)<<calc_sub_grade(this->marks[1])<<"|"
        <<"\n|"<<setw(6)<<"49932"<<"|"<<setw(44)<<"Relational Database Managemant system"<<"|"<<setw(8)<<100<<"|"<<setw(8)<<marks[2]<<"|"<<setw(8)<<calc_sub_grade(this->marks[2])<<"|"
        <<"\n|------------------------------------------------------------------------------|"
        <<"\n|------------------------------------------------------------------------------|"
        <<"\n|"<<setw(23)<<result<<"|"<<setw(13)<<"Percentage : "<<setw(20)<<percent<<"|"<<setw(8)<<"Grade : "<<setw(12)<<grade<<"|"
        <<"\n+------------------------------------------------------------------------------+";
}

int search(vector<Marksheet> m, int key)
{
    vector<Marksheet>::iterator i;
    for (i = m.begin(); i < m.end(); i++)
    {
        if (i->rollno == key) return i-m.begin();
    }
    
}

int main()
{
	vector<Marksheet> m;
    int roll, mark1, mark2, mark3, n;
    string name, contact;
	
    // for testing
	m.push_back(Marksheet(104, "Chirag Dudhrejia", "82948859496", 19, 38, 28));
	m.push_back(Marksheet(102, "Jigar Dudhrejia", "82945859496", 96, 94, 99));
	m.push_back(Marksheet(103, "Sahadev Nai", "82943857496", 84, 76, 29));
	m.push_back(Marksheet(101, "Gautam Chauhan", "82943859496", 79, 83, 92));
	m.push_back(Marksheet(101, "Jatin Solanki", "82944559496", 68, 88, 90));

    //for user input
    // cout<<"How many records to enter? : ";
    // cin>>n;

    // while (n)
    // {
    //     cout<<"Roll No. : ";
    //     cin>>roll;
    //     cout<<"Name : ";
    //     getline(cin>>ws, name);
    //     cout<<"Contact No. : ";
    //     cin>>contact;
    //     cout<<"Marks of sub 1, sub 2 and sub 3 respectively : ";
    //     cin>>mark1>>mark2>>mark3;
    //     m.push_back(Marksheet(roll, name, contact, mark1, mark2, mark3));
    //     n--;
    // }

    //writing into file
    ofstream out_file("file.txt", ios::out | ios::binary | ios::trunc);
    if (!out_file.is_open())
    {
        cout<<"Failed to open file\n";
    }

    vector<Marksheet>::iterator i;

    for (i = m.begin(); i < m.end(); i++)
    {
        out_file.write((char*)&*i, sizeof(*i));
        if (out_file.fail())
        {
            cout<<"Failed To write into file\n";
            break;
        }
    }
    out_file.close();


    //reading from file
    vector<Marksheet> out_marks;
    Marksheet temp;
    ifstream read_file("file.txt", ios::in | ios::binary);
    if (!read_file.is_open())
    {
        cout<<"file failed to open.\n";
    }

    while (read_file.good())
    {
        read_file.read((char*)&temp, sizeof(temp));
        out_marks.push_back(temp);
    }
    read_file.close();
    
    
    // Printing output
    cout<<"Enter Roll no. to get result : ";
    cin>>roll;
    system("cls");
	out_marks[search(m, roll)].output();

	return 0;
}