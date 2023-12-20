#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    int rollno;
    string name;
    string address;
    int age;

public:
    void read_data();
    void write_data();
}; 
void Student::read_data()
{
    cout << "Enter roll no : ";
    cin >> rollno;
    cout << "Enter name : ";
    getline(cin >> ws, name);
    cout << "Enter address : ";
    getline(cin >> ws, address);
    cout << "Enter age : ";
    cin >> age;
}
void Student::write_data()
{
    cout<<"\nRoll No : "<<rollno;
    cout<<"\nName : "<<name;
    cout<<"\nAddress : "<<address;
    cout<<"\nAge : "<<age;
}

int main()
{
    Student stu[2];
    ofstream stu_file_out;
    stu_file_out.open("students.txt", ios::out | ios::binary | ios::trunc);
    if (!stu_file_out.is_open())
    {
        cout<<"File cannot be opened.\n";
    }
    char Continue = 'y';
    int i = 0;

    while (Continue != 'n')
    {
        stu[i].read_data();
        // stu_file_out.seekp(i*sizeof(stu), ios::beg);
        stu_file_out.write((char*)&stu[i], sizeof(stu[i]));

        if (stu_file_out.fail())
        {
            cout<<"File write failed.\n";
        }
        cout<<"Do you want to continue?\n";
        cin>>Continue;
        i++;
    }
    stu_file_out.close();


    Student stus;
    ifstream stu_file_in;
    stu_file_in.open("students.txt", ios::in | ios::binary);

    while (!stu_file_in.eof())
    {
        // stu_file_in.seekg(i*sizeof(stus), ios::beg);
        stu_file_in.read((char*)&stus, sizeof(stus));

        if (stu_file_in.fail())
        {
            break;
        }
        stus.write_data();
        cout<<"\n\n";
    }
    stu_file_in.close();
    
    return 0;
}