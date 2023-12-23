#include <iostream>
using namespace std;

class Book
{
protected:
    int book_id;
    string name;
public:
    Book(){}
    Book(int id, string name): book_id(id), name(name){}
};

class Sales: public Book
{
    int qty_sold;
public:
    Sales(){}
    Sales(int id, string name): Book(id, name), qty_sold(0){}
    void sale_books(int qty);
    void display_data();
};

void Sales::sale_books(int qty)
{
    qty_sold += qty;
}
void Sales::display_data()
{
    cout<<"\nBook ID : "<<book_id;
    cout<<"\nBook Name : "<<name;
    cout<<"\nTotal copies of "<<name<<" sold : "<<qty_sold<<"\n";
}


int main()
{
    int books = 0;
    int id, qty;
    string name;
    Sales s[2];

    for (int i = 0; i < 2; i++)
    {
        cout<<"Enter book Id : ";
        cin>>id;
        cout<<"Enter Name of Book : ";
        getline(cin>>ws, name);
        s[books++] = Sales(id, name);
    }
    
    s[0].sale_books(6);
    s[0].sale_books(4);
    s[1].sale_books(7);

    s[0].display_data();
    s[1].display_data();

    return 0;
}