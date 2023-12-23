#include <iostream>
#include <iomanip>
using namespace std;

class Book
{
protected:
    int book_id;
    string name;
    static int academics;
    static int thriller;
public:
    Book(){}
    Book(int id, string name): book_id(id), name(name){}
    void display_details();
    void total_books();
};
int Book::academics = 0;
int Book::thriller = 0;
void Book::display_details()
{
    cout<<left<<"|"<<setw(6)<<book_id<<"|"<<setw(24)<<name<<"|\n"
        <<"+------+------------------------+\n";
}
void Book::total_books()
{
    cout<<"\nAcademics : "<<academics<<"  "<<"Thriller : "<<thriller;
}

class Academics:public Book
{
    public:
    Academics(){}
    Academics(int id, string name): Book(id, name){academics += 1;}
};


class Thriller:public Book
{
    public:
    Thriller(){}
    Thriller(int id, string name): Book(id, name){thriller += 1;}
};

int main()
{
    int acad_qty = 0, thrill_qty = 0;
    int id;
    string name;
    Academics a[3];
    Thriller t[2];

    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter Book ID : ";
        cin>>id;
        cout<<"Enter Academics book name : ";
        getline(cin>>ws, name);
        a[acad_qty++] = Academics(id, name);
    }

    for (int i = 0; i < 2; i++)
    {
        cout<<"Enter Book ID : ";
        cin>>id;
        cout<<"Enter Thriller book name : ";
        getline(cin>>ws, name);
        t[thrill_qty++] = Thriller(id, name);
    }
    
    cout<<"+------+------------------------+\n";
    cout<<left<<"|"<<setw(6)<<"ID"<<"|"<<setw(24)<<"Book Name"<<"|\n";
    cout<<"+------+------------------------+\n";
    for (int i = 0; i < 3; i++)
    {
        a[i].display_details();
    }

    for (int i = 0; i < 2; i++)
    {
        t[i].display_details();
    }
    a[0].total_books();
    

    return 0;
}