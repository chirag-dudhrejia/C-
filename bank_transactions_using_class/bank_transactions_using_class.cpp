#include <iostream>
using namespace std;

class Bank_account
{
    string name;
    int account_no;
    string acc_type;
    float balance;

public:
    Bank_account() {}
    Bank_account(string n, int ac_no, string ac_type, float bal);
    void deposit(float);
    void withdraw(float);
    void detail_display(Bank_account account[]);
    friend int search_account(Bank_account account[], int acc_num);
};

Bank_account::Bank_account(string n, int ac_no, string ac_type, float bal)
{
    name = n;
    account_no = ac_no;
    acc_type = ac_type;
    balance = bal;
}

void Bank_account::deposit(float deposit_amount)
{
    balance = balance + deposit_amount;
    cout <<endl<< "Transaction Successfull" << endl;
    cout << "New Balance : " << balance << endl;
    cout << endl;
}

void Bank_account::withdraw(float withdraw_amount)
{
    if (balance >= withdraw_amount)
    {
        balance = balance - withdraw_amount;
        cout <<endl<< "Withdrawal Successfull of : " << withdraw_amount << endl;
        cout << "New Balance amount : " << balance << endl;
        if (balance < 2000)
        {
            cout << "Balance below minimum requirement of 2000" << endl;
        }
        cout<<endl;
    }
    else
    {
        cout << "Transaction Fail" << endl
             << "Insufficient Balance" << endl;
    }
}

void Bank_account::detail_display(Bank_account account[])
{
    for (int i = 0; i < 10; i++)
    {
        cout <<endl<< "Account Holder : " << account[i].name << endl;
        cout << "Account Number : " << account[i].account_no << endl;
        cout << "Account Type : " << account[i].acc_type << endl;
        cout << "Balance : " << account[i].balance << endl;
        cout << endl;
    }
}

int search_account(Bank_account account[], int acc_num)
{
    for (int i = 0; i < 10; i++)
    {
        if (account[i].account_no == acc_num)
        {
            cout<<endl<<"Name : "<<account[i].name<<endl;
            cout<<"A/c Number : "<<account[i].account_no<<endl;
            cout<<"A/c Type : "<<account[i].acc_type<<endl;
            cout<<"Balance : "<<account[i].balance<<endl<<endl;
            return i;
        }
    }
    return -1;
}

int main()
{
    Bank_account account[10];

    account[0] = Bank_account("Chirag Dudhrejia", 1001, "Saving Account", 20000);
    account[1] = Bank_account("Trupti Thakar", 1002, "Current Account", 80000);
    account[2] = Bank_account("Jigar Dudhrejia", 1003, "Saving Account", 35000);
    account[3] = Bank_account("Yash Thakar", 1004, "Saving Account", 50000);
    account[4] = Bank_account("Yash Gorakhiya", 1005, "Ccurrent Account", 30000);
    account[5] = Bank_account("Rohan Dhakan", 1006, "Saving Account", 15000);
    account[6] = Bank_account("Rahul Jayani", 1007, "Current Account", 23000);
    account[7] = Bank_account("Jay Gorakhiya", 1008, "Saving Account", 10000);
    account[8] = Bank_account("Kishan Sonpal", 1009, "Saving Account", 12000);
    account[9] = Bank_account("Jay Talaviya", 1010, "Current Account", 38000);

    char cases = 1;
    int acc_no;
    float amount;

    while (cases != '0')
    {
        cout << "Choose from below." << endl
             << "1 : Details Of all account." << endl
             << "2 : Detail of particular account" << endl
             << "3 : Deposit" << endl
             << "4 : Withdraw" << endl
             << "0 : Exit" << endl;
        cin >> cases;

        switch (cases)
        {
        case '0':
            cout<<"Program Exited"<<endl;
            break;

        case '1':
            account[0].detail_display(account);
            break;

        case '2':

            break;
        case '3':
            cout << "Enter Account Number : ";
            cin >> acc_no;

            acc_no = search_account(account, acc_no);

            if (acc_no != -1)
            {
                cout << "Enter amount to deposit : ";
                cin >> amount;

                account[acc_no].deposit(amount);
            }
            else
            {
                cout << "Invalid Account Number" << endl;
            }

            break;
        case '4':
            cout << "Enter Account Number : ";
            cin >> acc_no;

            acc_no = search_account(account, acc_no);

            if (acc_no != -1)
            {
                cout << "Enter amount to withdraw : ";
                cin >> amount;

                account[acc_no].withdraw(amount);
            }
            else
            {
                cout << "Invalid Account Number" << endl;
            }
            break;

        default:
            cout << "Innvalid Input" << endl;
            break;
        }

    }

    return 0;
}