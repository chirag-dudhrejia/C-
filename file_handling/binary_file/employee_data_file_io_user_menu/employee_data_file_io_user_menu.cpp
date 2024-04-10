#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Employee
{
    int empid;
    string name;
    string address;
    string telephone;

public:
    Employee() {}
    Employee(int empid, string name, string add, string tele) : empid(empid), name(name), address(add), telephone(tele) {}
    void input()
    {
        cout << "Enter Emp ID : ";
        cin >> empid;
        cout << "Enter name : ";
        getline(cin >> ws, name);
        cout << "Address : ";
        getline(cin >> ws, address);
        cout << "Telephone No. : ";
        getline(cin >> ws, telephone);
    }
    void output_single_record();
    friend class Operations;
};
void Employee::output_single_record()
{
    cout << "\nemp ID : " << empid;
    cout << "\nname : " << name;
    cout << "\nAddress : " << address;
    cout << "\nTelephone No. : " << telephone;
}

class Operations
{
public:
    void add_record();
    void read_records(vector<Employee> &e);
    void output_records(vector<Employee> e);
};
void Operations::add_record()
{
    Employee e;
    ofstream out_file("employees.txt", ios::out | ios::binary | ios::app);
    if (!out_file.is_open())
    {
        cout << "Falied to open file.\n";
        exit(1);
    }
    out_file.seekp(0, ios::end);
    // int empid;
    // string name, add, tele;
    e.input();
    out_file.write((char *)&e, sizeof(e));
    if (out_file.fail())
    {
        cout << "Failed to write into file.\n";
        return;
    }
    out_file.close();
}
// void Operations::read_records(vector<Employee>& e)
// {
//     Employee temp;
//     ifstream read_file("employees.txt", ios::in | ios::binary);
//     if (!read_file.is_open())
//     {
//         cout<<"Failed to open read file.\n";
//         return;
//     }

//     while (read_file.good())
//     {
//         read_file.read((char*)&temp, sizeof(temp));
//         e.push_back(temp);
//     }
//     read_file.close();
// }

// void Operations::output_records(vector<Employee> e)
// {
//     vector<Employee>::iterator i;
//     for ( i = e.begin(); i < e.end(); i++)
//     {
//         i->output_single_record();
//         cout<<"\n";
//     }
// }

int main()
{
    int option = -1;
    vector<Employee> e;
    Operations o;

    while (option != 0)
    {
        cout << "\nChoose\n";
        cin >> option;

        if (option == 1)
        {
            o.add_record();
        }
        else if (option == 2)
        {

            // o.output_records(e);

            vector<Employee> emp;

            Employee temp;
            ifstream read_file("employees.txt", ios::in | ios::binary);
            if (!read_file.is_open())
            {
                cout << "Failed to open read file.\n";
            }

            while (read_file.good())
            {
                read_file.read((char *)&temp, sizeof(temp));
                if (read_file.fail())
                {
                    break;
                }
                temp.output_single_record();
                emp.push_back(temp);
                cout << "\n\nRead\n\n";
            }
            read_file.close();

            // o.output_records(emp);
            vector<Employee>::iterator i;
            for (i = emp.begin(); i < emp.end(); i++)
            {
                i->output_single_record();
                cout << "\n";
            }
        }
    }
    return 0;
}