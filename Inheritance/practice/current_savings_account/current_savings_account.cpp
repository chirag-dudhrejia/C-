#include <iostream>
using namespace std;
#define MIN_BAL 2000
#define SERVICE_CHARGE 500
#define R 4

class Account
{
    string name;
    long int acc_number;
    string acc_type;
public:
    void create_account(string ac_type);
};
void Account::create_account(string ac_type)
{
    cout<<"Full name.\n";
    getline(cin>>ws, name);
    cout<<"Account Number.\n";
    cin>>acc_number;
    acc_type = ac_type;
}

class current_ac:public Account
{
    float balance;
public:
    current_ac(): balance(0){}
    void deposit(float dep_amt);
    void withdraw(float withdraw_amt);
    void display();
};
void current_ac::deposit(float dep_amt)
{
    balance += dep_amt;
}
void current_ac::withdraw(float withdraw_amt)
{
    if (withdraw_amt>balance)
    {
        cout<<"Your balance is than your withdrawal amount.\n";
        cout<<"Transaction Terminated.\n";
    }
    else
    {
        balance -= withdraw_amt;
        if (balance<MIN_BAL)
        {
            cout<<"Your balance is "<<balance<<" which is below "<<MIN_BAL<<"\n";
            cout<<"Your account is discharged by "<<SERVICE_CHARGE<<"rs\n";
            cout<<"Kindly maintain minimum balance of "<<MIN_BAL<<"rs to avoid charges.\n";
            cout<<"Do you want to continue with withdrawal?\n1. Yes\n2. No\n";
            int keep_withdraw;
            cin>>keep_withdraw;

            if (keep_withdraw == 2)
            {
                balance += withdraw_amt;
            }  
        }
    }  
}
void current_ac::display()
{
    cout<<"Balance : "<<balance<<"\n";
}

class Savings_ac: public Account
{
    float balance;
    int d, m, y;
public:
    Savings_ac(): balance(0){}
    void deposit(float dep_amt);
    void withdraw(float withdraw_amt);
    void set_date(int d, int m, int y) {d=d; m=m; y=y;};
    void interest();
    void display();
};
void Savings_ac::deposit(float dep_amt)
{
    int d, m, y;
    cout<<"Enter today's date. (i.e. Day,month,year) : ";
    cin>>d>>m>>y;
    set_date(d, m, y);
    balance += dep_amt;
}
void Savings_ac::withdraw(float withdraw_amt)
{
    if (withdraw_amt>balance)
    {
        cout<<"Your balance is than your withdrawal amount.\n";
        cout<<"Transaction Terminated.\n";
    }
    else
    {
        balance -= withdraw_amt;
        if (balance<MIN_BAL)
        {
            cout<<"\nYour balance is "<<balance<<" which is below "<<MIN_BAL<<"\n";
            cout<<"Your account is discharged by "<<SERVICE_CHARGE<<"rs\n";
            cout<<"Kindly maintain minimum balance of "<<MIN_BAL<<"rs to avoid charges.\n";
            cout<<"Do you want to continue with withdrawal?\n1. Yes\n2. No\n";
            int keep_withdraw;
            cin>>keep_withdraw;

            if (keep_withdraw == 2)
            {
                balance += withdraw_amt;
            }  
        }
    } 
}
void Savings_ac::interest()
{
    int d1, m1, y1;
    cout<<"Enter today's date : (i,e day, month, year)";
    cin>>d1>>m1>>y1;

    if (y1>y)
    {
        cout<<"Interest : "<<balance*R*(y1-y)/100<<"\n";
        balance += balance*R*(y1-y)/100;
    }
}
void Savings_ac::display()
{
    cout<<"Balance : "<<balance<<"\n";
}

int main()
{
    Savings_ac s;
    s.create_account("saving");
    s.deposit(5000);
    s.display();

    s.interest();

    s.withdraw(3000);
    s.display();

    s.withdraw(1500);
    s.display();
    s.withdraw(1000);
    s.display();
    return 0;
}