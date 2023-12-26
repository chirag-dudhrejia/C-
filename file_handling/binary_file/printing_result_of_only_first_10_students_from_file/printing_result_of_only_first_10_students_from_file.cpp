#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Result
{
    int rollno;
    string name;
    int oocp;
    int dbms;
    int dsa;
    float percentage;
    string result;
public:
    Result(){}
    Result(int roll, string name, int oocp, int dbms, int dsa);
    void calculate_percent();
    void output();
};
Result::Result(int roll, string name, int oocp, int dbms, int dsa): rollno(roll), name(name), oocp(oocp), dbms(dbms), dsa(dsa), percentage(0)
{
    calculate_percent();
    if (percentage>=40)
    {
        result = "Pass";
    }
    else
    {
        result = "Fail";
    }
}
void Result::calculate_percent()
{
    percentage = (oocp+dbms+dsa)/3;
}
void Result::output()
{
    cout<<"\n|"<<setw(8)<<rollno<<"|"<<setw(25)<<name<<"|"<<setw(8)<<oocp<<"|"<<setw(8)<<dbms<<"|"<<setw(8)<<dsa<<"|"<<setw(10)<<percentage<<"|"<<setw(10)<<result<<"|";
}

int main()
{
    vector<Result> r;

    ofstream file("data.dat", ios::out | ios::binary | ios::trunc);
    if (!file.is_open())
    {
        cout<<"failed to open file!\n";
    }
    r.push_back(Result(101, "chirag", 79, 87, 98));
    r.push_back(Result(102, "jigar", 89, 86, 88));
    r.push_back(Result(103, "rohan", 79, 87, 68));
    r.push_back(Result(104, "chintan", 59, 87, 98));
    r.push_back(Result(105, "yash", 29, 17, 38));
    r.push_back(Result(106, "jay", 79, 87, 98));
    r.push_back(Result(107, "harsh", 22, 47, 17));
    r.push_back(Result(108, "harshal", 39, 87, 48));
    r.push_back(Result(109, "sahadev", 79, 87, 98));
    r.push_back(Result(110, "gautam", 79, 87, 98));
    r.push_back(Result(111, "jatin", 79, 87, 98));
    
    vector <Result>::iterator i;
    for (i = r.begin(); i < r.end(); i++)
    {
        file.write((char*)&*i, sizeof(*i));
        if (file.fail())
        {
            cout<<"File write failed.\n";
            break;
        }
    }
    file.close();

    vector<Result> rout;
    Result temp;

    ifstream read_file("data.dat", ios::in | ios::binary);
    if (!read_file.is_open())
    {
        cout<<"Failed to open read file.\n";
    }
    
    for (int i = 0; i < 10; i++)
    {
        read_file.read((char*)&temp, sizeof(temp));
        rout.push_back(temp);
        if (read_file.fail())
        {
            cout<<"File read failed.\n";
            break;
        }
    }
    read_file.close();
    
    cout<<left;
    cout<<"\n+--------+-------------------------+--------+--------+--------+----------+----------+"
        <<"\n|"<<setw(8)<<"Roll No."<<"|"<<setw(25)<<"Name"<<"|"<<setw(8)<<"OOCP"<<"|"<<setw(8)<<"DBMS"<<"|"<<setw(8)<<"DSA"<<"|"<<setw(10)<<"Percentage"<<"|"<<setw(10)<<"Result"<<"|"
        <<"\n+--------+-------------------------+--------+--------+--------+----------+----------+";
    for (int i = 0; i < 10; i++)
    {
        rout[i].output();
        cout<<"\n+--------+-------------------------+--------+--------+--------+----------+----------+";
    }
    
    
    return 0;
}